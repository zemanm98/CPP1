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
            int object_count, int step_size, int max_step, ObjectType object_type, std::string out);

    void find_collisions();
    void run_simulation();
    void step();
    bool check_lifetime(Shape* sh);
    bool check_creation(Shape* sh);
    ~Arena() = default;
    std::vector<std::shared_ptr<Shape>> objects;
    std::vector<bool> out_opt;
    std::string outoption;
    int width;
    int height;
    int current_step;
    int object_count;
    int step_size;
    int max_step;
    ObjectType object_type;

};


#endif //CPP_SEMESTRALKA1_ARENA_HPP
