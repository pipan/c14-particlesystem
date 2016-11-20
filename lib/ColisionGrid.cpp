/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/ColisionGrid.h"

ColisionGrid::hash(int x, int y){
    return (((x * PRIME_X) ^ (y * PRIME_Y)) % HASH_N);
}

int ColisionGrid::hash(sf::Vector2i tile) {
    return this->hash(tile.x, tile.y);
}


std::map<int, ColisionGridObject*>* ColisionGrid::getColision(int x, int y) {
    sf::Vector2i tile = this->getPreciseTile(x, y);
    std::unordered_map<int, ColisionGridTile*>::iterator iterator = this->gridTable.find(this->hash(tile));
    if (iterator != this->gridTable.end()){
        return iterator->second->getObjects();
    }
    else{
        return NULL;
    }
}

void ColisionGrid::updateObject(Renderable* object) {
    ColisionGridObject*  gridObject;
    std::unordered_map<int, ColisionGridObject*>::iterator iterator = this->objectTable.find(object->getId());
    if (iterator == this->objectTable.end()){
        gridObject = new ColisionGridObject(object);
        this->objectTable.insert({object->getId(), gridObject});
    }
    else{
        gridObject = iterator->second;
    }
    
    this->updateObject(gridObject);
}

void ColisionGrid::updateObject(ColisionGridObject* gridObject) {
    if (this->hasChanged(gridObject)){
        this->removeFromGrid(gridObject, gridObject->getPreviousRect());
        this->addToGrid(gridObject, gridObject->getCurrentRect());
        gridObject->swap();
    }
}

void ColisionGrid::updateAll() {
    std::unordered_map<int, ColisionGridObject*>::iterator iterator = this->objectTable.begin();
    std::unordered_map<int, ColisionGridObject*>::iterator end = this->objectTable.end();
    while (iterator != end){
        this->updateObject(iterator->second);
        iterator++;
    }
}

void ColisionGrid::removeObject(Renderable* object) {
    std::unordered_map<int, ColisionGridObject*>::iterator iterator = this->objectTable.find(object->getId());
    if (iterator != this->objectTable.end()){
        this->removeFromGrid(iterator->second, iterator->second->getPreviousRect());
        this->objectTable.erase(object->getId());
        delete iterator->second;
    }
}

void ColisionGrid::removeFromGrid(ColisionGridObject* object, sf::FloatRect tiles) {
    sf::Vector2i from = this->getPreciseTile(tiles.left, tiles.top);
    sf::Vector2i to = this->getPreciseTile(tiles.left + tiles.width, tiles.top + tiles.height);
    int i;
    int j;
    for (i = from.x; i <= to.x; i++){
        for (j = from.y; j <= to.y; j++){
            std::unordered_map<int, ColisionGridTile*>::iterator iterator = this->gridTable.find(this->hash(i,j));
            if (iterator != this->gridTable.end()){
                iterator->second->remove(object->getId());
            }
        }
    }
}

void ColisionGrid::addToGrid(ColisionGridObject* object, sf::FloatRect tiles) {
    ColisionGridTile* tile;
    sf::Vector2i from = this->getPreciseTile(tiles.left, tiles.top);
    sf::Vector2i to = this->getPreciseTile(tiles.left + tiles.width, tiles.top + tiles.height);
    int i;
    int j;
    for (i = from.x; i <= to.x; i++){
        for (j = from.y; j <= to.y; j++){
            std::unordered_map<int, ColisionGridTile*>::iterator iterator = this->gridTable.find(this->hash(i,j));
            if (iterator == this->gridTable.end()){
                tile = new ColisionGridTile();
                this->gridTable.insert({this->hash(i,j), tile});
            }
            else{
                tile = iterator->second;
            }
            tile->add(object->getId(), object);
        }
    }
}


sf::Vector2i ColisionGrid::getPreciseTile(int x, int y) {
    return sf::Vector2i((int) x / TILE_SIZE, (int) y / TILE_SIZE);
}


bool ColisionGrid::hasDifferentTiles(sf::FloatRect rect1, sf::FloatRect rect2) {
    sf::Vector2i tile1 = this->getPreciseTile(rect1.left, rect1.top);
    sf::Vector2i tile2 = this->getPreciseTile(rect2.left, rect2.top);
    if (tile1.x != tile2.x || tile1.y != tile2.y){
        return true;
    }
    tile1 = this->getPreciseTile(rect1.left + rect1.width, rect1.top +  rect1.height);
    tile2 = this->getPreciseTile(rect2.left + rect2.width, rect2.top + rect2.height);
    if (tile1.x != tile2.x || tile1.y != tile2.y){
        return true;
    }
    
    return false;
}


bool ColisionGrid::hasChanged(ColisionGridObject* object) {
    return this->hasDifferentTiles(object->getPreviousRect(), object->getCurrentRect());
}



