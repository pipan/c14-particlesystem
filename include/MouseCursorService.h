/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MouseCursonService.h
 * Author: arksys
 *
 * Created on November 5, 2016, 8:56 PM
 */

#ifndef MOUSECURSONSERVICE_H
#define MOUSECURSONSERVICE_H

#include "EventHandler.h"
#include "Provider.h"
#include "MouseService.h"
#include "FormService.h"
#include "ShortcutService.h"
#include "ColisionGrid.h"
#include "Particle.h"

class MouseCursorService : public EventHandler {
    CURSOR_TYPE cursor;
    
    Renderable* pressedObject;
    bool pressedObjectMoved;
    
    void eventAll(MouseEvent* mouseEvent);
public:
    MouseCursorService(CURSOR_TYPE cursor);
    virtual ~MouseCursorService();

    CURSOR_TYPE getCursorType();
    void setCursorType(CURSOR_TYPE type);
    
    /**
     * Method that decides which listener should receive fired event.
     * 
     * @param Event* e
     */
    virtual void fire(Event* event) override;
};

#endif /* MOUSECURSONSERVICE_H */

