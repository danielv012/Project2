#include "LinkList.h"

#include <iostream>

using namespace std;

//------Constructors-------//
LinkList::LinkList()
{
    head = nullptr;
    tail = nullptr;
}

LinkList::LinkList(Node* head)
{
    this->head = head;
    this->tail = head;
    Node* curr = head->next;
    while(curr != nullptr)
    {
        this->tail = curr;
        curr = curr->next;
    }
}

//--------Destructors---------//
LinkList::~LinkList()
{
    Node* prev = head, *curr = head;

    while(curr != nullptr)
    {
        curr = curr->next;
        delete prev;
        prev = curr;
    }
}

//--------Miscellaneous=--------//
Node* LinkList::exists(Node *node)
{
    Node* curr = this->head;
    while(curr != nullptr)
    {
        if(curr->object->getName() == node->object->getName())
        {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

void LinkList::addNode(Node *node)
{
    Node* existingNode = exists(node);
    
    if(head == nullptr)
    {
        head = node;
        tail = node;
    }
    else if(existingNode)
    {
        *existingNode += *node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

//--------Overloaded Operators-----------//

