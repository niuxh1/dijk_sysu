//
// Created by ASUS on 24-12-21.
//

#ifndef MAP_FOR_SYSU__POINT_H_
#define MAP_FOR_SYSU__POINT_H_
#include<string>
#include<iostream>

using namespace std;

class point {
private:
  string name;
public:
    point();
    point(string name);
    string get_name();
    void set_name(string name);
    void print();
    ~point();
     point& operator=(const point& other) {
        if (this != &other) { // 自我赋值检查
          name = other.name;
        }
         return *this;
     }
    bool operator==(const point& other) const {
        return name == other.name;
    }
    bool operator<(const point& other) const {
        return name < other.name;
    }
    bool operator>(const point& other) const {
        return name > other.name;
    }
};

#endif //MAP_FOR_SYSU__POINT_H_
