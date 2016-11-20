/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/System/Clock.hpp>

#include "../include/ColorTemplate.h"

ColorTemplate::ColorTemplate() : ColorTemplate(sf::Color(57, 71 ,152, 255), sf::Color(200, 210, 250, 255), sf::Color(255, 152, 0, 255)) {

}

ColorTemplate::ColorTemplate(sf::Color primary, sf::Color secondary, sf::Color accent) : ColorTemplate(primary, secondary, accent, sf::Color(244, 244, 244, 255), sf::Color(33, 33, 33, 255)) {

}

ColorTemplate::ColorTemplate(sf::Color primary, sf::Color secondary, sf::Color accent, sf::Color light, sf::Color dark) {
    this->primary = primary;
    this->secondary = secondary;
    this->accent = accent;
    this->light = light;
    this->dark = dark;
    this->warn = sf::Color();
    this->lightDisabled = sf::Color(this->light.r, this->light.g, this->light.b, 77);
    this->darkDisabled = sf::Color(this->dark.r, this->dark.g, this->dark.b, 77);
    this->lightLow = sf::Color(this->light.r, this->light.g, this->light.b, 200);
    this->darkLow = sf::Color(this->dark.r, this->dark.g, this->dark.b, 200);
}

sf::Color* ColorTemplate::getAccent() {
    return &(this->accent);
}

sf::Color* ColorTemplate::getPrimary() {
    return &(this->primary);
}

sf::Color* ColorTemplate::getSecondary() {
    return &(this->secondary);
}

sf::Color* ColorTemplate::getWarn() {
    return &(this->warn);
}

sf::Color* ColorTemplate::getForegroundDark(COLOR_MODE mode) {
    switch (mode){
        case NORMAL:
            return &(this->dark);
            break;
        case LOW:
            return &(this->darkLow);
            break;
        case DISABLED:
            return &(this->darkDisabled);
            break;
    }
    return &(this->dark);
}

sf::Color* ColorTemplate::getForegroundLight(COLOR_MODE mode) {
    switch (mode){
        case NORMAL:
            return &(this->light);
            break;
        case LOW:
            return &(this->lightLow);
            break;
        case DISABLED:
            return &(this->lightDisabled);
            break;
    }
    return &(this->light);
}

sf::Color* ColorTemplate::getBackgroundDark(COLOR_MODE mode) {
    return this->getForegroundDark(mode);
}

sf::Color* ColorTemplate::getBackgroundLight(COLOR_MODE mode) {
    return this->getForegroundLight(mode);
}