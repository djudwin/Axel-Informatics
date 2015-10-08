//
//  Node.h
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <iostream>
using namespace std;

class Node{
    
public:
    
    Node();
    
    void setName(char name);
    
    char getName() const;
    
    void setWaitTime(int waitTime);
    
    int getWaitTime() const;
    
    Node* getLink() const;
    
    void setLink(Node* newLink);
   
    char m_name;
    int m_waitTime;
    Node *link;
    
};

#endif /* Node_h */
