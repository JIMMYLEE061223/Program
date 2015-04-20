#include "Player.hpp"
#include "Square.hpp"


//-----------------
// Plyer Class
//-----------------
const int initCash = 10000;

//Constructor
Player::Player() :
  name_(""),
  position_(NULL),
  money_(initCash)
{
  vihecle_ = new Car;
}

void Player::setName(string name) { name_ = name; } 
void Player::setPosition(Square* sq) { position_ = sq; }

//Money
void Player::setMoney(unsigned money) { money_ = money; }
void Player::EarnMoney(unsigned money) { money_ += money; }
void Player::PayMoney(unsigned money) { money_ -= money; }

//Getter
string        Player::Name() { return name_; }
unsigned      Player::Money() { return money_; }
Square*       Player::Position() {return position_; }

//Families related method
void Player::GetMarry(){
  families_.GetMarry();
}

void Player::HaveABaby() {
  families_.HaveABaby();
}

void Player::GetAPet() {
  families_.GetAPet();
}


//House related methods
void Player::BuyHouse(Square *sq) { 
  house_.Buy(sq);
  money_ -= sq->Number(); //pay money
}

void Player::SellHouse() {
  money_ += house_.Place()->Number(); //get money first
  house_.Sell();
}

//Passport Stamp related methods
void Player::GetAStamp(Stamp::StampType type) {
  stamps_.GetAStamp(type);
}


//Count total property value
int Player::ComputeTotalValue() {
  //In order to demonstrate polymorphism....
  int value=0;

  Property *p_ptr;

  //House
  p_ptr = &(this->house_);
  value += p_ptr->ComputeValue();

  //Families
  p_ptr = &(this->families_);
  value += p_ptr->ComputeValue();

  //vihecle
  p_ptr = this->vihecle_;
  value += p_ptr->ComputeValue();

  //Passpoet Stamp
  p_ptr = &(this->stamps_);
  value += p_ptr->ComputeValue();

  //money
  value += money_;

  return value;

}

//Count total property value
void Player::ReportValues() {

  Property *p_ptr;

  //House
  p_ptr = &(this->house_);
  cout << "House: " << p_ptr->ComputeValue() << endl;

  //Families
  p_ptr = &(this->families_);
  cout << "Family: " << p_ptr->ComputeValue() << endl;

  //vihecle
  p_ptr = this->vihecle_;
  cout << "Vehicle: " << p_ptr->ComputeValue() << endl;

  //Passport Stamp
  p_ptr = &(this->stamps_);
  cout << "Passport: " <<  p_ptr->ComputeValue() << endl;

  //money
  cout << "Money: " <<  money_ << endl;

}

