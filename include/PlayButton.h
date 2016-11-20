/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayButton.h
 * Author: arksys
 *
 * Created on October 18, 2016, 12:47 PM
 */

#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include "ImageButton.h"

//const char* PLAY_IMAGE_PATH = "C:/peto/projekty/C/mmpafp/assets/images/play.png";
//const char* PAUSE_IMAGE_PATH = "C:/peto/projekty/C/mmpafp/assets/images/pause.png";

/**
 * Image button that is used specialy for play and pouse purpose. It has a global shortcut assign to it (SPACE)
 */
class PlayButton : public ImageButton{
    bool playValue;
    sf::Texture pauseTexture;
    ChangeListener* changeListener;
public:
    PlayButton(sf::Vector2f size);
    /**
     * Check if button is in play state.
     * 
     * @return bool
     */
    bool isPlaying();
    /**
     * Set button play status.
     * 
     * @param bool play
     */
    void setPlay(bool play);
    /**
     * Set button play status to true.
     */
    void play();
    /**
     * Set button play status to false.
     */
    void pause();
    /**
     * Set button play status to the oposit of current status.
     */
    void toggle();

    /**
     * Set change listener.
     * 
     * @param ChangeListener* listener
     */
    void setChangeListener(ChangeListener* listener);
    /**
     * Check if button has change listener set.
     * 
     * @return bool
     */
    bool hasChangeListener();
    /**
     * method that call onChange method of change listener if there is any set.
     */
    void onChange();

    /**
     * This method is called every time object is clicked, hovered or moved over object. You can specify what to do. Default behavior is to check if there is mouse listener registered and call it.
     * 
     * @param MouseEvent* event
     */
    void onClick(MouseEvent* event) override;
};

/**
 * Keyboard shortcut listener that is called when user pres specific key combination for play button (SPACE).
 */
class PlayShortcutListener : public ShortcutListener{
public:
    /**
     * Method that is called when user press SPACE.
     * 
     * @param KeyboardEvent* event
     */
    void onTrigger(KeyboardEvent* event);
};

#endif /* PLAYBUTTON_H */

