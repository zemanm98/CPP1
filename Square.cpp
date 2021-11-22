//
// Created by zeman on 21.10.2021.
//

#include "Square.hpp"

Square::Square(std::string nam, int x, int y, int vx, int vy, int ct, int dt, int length){
    this->name = nam;
    this->start_x = x;
    this->start_y = y;
    this->creation_time = ct;
    this->deletion_time = dt;
    this->speed_x = vx;
    this->speed_y = vy;
    this->side_length = length;
}

void Square::operator ++(){
    this->start_x += this->speed_x;
    this->start_y += this->speed_y;

}
void Square::set_x(int val) {
    this->start_x = val;
}
void Square::set_y(int val) {
    this->start_y = val;
}
int Square::get_x_speed(){
    return this->speed_x;
}
int Square::get_y_speed(){
    return this->speed_y;
}
void Square::invert_speed_y(){
    this->speed_y = -1 * this->speed_y;
}
void Square::invert_speed_x(){
    this->speed_x = -1 * this->speed_x;
}
int Square::get_x() {
    return this->start_x;
}

int Square::get_y() {
    return this->start_y;
}

int *Square::get_params() {
    return &this->side_length;
}
