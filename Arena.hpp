//
// Created by zeman on 21.10.2021.
//

#ifndef CPP_SEMESTRALKA1_ARENA_HPP
#define CPP_SEMESTRALKA1_ARENA_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Shape.hpp"

class Arena {
public:
    enum ObjectType {square, ball, rectangle};
    Arena(std::vector<Shape*> objects, std::vector<bool> out_opt, int width, int height,
            int object_count, int step_size, int max_step, ObjectType object_type);
private:
    std::vector<Shape*> objects;
    const std::vector<bool> out_opt;
    const int width;
    const int height;
    const int object_count;
    const int step_size;
    const int max_step;
    const ObjectType object_type;
};


#endif //CPP_SEMESTRALKA1_ARENA_HPP
