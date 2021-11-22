//
// Created by zeman on 21.10.2021.
//

#ifndef CPP_SEMESTRALKA1_SQUARE_HPP
#define CPP_SEMESTRALKA1_SQUARE_HPP

#include <iostream>
#include <string>
#include "Shape.hpp"

class Square : public Shape{
public:
    explicit Square(std::string nam, int x, int y, int vx, int vy, int ct, int dt, int length);

    void invert_speed_x() override;
    void invert_speed_y() override;
    int get_x() override;
    int get_y() override;
    int* get_params() override;
    void operator ++() override;
    int get_x_speed() override;
    int get_y_speed() override;
    void set_x(int val) override;
    void set_y(int val) override;
    ~Square() = default;

private:
    std::string name;
    int start_x;
    int start_y;
    int speed_x;
    int speed_y;
    int creation_time;
    int deletion_time;
    int side_length;
};


#endif //CPP_SEMESTRALKA1_SQUARE_HPP
