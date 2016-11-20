/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColorConfig.h
 * Author: arksys
 *
 * Created on October 16, 2016, 2:51 PM
 */

#ifndef COLORCONFIG_H
#define COLORCONFIG_H

#include <SFML/Graphics.hpp>

#include "System/Enum.h"

/**
 * Class that allows you to create your own color template and use thit color scheme in application.
 */
class ColorTemplate{
    sf::Color primary;
    sf::Color secondary;
    sf::Color accent;
    sf::Color light;
    sf::Color dark;
    sf::Color warn;
    sf::Color lightDisabled;
    sf::Color darkDisabled;
    sf::Color lightLow;
    sf::Color darkLow;
public:
    /**
     * Default constructor will set default color values for this template
     */
    ColorTemplate();
    
    /**
     * This constructor allows you to set three main color for this application. Other colors will be default
     * 
     * @param primary primary color
     * @param secondary secondary color (usually lighter or darker version of primary color)
     * @param accent usually oposite color to primary
     */
    ColorTemplate(sf::Color primary, sf::Color secondary, sf::Color accent);
    
    /**
     * This constructor allows you to set all avalible colors
     * 
     * @param primary primary color
     * @param secondary secondary color (usually lighter or darker version of primary color)
     * @param accent usually oposite color to primary
     * @param light usually some kind of white
     * @param dark usually some kind of black
     */
    ColorTemplate(sf::Color primary, sf::Color secondary, sf::Color accent, sf::Color light, sf::Color dark);
    /**
     * Retrieve primary color
     * 
     * @return sf::Color*
     */
    sf::Color* getPrimary();
    /**
     * Retrieve secondary color
     * 
     * @return sf::Color*
     */
    sf::Color* getSecondary();
    /**
     * Retrieve accent color
     * 
     * @return sf::Color*
     */
    sf::Color* getAccent();
    /**
     * Retrieve some kind of light text color. This color can be modified byt COLOR_MODE argument, which changes opacity of the color.
     * 
     * @param COLOR_MODE=NORMAL
     * @return sf::Color*
     */
    sf::Color* getWarn();
    /**
     * Retrieve some kind of light text color. This color can be modified byt COLOR_MODE argument, which changes opacity of the color.
     * 
     * @param COLOR_MODE=NORMAL
     * @return sf::Color*
     */
    sf::Color* getForegroundLight(COLOR_MODE = NORMAL);
    /**
     * Retrieve some kind of dark text color. This color can be modified byt COLOR_MODE argument, which changes opacity of the color.
     * 
     * @param COLOR_MODE=NORMAL
     * @return sf::Color*
     */
    sf::Color* getForegroundDark(COLOR_MODE = NORMAL);
    /**
     * Retrieve some kind of light background color. This color can be modified byt COLOR_MODE argument, which changes opacity of the color.
     * 
     * @param COLOR_MODE=NORMAL
     * @return sf::Color*
     */
    sf::Color* getBackgroundLight(COLOR_MODE = NORMAL);
    /**
     * Retrieve some kind of dark background color. This color can be modified byt COLOR_MODE argument, which changes opacity of the color.
     * 
     * @param COLOR_MODE=NORMAL
     * @return sf::Color*
     */
    sf::Color* getBackgroundDark(COLOR_MODE = NORMAL);
};

#endif /* COLORCONFIG_H */

