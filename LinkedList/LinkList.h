#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"

#include <string>

//TODO: Sort method

using namespace std;

//template <typename Type>
class LinkList
{
    public:
        Node* head; //are the the brackets needed?
        Node* tail;

        //--------Constructors & Destructors--------//
        LinkList();
        LinkList(Node*);
        ~LinkList();

        
        void Sort();
        void addNode(Node *node);
        Node* exists(Node *node);
        void ToString();
        void getSize();

        //-----Overloaded Operator---------//
        Node operator[](int index);
        friend ostream& operator<<(ostream& out, const LinkList &obj)
        {
            Node* curr = obj.head;
            while(curr != nullptr)
            {
                out << *(curr->object) << endl;
                curr = curr->next;
            }
            return out;
        }
        friend istream& operator>>(istream&, LinkList &obj);

    // private:
    // protected:
};

#endif //LINKLIST_H
