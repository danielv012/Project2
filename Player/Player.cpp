#include "Player.h"

#include <iostream>

using namespace std;

//----------Constructors--------//
Player::Player() //sets all values to 0
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
void Player::sortRecord(string record) //given a string of characters, increases respective value in Player object
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
bool Player::operator==(const Player &right) // returns true if objects are equal
{
    if(this->name == right.name &&
       this->at_bats == right.at_bats &&
       this->hits == right.hits &&
       this->walks == right.walks &&
       this->strikeouts == right.strikeouts &&
       this->outs == right.outs &&
       this->hits_by_pitch == right.hits_by_pitch &&
       this->sacrifices == right.sacrifices &&
       this->plate_appearances == right.plate_appearances) return true;
    return false;
}

bool Player::operator>(const Player &right) //returns true if first object is greater
{
    if(this->name > right.name &&
       this->at_bats > right.at_bats &&
       this->hits > right.hits &&
       this->walks > right.walks &&
       this->strikeouts > right.strikeouts &&
       this->outs > right.outs &&
       this->hits_by_pitch > right.hits_by_pitch &&
       this->sacrifices > right.sacrifices &&
       this->plate_appearances > right.plate_appearances) return true;
    return false;
}

bool Player::operator<(const Player &right) //returns true if first object is less
{
    if(this->name < right.name &&
       this->at_bats < right.at_bats &&
       this->hits < right.hits &&
       this->walks < right.walks &&
       this->strikeouts < right.strikeouts &&
       this->outs < right.outs &&
       this->hits_by_pitch < right.hits_by_pitch &&
       this->sacrifices < right.sacrifices &&
       this->plate_appearances < right.plate_appearances) return true;
    return false;
}

bool Player::operator<=(const Player &right) //returns true if first object is less than or equal to
{
    if(this->name <= right.name &&
       this->at_bats <= right.at_bats &&
       this->hits <= right.hits &&
       this->walks <= right.walks &&
       this->strikeouts <= right.strikeouts &&
       this->outs <= right.outs &&
       this->hits_by_pitch <= right.hits_by_pitch &&
       this->sacrifices <= right.sacrifices &&
       this->plate_appearances <= right.plate_appearances) return true;
    return false;
}

Player& Player::operator=(const Player &obj) //copies a given player object to the one that called
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
