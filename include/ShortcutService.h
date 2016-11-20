/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShortcutService.h
 * Author: arksys
 *
 * Created on October 18, 2016, 2:34 PM
 */

#ifndef SHORTCUTSERVICE_H
#define SHORTCUTSERVICE_H

#include <unordered_map>
#include <string>

#include "EventListener.h"
#include "Event.h"
#include "KeyboardComb.h"

/**
 * Service that handles registering shortcuts from objects in applications and assigning user defined keyboard shortcuts for those objects. It also handles recognition of those keyboard shortcuts.
 */
class ShortcutService {
    std::unordered_map<std::string, ShortcutListener*> callbacks;
    std::unordered_map<std::string, std::string> mapping;
    KeyboardListener* keyboardListener;
    KeyboardComb combination;
    
    /**
     * Check if there is any callback for application object with specific shortcut name.
     * 
     * @param std::string name
     * @return bool
     */
    bool existsCallback(std::string name);
    /**
     * Check it there is any user defined keyboard shortcut for specific object shortcut.
     * 
     * @param std::string name
     * @return bool
     */
    bool existsMapping(std::string name);
public:
    /**
     * Register application object shortcutlistener for some unique name.
     * 
     * @param std::string uniqName
     * @param ShortcutListener* listener
     */
    void registerCallback(std::string uniqName, ShortcutListener* listener);
    
    /**
     * Register user defined keyboard shortcut and assign it to some unique name that is bind to application object listener.
     * 
     * @param std::string keyboardShortcut
     * @param std::string uniqName
     */
    void registerMapShortcut(std::string keyboardShortcut, std::string uniqName);
    /**
     * Unregister user defined keyboard shortcut.
     * 
     * @param std::string keyboardShortcut
     */
    void unregisterMapShortcut(std::string keyboardShortcut);
    
    /**
     * We will fire this event each time keyboard is pressed and we don't have any objecct focused. Then, lets always add a new key to combination and check if previous are still pressed. then check the combination in our mapping
     * 
     * @param KeyboardEvent* event
     */
    void fire(KeyboardEvent *event);
};

/**
 * Concrete implementation of a keyboard listener that listen for keyboard shortcut events.
 */
class ShortcutKeyboardListener : public KeyboardListener{
public:
    /**
     * On key press we want to check shortcuts.
     * @param event
     */
    void onPress(KeyboardEvent* event);
};

#endif /* SHORTCUTSERVICE_H */

