#include "Property.hpp"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//-----------------------
// Families methods
//-----------------------
Families::Families():
  MAX_FAMILIES(4)
{
  married_ = false;
  petNum_ = 0;
  childrenNum_ = 0;
}

void Families::GetMarry() {
  married_ = true;
}

void Families::GetAPet() {
  if (childrenNum_ + petNum_ < MAX_FAMILIES) {
    petNum_ ++;
    value_ += 100;  
  }
}

void Families::HaveABaby() {
  if (childrenNum_ + petNum_ < MAX_FAMILIES) {
    childrenNum_ ++;
    value_ += 100;  
  }
}

bool Families::Married() { 
  return married_;
}

int Families::ChildrenNum() {
  return childrenNum_;
}

int Families::PetNum() {
  return petNum_;
}

int Families::ComputeValue() {
  if (petNum_ + childrenNum_ == MAX_FAMILIES){
    return 600;
  }
  else {
    return value_;
  }
}


//-----------------------
// House methods
//-----------------------
House::House () {
  place_ = NULL;
  value_ = 0;
}


void House::Buy(Square* houseSquare) {
  place_ = houseSquare;
  record++;
  value_ = houseSquare->Number(); 
}

void House::Sell() {
  place_ = NULL;
  value_ = 0; 
}

Square* House::Place() {
  return place_;
}


//-----------------------
// Stamp methods
//-----------------------
Stamp::Stamp() {
  for (int i=0; i<4; i++) {
    stamps_[i] = false;
  }
  value_ = 0;
}


void Stamp::GetAStamp(StampType type) {
  if (!stamps_[type]){
    stamps_[type] = true;
    value_ += 100;
  }
}

int Stamp::ComputeValue() {
  int stampNum = 0;
  for (int i=0; i<4; i++) {
    if (stamps_[i] == true) {
      stampNum ++;
    }
  }
  if (stampNum == 4) return 500;
  else return value_;
}


