//
// Created by zeman on 24.11.2021.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(std::string nam, int x, int y, int vx, int vy, int ct, int dt, double base1, double base2) {
    this->name = nam;
    this->start_x = x;
    this->start_y = y;
    this->speed_x = vx;
    this->speed_y = vy;
    this->creation_time = ct;
    this->deletion_time = dt;
    this->base1 = base1;
    this->base2 = base2;
    this->alive = false;
}

void Rectangle::invert_speed_x() {
    this->speed_x = -1 * this->speed_x;
}

void Rectangle::invert_speed_y() {
    this->speed_y = -1 * this->speed_y;
}

int Rectangle::get_x() {
    return this->start_y;
}

int Rectangle::get_y() {
    return this->start_y;
}

double *Rectangle::get_params(double arr[2]) {
    double *out = arr;
    out[0] = this->base1;
    out[1] = this->base2;
    return out;
}

void Rectangle::operator++() {
    this->start_x += this->speed_x;
    this->start_y += this->speed_y;
}

int Rectangle::get_x_speed() {
    return this->speed_x;
}

int Rectangle::get_y_speed() {
    return this->speed_y;
}

void Rectangle::set_x(int val) {
    this->start_x = val;
}

void Rectangle::set_y(int val) {
    this->start_y = val;
}

bool Rectangle::collision(Shape *shp1, Shape *shp2) {
    double ar[2];
    double* params1 = shp1->get_params(ar);
    double len1x = ((double)params1[0]/2);
    double len1y = ((double)params1[1]/2);
    double* params2 = shp2->get_params(ar);
    double len2x = ((double)params2[0]/2);
    double len2y = ((double)params2[1]/2);
    if(abs((shp1->get_x() - shp2->get_x())) <= (len1x + len2x) && abs((shp1->get_y() - shp2->get_y())) <= (len1y + len2y)){
        return true;
    }
    return false;
}

int Rectangle::get_creation_time() {
    return this->creation_time;
}

int Rectangle::get_deletion_time() {
    return this->deletion_time;
}

void Rectangle::set_alive(bool value) {
    this->alive = value;
}

bool Rectangle::get_alive() {
    return this->alive;
}

std::string Rectangle::get_name() {
    return this->name;
}

void Rectangle::wall_hit(int height, int width) {
    double addx = ((double)this->base1 / 2);
    double addy = ((double)this->base2 / 2);
    if((this->start_x + addx) > width && (this->start_y + addy) < height && (this->start_y - addy) > 0){
        this->start_x = (width - ((this->start_x + addx) - width));
        this->speed_x = -1 * this->speed_x;
    }
    else if((this->start_x - addx) < 0 && (this->start_y + addy) < height && (this->start_y - addy) > 0){
        this->start_x = (0 + (-1 * (this->start_x - addx)));
        this->speed_x = -1 * this->speed_x;
    }
    else if((this->start_y + addy) > height && (this->start_x + addx) < width && (this->start_x - addx) > 0){
        this->start_y = (height - ((this->start_y + addy) - height));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_y - addy) < 0 && (this->start_x + addx) < width && (this->start_x - addx) > 0){
        this->start_y = (0 + (-1 * (this->start_y - addy)));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_x + addx) > width && (this->start_y + addy) > height){
        this->start_x = (width - ((this->start_x + addx) - width));
        this->speed_x = -1 * this->speed_x;
        this->start_y = (height - ((this->start_y + addy) - height));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_x + addx) > width && (this->start_y - addy) < 0){
        this->start_x = (width - ((this->start_x + addx) - width));
        this->speed_x = -1 * this->speed_x;
        this->start_y = (0 + (-1 * (this->start_y - addy)));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_x - addx) < 0 && (this->start_y - addy) < 0){
        this->start_x = (0 + (-1 * (this->start_x - addx)));
        this->speed_x = -1 * this->speed_x;
        this->start_y = (0 + (-1 * (this->start_y - addy)));
        this->speed_y = -1 * this->speed_y;
    }
    else if((this->start_x - addx) < 0 && (this->start_y + addy) > height){
        this->start_x = (0 + (-1 * (this->start_x - addx)));
        this->speed_x = -1 * this->speed_x;
        this->start_y = (height - ((this->start_y + addy) - height));
        this->speed_y = -1 * this->speed_y;
    }
}
