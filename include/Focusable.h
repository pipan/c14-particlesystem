/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Focusable.h
 * Author: arksys
 *
 * Created on October 23, 2016, 11:29 PM
 */

#ifndef FOCUSABLE_H
#define FOCUSABLE_H

#include "Renderable.h"

/**
 * Basically a renderable object that also has focus element attached to it. This object can be focused and blurred by user input.
 */
class Focusable : public Renderable{
public:
    Focusable();
    /**
     * Focus this element. This method triggers onFocus method of a focus listener if it has some listener registered.
     */
    virtual void focus() = 0;
    /**
     * Blur this element. This method triggers onBlur method of a focus listener if it has some listener registered.
     */
    virtual void blur() = 0;
    /**
     * Change value of a object by user input. This method triggers onInput method of a input listener if it has some listener registered.
     */
    virtual void input() = 0;
    
    /**
     * Set a form listener for this object.
     * 
     * @param FormListener* listener
     */
    virtual void setFormListener(FormListener* listener) = 0;
    /**
     * Retrieve form listener of this object.
     * 
     * @return FormListener*
     */
    virtual FormListener* getFormListener() = 0;
    /**
     * Check if this object has some form listener attached.
     * 
     * @return bool
     */
    virtual bool hasFormListener() = 0;
    
    /**
     * Set an input listener for this object.
     * 
     * @param InputListener* listener
     */
    virtual void setInputListener(InputListener* listener) = 0;
    /**
     * Retrieve an input listener of this object.
     * 
     * @return InputListener*
     */
    virtual InputListener* getInputListener() = 0;
    /**
     * check if this object has some input listener attached.
     * 
     * @return bool
     */
    virtual bool hasInputListener() = 0;
};

#endif /* FOCUSABLE_H */

