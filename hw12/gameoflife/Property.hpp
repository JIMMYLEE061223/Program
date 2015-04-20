#ifndef PROPERTY_H
#define PROPERTY_H

#include "Square.hpp"

//--------------------------------------
//Property class:
//  Base class for all properties that
//  have some value when count final 
//  score at the end of the game.
//
//  The way to compute value may be
//  different for different kinds of 
//  properties, use virtual function if 
//  there are some special rules to compute
//  value. (Families and Stamp)
//--------------------------------------
class Property {
  public:
    //constructor
    Property(){ value_ = 0;}
    Property(int value){value_ = value;}

    void setValue(int value){value_ = value;}
    virtual int ComputeValue(){ return value_;}

  protected:
    int value_;
};

//---------------------------------------
//Vihecle class:
//  There are four types of Vihecle:
//  Car, Airplane, Boat and Seaboat
//  Vihecle is the base class
//  of them.
//---------------------------------------

class Vihecle: public Property {
  public:
    Vihecle(){value_ = 0;}
    Vihecle(int value) { value_ = value; }
    virtual ~Vihecle(){}
};
//--------------------------------------------
// Car, Airplane, Boat and Seaplane 
// are derived classes of Vihecle
// The difference for these four tranpotation are value and type
// Seaplane values 400 and other kinds value 0.
// (Value and type are initialized in constructor)
//-----------------------------------------------------
class Car: public Vihecle {
  public:
    Car(): Vihecle(50){}
    virtual ~Car(){}
};

class Airplane: public Vihecle {
  public:
    Airplane(): Vihecle(100){}
    virtual ~Airplane(){}
};

class Boat: public Vihecle {
  public:
    Boat(): Vihecle(200){}
    virtual ~Boat(){}
};

class Seaplane: public Vihecle {
  public:
    Seaplane(): Vihecle(400){}
    virtual ~Seaplane(){}
};


//----------------------------------------
//Family class:
//  Inherits "Property" class.
//  Including information like married, 
//  number of child and pets.
//----------------------------------------
class Families: public Property {
  public: 
    Families();

    bool Married();
    int  ChildrenNum();
    int  PetNum();

    void GetMarry();
    void GetAPet();
    void HaveABaby();
    bool Reportmarry(){return married_;}
    //virtual function becaues may have bonus
    virtual int ComputeValue();

  private:
    int childrenNum_;
    int petNum_;
    bool married_;
    const int MAX_FAMILIES; 
    //children + pet have to be smaller than MAX_FAMILIES

};

//----------------------------------------
//House class:
//  Inherits "Property" class.
//  The variable place_ is a pointer that 
//  points to the house square on the Map
//
//  If the place_ points to NULL, it means
//  that the player doesn't has a house.
//----------------------------------------

class House: public Property {
  public:
    House();
    void Buy(Square* square);
    void Sell();
    Square* Place();
    //no virtual function
    int Getrecord(){return record;}
  private:
    Square* place_; //pointer to the house on the map
    int record=0;
};

class Stamp: public Property {
  public:
    enum StampType {Snow, Jungle, Beach, City};
    
  public:
    Stamp();
    void GetAStamp(StampType type);
    virtual int ComputeValue();

  private:
    //each element in the array records whether 
    //the play has the specific type of stamp
    bool stamps_[4]; 
};

#endif /* end of include guard: PROPERTY_H */
