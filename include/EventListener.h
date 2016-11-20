/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EventListener.h
 * Author: arksys
 *
 * Created on October 15, 2016, 12:19 AM
 */

#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "System/Enum.h"


class Event;
class MouseEvent;
class KeyboardEvent;
class ParticleEvent;
class InputEvent;

/**
 * Default event listener. This listener have core and basic functionality so advanced listeners should extend this class. Advanced listeners should provide abstract method that will be implemented in concreate implmenetation of advanced listener.
 */
class EventListener{
    EVENT_TYPE type;
    void* object;
public:
    /**
     * Retrieve listeners type.
     * 
     * @return EVENT_TYPE
     */
    EVENT_TYPE getType();
    /**
     * Set listener type.
     * 
     * @param EVENT_TYPE type
     */
    void setType(EVENT_TYPE type);
    /**
     * Set object that this listener is bound to.
     * 
     * @param void* object
     */
    void setObject(void* object);
    /**
     * Retrieve object that this listener is bound to.
     * 
     * @return void*
     */
    void* getObject();
};

/**
 * Advanced listener. This listener is waiting for a mouse event and provides onClick method that you have to implement in your Mouse listener implementation.
 */
class MouseListener : public EventListener{
public:
    MouseListener();
    /**
     * This method is trigered when user click on a object.
     * 
     * @param MouseEvent* event
     */
    virtual void onClick(MouseEvent* event) = 0;
    virtual void onDrag(MouseEvent* event) = 0;
    virtual void onDrop(MouseEvent* event) = 0;
    virtual void onMove(MouseEvent* event) = 0;
};

/**
 * Advanced listener. This listener is waiting for a form event adn provides onFocus and onBlur method that you have to implement in your form listener implementation.
 */
class FormListener : public EventListener{
public:
    FormListener();
    /**
     * Method is triggered when object gains focus.
     * 
     * @param Event* event
     */
    virtual void onFocus(Event* event) = 0;
    /**
     * Method is triggered when object looses focus.
     * 
     * @param Event* event
     */
    virtual void onBlur(Event* event) = 0;
};

/**
 * Advanced listener. This listener is waiting for a form event and provides onFocus and onBlur method that you have to implement in your form listener implementation.
 */
class InputListener : public EventListener{
public:
    InputListener();
    /**
     * Method is triggered when GUI element changes it's value.
     * @param event
     */
    virtual void onInput(InputEvent* event) = 0;
};

/**
 * Advanced listener. This listener is waiting for a keyboard event and provides onPress and onReleas method that you have to implement in your keyboard listener implementation.
 */
class KeyboardListener : public EventListener{
public:
    KeyboardListener();
    /**
     * Method is triggered when user press a key on keyboard.
     * 
     * @param KeyboardEvent* event
     */
    virtual void onPress(KeyboardEvent* event) = 0;
    /**
     * Method is triggered when user releases a key on keyboard.
     * 
     * @param KeyboardEvent* event
     */
    virtual void onReleas(KeyboardEvent* event) = 0;
};

/**
 * Advanced listener. This listener is waiting for a change event and provides onChange method that you have to implement in your change listener implementation.
 */
class ChangeListener : public EventListener {
public:
    ChangeListener();
    /**
     * Method is triggered when a value is changed in object.
     * @param event
     */
    virtual void onChange(Event* event) = 0;
};

/**
 * Advanced listener. This listener is waiting for a shortcut event and provides onTrigger method that you have to implement in your shortcut listener implementation.
 */
class ShortcutListener : public EventListener{
public:
    ShortcutListener();
    /**
     * Method is triggered when a user press specific keyboard combination.
     * 
     * @param KeyboardEvent* event
     */
    virtual void onTrigger(KeyboardEvent* event) = 0;
};

/**
 * Advanced listener. This listener is waiting for a particle event and provides onSelect and onDeselect method that you have to implement in your particle listener implementation.
 */
class ParticleListener : public EventListener{
public:
    ParticleListener();
    /**
     * Method is triggered when a particle is selected.
     * 
     * @param ParticleEvent* event
     */
    virtual void onSelect(ParticleEvent* event) = 0;
    /**
     * Method is triggered when a particle is deselected.
     * 
     * @param ParticleEvent* event
     */
    virtual void onDeselect(ParticleEvent* event) = 0;
};
#endif /* EVENTLISTENER_H */

