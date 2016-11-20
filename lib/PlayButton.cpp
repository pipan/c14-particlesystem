/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/PlayButton.h"

PlayButton::PlayButton(sf::Vector2f size) : ImageButton("C:/peto/projekty/C/mmpafp/assets/images/play.png", size) {
    this->pause();
    
    this->changeListener = NULL;
    
    this->pauseTexture.loadFromFile("C:/peto/projekty/C/mmpafp/assets/images/pause.png");
    this->texture.setSmooth(false);
    this->texture.setRepeated(false);
    
    this->setShortcutListener("PlayPause", new PlayShortcutListener());
}

bool PlayButton::isPlaying() {
    return this->playValue;
}

void PlayButton::setPlay(bool play) {
    bool change = (this->playValue != play);
    
    this->playValue = play;
    if (change){    
        this->onChange();
    }
}

void PlayButton::play(){
    this->shape.setTexture(&(this->pauseTexture));
    this->setPlay(true);
}

void PlayButton::pause(){
    this->shape.setTexture(&(this->texture));
    this->setPlay(false);
}

void PlayButton::toggle() {
    if (this->isPlaying()){
        this->pause();
    }
    else{
        this->play();
    }
}

void PlayButton::setChangeListener(ChangeListener* listener) {
    if (this->hasChangeListener()){
        delete this->changeListener;
    }
    this->changeListener = listener;
}

bool PlayButton::hasChangeListener() {
    return (this->changeListener != NULL);
}

void PlayButton::onChange() {
    if (this->hasChangeListener()){
        Event* e = new Event();
        e->setObject(this);
        this->changeListener->onChange(e);
    }
}

void PlayShortcutListener::onTrigger(KeyboardEvent* event){
    PlayButton* button = (PlayButton*) event->getObject();
    
    button->toggle();
}

void PlayButton::onClick(MouseEvent* event) {
    
    this->toggle();
    
    ImageButton::onClick(event);
}
