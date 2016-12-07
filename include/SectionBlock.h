/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SectionBlock.h
 * Author: arksys
 *
 * Created on December 6, 2016, 10:47 PM
 */

#ifndef SECTIONBLOCK_H
#define SECTIONBLOCK_H

#include "Renderable.h"

class SectionBlock : public Renderable {
public:
    void update(sf::RenderWindow* window) override;
    /**
     * This method is called every time object is clicked, hovered or moved over object. You can specify what to do. Default behavior is to check if there is mouse listener registered and call it.
     * 
     * @param MouseEvent* event
     */
    void render(sf::RenderWindow* window) override;
};

#endif /* SECTIONBLOCK_H */

