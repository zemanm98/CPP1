//
// Created by zeman on 21.10.2021.
//

#ifndef CPP_SEMESTRALKA1_SHAPE_HPP
#define CPP_SEMESTRALKA1_SHAPE_HPP
#import <string>

class Shape {
public:
    virtual void invert_speed_x() = 0;
    virtual void invert_speed_y() = 0;
    virtual int get_x() = 0;
    virtual int get_y() = 0;
    virtual int get_x_speed() = 0;
    virtual int get_y_speed() = 0;
    virtual int get_creation_time() = 0;
    virtual int get_deletion_time() = 0;
    virtual void set_alive(bool value) = 0;
    virtual bool get_alive() = 0;
    virtual std::string get_name() = 0;
    virtual void set_x(int val) = 0;
    virtual void set_y(int val) = 0;
    virtual double* get_params(double arr[2]) = 0;
    virtual void operator ++() = 0;
    virtual bool collision(Shape* shp1, Shape* shp2) = 0;
    virtual void wall_hit(int height, int width) = 0;
    ~Shape() = default;
};


#endif //CPP_SEMESTRALKA1_SHAPE_HPP
