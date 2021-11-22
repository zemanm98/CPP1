//
// Created by zeman on 21.10.2021.
//

#include "Arena.hpp"

Arena::Arena(std::vector<std::shared_ptr<Shape>> objects, std::vector<bool> out_opt, int width, int height, int object_count,
             int step_size, int max_step, Arena::ObjectType object_type) {
    this->objects = objects;
    this->out_opt = out_opt;
    this->width = width;
    this->height = height;
    this->object_count = object_count;
    this->step_size = step_size;
    this->max_step = max_step;
    this->object_type = object_type;
}

void Arena::step() {
    for(int i = 0; i < this->objects.size(); i++){
        ++*(this->objects[i].get());
        check_wall_hit(this->objects[i].get());
        std::cout << "obj: " << i << " x: " << this->objects[i]->get_x() << " y: " << this->objects[i]->get_y() << std::endl;
    }
}

void Arena::check_wall_hit(Shape* sh){
    if(sh->get_x() >= this->width && sh->get_y() < this->height && sh->get_y() > 0){
        sh->set_x(this->width - (sh->get_x() % this->width));
        sh->invert_speed_x();
    }
    else if(sh->get_x() <= 0 && sh->get_y() < this->height && sh->get_y() > 0){
        sh->set_x(0 + (-1 * sh->get_x()));
        sh->invert_speed_x();
    }
    else if(sh->get_y() >= this->height && sh->get_x() < this->width && sh->get_x() > 0){
        sh->set_y(this->height - (sh->get_y() % this->height));
        sh->invert_speed_y();
    }
    else if(sh->get_y() <= 0 && sh->get_x() < this->width && sh->get_x() > 0){
        sh->set_y(0 + (-1 * sh->get_y()));
        sh->invert_speed_y();
    }
    else if(sh->get_x() >= this->width && sh->get_y() >= this->height){
        sh->set_x(this->width - (sh->get_x() % this->width));
        sh->invert_speed_x();
        sh->set_y(this->height - (sh->get_y() % this->height));
        sh->invert_speed_y();
    }
    else if(sh->get_x() >= this->width && sh->get_y() <= 0){
        sh->set_x(this->width - (sh->get_x() % this->width));
        sh->invert_speed_x();
        sh->set_y(0 + (-1 * sh->get_y()));
        sh->invert_speed_y();
    }
    else if(sh->get_x() <= 0 && sh->get_y() <= 0){
        sh->set_x(0 + (-1 * sh->get_x()));
        sh->invert_speed_x();
        sh->set_y(0 + (-1 * sh->get_y()));
        sh->invert_speed_y();
    }
    else if(sh->get_x() <= 0 && sh->get_y() >= this->height){
        sh->set_x(0 + (-1 * sh->get_x()));
        sh->invert_speed_x();
        sh->set_y(this->height - (sh->get_y() % this->height));
        sh->invert_speed_y();
    }
}

void Arena::run_simulation(){
    for(int i = 1; i <= this->max_step; i++){
        this->step();
        this->find_collisions();
    }
}

void Arena::find_collisions(){
    for(int i = 0; i < this->objects.size(); i++){
        for(int a = i; a < this->objects.size(); a++){
            if(a != i){
                if(this->collision(this->objects[i].get(), this->objects[a].get())){
                    /*
                    if(out_opt[0]){
                        exit(0);
                    }
                    */
                    std::cout << "kolize: " << i << " a " << a << std::endl;
                }
            }
        }
    }
}

bool Arena::collision(Shape* sh1, Shape* sh2){
    double len1 = ((double)*sh1->get_params()/2);
    double len2 = ((double)*sh2->get_params()/2);
    if(abs((sh1->get_x() - sh2->get_x())) <= (len1 + len2) && abs((sh1->get_y() - sh2->get_y())) <= (len1 + len2)){
        return true;
    }
    return false;
}
