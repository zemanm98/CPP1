//
// Created by zeman on 24.11.2021.
//

#ifndef CPP_SEMESTRALKA1_RECTANGLE_HPP
#define CPP_SEMESTRALKA1_RECTANGLE_HPP
#include "Shape.hpp"
#include <iostream>
#include <string>

class Rectangle : public Shape{
public:
    explicit Rectangle(std::string nam, int x, int y, int vx, int vy, int ct, int dt, double base1, double base2);

    void invert_speed_x() override;
    void invert_speed_y() override;
    int get_x() override;
    int get_y() override;
    double* get_params(double arr[2]) override;
    void operator ++() override;
    int get_creation_time() override;
    int get_deletion_time() override;
    void set_alive(bool value) override;
    bool get_alive() override;
    std::string get_name() override;
    void wall_hit(int height, int width) override;
    int get_x_speed() override;
    int get_y_speed() override;
    void set_x(int val) override;
    void set_y(int val) override;
    bool collision(Shape* shp1, Shape* shp2) override;
    ~Rectangle() = default;
private:
    std::string name;
    double start_x;
    double start_y;
    int speed_x;
    int speed_y;
    int creation_time;
    int deletion_time;
    double base1;
    double base2;
    bool alive;
};


#endif //CPP_SEMESTRALKA1_RECTANGLE_HPP
