#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include "Property.hpp"
using namespace std;



class Square;

class Career {
public:

    Career() {promotion_=0;}
    virtual ~Career(){}

    //Setter
    void setPromotion(int promotion){ promotion_ = promotion; }

    //Getter
    int getPromotion(){return promotion_;}

    //Other functions
    void Promote(){ if (promotion_ < 3) promotion_ ++;}
    virtual unsigned Payment(int degree){ //default job payment
        switch (promotion_) {
        case 0: return 50;
        case 1: return 150;
        case 2: return 250;
        case 3: return 450;
        default: cerr << "Error when computing payment...\n";
        }
        return 0;
    }

protected:
    int promotion_;
};

class StuntDouble: public Career{};
class TrapezeArtist: public Career{};
class PopStar: public Career{};
class MovirStar: public Career{};
class JetPilot: public Career{};
class Explorer: public Career{};

//College Career
class CollageCareer: public Career{
public:
    virtual unsigned Payment(int degree){
        if(degree==0){
            cerr<< "You need to get a collage degree for this job!" <<endl;
            return 0;
        }
        switch (promotion_) {
        case 0: return 150;
        case 1: return 250;
        case 2: return 350;
        case 3: return 550;
        default: cerr << "Error when computing payment...\n";
        }
        return 0;
    }
};
class Teacher: public CollageCareer{};
class MadScientist: public CollageCareer{};
class FlyingDoctor: public CollageCareer{};
class RocketDesigner: public CollageCareer{};
class Vet: public CollageCareer{};
class Politician: public CollageCareer{};

class Degree {
public:
    enum DegreeType {None, Collage, Master, PhD};

public:
    Degree(){level_=None;}
    void GetaDegree(DegreeType d) {level_=d;}
    DegreeType Level(){ return static_cast<DegreeType>(level_);}
    void Advance(){level_++;}

private:
    int level_;
};

class Player {
public:
    Player();

    void setName(string name);
    void setPosition(Square* sq);
    void setMoney(unsigned money);
    void EarnMoney(unsigned money);
    void PayMoney(unsigned money);

    //Families related methods
    void GetMarry();
    void HaveABaby();
    void GetAPet();

    //House related methods
    void BuyHouse(Square *sq);
    void SellHouse();

    //Passport Stamp related methods
    void GetAStamp(Stamp::StampType type);

    //Vihecle related methods
    void GetaVehicle(Vihecle* t){
        if(vihecle_!=NULL) delete vihecle_;
        vihecle_=t;
    }

    //Education related
    void GotoCollage() { degree_.GetaDegree(Degree::Collage);}
    int DegreeLevel() { return degree_.Level();}
    void AdvanceDegree() { degree_.Advance(); }

    //Career related
    void GetaJob(Career* c){
        if(career_!=NULL) delete career_;
        career_=c;
    }

    int GetSalary(){
        return career_->Payment(DegreeLevel());
    }
    void Promote(){ career_->Promote();}
    House GetHouse(){return house_;}
    //Count total property value
    int ComputeTotalValue();
    void ReportValues();
    Families Reportmarried(){return families_;}
    string Name();
    Square* Position();
    unsigned Money();

private:
    string name_;

    //Current position on the map
    Square *position_;

    //Properties
    Vihecle*  vihecle_;
    Families  families_;
    House     house_;
    Stamp     stamps_;
    int       money_;

    //Degree
    Degree degree_;

    //Career
    Career* career_=NULL;
};

#endif 

