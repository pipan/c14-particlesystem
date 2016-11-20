/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/ShortcutService.h"

bool ShortcutService::existsCallback(std::string name) {
    std::unordered_map<std::string, ShortcutListener*>::iterator iterator = this->callbacks.find(name);
    std::unordered_map<std::string, ShortcutListener*>::iterator end = this->callbacks.end();
    return (iterator != end);
}

bool ShortcutService::existsMapping(std::string name) {
    std::unordered_map<std::string, std::string>::iterator iterator = this->mapping.find(name);
    std::unordered_map<std::string, std::string>::iterator end = this->mapping.end();
    return (iterator != end);
}

void ShortcutService::registerCallback(std::string uniqName, ShortcutListener* listener){
    if (!this->existsCallback(uniqName)){
        this->callbacks.insert({uniqName, listener});
    }
}

void ShortcutService::registerMapShortcut(std::string keyboardShortcut, std::string uniqName){
    if (!this->existsMapping(keyboardShortcut)){
        this->mapping.insert({keyboardShortcut, uniqName});
    }
}

void ShortcutService::unregisterMapShortcut(std::string keyboardShortcut) {
    this->mapping.erase(keyboardShortcut);
}

void ShortcutService::fire(KeyboardEvent* event) {
    this->combination.add(event->getEvent()->key.code);
    
    if (this->existsMapping(this->combination.toString())){
        std::string shortcutName = this->mapping.at(this->combination.toString());
        if (this->existsCallback(shortcutName)){
            ShortcutListener* callback = this->callbacks.at(shortcutName);
            event->setObject((Renderable*) callback->getObject());
            callback->onTrigger(event);
        }
    }
}
