#ifndef NODE_H
#define NODE_H

#include <string>
#include "Player.h"

using namespace std;

//template<typename Type>
class Node
{
    public:
        Player* object;
        Node* next;

        //-------Constructors & Destructors-------//
        Node();
        Node(Player *object);
        Node(const Node &obj);
        ~Node();

        //------Overloaded Operators-----------//
        bool operator==(const Node &right);
        bool operator>(const Node &right);
        bool operator<<(const Node &right);
        Node& operator=(const Node &obj);
    
        void operator+=(Node &obj);

    private:
    protected:
};
#endif //NODE_H
