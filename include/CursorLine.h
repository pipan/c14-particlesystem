/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CursorLine.h
 * Author: arksys
 *
 * Created on October 15, 2016, 10:36 PM
 */

#ifndef CURSORLINE_H
#define CURSORLINE_H

#include "Renderable.h"
#include "TimeService.h"

/**
 * duration of time in miliseconds of how long will be cursor visible
 */
#define CURSOR_SHOW_DURATION 500
/**
 * duration of time in miliseconds of how long will be cursor hidden
 */
#define CURSOR_HIDE_DURATION 333

/**
 * Visual class that creates cursor for a input text. This class is not used by itself, it is always part of a bigger object. (for example text input element)
 */
class CursorLine : public Renderable{
    int cursotPosition;
    bool visible;
    sf::Int32 lastChange;
    TimeService* time;
    sf::RectangleShape line;
public:
    /**
     * Create line that is at a specific position in text.
     */
    CursorLine();

    /**
     * Set positin of a line inside a text. Position is specified by a character index of a text (0 means before first character).
     * 
     * @param int position
     */
    void setCursorPosition(int position);
    /**
     * Retrieve position of a line inside a text. Position is a character position and not a pixel position.
     * @return 
     */
    int getCursorPosition();

    /**
     * Increment position of a line in text;
     */
    void inc();
    /**
     * Increment position of a line in text, only if new position is not bigger then max.
     * 
     * @param int max
     */
    void inc(int max);
    /**
     * Decrement position of a line in text.
     */
    void dec();
    /**
     * Decrement position of a line in text, only if new position is not lower then min.
     * 
     * @param int min
     */
    void dec(int min);

    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    void update(sf::RenderWindow* window);
    /**
     * This method is called every time object is clicked, hovered or moved over object. You can specify what to do. Default behavior is to check if there is mouse listener registered and call it.
     * 
     * @param MouseEvent* event
     */
    void render(sf::RenderWindow* window);
};

#endif /* CURSORLINE_H */

