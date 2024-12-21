//
// Created by ASUS on 24-12-21.
//

#include "all_points.h"
all_points::all_points() {
    points = vector<point>();
    point_map = map<const point, int>();
}
void all_points::add_point(point p) {
    points.push_back(p);
    point_map[p] = points.size() - 1;
    point_map2[points.size() - 1] = p;
}

void all_points::print() {
    for (int i = 0; i < points.size(); i++) {
        cout<<"number: "<<point_map[points[i]]<<endl;
        points[i].print();
    }
}
all_points::~all_points() {
    points.clear();
    point_map.clear();
}
int all_points::size() {
  return points.size();
}
int all_points::points_number(point p) {
  return point_map[p];
}
string all_points::get_name(int i) {
  return point_map2[i].get_name();
}
map<int, point> all_points::point_map2_get() {
  return point_map2;
}
map<const point, int> all_points::point_map_get() {
  return point_map;
}
