#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

template<typename T>
class Node
{
    public:
        T object;
        Node* next;

        //-------Constructors & Destructors-------//
        Node();
        Node(T object);
        Node(const Node &obj);
        ~Node();

        //------Overloaded Operators-----------//
        bool operator==(const Node &right);
        bool operator>(const Node &right);
        bool operator<(const Node &right);
        Node& operator=(const Node &obj);
    
        void operator+=(Node &obj);

    private:
    protected:
};

//-------Constructors & Destructors-------//
template<typename T>
Node<T>::Node()
{
    object = T();
    next = nullptr;
}

template<typename T>
Node<T>::Node(T object)
{
    this->object = object;
    next = nullptr;
}

template<typename T>
Node<T>::Node(const Node &obj)
{
    this->object = obj.object;
    this->next = nullptr;
}
template<typename T>
Node<T>::~Node()
{
    //destructor
}

    

//-----Overloaded Operators-------//
template<typename T>
bool Node<T>::operator==(const Node &right)
{
    if(this->object == right.object) return true;
    return false;
}

template<typename T>
bool Node<T>::operator>(const Node &right)
{
    if(this->object > right.object) return true;
    return false;
}

template<typename T>
bool Node<T>::operator<(const Node &right)
{
    if(this->object < right.object) return true;
    return false;
}

template<typename T>
Node<T>& Node<T>::operator=(const Node &obj)
{
    this->object = obj.object;
    this->next = obj.next;
    return *this;
}

template<typename T>
void Node<T>::operator+=(Node &obj) //adds all object member variables to another
{
    this->object.setAt_Bats(
    this->object.getAt_Bats() + obj.object.getAt_Bats());
    
    this->object.setHits(
    this->object.getHits() + obj.object.getHits());
    
    this->object.setWalks(
    this->object.getWalks() + obj.object.getWalks());
    
    this->object.setStrikeouts(
    this->object.getStrikeouts() + obj.object.getStrikeouts());
    
    this->object.setOuts(
    this->object.getOuts() + obj.object.getOuts());
    
    this->object.setHits_By_Pitch(
    this->object.getHits_By_Pitch() + obj.object.getHits_By_Pitch());
    
    this->object.setSacrifices(
    this->object.getSacrifices() + obj.object.getSacrifices());
    
    this->object.setPlate_Appearances(
    this->object.getPlate_Appearances() + obj.object.getPlate_Appearances());
}

#endif //NODE_H
