/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <map>

#include "../include/ColisionGridTile.h"

ColisionGridTile::ColisionGridTile(){
    this->objects = new std::map<int, ColisionGridObject*>();
}

void ColisionGridTile::add(int id, ColisionGridObject* object) {
    this->objects->insert({id, object});
}

std::map<int, ColisionGridObject*>* ColisionGridTile::getObjects() {
    return this->objects;
}

void ColisionGridTile::remove(int id) {
    this->objects->erase(id);
}