/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MouseCursorController.h
 * Author: arksys
 *
 * Created on November 5, 2016, 8:54 PM
 */

#ifndef MOUSECURSORCONTROLLER_H
#define MOUSECURSORCONTROLLER_H

#include "EventHandler.h"

/**
 * Mouse event handler implementation. This handler looks for a clicked object in grid and activate appropriate listener.
 */
class PointerCursorController : public EventHandler{
    Renderable* pressedObject;
    bool pressedObjectMoved;
    
    void eventAll(MouseEvent* mouseEvent);
public:
    PointerCursorController();
    /**
     * Method that decides which listener should receive fired event.
     * 
     * @param Event* e
     */
    virtual void fire(Event* event) override;
};

class RemoveCursorController : public EventHandler{
    
public:
    RemoveCursorController();
    /**
     * Method that decides which listener should receive fired event.
     * 
     * @param Event* e
     */
    virtual void fire(Event* event) override;
};

class AddCursorController : public EventHandler{
    
public:
    AddCursorController();
    /**
     * Method that decides which listener should receive fired event.
     * 
     * @param Event* e
     */
    virtual void fire(Event* event) override;
};

#endif /* MOUSECURSORCONTROLLER_H */

