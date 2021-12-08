//
// Created by zeman on 21.10.2021.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "Arena.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

std::vector<std::string> parse_input(std::string &line, const std::string& delim){
    std::vector<std::string> res;
    size_t pos = 0;
    std::string data;
    while ((pos = line.find(delim)) != std::string::npos) {
        data = line.substr(0, pos);
        res.push_back(data);
        line.erase(0, pos + delim.length());
    }
    res.push_back(line);
    return res;
}


std::shared_ptr<Arena> load_file(const std::shared_ptr<std::string>& name, const std::shared_ptr<std::string>& outopt){
    std::string names = *name;
    std::string outoption = *outopt;
    std::ifstream fin;
    fin.open(names, std::ios::in);
    if(!fin.is_open()){
        std::cout << "File " << name << " cannot be opened" << std::endl;
        exit(0);
    }
    std::vector<std::shared_ptr<Shape>> objects;
    std::vector<bool> out_opt(2);
    int width;
    int height;
    int object_count;
    int step_size;
    int max_step;
    Arena::ObjectType object_type;
    std::string line;
    getline(fin, line);
    int decision_counter = 0;
    while (getline(fin, line)) {
        decision_counter++;
        switch (decision_counter) {
            case 1: {
                std::vector<std::string> sizes = parse_input(line, " ");
                width = std::stoi(sizes[0]);
                height = std::stoi(sizes[1]);
                break;
            }
            case 2: {
                step_size = std::stoi(line);
                break;
            }
            case 3: {
                max_step = std::stoi(line);
                break;
            }
            case 4: {
                std::vector<std::string> attrs = parse_input(line, ",");
                for(int i = 0; i < attrs.size(); i++){
                    if(attrs[i].compare("end_after_collision") == 0 || attrs[i].compare("end_after_collision\r") == 0){
                        out_opt[0] = true;
                    }
                    else if(attrs[i].compare("report_distance") == 0 || attrs[i].compare("report_distance\r") == 0){
                        out_opt[1] = true;
                    }
                }
                break;
            }
            case 6: {
                if(line.compare("square\r") == 0){
                    object_type = Arena::ObjectType::square;
                }
                else if(line.compare("ball\r") == 0){
                    object_type = Arena::ObjectType::ball;
                }
                else if(line.compare("rectangle\r") == 0) {
                    object_type = Arena::ObjectType::rectangle;
                }
                break;
            }
            case 7: {
                object_count = std::stoi(line);
                break;
            }
            case 8: {

                for(int i = 0 ; i < object_count ; i++) {
                    std::vector<std::string> object = parse_input(line, " ");
                    if(object_type == Arena::ObjectType::square){
                        objects.push_back(std::make_shared<Square>(object[0], std::stoi(object[1]), std::stoi(object[2]),
                                                                   std::stoi(object[3]), std::stoi(object[4]),
                                                                   std::stoi(object[5]), std::stoi(object[6]),
                                                                   std::stoi(object[7])));
                    }
                    else if(object_type == Arena::ObjectType::ball){
                        objects.push_back(std::make_shared<Circle>(object[0], std::stoi(object[1]), std::stoi(object[2]),
                                                                   std::stoi(object[3]), std::stoi(object[4]),
                                                                   std::stoi(object[5]), std::stoi(object[6]),
                                                                   std::stoi(object[7])));
                    }
                    else if(object_type == Arena::ObjectType::rectangle){
                        objects.push_back(std::make_shared<Rectangle>(object[0], std::stoi(object[1]), std::stoi(object[2]),
                                                                   std::stoi(object[3]), std::stoi(object[4]),
                                                                   std::stoi(object[5]), std::stoi(object[6]),
                                                                   std::stoi(object[7]), std::stoi(object[8])));
                    }
                    else{
                        std::cout << "unknown shape type" << std::endl;
                        exit(0);
                    }
                    getline(fin, line);
                }

                break;
            }
        }

    }
    return std::make_shared<Arena>(objects, out_opt, width, height, object_count, step_size, max_step, object_type);
}


int main(int argc, char** argv){
    std::shared_ptr<std::string> data_file_name = std::make_shared<std::string>(argv[1]);
    std::shared_ptr<std::string> output_option = std::make_shared<std::string>(argv[2]);
    std::shared_ptr<Arena> arena = load_file(data_file_name, output_option);
    arena->run_simulation();
    return 0;
}
