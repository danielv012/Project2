#include "Player.h"

#include <iostream>

using namespace std;

//----------Constructors--------//
Player::Player()
{
    name = "";
    
    at_bats = 0;
    hits = 0;
    walks = 0;
    strikeouts = 0;
    outs = 0;
    hits_by_pitch = 0;
    sacrifices = 0;
    plate_appearances = 0;
    
}

Player::Player(string x)
{
    name = x;
}

Player::Player(string name, string recordLine)
{
    this->name = name;
    at_bats = 0;
    hits = 0;
    walks = 0;
    strikeouts = 0;
    outs = 0;
    hits_by_pitch = 0;
    sacrifices = 0;
    plate_appearances = 0;
    sortRecord(recordLine);
}

Player::Player(const Player &obj)
{
    this->name = obj.name;
    
    this->at_bats = obj.at_bats;
    this->hits = obj.hits;
    this->walks = obj.walks;
    this->strikeouts = obj.strikeouts;
    this->outs = obj.outs;
    this->hits_by_pitch = obj.hits_by_pitch;
    this->sacrifices = obj.sacrifices;
    this->plate_appearances = obj.plate_appearances;
}

//---------Destructor--------//
Player::~Player()
{
    //run destructor
}

//----------Miscellaneous--------//
void Player::sortRecord(string record)
{
    bool invalid = false;
    bool atbat = false;
    for(char x : record)
    {
        switch (x)
        {
        case 'H':
            this->hits++;
            atbat = true;
            break;
        case 'O':
            this->outs++;
            atbat = true;
            break;
        case 'K':
            this->strikeouts++;
            atbat = true;
            break;
        case 'W':
            this->walks++;
            break;
        case 'P':
            this->hits_by_pitch++;
            break;
        case 'S':
            this->sacrifices++;
            break;
        default:
            invalid = true;
            break;
        }
        if(!invalid) this->plate_appearances++;
        if(atbat) this->at_bats++;
        atbat = false;
        invalid = false;
    }
}

//-------Overloaded Operators---------//
Player& Player::operator=(const Player &obj)
{
    this->name = obj.name;
    
    this->at_bats = obj.at_bats;
    this->hits = obj.hits;
    this->walks = obj.walks;
    this->strikeouts = obj.strikeouts;
    this->outs = obj.outs;
    this->hits_by_pitch = obj.hits_by_pitch;
    this->sacrifices = obj.sacrifices;
    this->plate_appearances = obj.plate_appearances;
    
    return *this;
}
