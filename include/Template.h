/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Template.h
 * Author: arksys
 *
 * Created on October 16, 2016, 3:04 PM
 */

#ifndef TEMPLATE_H
#define TEMPLATE_H

#include "ColorTemplate.h"

/**
 * Static class that provides visual configuration of a application
 */
class Template {
    static ColorTemplate* active;
public:
    /**
     * method that retubts active color palette
     * 
     * @return ColorTemplate*
     */
    static ColorTemplate* getActive();
    /**
     * Setting active color template for application
     * 
     * @param colorTemplate* colorTemplate
     */
    static void activate(ColorTemplate* colorTemplate);
};

#endif /* TEMPLATE_H */

