//
// Created by ASUS on 24-12-21.
//

#ifndef MAP_FOR_SYSU__DIJK_H_
#define MAP_FOR_SYSU__DIJK_H_
#include <vector>
#include <string>
#include <map>
#include "point.h"

using namespace std;

class dijk {
private:
  vector<vector<int>> len;
  vector<vector<int>> path;
public:
    dijk();
    pair<vector<int>,vector<int>> dijkstra(int start, vector<vector<int>> map_points);
    void all_pair_dijkstra(vector<vector<int>> map_points);
    vector<vector<int>> get_len(){
      return len;
    }
    vector<vector<int>> get_path(){
      return path;
    }
    string path_print(int start, int end,map<int,point> point_map2);
    void len_print(int start,int end);
    ~dijk();
};

#endif //MAP_FOR_SYSU__DIJK_H_
