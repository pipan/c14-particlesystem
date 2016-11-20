/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShortcutCombo.h
 * Author: arksys
 *
 * Created on October 19, 2016, 12:43 PM
 */

#ifndef SHORTCUTCOMBO_H
#define SHORTCUTCOMBO_H

#include <list>
#include <string>

#include <SFML/Window.hpp>

/**
 * Class that represents character keyboard combination. (for example CTRL+SPACE+V)
 */
class KeyboardComb{
    std::string stringValue;
    std::list<sf::Keyboard::Key> combination;
    
    void checkAllPressed();
    void buildString();
    char* keyToString(sf::Keyboard::Key key);
public:
    /**
     * Add key to combination.
     * 
     * @param sf::Keyboard::Key key
     */
    void add(sf::Keyboard::Key key);
    /**
     * Transform keys to string representation. for example "CTRL+SPACE+V".
     * 
     * @return std::string
     */
    std::string toString();
};

#endif /* SHORTCUTCOMBO_H */

