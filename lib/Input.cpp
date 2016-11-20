/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <sstream>
#include <SFML/Graphics/Text.hpp>
#include <iostream>

#include "../include/Input.h"
#include "../include/Provider.h"
#include "../include/FormService.h"


Input::Input(std::string value) : Input(value, ""){
    
}

Input::Input(std::string value, std::string placeholder) : Focusable(){
    this->inputListener = NULL;
    this->formListener = NULL;
    
    this->setValue(value);
    this->setPlaceholder(placeholder);
    this->setFocus(false);
    
    this->selectableText = new SelectableText(&(this->value));
    this->selectableText->setParent(this);
    
    this->background.setFillColor(sf::Color(244, 244, 244, 255));
    this->background.setOutlineThickness(1.0f);
    
    
    if (!this->font.loadFromFile("assets/fonts/arial.ttf")){
        std::cout << "LOAD FONT ERROR";
        //ERROR
    }
    this->renderText.setFont(this->font);
    this->renderText.setCharacterSize(16);
    
    this->addRenderable(this->selectableText);
}

Input::~Input(){
    delete this->selectableText;
}

std::string Input::getString() {
    return this->value;
}

float Input::getFloat() {
    return std::atof(this->value.c_str());
}

int Input::getInt() {
    return std::atoi(this->value.c_str());
}

void Input::setValue(std::string value) {
    this->value = value;
}

void Input::setValue(float value){
    std::ostringstream stream;
    stream << value;
   
    this->setValue(stream.str());
}

void Input::setValue(int value){
    std::ostringstream stream;
    stream << value;
   
    this->setValue(stream.str());
}

void Input::addChar(char c) {
    if (this->selectableText->hasSelection()){
        this->getSelectableText()->erase(0);
    }
    this->value.insert(this->getCursor()->getCursorPosition(), 1, c);
    this->getCursor()->inc();
    
    this->input();
}

bool Input::removeChar(int position) {
    bool ret = false;
    if (this->selectableText->hasSelection()){
        this->getSelectableText()->erase(position);
        ret = true;
    }
    else if (position >= 0 && position < this->value.size()){
        this->getSelectableText()->erase(position);
        ret = true;
    }
    
    this->input();
    
    return ret;
}

sf::Font Input::getFont() {
    return this->font;
}

SelectableText* Input::getSelectableText() {
    return this->selectableText;
}

CursorLine* Input::getCursor() {
    return this->selectableText->getCursor();
}

void Input::setCursorPosition(int position) {
    this->getCursor()->setCursorPosition(position);
}

int Input::getCursorPosition() {
    return this->getCursor()->getCursorPosition();
}

void Input::setPlaceholder(std::string placeholder) {
    this->placeholder = placeholder;
}

std::string Input::getPlaceholder() {
    return this->placeholder;
}

bool Input::hasPlaceholder() {
    return (this->placeholder.size() > 0);
}

bool Input::hasFocus(){
    return this->focusValue;
}

void Input::setFocus(bool focus){
    this->focusValue = focus;
}

void Input::focus() {
    this->setFocus(true);
    
    this->background.setOutlineColor(sf::Color(255, 152, 0, 255));
    
    this->getCursor()->setCursorPosition(this->getString().size());
    
    if (this->hasFormListener()){
        this->getFormListener()->onFocus(new FormEvent(this));
    }
}

void Input::blur() {
    this->setFocus(false);
    
    this->background.setOutlineColor(sf::Color(244, 244, 244, 255));
    
    if (this->hasFormListener()){
        this->getFormListener()->onBlur(new FormEvent(this));
    }
}

void Input::input() {

    if (this->hasInputListener()){
        this->inputListener->onInput(new InputEvent(this));
    }
}

void Input::keyboard(Event* event) {

    if (this->hasFocus()){
        if (event->getType() == TEXT){
            KeyboardEvent* keyboardEvent = (KeyboardEvent*) event;
            this->addChar(keyboardEvent->getChar());
        }
        else if (event->getType() == KEYBOARD && this->hasFocus()){
            this->innerShortcut((KeyboardEvent*) event);
        }
    }
    
    Renderable::keyboard(event);
}

void Input::innerShortcut(KeyboardEvent* event) {
    //RIGHT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            this->getSelectableText()->moveSelectionRight();
        }
        else{
            this->getSelectableText()->clearSelection();
            this->getCursor()->inc(this->getString().size());
        }
    }
    //LEFT
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            this->getSelectableText()->moveSelectionLeft();
        }
        else{
            this->getSelectableText()->clearSelection();
            this->getCursor()->dec(0);
        }
    }
    //BACKSPACE
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
        this->removeChar(this->getCursor()->getCursorPosition() - 1);
    }
    //DELETE
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)){
        this->removeChar(this->getCursor()->getCursorPosition());
    }
    //HOME
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Home)){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            this->getSelectableText()->moveSelection(0);
        }
        else{
            this->getSelectableText()->clearSelection();
            this->getCursor()->setCursorPosition(0);
        }
    }
    //END
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            this->getSelectableText()->moveSelection(this->getString().size());
        }
        else{
            this->getSelectableText()->clearSelection();
            this->getCursor()->setCursorPosition(this->getString().size());
        }
    }
    //ESCAPE
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        if (this->hasFocus()){
            FormService* formService = (FormService*) Provider::getInstance()->get("formService");
            formService->blur(event);
        }
    }
}

FormListener* Input::getFormListener() {
    return this->formListener;
}

void Input::setFormListener(FormListener* listener) {
    this->formListener = listener;
}

bool Input::hasFormListener() {
    return (this->formListener != NULL);
}

InputListener* Input::getInputListener() {
    return this->inputListener;
}

void Input::setInputListener(InputListener* listener) {
    this->inputListener = listener;
}

bool Input::hasInputListener() {
    return (this->inputListener != NULL);
}

void Input::update(sf::RenderWindow* window) {
    this->getLayout()->resize(this->getParent()->getLayout());
    
    this->renderText.setPosition(this->getLayout()->getBounds().left + 6, this->getLayout()->getBounds().top + 6);
    
    this->background.setPosition(this->getLayout()->getBounds().left, this->getLayout()->getBounds().top);
    this->background.setSize(sf::Vector2f(this->getLayout()->getBounds().width, this->getLayout()->getBounds().height));
    
    this->selectableText->update(window);
}

void Input::render(sf::RenderWindow* window) {
    
    window->draw(this->background);
    
    if (this->getString().empty() && !this->hasFocus()){
        this->renderText.setString(this->getPlaceholder());
        this->renderText.setColor(*Template::getActive()->getForegroundDark(DISABLED));
        window->draw(this->renderText);
    }
    else{
        if (this->hasFocus()){
            this->selectableText->render(window);
        }
        else{
            this->renderText.setString(this->value);
            this->renderText.setColor(*Template::getActive()->getForegroundDark(LOW));
            window->draw(this->renderText);
        }
    }
}

void Input::onClick(MouseEvent* event) {
    FormService* formService = (FormService*) Provider::getInstance()->get("formService");
    
    event->setObject(this);
    formService->focus(event);
    
    Renderable::onClick(event);
}
