//
//  Linked_List.hpp
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#ifndef Linked_List_h
#define Linked_List_h

#include <stdio.h>
#include "Node.h"
#include <iostream>

using namespace std;

class Linked_List{
    
public:
    
    Linked_List();
    
    void insert(char name, int waitTime);
    
    bool remove(char target);
    
    void printList();
    
    bool isEmpty();
    
private:
    
    Node *FRONT;
    Node *REAR;
    Node *INSERT;
    Node *CURR;
    Node *PREV;
};



#endif /* Linked_List_h */
