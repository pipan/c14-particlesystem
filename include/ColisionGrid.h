/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColisionGrid.h
 * Author: arksys
 *
 * Created on October 17, 2016, 6:58 PM
 */

#ifndef COLISIONGRID_H
#define COLISIONGRID_H

#include <unordered_map>

#include "ColisionGridTile.h"
#include "ColisionGridObject.h"
#include "Renderable.h"

/**
 * prime number for hashing the X position in grid system
 */
const int PRIME_X = 611953;
/**
 * prime number for hashing the Y position in grid system
 */
const int PRIME_Y = 104729;
/**
 * size of hashe table
 */
const int HASH_N = 50000;
/**
 * size of 1 tile in pixels in grid
 */
const int TILE_SIZE = 10;

/**
 * Collision grid is a grid with size of one tile of TILE_SIZE. This grid stores information about rendered object and can return all objects that are in specific tile. We use this grid for mouse click events and deciding, which object has been clicked.
 */
class ColisionGrid {
    std::unordered_map<int, ColisionGridTile*> gridTable;
    std::unordered_map<int, ColisionGridObject*> objectTable;
    int hash(int x, int y);
    int hash(sf::Vector2i tile);
public:
    /**
     * Return all objects that are in tile with x and y indexes
     * 
     * @param int x
     * @param int y
     * @return std::map<int, CollisionGridObject*>
     */
    std::map<int, ColisionGridObject*>* getColision(int x, int y);
    /**
     * Object changed position so we have to check if the object also changed tiles that it is in
     * 
     * @param Renderable* object object that changed position
     */
    void updateObject(Renderable * object);
    /**
     * Object changed position so we have to check if the object also changed tiles that it is in
     * 
     * @param ColisionGridObject* object object that changed position
     */
    void updateObject(ColisionGridObject * object);
    /**
     * Check position of all objects that are registered in grid
     */
    void updateAll();
    /**
     * Remove object from grid system and do not check its position again
     * 
     * @param Renderable* object
     */
    void removeObject(Renderable* object);
    /**
     * Unregister object in grid with this size. It will still be checked and stay in grid, just values in grid will be updated. It means that this method will remove the information that this object is in grid with this size, but its highly probable that this object is going to be registered in grid with different position and size.
     * 
     * @param ColisionGridObject* object
     * @param sf::FloatRect tiles
     */
    void removeFromGrid(ColisionGridObject* object, sf::FloatRect tiles);
    /**
     * Add this object to grid with specified position and size. This object is already in grid system, but only grid values get updated. This method will say o grid system that this object wants to be registered in grid with this position and size.
     * 
     * @param ColisionGridObject* object
     * @param sf::FloatRect tiles
     */
    void addToGrid(ColisionGridObject* object, sf::FloatRect tiles);
    /**
     * Check if those two rectangles take same grid tile space.
     * 
     * @param sf::FloatRect rect1
     * @param sf::FloatRect rect2
     * @return bool
     */
    bool hasDifferentTiles(sf::FloatRect rect1, sf::FloatRect rect2);
    /**
     * check if this object changed its tile space in grid
     * 
     * @param ColisionGridObject* object
     * @return bool
     */
    bool hasChanged(ColisionGridObject* object);
    /**
     * get tile indexes based on window x and y coordinate
     * 
     * @param x window x coordinate
     * @param y window y coordinate
     * @return sf::Vector2f
     */
    sf::Vector2i getPreciseTile(int x, int y);
};

#endif /* COLISIONGRID_H */

