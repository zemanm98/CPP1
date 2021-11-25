//
// Created by zeman on 21.10.2021.
//

#include "Square.hpp"

Square::Square(std::string nam, double x, double y, int vx, int vy, int ct, int dt, double length){
    this->name = nam;
    this->start_x = x;
    this->start_y = y;
    this->creation_time = ct;
    this->deletion_time = dt;
    this->speed_x = vx;
    this->speed_y = vy;
    this->side_length = length;
    this->alive = false;
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

double *Square::get_params(double arr[2]) {
    return &this->side_length;
}

bool Square::collision(Shape* shp1, Shape* shp2){
    double ar[2];
    double len1 = ((double)*shp1->get_params(ar)/2);
    double len2 = ((double)*shp2->get_params(ar)/2);
    if(abs((shp1->get_x() - shp2->get_x())) <= (len1 + len2) && abs((shp1->get_y() - shp2->get_y())) <= (len1 + len2)){
        return true;
    }
    return false;
}

int Square::get_creation_time() {
    return this->creation_time;
}

int Square::get_deletion_time() {
    return this->deletion_time;
}

void Square::set_alive(bool value) {
    this->alive = value;
}

bool Square::get_alive() {
    return this->alive;
}

std::string Square::get_name() {
    return this->name;
}

void Square::wall_hit(int height, int width) {
    double add = ((double)this->side_length / 2);
    if((this->start_x + add) > width && (this->start_y + add) < height && (this->start_y - add) > 0){
        this->start_x = (width - ((this->start_x + add) - width));
        this->speed_x = -1 * this->speed_x;
    }
    else if((this->start_x - add) < 0 && (this->start_y + add) < height && (this->start_y - add) > 0){
        this->start_x = (0 + (-1 * (this->start_x - add)));
        this->speed_x = -1 * this->speed_x;
    }
    else if((this->start_y + add) > height && (this->start_x + add) < width && (this->start_x - add) > 0){
        this->start_y = (height - ((this->start_y + add) - height));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_y - add) < 0 && (this->start_x + add) < width && (this->start_x - add) > 0){
        this->start_y = (0 + (-1 * (this->start_y - add)));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_x + add) > width && (this->start_y + add) > height){
        this->start_x = (width - ((this->start_x + add) - width));
        this->speed_x = -1 * this->speed_x;
        this->start_y = (height - ((this->start_y + add) - height));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_x + add) > width && (this->start_y - add) < 0){
        this->start_x = (width - ((this->start_x + add) - width));
        this->speed_x = -1 * this->speed_x;
        this->start_y = (0 + (-1 * (this->start_y - add)));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_x - add) < 0 && (this->start_y - add) < 0){
        this->start_x = (0 + (-1 * (this->start_x - add)));
        this->speed_x = -1 * this->speed_x;
        this->start_y = (0 + (-1 * (this->start_y - add)));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_x - add) < 0 && (this->start_y + add) > height){
        this->start_x = (0 + (-1 * (this->start_x - add)));
        this->speed_x = -1 * this->speed_x;
        this->start_y = (height - ((this->start_y + add) - height));
        this->speed_y = -1 * this->speed_y;
    }
}
