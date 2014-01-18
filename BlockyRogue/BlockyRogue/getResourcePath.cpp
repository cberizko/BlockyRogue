//
//  getResource.cpp
//  BlockyRogue
//
//  Created by Jeff More on 1/18/14.
//  Copyright (c) 2014 VGDC. All rights reserved.
//

#include "getResourcePath.h"


std::string getResourcePath(std::string path)
{
#ifdef  __APPLE__
    return resourcePath();
#endif
    return path;
}