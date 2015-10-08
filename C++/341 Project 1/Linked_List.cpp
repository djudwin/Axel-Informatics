//
//  Linked_List.cpp
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#include "Linked_List.h"


Linked_List::Linked_List(){
    
    FRONT = NULL;
    REAR = NULL;
    INSERT = NULL;
    CURR = NULL;
    PREV = NULL;
    
}

void Linked_List::insert(char name, int waitTime){
    
    INSERT = new Node();
    
    INSERT->setName(name);
    INSERT->setWaitTime(waitTime);
    
    if (Linked_List::isEmpty()){
        FRONT = INSERT;
        REAR = INSERT;
    }
    else{
        REAR->link = INSERT;
        REAR = INSERT;
    }
    
    INSERT = NULL;
}

bool Linked_List::isEmpty(){
    if (FRONT == NULL && REAR == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool Linked_List::remove(char target){
    CURR = PREV = NULL;
    
    for (CURR = FRONT; CURR != NULL; CURR -> getLink()){
        if (CURR->m_name == target){
            if (CURR == FRONT && CURR == REAR){
                FRONT = FRONT -> link;
                REAR = REAR->getLink();
            }
            else if (CURR == FRONT){
                FRONT = FRONT->getLink();
            }
            else if(CURR == REAR){
                PREV->link = NULL;
                REAR = PREV;
            }
            else{
                PREV->link = CURR->getLink();
            }
            delete CURR;
            return true;
        }
        else{
            PREV = CURR;
        }
    }
    return false;
}

void Linked_List::printList(){
    
    
    
}