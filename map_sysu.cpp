//
// Created by ASUS on 24-12-21.
//

#include "map_sysu.h"
map_sysu::map_sysu(all_points all_p) {
    this->all_p = all_p;
    make_map();
}
void map_sysu::add_point(point p) {
    all_p.add_point(p);
}
void map_sysu::make_map() {
    map_points = vector<vector<int>>(all_p.size(), vector<int>(all_p.size(), INT_MAX));
}
void map_sysu::add_edge(point p1, point p2, int weight) {
    int i=all_p.points_number(p1);
    int j=all_p.points_number(p2);
    map_points[i][j]=weight;
    map_points[j][i]=weight;
}
void map_sysu::print() {
    int size=all_p.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout<<map_points[i][j]<<" ";
        }
        cout<<endl;
    }
}
map_sysu::~map_sysu() {
    all_p.~all_points();
    map_points.clear();
}
vector<vector<int>> map_sysu::get_map_points() {
  return map_points;
}
