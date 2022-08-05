#include "obstacle.h"

constexpr std::array<std::array<int, 2>, 1> dot_construction = {{{0,0}}};
constexpr std::array<std::array<int, 2>, 6> rod_construction = {{{0,0},{1,0},{2,0},{3,0},{4,0},{5,0}}};
constexpr std::array<std::array<int, 2>, 9> lshape_construction = {{{0,5},{0,4},{0,3},{0,2},{0,1},{0,0},{1,5},{2,5},{3,5}}};


bool ObstacleBox::isBlocked(int x, int y)
{
    if(_x == x && _y == y)
        return true;
    else
        return false;    
}

Obstacle::Obstacle(int x, int y, ShapeType shape)
{
    _x = x;
    _y = y;
    createShape(shape);
}

void Obstacle::createShape(ShapeType shape)
{
    switch(shape)
    {
    case ShapeType::Dot:
        for (auto& point : dot_construction)
        {
            _boxList.emplace_back(ObstacleBox(_x + point[0], _y + point[1]));
        }
        break;
    case ShapeType::Rod:
        for (auto& point : rod_construction)
        {
            _boxList.emplace_back(ObstacleBox(_x + point[0], _y + point[1]));
        }
        break;
    case ShapeType::LShape:
        for (auto& point : lshape_construction)
        {
            _boxList.emplace_back(ObstacleBox(_x + point[0], _y + point[1]));
        }
        break;
    }
    
}

std::vector<ObstacleBox>& Obstacle::getBoxList()
{
    return _boxList;
}

bool Obstacle::isBlocked(int x, int y)
{
    for (auto& box : _boxList)
    {
        if (box.isBlocked(x,y))
            return true;
    }
    return false;
}