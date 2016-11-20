/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnviromentForm.h
 * Author: arksys
 *
 * Created on October 25, 2016, 11:14 AM
 */

#ifndef ENVIROMENTFORM_H
#define ENVIROMENTFORM_H

#include <iostream>

#include "Radio.h"
#include "LabelInput.h"
#include "Enviroment.h"

/**
 * This is basically a controller for a big form element. This is handling value in environment class.
 */
class EnviromentForm : public Radio{
    LabelInput* gravityX;
    LabelInput* gravityY;
    LabelInput* damping;
    LabelInput* iterations;
    LabelInput* groundPosition;
    
    Enviroment* env;
public:
    /**
     * Create environment form.
     * 
     * @param bool visible
     */
    EnviromentForm(bool selected);
    /**
     * Create environment form with a environment object bind to it.
     * 
     * @param Enviroment* env
     * @param bool visible
     */
    EnviromentForm(Enviroment* env, bool visible);
    /**
     * Destructor
     */
    ~EnviromentForm();
    
    /**
     * Set environment object for this form.
     * 
     * @param Enviroment* env
     */
    void setEnviroment(Enviroment* env);
    /**
     * Retrieve environment object that is bound to this form.
     * 
     * @return Enviroment*
     */
    Enviroment* getEnviroment();
    /**
     * Check if this form has some environment variable bind.
     * 
     * @return bool
     */
    bool hasEnviroment();
    
    void setSelected(bool selected) override;

    void update(sf::RenderWindow* window) override;
    /**
     * This method is called every time object is clicked, hovered or moved over object. You can specify what to do. Default behavior is to check if there is mouse listener registered and call it.
     * 
     * @param MouseEvent* event
     */
    void render(sf::RenderWindow* window) override;
};

/**
 * Input listener that can handle input box for a gravity property in environment form.
 */
class GravityInputListener : public InputListener{
    EnviromentForm* form;
    VECTOR_INDEX index;
public:
    GravityInputListener(EnviromentForm* form, VECTOR_INDEX index);
    void onInput(InputEvent* event) override;
};

/**
 * Input listener that can handle input box for a damping property in environment form.
 */
class DampingInputListener : public InputListener{
    EnviromentForm* form;
public:
    DampingInputListener(EnviromentForm* form);
    void onInput(InputEvent* event) override;
};

/**
 * Input listener that can handle input box for a number of iteration of a constraint projection property in environment form.
 */
class IterationsInputListener : public InputListener{
    EnviromentForm* form;
public:
    IterationsInputListener(EnviromentForm* form);
    void onInput(InputEvent* event) override;
};

/**
 * Input listener that can handle input box for a pround position y property in environment form.
 */
class GroundPositionInputListener : public InputListener{
    EnviromentForm* form;
public:
    GroundPositionInputListener(EnviromentForm* form);
    void onInput(InputEvent* event) override;
};
#endif /* ENVIROMENTFORM_H */

