//
// Created by zeman on 21.10.2021.
//

#ifndef CPP_SEMESTRALKA1_SHAPE_HPP
#define CPP_SEMESTRALKA1_SHAPE_HPP


class Shape {
public:
    virtual void invert_speed_x() = 0;
    virtual void invert_speed_y() = 0;
    virtual int get_x() = 0;
    virtual int get_y() = 0;
    virtual int get_x_speed() = 0;
    virtual int get_y_speed() = 0;
    virtual void set_x(int val) = 0;
    virtual void set_y(int val) = 0;
    virtual int* get_params() = 0;
    virtual void operator ++() = 0;
    ~Shape() = default;
};


#endif //CPP_SEMESTRALKA1_SHAPE_HPP
