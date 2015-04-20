//============================================================================
// Name        : cards.cpp
//============================================================================

#include <iostream>
using namespace std;

class Card{
public:
	enum Suit {None, Club, Diamond, Heart, Spade};
	enum Rank {Unknown, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

	Card(){
		my_suit=None;
		my_rank=Unknown;
	}

	Card(Suit s, Rank r){
		my_suit=s;
		my_rank=r;
	}

	void set_suit(Suit s){ my_suit=s;}
	Suit suit() const { return my_suit;}
	string suit_name() const {return Suit_Names[my_suit];}

	void set_rank(Rank r){ my_rank=r;}
	Rank rank() const { return my_rank;}
	string rank_name() const {return Rank_Names[my_rank];}

private:
	Suit my_suit;
	Rank my_rank;
	static const string Suit_Names[];
	static const string Rank_Names[];
};

const string Card::Suit_Names[]={"None", "Club", "Diamond", "Heart", "Spade"};
const string Card::Rank_Names[]={"Unknown", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

class Deck{
public:
	Deck(){
		num=52;
		for(int i=1; i<5; i++){
			for(int j=1; j<14; j++){
				cards[(i-1)*13+(j-1)].set_suit(static_cast<Card::Suit>(i));
				cards[(i-1)*13+(j-1)].set_rank(static_cast<Card::Rank>(j));
			}
		}
	}

	void Shuffle(){ //Randomize the sequence of the cards

	}

	Card& Deal(){ //Hand out the next card on top
		num--;
		return cards[num];
	}

	Card& card(int i){
		return cards[i];
	}

private:
	Card cards[52]; //There are 52 cards in each deck
	unsigned int num; //How many cards are left in the deck
};

int main() {
	Deck d1;

	for(int i=0; i<52; i++){
		cout << "[" << d1.card(i).suit_name() << ", " << d1.card(i).rank_name() << "]" <<endl;
	}
	cout << endl;
	return 0;
}
