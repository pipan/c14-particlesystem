/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Input.h
 * Author: arksys
 *
 * Created on October 15, 2016, 1:37 PM
 */

#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

#include "Renderable.h"
#include "EventListener.h"
#include "Event.h"
#include "CursorLine.h"
#include "SelectableText.h"
#include "Focusable.h"

/**
 * Visual GUI element that allows change value.
 */
class Input : public Focusable{
    FormListener* formListener;
    InputListener* inputListener;
protected:
    std::string value;
    std::string placeholder;
    SelectableText* selectableText;
    bool focusValue;
    sf::RectangleShape background;
    sf::Text renderText;
    sf::Font font;
public:
    /**
     * Create GUI input element with the initial value.
     * 
     * @param std::string value
     */
    Input(std::string value);
    /**
     * Create GUI input element with the initial value and a placeholde value that is shown if value is empty and input element is not focused.
     * 
     * @param std::string value
     * @param std::string placeholder
     */
    Input(std::string value, std::string placeholder);
    /**
     * Destructor
     */
    virtual ~Input();

    /**
     * Retrieve input value as a string.
     * 
     * @return std::string
     */
    std::string getString();
    /**
     * Retrieve input value as a float.
     * 
     * @return float
     */
    float getFloat();
    /**
     * Retrieve input value as a int.
     * 
     * @return int
     */
    int getInt();
    /**
     * Set input value from string.
     * 
     * @param std::string value
     */
    void setValue(std::string value);
    /**
     * Set input value from float
     * 
     * @param float value
     */
    void setValue(float value);
    /**
     * Set input value from a int.
     * 
     * @param int value
     */
    void setValue(int value);

    /**
     * Add character to a input. This character is going to be added at the position of a cursor.
     * @param c
     */
    void addChar(char c);
    /**
     * Remove char at a specified position. Returns if the character was really removed.
     * 
     * @param int position
     * @return bool
     */
    bool removeChar(int position);

    /**
     * Get value of a selected text in the input. Selected text is a text that has been marked.
     * 
     * @return SelectableText*
     */
    SelectableText* getSelectableText();

    /**
     * Retrieve font that is used for this input.
     * 
     * @return sf::Font
     */
    sf::Font getFont();

    /**
     * Return a cursor object that can tell you position of the cursor.
     * 
     * @return CursorLine*
     */
    CursorLine* getCursor();
    /**
     * Set cursor position.
     * 
     * @param int position
     */
    void setCursorPosition(int position);
    /**
     * Retrieve cursor position.
     * 
     * @return int
     */
    int getCursorPosition();

    /**
     * Set value for a placeholder.
     * 
     * @param std::string placeholder
     */
    void setPlaceholder(std::string placeholder);
    /**
     * Retrieve placeholder value.
     * 
     * @return std::string
     */
    std::string getPlaceholder();
    /**
     * check if placeholder value is set.
     * 
     * @return bool
     */
    bool hasPlaceholder();

    /**
     * Set focus value.
     * 
     * @param bool focus
     */
    void setFocus(bool focus);
    /**
     * Check if element is focused. Element is focused if this method returns true.
     * 
     * @return bool
     */
    bool hasFocus();

    /**
     * Keyboard combinations that applies for this object if it has focus.
     * 
     * @param KeyboardEvent* event
     */
    void innerShortcut(KeyboardEvent* event);

    /**
     * Retrieve form listener of this object.
     * 
     * @return FormListener*
     */
    FormListener* getFormListener() override;
    /**
     * Set a form listener for this object.
     * 
     * @param FormListener* listener
     */
    void setFormListener(FormListener* listener) override;
    /**
     * Check if this object has some form listener attached.
     * 
     * @return bool
     */
    bool hasFormListener() override;
    /**
     * Focus this element. This method triggers onFocus method of a focus listener if it has some listener registered.
     */
    void focus() override;
    /**
     * Blur this element. This method triggers onBlur method of a focus listener if it has some listener registered.
     */
    void blur() override;

    /**
     * Retrieve an input listener of this object.
     * 
     * @return InputListener*
     */
    InputListener* getInputListener() override;
    /**
     * Set an input listener for this object.
     * 
     * @param InputListener* listener
     */
    void setInputListener(InputListener* listener) override;
    /**
     * check if this object has some input listener attached.
     * 
     * @return bool
     */
    bool hasInputListener() override;
    /**
     * Change value of a object by user input. This method triggers onInput method of a input listener if it has some listener registered.
     */
    void input() override;

    /**
     * This method is called every time object is clicked, hovered or moved over object. You can specify what to do. Default behavior is to check if there is mouse listener registered and call it.
     * 
     * @param MouseEvent* event
     */
    //void mouse(MouseEvent* event) override;
    /**
     * This method is called every time keyboard is pressed and object is interested in keyboard events.
     * 
     * @param MouseEvent* event
     */
    void keyboard(Event* event) override;
    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    virtual void update(sf::RenderWindow* window) override;
    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    virtual void render(sf::RenderWindow* window) override;
    void onClick(MouseEvent* event) override;
};
#endif /* INPUT_H */

