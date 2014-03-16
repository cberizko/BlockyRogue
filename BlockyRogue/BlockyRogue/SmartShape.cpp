#include "SmartShape.hpp"

SmartShape::SmartShape(int verts, int radius, int variance)
{
    position = sf::Vector2f();
    for(int i = 0; i < verts+1; i++)
    {
        //Equation of a Circle: (parametric coordinates)
        //for a circle with origin (j, k) and radius r:
        //x(t) = r cos(t) + j       y(t) = r sin(t) + k

        radius += (rand()%10)-5;

        int radius_offset = std::rand()%variance; 
        double location = i*((2*PI)/verts);

        sf::Vector2f pointOffset = sf::Vector2f((radius+radius_offset)*std::cos(location)
                                            ,(radius+radius_offset)*std::sin(location));

        points.push_back(new SmartPoint(pointOffset, radius_offset, position)); 
    }
}


SmartShape::SmartShape(int verts, int radius, int variance, sf::Vector2f p)
{
    position = p;
    for(int i = 0; i < verts+1; i++)
    {
        //Equation of a Circle: (parametric coordinates)
        //for a circle with origin (j, k) and radius r:
        //x(t) = r cos(t) + j       y(t) = r sin(t) + k

        radius += (rand()%10)-5;
        int radius_offset = std::rand()%variance; 
        double location = i*((2*PI)/verts);

        sf::Vector2f pointOffset = sf::Vector2f((radius+radius_offset)*std::cos(location) 
                                            ,(radius+radius_offset)*std::sin(location));

        points.push_back(new SmartPoint(pointOffset+position, radius_offset, position)); 
    }
}

SmartShape::~SmartShape()
{
    while(!points.empty())
    {
        delete points.back();
        points.pop_back();
    }
}

void SmartShape::addPoint()
{
    
    int seedPoint = rand()%(points.size()-1);
    sf::Vector2f position = points[seedPoint]->position;
    std::cout<<"New point from seed: " << seedPoint << std::endl;
    position += sf::Vector2f(rand()%60, rand()%60);
    
    points.push_back(new SmartPoint(position,10, position));

    std::sort(points.begin(), points.end(), SmartShape::sortPoints);
}

void SmartShape::bouncePoints()
{
    for(int i=0; i < points.size(); i++)
    {
        points[i]->positionOffset += sf::Vector2f((rand()%70)-35,(rand()%70)-35);
    }
}

void SmartShape::update(sf::Vector2f moveBy)
{
    position+=moveBy;
    for(int i=0; i < points.size(); i++)
    {
        points[i]->update(moveBy);
    }
}


sf::VertexArray SmartShape::getShape(sf::Color c)
{
    vertArray.clear();
    vertArray = sf::VertexArray(sf::TrianglesFan, points.size());
    
    for(int i = 0; i < points.size(); i++)
    {
        vertArray[i].position = points[i]->positionOffset;
        vertArray[i].color = c;
    }
    vertArray[0].color = sf::Color::White;

    return vertArray;
}

bool SmartShape::sortPoints(SmartPoint *a,SmartPoint *b)
{
    return (a->positionOffset.x > b->positionOffset.x);
}
