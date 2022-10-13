#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

class Player
{
    public:
        //---------Constructors & Destructors--------//
        Player();
        Player(string);
        Player(string, string);
        ~Player();
    
        Player(const Player &obj);

        //---------Accessors & Mutators---------//
        string getName() {return name;}
        void setName(string n) {name = n;}

        int getAt_Bats() {return at_bats;}
        void setAt_Bats(int num) {at_bats = num;}

        int getHits() {return hits;}
        void setHits(int num) {hits = num;}

        int getWalks() {return walks;}
        void setWalks(int num) {walks = num;}

        int getStrikeouts() {return strikeouts;}
        void setStrikeouts(int num) {strikeouts = num;}
    
        int getOuts() {return outs;}
        void setOuts(int num) {outs = num;}

        int getHits_By_Pitch() {return hits_by_pitch;}
        void setHits_By_Pitch(int num) {hits_by_pitch = num;}

        int getSacrifices() {return sacrifices;}
        void setSacrifices(int num) {sacrifices = num;}
    
        int getPlate_Appearances() {return plate_appearances;}
    void setPlate_Appearances(int num) {plate_appearances = num;}
    
        //-----------Calculators------------//
        double calcBA()
        {
            if(at_bats == 0) return 0;
            return (double)hits/at_bats;
        }
        double calcOB()
        {
            if(plate_appearances == 0) return 0;
            return ((double)(hits + walks + hits_by_pitch)/(double)plate_appearances);
        }

        //----------Overloaded Operators----------//
        bool operator==(Player &right);
        bool operator>(Player &right);
        bool operator<(Player &right);

        Player& operator=(const Player &obj);
        friend ostream& operator<<(ostream&, const Player &obj);
    
        friend ostream& operator<<(ostream& out, Player &obj)
        {
            out << obj.getName() << "\t";
            out << obj.getAt_Bats() << "\t";
            out << obj.getHits() << "\t";
            out << obj.getWalks() << "\t";
            out << obj.getStrikeouts() << "\t";
            out << obj.getHits_By_Pitch() << "\t";
            out << obj.getSacrifices() << "\t";
            out << fixed << setprecision(3) << obj.calcBA() << "\t";
            out << fixed << setprecision(3) << obj.calcOB() << endl;
            return out;
        }
        friend istream& operator>>(istream&, Player &obj);

    private:
        string name;
        int at_bats, hits, walks, strikeouts, outs, hits_by_pitch, sacrifices, plate_appearances;
    
        void sortRecord(string);
    protected:
};

#endif //PLAYER_H
