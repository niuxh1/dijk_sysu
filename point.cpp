//
// Created by ASUS on 24-12-21.
//

#include "point.h"
point::point() {
    name = "default";
}
point::point(string name) {
    this->name = name;
}
string point::get_name() {
    return name;
}
void point::set_name(string name) {
    this->name = name;
}
void point::print() {
    cout << "point name: " << name << endl;
}
point::~point() {
    name.clear();
}
