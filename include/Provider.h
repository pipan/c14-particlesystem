/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Provider.h
 * Author: arksys
 *
 * Created on October 14, 2016, 11:33 PM
 */

#ifndef PROVIDER_H
#define PROVIDER_H

#include <map>
#include <string>

/**
 * static class that allows you to register services with name and retreive those cervices.
 */
class Provider{
    static Provider* instance;
    std::map<std::string, void*> map;
public:
    /**
     * method that will return registered service. You have to correctly retype returned value.
     * 
     * @throws out of scope exception
     * @param std::string key
     * @return void*
     */
    void* get(std::string key);
    
    /**
     * Method that allows you to register new service with a key name.
     * 
     * @param std::string key
     * @param void* obj
     */
    void add(std::string key, void*  obj);
    
    /**
     * singleton method
     *
     * @return Provider*
     */
    static Provider* getInstance();
};

#endif /* PROVIDER_H */

