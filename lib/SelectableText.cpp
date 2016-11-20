/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/SelectableText.h"

SelectableText::SelectableText(std::string* value) : Renderable(false) {
    this->value = value;
    this->cursor = new CursorLine();
    
    if (!this->font.loadFromFile("assets/fonts/arial.ttf")){
        std::cout << "LOAD FONT ERROR";
        //ERROR
    }
    
    this->cursor->setLayout(new Layout(0, 0, 2, 20));
    this->cursor->setParent(this);
    
    //this->selectionBg.setFillColor(sf::Color(255, 255, 180, 255));
    this->selectionBg.setFillColor(*Template::getActive()->getSecondary());
    
    this->renderLeft.setFont(this->font);
    this->renderLeft.setColor(*Template::getActive()->getForegroundDark());
    this->renderLeft.setCharacterSize(16);
    
    this->renderSelection.setFont(this->font);
    //this->renderSelection.setColor(sf::Color(255, 152, 0, 255));
    this->renderSelection.setColor(*Template::getActive()->getForegroundDark());
    this->renderSelection.setCharacterSize(16);
    
    this->renderRight.setFont(this->font);
    this->renderRight.setColor(*Template::getActive()->getForegroundDark());
    this->renderRight.setCharacterSize(16);
}

SelectableText::~SelectableText(){
    delete this->cursor;
}

CursorLine* SelectableText::getCursor() {
    return this->cursor;
}

void SelectableText::setSelection(sf::Vector2i selection) {
    this->selection = selection;
}

void SelectableText::setSelection(int left, int right) {
    this->setSelectionLeft(left);
    this->setSelectionRight(right);
}

void SelectableText::setSelectionLeft(int left) {
    if (left < 0){
        left = 0;
    }
    this->selection.x = left;
}

void SelectableText::setSelectionRight(int right) {
    if (right > this->value->size()){
        right = this->value->size();
    }
    this->selection.y = right;
}

void SelectableText::setValue(std::string* value) {
    this->value = value;
}

int SelectableText::getSelectionLeft() {
    return this->selection.x;
}

int SelectableText::getSelectionRight() {
    return this->selection.y;
}

void SelectableText::moveSelectionLeft() {
    if (!this->hasSelection()){
        this->setSelection(this->getCursor()->getCursorPosition(), this->getCursor()->getCursorPosition());
    }
    if (this->cursor->getCursorPosition() == this->getSelectionLeft()){
        this->decLeft();
    }
    else{
        this->decRight();
    }
    this->cursor->dec(0);
}

void SelectableText::moveSelectionRight() {
    if (!this->hasSelection()){
        this->setSelection(this->getCursor()->getCursorPosition(), this->getCursor()->getCursorPosition());
    }
    if (this->cursor->getCursorPosition() == this->getSelectionRight()){
        this->incRight();
    }
    else{
        this->incLeft();
    }
    this->cursor->inc(this->value->size());
}

void SelectableText::moveSelection(int position) {
    if (!this->hasSelection()){
        this->setSelection(this->getCursor()->getCursorPosition(), this->getCursor()->getCursorPosition());
    }
    
    if (position < this->getSelectionLeft()){
        if (this->cursor->getCursorPosition() > this->getSelectionLeft()){
            this->setSelectionRight(this->getSelectionLeft());
        }
        this->setSelectionLeft(position);
    }
    else {
        if (this->cursor->getCursorPosition() < this->getSelectionRight()){
            this->setSelectionLeft(this->getSelectionRight());
        }
        this->setSelectionRight(position);
    }
    
    this->cursor->setCursorPosition(position);
}

void SelectableText::incLeft() {
    if (this->getSelectionLeft() < this->getSelectionRight()){
        this->setSelectionLeft(this->selection.x + 1);
    }
}

void SelectableText::decLeft() {
    if (this->getSelectionLeft() > 0){
        this->setSelectionLeft(this->selection.x - 1);
    }
}

void SelectableText::incRight() {
    if (this->getSelectionRight() < this->value->size()){
        this->setSelectionRight(this->selection.y + 1);
    }
}

void SelectableText::decRight() {
    if (this->getSelectionLeft() < this->getSelectionRight()){
        this->setSelectionRight(this->selection.y - 1);
    }
}

bool SelectableText::hasSelection() {
    return (this->getSelectionLeft() < this->getSelectionRight());
}

int SelectableText::getSelectionSize() {
    return (this->getSelectionRight() - this->getSelectionLeft());
}

void SelectableText::clearSelection() {
    this->setSelectionLeft(this->cursor->getCursorPosition());
    this->setSelectionRight(this->cursor->getCursorPosition());
}

void SelectableText::erase(int position) {
    if (this->hasSelection()){
        this->value->erase(this->getSelectionLeft(), this->getSelectionSize());
        this->cursor->setCursorPosition(this->getSelectionLeft());
        this->clearSelection();
    }
    else{
        this->value->erase(position, 1);
        if (position  < this->cursor->getCursorPosition()){
            this->cursor->dec(0);
        }
    }
}

void SelectableText::update(sf::RenderWindow* window) {  
    
    Layout *myLayout = this->getLayout();
    sf::FloatRect pBounds = this->getParent()->getBounds();
    myLayout->setPosition(pBounds.left + 6, pBounds.top + 6);
    myLayout->setSize(pBounds.width - 12, pBounds.height - 12);
    
    sf::FloatRect myBounds = myLayout->getBounds();
    
    this->cursor->update(window);
}

void SelectableText::render(sf::RenderWindow* window) {
    
    sf::FloatRect myBounds = this->getLayout()->getBounds();
    
    this->renderLeft.setPosition(myBounds.left, myBounds.top);
    
    if (this->hasSelection()){
        
        this->renderLeft.setString(this->value->substr(0, this->selection.x));
        
        this->renderSelection.setString(this->value->substr(this->selection.x, this->selection.y - this->selection.x));
        this->renderSelection.setPosition(myBounds.left + this->renderLeft.getLocalBounds().width, myBounds.top);
        
        this->renderRight.setString(this->value->substr(this->selection.y));
        this->renderRight.setPosition(myBounds.left + this->renderLeft.getLocalBounds().width + this->renderSelection.getLocalBounds().width, myBounds.top);
        
        this->selectionBg.setPosition(myBounds.left + this->renderLeft.getLocalBounds().width, myBounds.top);
        this->selectionBg.setSize(sf::Vector2f(this->renderSelection.getLocalBounds().width, this->cursor->getLayout()->getSize().y));        
        
        if (this->cursor->getCursorPosition() == this->selection.x){
            this->cursor->getLayout()->setPosition(myBounds.left + this->renderLeft.getLocalBounds().width, myBounds.top);
        }
        else{
            this->cursor->getLayout()->setPosition(myBounds.left + this->renderLeft.getLocalBounds().width + this->renderSelection.getLocalBounds().width, myBounds.top);
        }
        
        window->draw(this->selectionBg);
        window->draw(this->renderSelection);
        window->draw(this->renderLeft);
        window->draw(this->renderRight);
        
//        this->selectionBg.setPosition();
//        this->selectionBg.setSize();
    }
    else{
        this->renderLeft.setString(this->value->substr(0, this->cursor->getCursorPosition()));
        this->renderRight.setString(this->value->substr(this->cursor->getCursorPosition()));
        this->renderRight.setPosition(myBounds.left + this->renderLeft.getLocalBounds().width, myBounds.top);
        
        this->cursor->getLayout()->setPosition(myBounds.left + this->renderLeft.getLocalBounds().width, myBounds.top);
        
        window->draw(this->renderLeft);
        window->draw(this->renderRight);
    }
    
    this->cursor->render(window);
}