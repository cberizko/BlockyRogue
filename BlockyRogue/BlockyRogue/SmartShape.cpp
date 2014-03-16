#include "SmartShape.hpp"

SmartShape::SmartShape(int verts, int radius, int variance)
{
    for(int i = 0; i < verts+1; i++)
    {
        //Equation of a Circle: (parametric coordinates)
        //for a circle with origin (j, k) and radius r:
        //x(t) = r cos(t) + j       y(t) = r sin(t) + k

        radius += (rand()%10)-5;

        int radius_offset = std::rand()%variance; 
        double location = i*((2*PI)/verts);

        sf::Vector2f position = sf::Vector2f((radius+radius_offset)*std::cos(location)
                                            ,(radius+radius_offset)*std::sin(location));

        points.push_back(new SmartPoint(position, radius_offset)); 
    }
}


SmartShape::SmartShape(int verts, int radius, int variance, sf::Vector2f p)
{
    for(int i = 0; i < verts+1; i++)
    {
        //Equation of a Circle: (parametric coordinates)
        //for a circle with origin (j, k) and radius r:
        //x(t) = r cos(t) + j       y(t) = r sin(t) + k

        radius += (rand()%10)-5;
        int radius_offset = std::rand()%variance; 
        double location = i*((2*PI)/verts);

        sf::Vector2f position = sf::Vector2f((radius+radius_offset)*std::cos(location) 
                                            ,(radius+radius_offset)*std::sin(location));

        points.push_back(new SmartPoint(position+p, radius_offset)); 
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
    int seedPoint = (rand()%points.size()-1);
    
    sf::Vector2f position = points[seedPoint]->position;
    position += sf::Vector2f(rand()%60, rand()%60);
    
    points.push_back(new SmartPoint(position,10));
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

    return vertArray;
}
