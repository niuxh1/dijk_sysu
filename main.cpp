#include <iostream>
#include <fstream>
#include <sstream>
#include "point.h"
#include "dijk.h"
#include "all_points.h"
#include "map_sysu.h"

using namespace std;

int main() {
    string file_name = R"(C:\Users\ASUS\Desktop\clion\map_for_sysu\campus_map.txt)";
    ifstream inputFile(file_name);
    if (!inputFile.is_open()) { // 检查文件是否成功打开
      cerr << "无法打开文件: " << file_name << endl;
      return 1; // 返回错误代码
    }else{
      cout<<"成功打开文件: "<<file_name<<endl;
    }
    int n, m;
    inputFile >> n >> m;
    cout<<n<<" "<<m<<endl;
    vector<string> locations(n);
    inputFile.ignore();
    string line;
    getline(inputFile, line);
    stringstream ss(line);
    all_points all_p;
    point p;
    for (int i = 0; i < n; ++i) {
      ss >> locations[i];
      p = point(locations[i]);
      all_p.add_point(p);
    }
    map_sysu map_s(all_p);
    for(int i=0;i<m;i++){
        string p1,p2;
        int weight;
        inputFile>>p1>>p2>>weight;
        map_s.add_edge(point(p1),point(p2),weight);
    }
    auto v=map_s.get_map_points();
    dijk d;
    d.all_pair_dijkstra(v);
    inputFile.close();
    file_name = R"(C:\Users\ASUS\Desktop\clion\map_for_sysu\query.txt)";
    ifstream inputFile2(file_name);
    auto file_name3 = R"(C:\Users\ASUS\Desktop\clion\map_for_sysu\result.txt)";
    ofstream outputFile(file_name3);
    if (!inputFile2.is_open()) { // 检查文件是否成功打开
      cerr << "无法打开文件: " << file_name << endl;
      return 1; // 返回错误代码
    }else{
      cout<<"成功打开文件: "<<file_name<<endl;
    }
    if(!outputFile.is_open()) {
      cerr << "无法打开文件: " << file_name3 << endl;
      return 1; // 返回错误代码
    }else{
      cout<<"成功打开文件: "<<file_name3<<endl;
    }
    int q;
    inputFile2>>q;
    cout<<q;
    for(int i=0;i<q;i++){
        string p1,p2;
        inputFile2>>p1>>p2;
        string flag="numth: "+to_string(i+1)+"\n";
        string result=p1+"->"+p2+" shortest path is: "+d.path_print(all_p.points_number(point(p1)),all_p.points_number(point(p2)),all_p.point_map2_get())+"\n";
        string length=p1+"->"+p2+" shortest length is: "+to_string(d.get_len()[all_p.points_number(point(p1))][all_p.points_number(point(p2))])+"\n";
        outputFile<<flag<<result<<length;
    }
    return 0;
}
