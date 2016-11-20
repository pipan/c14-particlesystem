/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColisionGridTile.h
 * Author: arksys
 *
 * Created on October 17, 2016, 7:08 PM
 */

#ifndef COLISIONGRIDTILE_H
#define COLISIONGRIDTILE_H

#include <map>

#include "ColisionGridObject.h"

/**
 * One tile of a grid. This class handles information about all object that actualy take space in this tile.
 */
class ColisionGridTile {
    std::map<int, ColisionGridObject*>* objects;
public:
    /**
     * Create grid tile
     */
    ColisionGridTile();
    /**
     * Remove Object with id from this grid
     * 
     * @param int id
     */
    void remove(int id);
    /**
     * Add object to this tile
     * 
     * @param int id
     * @param ColisionGridObject* object
     */
    void add(int id, ColisionGridObject* object);
    /**
     * Retrieve all objects that are in this tile
     * 
     * @return std::map<int, ColisionGridObject*>
     */
    std::map<int, ColisionGridObject*>* getObjects();
};

#endif /* COLISIONGRIDTILE_H */

