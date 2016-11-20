/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: arksys
 *
 * Created on October 14, 2016, 11:43 PM
 */

#ifndef EVENT_H
#define EVENT_H

#include "Focusable.h"

class Particle;

/**
 * Event is anything that happens to a object. It might be user triggered or state triggered.
 */
class Event {
    Renderable* object;
    sf::Event* sfmlEvent;
    EVENT_TYPE type;
public:
    /**
     * Create and empty event.
     */
    Event();
    /**
     * Create and event out of user input.
     * 
     * @param sf::Event* sfmlEvent
     */
    Event(sf::Event* sfmlEvent);
    Event(sf::Event* sfmlEvent, Renderable* object);

    /**
     * get a object that this event is bind to.
     * 
     * @return Renderable*
     */
    Renderable* getObject();
    /**
     * Set a object that this event is going to be bound to.
     * 
     * @param Renderable* o
     */
    void setObject(Renderable* o);
    
    /**
     * Set sf event object.
     * 
     * @param sf::Event* event
     */
    virtual void setEvent(sf::Event* event);
    /**
     * Get the original user input event.
     * 
     * @return sf::Event*
     */
    sf::Event* getEvent();
    /**
     * Get the type of the event.
     * 
     * @return EVENT_TYPE
     */
    EVENT_TYPE getType();
    /**
     * Set the evnet type.
     * 
     * @param EVENT_TYPE type
     */
    void setType(EVENT_TYPE type);
};

/**
 * General mouse event. This event has mouse original input.
 */
class MouseEvent : public Event{
    bool buttonPressed;
    int x;
    int y;
    sf::Mouse::Button button;
    CURSOR_TYPE cursor;
    public:
        MouseEvent();
        MouseEvent(sf::Event* sfmlEvent);
        
        /**
        * Set sf event object.
        * 
        * @param sf::Event* event
        */
        void setEvent(sf::Event* event) override;
        bool isMove();
        bool isButton();
        bool isButton(sf::Mouse::Button button);
        /**
         * Retrieve which button has been pressed.
         * 
         * @return sf::Mouse::Button
         */
        sf::Mouse::Button getButton();
        /**
         * Check if button is pressed.
         * 
         * @return bool
         */
        bool isPressed();
        /**
         * Check if button is released.
         * 
         * @return bool
         */
        bool isReleased();
        /**
         * Return x position of the mouse.
         * 
         * @return int
         */
        int getX();
        /**
         * Return y position of the mouse.
         * 
         * @return int
         */
        int getY();
        
        void setCursorType(CURSOR_TYPE cursor);
        CURSOR_TYPE getCursorType();
};

/**
 * Event that is fired by focusable GUI element
 */
class FormEvent : public Event{
    Focusable* focusable;
public:
    FormEvent(Focusable* focusable);
    /**
     * Retrieve focusable element
     * 
     * @return Focusable* 
     */
    Focusable* getFocusable();
};

/**
 * Event that is fired by any GUI element that can be focues and can have input value.
 */
class InputEvent : public Event{
    Focusable* focusable;
public:
    InputEvent(Focusable* focusable);
    /**
     * Retrieve focusable element
     * 
     * @return Focusable* 
     */
    Focusable* getFocusable();
};

/**
 * Event that is fired by keyboard interaction
 */
class KeyboardEvent : public Event{
    bool pressed;
public:
    KeyboardEvent(sf::Event* sfmlEvent, EVENT_TYPE type);
    KeyboardEvent(sf::Event* sfmlEvent, bool pressed);
    KeyboardEvent(sf::Event* sfmlEvent, EVENT_TYPE type, bool pressed);
    /**
     * Get pressed character
     * 
     * @return char
     */
    char getChar();
    /**
     * Check if key was pressed or released. True is pressed, false is released.
     * 
     * @return bool
     */
    bool isPressed();
};

/**
 * Event that is fired by interaction with particle.
 */
class ParticleEvent : public Event{
    Particle* particle;
public:
    ParticleEvent(Particle* p);
    /**
     * Retrieve particle that fired event.
     * @return Particle*
     */
    Particle* getParticle();
};

#endif /* EVENT_H */

