/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LabelInput.h
 * Author: arksys
 *
 * Created on October 16, 2016, 2:36 PM
 */

#ifndef LABELINPUT_H
#define LABELINPUT_H

#include "Input.h"

class LabelInput : public Renderable {
protected:
    std::string label;
    sf::Text renderLabel;
    sf::Font font;
    sf::RectangleShape labelBg;
    Input* input;
public:
    /**
     * Create Label input with a label name and initial value.
     * 
     * @param std::string label
     * @param std::string value
     */
    LabelInput(std::string label, std::string value);
    /**
     * Create Label input with a label name, initila value and placeholder.
     * 
     * @param std::string label
     * @param std::string value
     * @param std::string placeholder
     */
    LabelInput(std::string label, std::string value, std::string placeholder);        
    /**
     * Destructor
     */
    virtual ~LabelInput();

    /**
     * Return input part of input label element. Input part is of a type Input  and you can call all methods from Input class.
     * @return 
     */
    Input* getInput();

    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    void update(sf::RenderWindow* window) override;
    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    void render(sf::RenderWindow* window) override;
};

#endif /* LABELINPUT_H */

