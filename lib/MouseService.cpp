/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/MouseService.h"

bool MouseService::isCollision(Renderable* object, int x, int y){
    sf::FloatRect rec = object->getBounds();
    
    return (rec.left <= x && rec.left + rec.width >= x && rec.top <= y && rec.top + rec.height >= y);
    
    //return rec.contains(x, y);
}