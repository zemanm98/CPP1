//
// Created by zeman on 24.11.2021.
//

#include "Circle.hpp"

Circle::Circle(std::string nam, int x, int y, int vx, int vy, int ct, int dt, double r) {
    this->name = nam;
    this->start_x = x;
    this->start_y = y;
    this->speed_x = vx;
    this->speed_y = vy;
    this->creation_time = ct;
    this->deletion_time = dt;
    this->diameter = r;
    this->alive = false;
}

void Circle::invert_speed_x() {
    this->speed_x = -1 * this->speed_x;
}

void Circle::invert_speed_y() {
    this->speed_y = -1 * this->speed_y;
}

int Circle::get_x() {
    return this->start_x;
}

int Circle::get_y() {
    return this->start_y;
}

double *Circle::get_params(double arr[2]) {
    return &this->diameter;
}

void Circle::operator++() {
    this->start_x += this->speed_x;
    this->start_y += this->speed_y;
}

int Circle::get_x_speed() {
    return this->speed_x;
}

int Circle::get_y_speed() {
    return this->speed_y;
}

void Circle::set_x(int val) {
    this->start_x = val;
}

void Circle::set_y(int val) {
    this->start_y = val;
}

bool Circle::collision(Shape* shp1, Shape* shp2){
    double ar[2];
    double len1 = ((double)*shp1->get_params(ar)/2);
    double len2 = ((double)*shp2->get_params(ar)/2);
    if(abs((shp1->get_x() - shp2->get_x())) <= (len1 + len2) && abs((shp1->get_y() - shp2->get_y())) <= (len1 + len2)){
        return true;
    }
    return false;
}

int Circle::get_creation_time() {
    return this->creation_time;
}

int Circle::get_deletion_time() {
    return this->deletion_time;
}

void Circle::set_alive(bool value) {
    this->alive = value;
}

bool Circle::get_alive() {
    return this->alive;
}

std::string Circle::get_name() {
    return this->name;
}

void Circle::wall_hit(int height, int width) {
    double add = ((double)this->diameter / 2);
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
