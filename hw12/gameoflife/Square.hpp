#ifndef SQUARE_H

#define SQUARE_H



#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Square {
  public:
    enum SquareType {Unknown, Start, 

      //Passthrough squares
      PassMin, Payday, GetPromotion, CollegeFee, House, PassMax,

      //Stop squares
      StopMin, SetSail, Exam, MarriedOrCelebrate, StopMax,

      //Travel squares
      TravelMin, Port, Airport, TravelMax,

      //Special squares
      SpecialMin, Empty, GetMoney, PayMoney, Birthday, HaveBaby, 
       SpinToWin, GetPet, GoToPort, SpecialMax
    };

    Square();
    Square(SquareType type, string desc);
    Square(SquareType type, int id, string desc, unsigned number);

    //Setter
    void Type(SquareType type);
    void ID(int id);
    void Description(string desc);
    void Number(unsigned number);
    void AddNextSquare(Square *sq);
    void AddNextID(int id);

    //Getter
    SquareType Type();

    int ID();
    string Description();
    unsigned Number();
    Square* NextSquare();
    Square* NextSquare(int i);

    unsigned BranchNum();
    int NextID();
    int NextID(int index);


  private:
    SquareType type_;
    int id_; //an unique id for each square
    string description_;
    int number_; //used when the square involve some number info
    vector<Square*> next_; //use vector because may have branch
    vector<int> nextID_; //use vector because may have branch
};

#endif /* end of include guard: SQUARE_H */
