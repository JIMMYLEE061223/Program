#include "Square.hpp"
#include <cassert>

//----------------
// Square Class
//----------------

Square::Square(): 
  next_(0)
{
  type_ = Unknown;
  id_ = -1;
  description_ = "";
  number_ = 0;
}

Square::Square(SquareType type, string desc): 
  next_(0)
{
  type_ = type;
  id_ = -1;
  description_ = desc;
  number_ = 0;
}

Square::Square(SquareType type, int id, string desc, unsigned number):
  next_(0)
{
  type_ = type;
  id_ = id;
  description_ = desc;
  number_ = number;
}

//Setter
void Square::ID(int id) { id_ = id; }

void Square::Type(SquareType type) { type_ = type; }

void Square::Number(unsigned number) { number_ = number; }

void Square::Description(string desc) { description_ = desc; }

void Square::AddNextSquare(Square *sq) { next_.push_back(sq); }

void Square::AddNextID(int id) {
  nextID_.push_back(id);
}



//Getter
int Square::ID() { return id_; }
Square::SquareType Square::Type() { return type_; }

string Square::Description() { return description_; }

unsigned Square::Number() { return number_; }

Square* Square::NextSquare() { 
  assert (next_.size() > 0);
  return next_[0];
}

Square* Square::NextSquare(int i) { 
  assert (next_.size() > i);
  return next_[i];
}


unsigned Square::BranchNum() {
  return nextID_.size();
}

int Square::NextID() {
  assert (nextID_.size() > 0);
  return nextID_[0];
}

int Square::NextID(int index) {
  assert (nextID_.size() > index);
  return nextID_[index];
}

