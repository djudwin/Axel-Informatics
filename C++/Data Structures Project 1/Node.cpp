//
//  Node.cpp
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#include "Node.h"

Node::Node(){
    
}

void Node::setName(char name){
    m_name = name;
}

char Node::getName() const{
    return m_name;
}

void Node::setWaitTime(int waitTime){
    m_waitTime = waitTime;
}

int Node::getWaitTime() const{
    return m_waitTime;
}

Node* Node::getLink() const{
    return link;
}

void Node::setLink(Node* newLink){
    link = newLink;
}
