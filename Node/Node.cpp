#include "Node.h"
#include "../Player/Player.h"

#include <iostream>

using namespace std;

//-------Constructors & Destructors-------//
Node::Node()
{
    object = nullptr;
    next = nullptr;
}

Node::Node(Player *object)
{
    this->object = object;
    next = nullptr;
}

Node::Node(const Node &obj)
{
    this->object = obj.object;
    this->next = obj.next;
}
Node::~Node()
{
    //destructor
}
    

//-----Overloaded Operators-------//
void Node::operator+=(Node &obj)
{
    this->object->setAt_Bats(
    this->object->getAt_Bats() + obj.object->getAt_Bats());
    
    this->object->setHits(
    this->object->getHits() + obj.object->getHits());
    
    this->object->setWalks(
    this->object->getWalks() + obj.object->getWalks());
    
    this->object->setStrikeouts(
    this->object->getStrikeouts() + obj.object->getStrikeouts());
    
    this->object->setOuts(
    this->object->getOuts() + obj.object->getOuts());
    
    this->object->setHits_By_Pitch(
    this->object->getHits_By_Pitch() + obj.object->getHits_By_Pitch());
    
    this->object->setSacrifices(
    this->object->getSacrifices() + obj.object->getSacrifices());
    
    this->object->setPlate_Appearances(
    this->object->getPlate_Appearances() + obj.object->getPlate_Appearances());
}
