//
// Created by ASUS on 24-12-21.
//

#ifndef MAP_FOR_SYSU__ALL_POINTS_H_
#define MAP_FOR_SYSU__ALL_POINTS_H_
#include <vector>
#include "point.h"
#include <map>

using namespace std;

class all_points {
private:
  vector<point> points;
  map<const point,int> point_map;
  map<int,point> point_map2;
public:
    all_points();
    void add_point(point p);
    int size();
    int points_number(point p);
    void print();
    map<int,point> point_map2_get();
    map<const point,int> point_map_get();
    string get_name(int i);
    ~all_points();
};

#endif //MAP_FOR_SYSU__ALL_POINTS_H_
