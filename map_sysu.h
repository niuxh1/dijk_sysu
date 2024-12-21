//
// Created by ASUS on 24-12-21.
//

#ifndef MAP_FOR_SYSU__MAP_SYSU_H_
#define MAP_FOR_SYSU__MAP_SYSU_H_
#include "all_points.h"

class map_sysu {
private:
  all_points all_p;
  vector<vector<int>> map_points;
public:
    map_sysu(all_points all_p);
    void add_point(point p);
    void make_map();
    void add_edge(point p1, point p2,int weight);
    void print();
    vector<vector<int>> get_map_points() ;
    ~map_sysu();

};

#endif //MAP_FOR_SYSU__MAP_SYSU_H_
