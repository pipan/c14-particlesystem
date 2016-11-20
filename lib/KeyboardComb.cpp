/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Window/Keyboard.hpp>

#include "../include/KeyboardComb.h"

void KeyboardComb::checkAllPressed(){
    std::list<sf::Keyboard::Key>::iterator iterator = this->combination.begin();
    std::list<sf::Keyboard::Key>::iterator end = this->combination.end();
    
    while (iterator != end){
        if (!sf::Keyboard::isKeyPressed(*iterator)){
            iterator = this->combination.erase(iterator);
            continue;
        }
        iterator++;
    }
}

void KeyboardComb::buildString() {
    
    std::list<sf::Keyboard::Key>::iterator iterator = this->combination.begin();
    std::list<sf::Keyboard::Key>::iterator end = this->combination.end();
    
    this->stringValue.clear();
    while (iterator != end){
        if (!this->stringValue.empty()){
            this->stringValue += "+";
        }
        this->stringValue += this->keyToString(*iterator);
        iterator++;
    }
}

char* KeyboardComb::keyToString(sf::Keyboard::Key key) {
    switch(key){
        case sf::Keyboard::Key::Space:
            return "SPACE";
        case sf::Keyboard::Key::LShift:
            return "LEFT_SHIFT";
        case sf::Keyboard::Key::LControl:
            return "LEFT_CTRL";
        case sf::Keyboard::Key::LAlt:
            return "LEFT_ALT";
        case sf::Keyboard::Key::A:
            return "A";
        case sf::Keyboard::Key::B:
            return "B";
        case sf::Keyboard::Key::C:
            return "C";
        case sf::Keyboard::Key::D:
            return "D";
        case sf::Keyboard::Key::E:
            return "E";
        case sf::Keyboard::Key::F:
            return "F";
        case sf::Keyboard::Key::G:
            return "G";
        case sf::Keyboard::Key::H:
            return "H";
        case sf::Keyboard::Key::I:
            return "I";
        case sf::Keyboard::Key::J:
            return "J";
        case sf::Keyboard::Key::K:
            return "K";
        case sf::Keyboard::Key::L:
            return "L";
        case sf::Keyboard::Key::M:
            return "M";
        case sf::Keyboard::Key::N:
            return "N";
        case sf::Keyboard::Key::O:
            return "O";
        case sf::Keyboard::Key::P:
            return "P";
        case sf::Keyboard::Key::Q:
            return "Q";
        case sf::Keyboard::Key::R:
            return "R";
        case sf::Keyboard::Key::S:
            return "S";
        case sf::Keyboard::Key::T:
            return "T";
        case sf::Keyboard::Key::U:
            return "U";
        case sf::Keyboard::Key::V:
            return "V";
        case sf::Keyboard::Key::W:
            return "W";
        case sf::Keyboard::Key::X:
            return "X";
        case sf::Keyboard::Key::Y:
            return "Y";
        case sf::Keyboard::Key::Z:
            return "Z";
        case sf::Keyboard::Key::Escape:
            return "ESCAPE";
        case sf::Keyboard::Key::Tab:
            return "TAB";
        case sf::Keyboard::Key::Delete:
            return "DELETE";
        default:
            return "";
    }
}

void KeyboardComb::add(sf::Keyboard::Key key) {
    this->combination.push_back(key);
    this->checkAllPressed();
    this->buildString();
}


std::string KeyboardComb::toString() {
    return this->stringValue;
}
