/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SelectableText.h
 * Author: arksys
 *
 * Created on October 16, 2016, 11:29 AM
 */

#ifndef SELECTABLETEXT_H
#define SELECTABLETEXT_H

#include <string>

#include "Renderable.h"
#include "CursorLine.h"

/**
 * Part of a text that is selected by user.
 */
class SelectableText : public Renderable{
    CursorLine* cursor;
    std::string* value;
    sf::Vector2i selection;
    sf::Text renderLeft;
    sf::Text renderSelection;
    sf::Text renderRight;
    sf::Font font;
    sf::RectangleShape selectionBg;
public:
    /**
     * Create new selection text with this text value. The string value is not a selected text but it can be selected.
     * 
     * @param std::string* value
     */
    SelectableText(std::string* value);
    /**
     * Destructor
     */
    virtual ~SelectableText();

    /**
     * Retrieve Cursor object.
     * 
     * @return CoursoreLine*
     */
    CursorLine* getCursor();

    /**
     * Set text selection. X value of a selection is beginning and y value is a position of the end of a selection.
     * 
     * @param sf::Vector2f selection
     */
    void setSelection(sf::Vector2i selection);
    /**
     * Set text selection. left value of a selection is beginning and right value is a position of the end of a selection.
     * 
     * @param int left
     * @param int right
     */
    void setSelection(int left, int right);
    /**
     * Set text selection, only beginning of a selection.
     * 
     * @param int left
     */
    void setSelectionLeft(int left);
    /**
     * Set text selection, only end of a selection.
     * 
     * @param int right
     */
    void setSelectionRight(int right);

    /**
     * Retrieve the end position of a selection.
     * 
     * @return int
     */
    int getSelectionRight();
    /**
     * Retrieve beggining part of a selection.
     * 
     * @return int
     */
    int getSelectionLeft();

    /**
     * Change selection one position to the left. It means if the cursor is at the end of the selection then the selection is going to be shorten by one at the end, if the cursor position is on the beginning of the selection, then the selection is going to be enlarged by one at the beginning of the selection.
     */
    void moveSelectionLeft();
    /**
     * Change selection one position to the right. It means if the cursor is at the end of the selection then the selection is going to be enlarge by one at the end, if the cursor position is on the beginning of the selection, then the selection is going to be shorten by one at the beginning of the selection.
     */
    void moveSelectionRight();
    /**
     * Change selection to the specific position. New selection is dependent of the new position and cursor position.
     */
    void moveSelection(int position);

    /**
     * Increment beginning position by one. It means shorten selection by one from beginning.
     */
    void incLeft();
    /**
     * Decrement beginning position by one. It means expand selection by one from beginning.
     */
    void decLeft();
    /**
     * Increment end position by one. It means expand selection by one from end.
     */
    void incRight();
    /**
     * Decrement end position by one. It means shorten selection by one from end.
     */
    void decRight();

    /**
     * Set the value of text.
     * 
     * @param std::string* value
     */
    void setValue(std::string* value);

    /**
     * Check if there is any selection. There is any selection only if the beginning and end position of the selection are different.
     * 
     * @return bool.
     */
    bool hasSelection();
    /**
     * Get the size of the selection. If the size is 0, then there is no selection.
     * 
     * @return int
     */
    int getSelectionSize();

    /**
     * Set selection size to 0, or set beggining of the selection and end of the selection to the same value. In normal cae, this method will set beginning and the end of the selection to the current cursor position.
     */
    void clearSelection();

    /**
     * Erase selection if there is any, or erase one character at specific position.
     * 
     * @param position
     */
    void erase(int position);

    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    void update(sf::RenderWindow* window);
    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    void render(sf::RenderWindow* window);
};

#endif /* SELECTABLETEXT_H */

