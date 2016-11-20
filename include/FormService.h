/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FormService.h
 * Author: arksys
 *
 * Created on October 15, 2016, 5:37 PM
 */

#ifndef FORMSERVICE_H
#define FORMSERVICE_H

#include "Focusable.h"

/**
 * Object that stores information about currently focused object. It also handles focusing other objects and blurring current object. Every focus event should go trough this service.
 */
class FormService{
    Focusable* currentFocus;
    bool shouldBlur;
public:
    /**
     * Create service.
     */
    FormService();
    /**
     * Focus some object according to a received event.
     * 
     * @param Event* e
     */
    void focus(Event *e);
    /**
     * Blur some object according to a received event.
     * 
     * @param Event* e
     */
    void blur(Event *e);
    /**
     * check if there is something focuesd.
     * 
     * @return bool
     */
    bool hasCurrentFocus();
    /**
     * return currently focused object. This object has to be of type Focusable.
     * 
     * @return Focusable*
     */
    Focusable* getCurrentFocus();
};

#endif /* FORMSERVICE_H */

