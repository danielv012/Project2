#ifndef LINKLIST_H
#define LINKLIST_H

#include <string>

using namespace std;

template <typename T>
class LinkList
{
    public:
        T* head; //are the the brackets needed?
        T* tail;
    
        T* sorted;

        //--------Constructors & Destructors--------//
        LinkList();
        LinkList(T*);
        ~LinkList();
        
        void insertionSort(T *node);
        void insertionSortBA(T *node);
        void insertionSortOB(T *node);
        void insertionSortHits(T *node);
        void insertionSortWalks(T *node);
        void insertionSortStrikeouts(T *node);
        void insertionSortHitsByPitch(T *node);
        
    
        void addNode(T *node);
        T* exists(T *node);
        void ToString(T *node);
        void purge(T *node);
    
        int getSize();
        
        //-----Overloaded Operator---------//
        T* operator[](int index);
    
        friend ostream& operator<<(ostream& out, const LinkList &obj)
        {
            T* curr = obj.head;
            while(curr != nullptr)
            {
                out << curr->object;
                curr = curr->next;
            }
            return out;
        }

    private:
        int getSize(T* head);
        void sortedInsert(T* newnode);
        void sortedInsertBA(T* newnode);
        void sortedInsertOB(T* newnode);
        void sortedInsertHits(T* newnode);
        void sortedInsertWalks(T* newnode);
        void sortedInsertStrikeouts(T* newnode);
        void sortedInsertHitsByPitch(T* newnode);
    // protected:
};

//------Constructors-------//
template <typename T>
LinkList<T>::LinkList()
{
    head = nullptr;
    tail = nullptr;
    sorted = nullptr;
}

template <typename T>
LinkList<T>::LinkList(T* head)
{
    this->head = head;
    this->tail = head;
    T* curr = head->next;
    while(curr != nullptr)
    {
        this->tail = curr;
        curr = curr->next;
    }
}

//--------Destructors---------//
template <typename T>
LinkList<T>::~LinkList()
{
    T* prev = head, *curr = head;

    while(curr != nullptr && prev != nullptr)
    {
        curr = curr->next;
        delete prev;
        prev = curr;
    }
}

template <typename T>
void LinkList<T>::purge(T *node)
{
    T* prev = node->next, *curr = node->next;

    while(curr != nullptr)
    {
        curr = curr->next;
        delete prev;
        prev = curr;
    }
    
    node->next = nullptr;
    tail = node;
    
    //MAKE SURE TO SET POINTER TO ARGUMENT NODE TO NULLPTR
}

//--------Miscellaneous=--------//

template <typename T>
void LinkList<T>::ToString(T *node)
{
    if(node == nullptr) return;
    T* curr = node;
    
    cout << curr->object.getName() << ((curr->next) ? ", " : "");
    curr = curr->next;
    ToString(curr);
}

//--------Sorting Methods--------?//

//-------------Insertion Sorts-----------------//

template <typename T>
void LinkList<T>::addNode(T *node)
{
    T* existingNode = exists(node);
    
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

template <typename T>
T* LinkList<T>::exists(T *node)
{
    T* curr = this->head;
    while(curr != nullptr) //traverses the list and returns true if a node equals the argument node
    {
        if(curr->object.getName() == node->object.getName())
        {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

//------Get Size--------//
template <typename T>
int LinkList<T>::getSize()
{
    int size = 0;
    T* curr = this->head;
    while(curr != nullptr) //traverses the list and returns size
    {
        curr = curr->next;
        size++;
    }
    return size;
}

template <typename T>
int LinkList<T>::getSize(T* head)
{
    int size = 0;
    T* curr = head;
    while(curr != nullptr)
    {
        curr = curr->next;
        size++;
    }
    return size;
}

//--------Overloaded Operators-----------//
template <typename T>
T* LinkList<T>::operator[](int index)
{
    int count = 0;
    T* curr = this->head;
    if(index == 0) return curr;
    while(curr != nullptr)
    {
        curr = curr->next;
        count++;
        if(count == index) return curr;
    }
    throw invalid_argument("Index out of bounds");
    return nullptr;
}






//--------------Stat-specific Insertion Sorts---------//

//BA
/*
 ALL COMMENTS IN THIS SECTION ARE THE SAME FOR THE FOLLOWING INSERTION SORT BLOCKS: OB, Hits, Walks, Strikeouts, Hits_By_Pitch, Alphabetically
 */
template <typename T>
void LinkList<T>::insertionSortBA(T *node)
{
    T* current(node); //create a current node from the argument
    while(current != NULL) //while it's an object
    {
        T* next(current->next); //create a pointer to the next object
        sortedInsertBA(current); //insertion sort from the previous object onward
        current = next; //set the pointer to the next object
    }
    
    head = sorted; //original head pointer points to the sorted order
}

template <typename T>
void LinkList<T>::sortedInsertBA(T* newnode)
{
    if(sorted == NULL || sorted->object.getBA() <= newnode->object.getBA()) //if there is nothing sorted, or the argument object is to be sorted first
    {
        newnode->next = sorted; //move the sorted list after the argument object
        sorted = newnode; //first sorted object becomes the newnode
    }
    else
    {
        T* curr = sorted; //current points to the sorted list
        while(curr->next != nullptr && curr->next->object.getBA() > newnode->object.getBA()) //while the next points to an object, and next objects value is less than the current objects value, keep looking for the place to insert the argument object
        {
            curr = curr->next; //move forward
        }
        
        newnode->next = curr->next; //insert the argument object
        curr->next = newnode;
    }
}

//OB//
template <typename T>
void LinkList<T>::insertionSortOB(T *node)
{
    T* current(node);
    while(current != NULL)
    {
        T* next(current->next);
        sortedInsertOB(current);
        current = next;
    }
    
    head = sorted;
}

template <typename T>
void LinkList<T>::sortedInsertOB(T* newnode)
{
    if(sorted == NULL || sorted->object.getOB() <= newnode->object.getOB())
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        T* curr = sorted;
        while(curr->next != nullptr && curr->next->object.getOB() > newnode->object.getOB())
        {
            curr = curr->next;
        }
        
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

//Hits//
template <typename T>
void LinkList<T>::insertionSortHits(T *node)
{
    T* current(node);
    while(current != NULL)
    {
        T* next(current->next);
        sortedInsertHits(current);
        current = next;
    }
    
    head = sorted;
}

template <typename T>
void LinkList<T>::sortedInsertHits(T* newnode)
{
    if(sorted == NULL || sorted->object.getHits() <= newnode->object.getHits())
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        T* curr = sorted;
        while(curr->next != nullptr && curr->next->object.getHits() > newnode->object.getHits())
        {
            curr = curr->next;
        }
        
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

//Walks//
template <typename T>
void LinkList<T>::insertionSortWalks(T *node)
{
    T* current(node);
    while(current != NULL)
    {
        T* next(current->next);
        sortedInsertWalks(current);
        current = next;
    }
    
    head = sorted;
}

template <typename T>
void LinkList<T>::sortedInsertWalks(T* newnode)
{
    if(sorted == NULL || sorted->object.getWalks() <= newnode->object.getWalks())
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        T* curr = sorted;
        while(curr->next != nullptr && curr->next->object.getWalks() > newnode->object.getWalks())
        {
            curr = curr->next;
        }
        
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

//Strikeouts//
template <typename T>
void LinkList<T>::insertionSortStrikeouts(T *node)
{
    T* current(node);
    while(current != NULL)
    {
        T* next(current->next);
        sortedInsertStrikeouts(current);
        current = next;
    }
    
    head = sorted;
}

template <typename T>
void LinkList<T>::sortedInsertStrikeouts(T* newnode)
{
    if(sorted == NULL || sorted->object.getStrikeouts() >= newnode->object.getStrikeouts())
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        T* curr = sorted;
        while(curr->next != nullptr && curr->next->object.getStrikeouts() < newnode->object.getStrikeouts())
        {
            curr = curr->next;
        }
        
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

//Hits By Pitch//
template <typename T>
void LinkList<T>::insertionSortHitsByPitch(T *node)
{
    T* current(node);
    while(current != NULL)
    {
        T* next(current->next);
        sortedInsertHitsByPitch(current);
        current = next;
    }
    
    head = sorted;
}

template <typename T>
void LinkList<T>::sortedInsertHitsByPitch(T* newnode)
{
    if(sorted == NULL || sorted->object.getHits_By_Pitch() <= newnode->object.getHits_By_Pitch())
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        T* curr = sorted;
        while(curr->next != nullptr && curr->next->object.getHits_By_Pitch() > newnode->object.getHits_By_Pitch())
        {
            curr = curr->next;
        }
        
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

//Alphabetically//
template <typename T>
void LinkList<T>::insertionSort(T *node)
{
    T* current(node);
    this->sorted = NULL;
    while(current != NULL)
    {
        T* next(current->next);
        sortedInsert(current);
        current = next;
    }
    
    head = sorted;
}

template <typename T>
void LinkList<T>::sortedInsert(T* newnode)
{
    if(sorted == NULL || sorted->object.getName() >= newnode->object.getName())
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        T* curr = sorted;
        while(curr->next != nullptr && curr->next->object.getName() < newnode->object.getName())
        {
            curr = curr->next;
        }
        
        newnode->next = curr->next;
        curr->next = newnode;
    }
}


#endif //LINKLIST_H
