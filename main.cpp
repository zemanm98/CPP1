//
// Created by zeman on 21.10.2021.
//
#include <iostream>

#include <string>
#include <fstream>
#include <vector>
#include <memory>

int main(int argc, char** argv){
    std::unique_ptr<std::string> data_file_name = std::make_unique<std::string>(argv[1]);
    std::unique_ptr<std::string> output_option = std::make_unique<std::string>(argv[2]);
    std::unique_ptr<std::fstream> fin;
    fin->open(data_file_name->data(), std::ios::in);
    if(!fin){
        std::cout << "File " << &data_file_name << " cannot be opened" << std::endl;
        exit(0);
    }

    std::cout << "jaj" << std::endl;
    return 0;
}
