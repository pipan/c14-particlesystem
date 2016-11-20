/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/Template.h"

ColorTemplate* Template::active = NULL;

ColorTemplate* Template::getActive(){
    if (Template::active == NULL){
        throw "ERR: NO COLO TEMPLATE";
    }
    return Template::active;
}

void Template::activate(ColorTemplate* colorTemplate){
    Template::active = colorTemplate;
}