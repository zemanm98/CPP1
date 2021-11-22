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
    Arena(std::vector<std::shared_ptr<Shape>> objects, std::vector<bool> out_opt, int width, int height,
            int object_count, int step_size, int max_step, ObjectType object_type);

    void find_collisions();
    bool collision(Shape* sh1, Shape* sh2);
    void run_simulation();
    void check_wall_hit(Shape* sh);
    void step();
    ~Arena() = default;
    std::vector<std::shared_ptr<Shape>> objects;
    std::vector<bool> out_opt;
    int width;
    int height;
    int object_count;
    int step_size;
    int max_step;
    ObjectType object_type;

};


#endif //CPP_SEMESTRALKA1_ARENA_HPP
