//============================================================================
// Name        : cards_struct.cpp
//============================================================================

#include <iostream>
using namespace std;

struct Card{
	enum Suit {None, Club, Diamond, Heart, Spade};
	enum Rank {Unknown, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

    Suit my_suit;
    Rank my_rank;

	static const string Suit_Names[];
	static const string Rank_Names[];
};

const string Card::Suit_Names[]={"None", "Club", "Diamond", "Heart", "Spade"};
const string Card::Rank_Names[]={"Unknown", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

string Suit_name(Card c) {return Card::Suit_Names[c.my_suit];} //prototype
string Rank_name(Card c) {return Card::Rank_Names[c.my_rank];}

struct Deck{
	Card cards[52]; //There are 52 cards in each deck
	unsigned int num; //How many cards are left in the deck
};

void Shuffle(Deck& d){
    //Randomize the sequence of the cards

}

Card& Deal(Deck& d){ //Hand out the next card on top
	d.num--;
	return d.cards[d.num];
}

int main() {
	Deck d1;
	//Initialize d1 struct
	d1.num=52;
	for(int i=1; i<5; i++){
		for(int j=1; j<14; j++){
            d1.cards[(i-1)*13+(j-1)].my_suit=static_cast<Card::Suit>(i);
			d1.cards[(i-1)*13+(j-1)].my_rank=static_cast<Card::Rank>(j);
		}
	}

	for(int i=0; i<52; i++){
		cout << "["<<Suit_name(d1.cards[i]) << ", " <<Rank_name(d1.cards[i]) << "]" <<endl;
	}

	return 0;
}
