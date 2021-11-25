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
    this->current_step = 0;
    this->max_step = max_step;
    this->object_type = object_type;
}

void Arena::step() {
    std::cout<<"step: " << this->current_step << std::endl;
    for(int i = 0; i < this->objects.size(); i++){
        check_lifetime(this->objects[i].get());
        if(this->objects[i]->get_creation_time() == this->current_step){
            this->objects[i]->set_alive(true);
        }
        if(this->objects[i]->get_alive()) {
            ++*(this->objects[i].get());
            this->objects[i]->wall_hit(this->height, this->width);
            std::cout << "obj: " << this->objects[i]->get_name() << " x: " << this->objects[i]->get_x() << " y: " << this->objects[i]->get_y()
                      << std::endl;
        }
    }
    this->current_step++;
}

bool Arena::check_lifetime(Shape* sh){
    if(sh->get_deletion_time() == this->current_step){
        sh->set_alive(false);
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
        if(this->objects[i]->get_alive()) {
            for (int a = i; a < this->objects.size(); a++) {
                if (a != i && this->objects[a]->get_alive()) {
                    if (this->objects[i]->collision(this->objects[i].get(), this->objects[a].get())) {
                        std::cout << "kolize: " << i << " a " << a << std::endl;
                    }
                }
            }
        }
    }
}
