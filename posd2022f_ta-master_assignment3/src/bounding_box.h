#pragma once

#include <set>
#include <string>
#include "shape.h"
#include "point.h"

class BoundingBox
{
private:
    Point *_max;
    Point *_min;

    std::set<const Point*> Points{};

public:
    BoundingBox(std::set<const Point *> points) 
    {
        Points = points;
        // 1. 找最大的x,y
        // 2. 找最小的x,y
        // 3. 最大的只給_max , 最小的指給 _min

        double max_x = -9999;
        double min_x = 9999;
        double max_y = -9999;
        double min_y = 9999;


        // find max x
        for (auto const &x: Points) 
        {
            if(max_x < x->x())
            {
                max_x = x->x();
            }
        }
        // find min x 
        for (auto const &x: Points) 
        {
            if(min_x > x->x())
            {
                min_x = x->x();
            }
        }
        // find max y
        for (auto const &y: Points) 
        {
            if(max_y < y->y())
            {
                max_y = y->y();
            }
        }
        // find min y 
        for (auto const &y: Points) 
        {
            if(min_y > y->y())
            {
                min_y = y->y();
            }
        }
        _max = new Point(max_x,max_y);
        _min = new Point(min_x,min_y);

    }

    // getNewMax 
    Point *calMaximumPoint(const std::set<const Point *> points) 
    {
        Points.insert(points.begin(),points.end());

        double max_x = -9999;
        double max_y = -9999;
        Point *MaximumPoint;

        // find max x
        for (auto const &x: Points) 
        {
            if(max_x < x->x())
            {
                max_x = x->x();
            }
        }
        // find max y
        for (auto const &y: Points) 
        {
            if(max_y < y->y())
            {
                max_y = y->y();
            }
        }

        MaximumPoint = new Point(max_x,max_y);

        return MaximumPoint;
    }

    // getNewMin
    Point *calMinimumPoint(const std::set<const Point *> points) 
    {
        Points.insert(points.begin(),points.end());

        double min_x = 9999;
        double min_y = 9999;
        Point *MinimumPoint;

        // find min x 
        for (auto const &x: Points) 
        {
            if(min_x > x->x())
            {
                min_x = x->x();
            }
        }
        // find min y 
        for (auto const &y: Points) 
        {
            if(min_y > y->y())
            {
                min_y = y->y();
            }
        }

        MinimumPoint = new Point(min_x,min_y);

        return MinimumPoint;
    }

    const Point *max() 
    {
        return _max;
    }

    const Point *min() 
    {
        return _min;
    }

    bool collide(BoundingBox *box) 
    {
        // the X_max of the box1 is smaller than the X_min of the box2; or
        // the X_min of the box1 is greater than the X_max of the box2; or
        // the Y_max of the box1 is smaller than the Y_min of the box2; or
        // the Y_min of the box1 is greater than the Y_max of the box2.

        // box1 _max , _min
        // box2 box.max box.min

        if(!((_max->x() < box->min()->x()) ||
             (_min->x() > box->max()->x()) ||
             (_max->y() < box->min()->y()) ||
             (_min->y() > box->max()->y()) ) )
        {
            return true;
        }
        return false;

    }
};