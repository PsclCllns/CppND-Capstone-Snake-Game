#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SDL.h"
#include <random>
#include <array>

enum class ShapeType
{
    Rod,
    LShape,
    Dot
};


class GeneralObstacle
{
public:
    GeneralObstacle() {}
    virtual bool isBlocked(int x, int y) = 0;
    int getX() {return _x;}
    int getY() {return _y;}
protected:
    int _x, _y;
};



class ObstacleBox : public GeneralObstacle
{
public:
    ObstacleBox(int x, int y) {_x = x; _y = y;};
    bool isBlocked(int x, int y) override;
};



class Obstacle : public GeneralObstacle
{
public:
    Obstacle(int x, int y, ShapeType shape);
    bool isBlocked(int x, int y) override;
    void createShape(ShapeType shape);
    std::vector<ObstacleBox>& getBoxList();

private:
    std::vector<ObstacleBox> _boxList;
};


#endif
