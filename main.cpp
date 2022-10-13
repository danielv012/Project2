#include <iostream>
#include <fstream>
#include <string>

#include "LinkList.h"
#include "Node.h"
#include "Player.h"

using namespace std;

void displayStats(LinkList &players);

int main()
{
    LinkList players;
    
    string filename;
    cout << "What's input file name? ";
    cin >> filename;
    
    ifstream file;
    file.open(filename);
    
    string line = "", name = "", record = "";
    while(getline(file,line))
    {
        name = line.substr(0, line.find(' '));
        record = line.substr(line.find(' ') + 1);
        Player *tempPlayer = new Player(name, record);
        Node *tempNode = new Node(tempPlayer);
        players.addNode(tempNode);
    }
    file.close();
    displayStats(players);
    //findLeaders(players);
    //displayLeaders(players);
}

//---------TESTING FUNCTION---------//
//void test()
//{
//
//}

void displayStats(LinkList &players)
{
    cout << players << endl;
}
