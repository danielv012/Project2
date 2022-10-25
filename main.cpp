#include <iostream>
#include <fstream>
#include <string>

#include "LinkedList/LinkList.h"
#include "Node/Node.h"
#include "Player/Player.h"

//#include "LinkList.h"
//#include "Node.h"
//#include "Player.h"

using namespace std;

void displayStats(LinkList<Node<Player>> &players);
void findLeaders(LinkList<Node<Player>> &players, int value);

void displayLeadersBA(LinkList<Node<Player>> &leaders);
void displayLeadersOB(LinkList<Node<Player>> &leaders);
void displayLeadersHits(LinkList<Node<Player>> &leaders);
void displayLeadersWalks(LinkList<Node<Player>> &leaders);
void displayLeadersStrikeouts(LinkList<Node<Player>> &leaders);
void displayLeadersHitsByPitch(LinkList<Node<Player>> &leaders);

int main()
{
    LinkList<Node<Player>> players;
    
    //inputs filename from user
    string filename;
    cout << "What's input file name? ";
    cin >> filename;
    
    //opens filestream
    ifstream file;
    file.open(filename);
    
    string line = "", name = "", record = "";
    while(getline(file,line)) //while the file contains another line, read from that line a name and record
    {
        name = line.substr(0, line.find(' '));
        record = line.substr(line.find(' ') + 1);
        Player tempPlayer(name, record);
        Node<Player> *tempNode = new Node(tempPlayer); //create a node with inputted player data
        players.addNode(tempNode); //add node to the list
    }
    file.close();
    
    players.insertionSort(players.head); //sort alphabetically
    displayStats(players); //display
    cout << "LEAGUE LEADERS" << endl;
    players.sorted = NULL;
    
    /*
     val 1 - BA
     val 2 - OB
     val 3 - Hits
     val 4 - Walks
     val 5 - Strikeouts
     val 6 - Hits_By_Pitch
     */
    
    //Each block here displays the name of the value, finds the leaders for that value, and displays them alphabetically
    findLeaders(players, 1);
    cout << "BATTING AVERAGE" << endl;
    displayLeadersBA(players);
    cout << endl;
    players.sorted = NULL;
    
    findLeaders(players, 2);
    cout << "ON-BASE PERCENTAGE" << endl;
    displayLeadersOB(players);
    cout << endl;
    players.sorted = NULL;
    
    findLeaders(players, 3);
    cout << "HITS" << endl;
    displayLeadersHits(players);
    cout << endl;
    players.sorted = NULL;
    
    findLeaders(players, 4);
    cout << "WALKS" << endl;
    displayLeadersWalks(players);
    cout << endl;
    players.sorted = NULL;
    
    findLeaders(players, 5);
    cout << "STRIKEOUTS" << endl;
    displayLeadersStrikeouts(players);
    cout << endl;
    players.sorted = NULL;
    
    findLeaders(players, 6);
    cout << "HIT BY PITCH" << endl;
    displayLeadersHitsByPitch(players);
    cout << endl;
    players.sorted = NULL;
}

//---------TESTING FUNCTION---------//
//void test()
//{
//
//}

void displayStats(LinkList<Node<Player>> &players)
{
    cout << players << endl;
}

void findLeaders(LinkList<Node<Player>> &players, int value)
{
    switch (value) { //depending on what value should be looked for, insertion sort for that specific value
        case 1:
            players.insertionSortBA(players.head);
            break;
        case 2:
            players.insertionSortOB(players.head);
            break;
        case 3:
            players.insertionSortHits(players.head);
            break;
        case 4:
            players.insertionSortWalks(players.head);
            break;
        case 5:
            players.insertionSortStrikeouts(players.head);
            break;
        case 6:
            players.insertionSortHitsByPitch(players.head);
            break;
        default:
            break;
    }
}


//----------Display Leaders------------//
/*
 COMMENTS FOR THIS METHOD ARE THE SAME FOR THE FOLLOWING 5 METHODS:
 displayLeadersOB, displayLeadersHits, displayLeadersWalks, displayLeadersStrikeouts, displayLeadersHitsByPitch
 */
void displayLeadersBA(LinkList<Node<Player>> &leaders)
{
    int leaderAmount = 0;
    if(leaders.getSize() == 0) return;
    
    LinkList<Node<Player>> first; //creates a linkedlist for 1st ties
    
    //1st Leader Row
    cout << leaders[0]->object.getBA() << "\t";
    int i = 0;
    while(leaders[i]->object.getBA() == leaders[0]->object.getBA()) //while the next player's value equals the current leading value
    {
        Node<Player> *temp = new Node(*leaders[i]); //create a new node from that leading player
        first.addNode(temp); //add it to the 1st ties list
        leaderAmount++;
        i++;
        if(i >= leaders.getSize()) break; //if there are no more leaders, break
    }
    first.insertionSort(first.head); //sort leaders alphabetically
    first.ToString(first.head); //print
    cout << endl;
    
    //2nd Leader Row
    if(leaderAmount >= 3 || i >= leaders.getSize()) return; //if there have been less than 3 leaders outputted and there are more leaders left, continue
    else
    {
        LinkList<Node<Player>> second; //creates a linkedlist for 2nd ties
        cout << leaders[i]->object.getBA() << "\t";
        int j = i;
        while(leaders[j]->object.getBA() == leaders[i]->object.getBA()) //while the next player's value equals the current leading value
        {
            Node<Player> *temp = new Node(*leaders[j]); //create a new node from that leading player
            second.addNode(temp); //add it to the 2nd ties list
            leaderAmount++;
            j++;
            if(j >= leaders.getSize()) break; //if there are no more leaders, break
        }
        second.insertionSort(second.head); //sort leaders alphabetically
        second.ToString(second.head); //print
        cout << endl;
        
        //3rd Leader Row
        if(leaderAmount >= 3 || j >= leaders.getSize()) return; //if there have been less than 3 leaders outputted and there are more leaders left, continue
        else
        {
            LinkList<Node<Player>> third; //creates a linkedlist for 2nd ties
            cout << leaders[j]->object.getBA() << "\t";
            int k = j;
            while(leaders[k]->object.getBA() == leaders[j]->object.getBA()) //while the next player's value equals the current leading value
            {
                Node<Player> *temp = new Node(*leaders[k]); //create a new node from that leading player
                third.addNode(temp); //add it to the 2nd ties list
                leaderAmount++;
                k++;
                if(k >= leaders.getSize()) break; //if there are no more leaders, break
            }
            third.insertionSort(third.head); //sort leaders alphabetically
            third.ToString(third.head); //print
            cout << endl;
        }
    }
}

void displayLeadersOB(LinkList<Node<Player>> &leaders)
{
    int leaderAmount = 0;
    if(leaders.getSize() == 0) return;
    
    LinkList<Node<Player>> first;
    
    //1st Leader Row
    cout << leaders[0]->object.getOB() << "\t";
    int i = 0;
    while(leaders[i]->object.getOB() == leaders[0]->object.getOB())
    {
        Node<Player> *temp = new Node(*leaders[i]);
        first.addNode(temp);
        leaderAmount++;
        i++;
        if(i >= leaders.getSize()) break;
    }
    first.insertionSort(first.head);
    first.ToString(first.head);
    cout << endl;
    
    //2nd Leader Row
    if(leaderAmount >= 3 || i >= leaders.getSize()) return;
    else
    {
        LinkList<Node<Player>> second;
        cout << leaders[i]->object.getOB() << "\t";
        int j = i;
        while(leaders[j]->object.getOB() == leaders[i]->object.getOB())
        {
            Node<Player> *temp = new Node(*leaders[j]);
            second.addNode(temp);
            leaderAmount++;
            j++;
            if(j >= leaders.getSize()) break;
        }
        second.insertionSort(second.head);
        second.ToString(second.head);
        cout << endl;
        
        //3rd Leader Row
        if(leaderAmount >= 3 || j >= leaders.getSize()) return;
        else
        {
            LinkList<Node<Player>> third;
            cout << leaders[j]->object.getOB() << "\t";
            int k = j;
            while(leaders[k]->object.getOB() == leaders[j]->object.getOB())
            {
                Node<Player> *temp = new Node(*leaders[k]);
                third.addNode(temp);
                leaderAmount++;
                k++;
                if(k >= leaders.getSize()) break;
            }
            third.insertionSort(third.head);
            third.ToString(third.head);
            cout << endl;
        }
    }
}

void displayLeadersHits(LinkList<Node<Player>> &leaders)
{
    int leaderAmount = 0;
    if(leaders.getSize() == 0) return;
    
    LinkList<Node<Player>> first;
    
    //1st Leader Row
    cout << leaders[0]->object.getHits() << "\t";
    int i = 0;
    while(leaders[i]->object.getHits() == leaders[0]->object.getHits())
    {
        Node<Player> *temp = new Node(*leaders[i]);
        first.addNode(temp);
        leaderAmount++;
        i++;
        if(i >= leaders.getSize()) break;
    }
    first.insertionSort(first.head);
    first.ToString(first.head);
    cout << endl;
    
    //2nd Leader Row
    if(leaderAmount >= 3 || i >= leaders.getSize()) return;
    else
    {
        LinkList<Node<Player>> second;
        cout << leaders[i]->object.getHits() << "\t";
        int j = i;
        while(leaders[j]->object.getHits() == leaders[i]->object.getHits())
        {
            Node<Player> *temp = new Node(*leaders[j]);
            second.addNode(temp);
            leaderAmount++;
            j++;
            if(j >= leaders.getSize()) break;
        }
        second.insertionSort(second.head);
        second.ToString(second.head);
        cout << endl;
        
        //3rd Leader Row
        if(leaderAmount >= 3 || j >= leaders.getSize()) return;
        else
        {
            LinkList<Node<Player>> third;
            cout << leaders[j]->object.getHits() << "\t";
            int k = j;
            while(leaders[k]->object.getHits() == leaders[j]->object.getHits())
            {
                Node<Player> *temp = new Node(*leaders[k]);
                third.addNode(temp);
                leaderAmount++;
                k++;
                if(k >= leaders.getSize()) break;
            }
            third.insertionSort(third.head);
            third.ToString(third.head);
            cout << endl;
        }
    }
}

void displayLeadersWalks(LinkList<Node<Player>> &leaders)
{
    int leaderAmount = 0;
    if(leaders.getSize() == 0) return;
    
    LinkList<Node<Player>> first;
    
    //1st Leader Row
    cout << leaders[0]->object.getWalks() << "\t";
    int i = 0;
    while(leaders[i]->object.getWalks() == leaders[0]->object.getWalks())
    {
        Node<Player> *temp = new Node(*leaders[i]);
        first.addNode(temp);
        leaderAmount++;
        i++;
        if(i >= leaders.getSize()) break;
    }
    first.insertionSort(first.head);
    first.ToString(first.head);
    cout << endl;
    
    //2nd Leader Row
    if(leaderAmount >= 3 || i >= leaders.getSize()) return;
    else
    {
        LinkList<Node<Player>> second;
        cout << leaders[i]->object.getWalks() << "\t";
        int j = i;
        while(leaders[j]->object.getWalks() == leaders[i]->object.getWalks())
        {
            Node<Player> *temp = new Node(*leaders[j]);
            second.addNode(temp);
            leaderAmount++;
            j++;
            if(j >= leaders.getSize()) break;
        }
        second.insertionSort(second.head);
        second.ToString(second.head);
        cout << endl;
        
        //3rd Leader Row
        if(leaderAmount >= 3 || j >= leaders.getSize()) return;
        else
        {
            LinkList<Node<Player>> third;
            cout << leaders[j]->object.getWalks() << "\t";
            int k = j;
            while(leaders[k]->object.getWalks() == leaders[j]->object.getWalks())
            {
                Node<Player> *temp = new Node(*leaders[k]);
                third.addNode(temp);
                leaderAmount++;
                k++;
                if(k >= leaders.getSize()) break;
            }
            third.insertionSort(third.head);
            third.ToString(third.head);
            cout << endl;
        }
    }
}

void displayLeadersStrikeouts(LinkList<Node<Player>> &leaders)
{
    int leaderAmount = 0;
    if(leaders.getSize() == 0) return;
    
    LinkList<Node<Player>> first;
    
    //1st Leader Row
    cout << leaders[0]->object.getStrikeouts() << "\t";
    int i = 0;
    while(leaders[i]->object.getStrikeouts() == leaders[0]->object.getStrikeouts())
    {
        Node<Player> *temp = new Node(*leaders[i]);
        first.addNode(temp);
        leaderAmount++;
        i++;
        if(i >= leaders.getSize()) break;
    }
    first.insertionSort(first.head);
    first.ToString(first.head);
    cout << endl;
    
    //2nd Leader Row
    if(leaderAmount >= 3 || i >= leaders.getSize()) return;
    else
    {
        LinkList<Node<Player>> second;
        cout << leaders[i]->object.getStrikeouts() << "\t";
        int j = i;
        while(leaders[j]->object.getStrikeouts() == leaders[i]->object.getStrikeouts())
        {
            Node<Player> *temp = new Node(*leaders[j]);
            second.addNode(temp);
            leaderAmount++;
            j++;
            if(j >= leaders.getSize()) break;
        }
        second.insertionSort(second.head);
        second.ToString(second.head);
        cout << endl;
        
        //3rd Leader Row
        if(leaderAmount >= 3 || j >= leaders.getSize()) return;
        else
        {
            LinkList<Node<Player>> third;
            cout << leaders[j]->object.getStrikeouts() << "\t";
            int k = j;
            while(leaders[k]->object.getStrikeouts() == leaders[j]->object.getStrikeouts())
            {
                Node<Player> *temp = new Node(*leaders[k]);
                third.addNode(temp);
                leaderAmount++;
                k++;
                if(k >= leaders.getSize()) break;
            }
            third.insertionSort(third.head);
            third.ToString(third.head);
            cout << endl;
        }
    }
}

void displayLeadersHitsByPitch(LinkList<Node<Player>> &leaders)
{
    int leaderAmount = 0;
    if(leaders.getSize() == 0) return;
    
    LinkList<Node<Player>> first;
    
    //1st Leader Row
    cout << leaders[0]->object.getHits_By_Pitch() << "\t";
    int i = 0;
    while(leaders[i]->object.getHits_By_Pitch() == leaders[0]->object.getHits_By_Pitch())
    {
        Node<Player> *temp = new Node(*leaders[i]);
        first.addNode(temp);
        leaderAmount++;
        i++;
        if(i >= leaders.getSize()) break;
    }
    first.insertionSort(first.head);
    first.ToString(first.head);
    cout << endl;
    
    //2nd Leader Row
    if(leaderAmount >= 3 || i >= leaders.getSize()) return;
    else
    {
        LinkList<Node<Player>> second;
        cout << leaders[i]->object.getHits_By_Pitch() << "\t";
        int j = i;
        while(leaders[j]->object.getHits_By_Pitch() == leaders[i]->object.getHits_By_Pitch())
        {
            Node<Player> *temp = new Node(*leaders[j]);
            second.addNode(temp);
            leaderAmount++;
            j++;
            if(j >= leaders.getSize()) break;
        }
        second.insertionSort(second.head);
        second.ToString(second.head);
        cout << endl;
        
        //3rd Leader Row
        if(leaderAmount >= 3 || j >= leaders.getSize()) return;
        else
        {
            LinkList<Node<Player>> third;
            cout << leaders[j]->object.getHits_By_Pitch() << "\t";
            int k = j;
            while(leaders[k]->object.getHits_By_Pitch() == leaders[j]->object.getHits_By_Pitch())
            {
                Node<Player> *temp = new Node(*leaders[k]);
                third.addNode(temp);
                leaderAmount++;
                k++;
                if(k >= leaders.getSize()) break;
            }
            third.insertionSort(third.head);
            third.ToString(third.head);
            cout << endl;
        }
    }
}
