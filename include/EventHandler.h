/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EventHandler.h
 * Author: arksys
 *
 * Created on October 14, 2016, 11:42 PM
 */

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <map>
#include <list>

#include "EventListener.h"
#include "Event.h"
#include "Particle.h"

/**
 * Interface for every EventHandler. Event handler is a class that takes care of fired events and decides which listener should receive this event.
 */
class IEventHandler{
public:
    /**
     * method that decides which listener should receive fired event.
     * 
     * @param Event* e
     */
    virtual void fire(Event* e) = 0;
    /**
     * register listener.
     * 
     * @param Renderable* listener
     */
    virtual void addListener(Renderable* listener) = 0;
    /**
     * Unregister listener
     * 
     * @param Renderable* listener
     */
    virtual void removeListener(Renderable* listener) = 0;
};

/**
 * Default event handler that implements addListener and Remove listener. Listeners are stored in list, so if you need better solution, you shoul override addListener and remveListener.
 */
class EventHandler : public IEventHandler{
protected:
    std::list<Renderable*> listeners;
public:
    /**
     * method that decides which listener should receive fired event.
     * 
     * @param Event* e
     */
    virtual void fire(Event* event) = 0;
    /**
     * register listener to linked list.
     * 
     * @param Renderable* listener
     */
    virtual void addListener(Renderable* listener);
    /**
     * Unregister listener from linked list.
     * 
     * @param Renderable* listener
     */
    virtual void removeListener(Renderable* listener);
    /**
     * return all listeners as a linked list structure.
     * 
     * @return std::list<Renderable*>*
     */
    virtual std::list<Renderable*>* getListeners();
};

/**
 * Keyboard implementation of a event handler. This handler checks for a focused element or shortcuts and activates appropriate listener and method.
 */
class KeyboardEventHandler : public EventHandler{
public:
    /**
     * method that decides which listener should receive fired event.
     * 
     * @param Event* e
     */
    virtual void fire(Event* event);
};

#endif /* EVENTHANDLER_H */

