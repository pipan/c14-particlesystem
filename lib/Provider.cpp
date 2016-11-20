/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/Provider.h"

Provider* Provider::instance = NULL;

void Provider::add(std::string key, void* obj) {
    this->map.insert(std::make_pair(key, obj));
}

void* Provider::get(std::string key) {
    //std::cout << "provider get: " << key << "\n";
    return this->map.at(key);
}

Provider* Provider::getInstance() {
    if (Provider::instance == NULL){
        Provider::instance = new Provider();
    }
    return Provider::instance;
}


