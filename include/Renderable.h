/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   renderable.h
 * Author: arksys
 *
 * Created on October 14, 2016, 12:08 AM
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <list>
    
#include <SFML/Graphics/RenderWindow.hpp>

#include "Layout.h"
#include "EventListener.h"

const char LMN_KEY_ENTER = 13;
const char LMN_KEY_ESC = 27;
const char LMN_KEY_SPACE = 32;
const char LMN_KEY_BACKSPACE = 8;
const char LMN_KEY_DELETE = 127;
const char LMN_KEY_LEFT = 100;
const char LMN_KEY_RIGHT = 102;

class Event;
class MouseEvent;
class KeyboardEvent;

/**
 * Interface that every object that wants to be drawn to the screen have to implement. Probably the most important interface of the entire GUI.
 */
class Renderable : public MouseListener {
    static int currentId;
    int id;
    Layout* layout;
    std::list<Renderable*>* renderItems;
    Renderable* parent;
    MouseListener *mouseListener;
    KeyboardListener* keyboardListener;
    bool visible;
public:
    /**
     * Constructor
     */
    Renderable();
    Renderable(bool registerToGrid);
    /**
     * Destructor
     */
    virtual ~Renderable();
    
    /**
     * Generate next number for a object. Each object has to have a unique number.
     * 
     * @return int
     */
    static int getNextId();
    
    /**
     * Get unique number of this object.
     * 
     * @return int
     */
    int getId();
    
    bool isVisible();
    void setVisibility(bool visible);
    void show();
    void hide();
    
    /**
     * Retrieve level number. This number represents hov deep in tree structure is this object.
     * 
     * @return int
     */
    virtual int getLevel();
    
    /**
     * Set layout for this object.
     * 
     * @param Layout* layout
     */
    void setLayout(Layout* layout);
    /**
     * Get layout for this object.
     * 
     * @return Layout*
     */
    Layout* getLayout();
    /**
     * Retrieve size and position of this object.
     * 
     * @return sf::FloatRect
     */
    virtual sf::FloatRect getBounds();
    
    virtual bool collision(float x, float y);
    
    /**
     * Add new renderable child.
     * 
     * @param Renderable* r
     */
    void addRenderable(Renderable* r);
    /**
     * Remove renderable child.
     * 
     * @param Renderable* r
     */
    void removeRenderable(Renderable* r);
    /**
     * Retrieve all renderable children.
     * 
     * @return std::list<Renderable*>*
     */
    std::list<Renderable*>* getRenderableItems();

    /**
     * Set parent object. You should not call this function it is automatically called when you add new Renderable to child.
     * 
     * @param Renderable* parent
     */
    void setParent(Renderable* parent);
    /**
     * Get parent object.
     * 
     * @return Renderable*
     */
    Renderable* getParent();
    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    virtual void update(sf::RenderWindow* window) = 0;
    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    virtual void render(sf::RenderWindow* window) = 0;
    
    /**
     * This method is called every time object is clicked, hovered or moved over object. You can specify what to do. Default behavior is to check if there is mouse listener registered and call it.
     * 
     * @param MouseEvent* event
     */
    //virtual void mouse(MouseEvent* event);
    /**
     * This method is called every time keyboard is pressed and object is interested in keyboard events.
     * 
     * @param MouseEvent* event
     */
    virtual void keyboard(Event* event);
    
    /**
     * Get mouse listener for this object.
     * 
     * @return MouseListener*
     */
    MouseListener* getMouseListener();
    /**
     * Set mouse listener for this object.
     * 
     * @param MouseListener* listener
     */
    void setMouseListener(MouseListener* listener);
    /**
     * Check if there is mouse listener set for this object
     * 
     * @return bool
     */
    bool hasMouseListener();
    
    /**
     * Get keyboard listener for this object.
     * 
     * @return KeyboardListener*
     */
    KeyboardListener* getKeyboardListener();
    /**
     * Set keyboard listener for this object.
     * 
     * @param keyboardListener* listener
     */
    void setKeyboardListener(KeyboardListener* listener);
    /**
     * Chceck if this object has keyboard listener set.
     * 
     * @return bool
     */
    bool hasKeyboardListener();
    
    /**
     * Set shortcut listener that this object is providing.
     * 
     * @param std::string uniqName name of shortcut
     * @param ShortcutListener* listener
     */
    void setShortcutListener(std::string uniqName, ShortcutListener* listener);
    
    virtual void onClick(MouseEvent* event) override;
    virtual void onDrag(MouseEvent* event) override;
    virtual void onDrop(MouseEvent* event) override;
    virtual void onMove(MouseEvent* event) override;
};

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#endif /* RENDERABLE_H */

