//
// Created by ASUS on 24-12-21.
//

#include "dijk.h"
#include "point.h"
#include <queue>
#include <iostream>
#include <map>

dijk::dijk() {}
pair<vector<int>,vector<int>> dijk::dijkstra(int start,vector<vector<int>> map_points) {
  int n = map_points.size();
  vector<int> dis(n, INT_MAX);
  dis[start] = 0;
  vector<int> pre(n, -1);
  pre[start]=start;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (d > dis[u]) {
      continue;
    }

    for (int v = 0; v < n; ++v) {
      if (map_points[u][v] != INT_MAX) {
        if (dis[v] > dis[u] + map_points[u][v]) {
          dis[v] = dis[u] + map_points[u][v];
          pre[v] = u;
          pq.push({dis[v], v});
        }
      }
    }
  }
  return {dis, pre};
}

void dijk::all_pair_dijkstra(vector<vector<int>> map_points) {
    int n =map_points.size();
    len=vector<vector<int>>(n);
    path=vector<vector<int>>(n);
    for(int i=0;i<n;i++){
      len[i]=dijkstra(i,map_points).first;
      path[i]=dijkstra(i,map_points).second;
    }
}
dijk::~dijk() {
    len.clear();
    path.clear();
}
string dijk::path_print(int start, int end,map<int,point> point_map2) {
    if(path[start][end]==-1){
      return "no path";
    }
    vector<int> p;
    p.push_back(end);
    string s;
    while(path[start][end]!=start){
      p.push_back(path[start][end]);
      end=path[start][end];
    }
    p.push_back(start);
    for(int i=p.size()-1;i>=0;i--){
        s+= point_map2[p[i]].get_name()+"->";
    }
    s.pop_back();
    s.pop_back();
    return s;
}
void dijk::len_print(int start, int end) {
    cout<<len[start][end]<<endl;
}
