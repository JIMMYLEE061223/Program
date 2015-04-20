//============================================================================
// Name        : cards_nostruct.cpp
//============================================================================

#include <iostream>
using namespace std;

enum Suit {None, Club, Diamond, Heart, Spade};
enum Rank {Unknown, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

const string Suit_Names[]={"None", "Club", "Diamond", "Heart", "Spade"};
const string Rank_Names[]={"Unknown", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

string Suit_name(Suit s) {return Suit_Names[s];}
string Rank_name(Rank r) {return Rank_Names[r];}

void Shuffle(Suit s[], Rank r[]){ //Randomize the sequence of the cards

}

void Deal(Suit& s1, Rank& r1, Suit s[], Rank r[], int& n){ //Hand out the next card on top
	n--;
	s1=s[n];
	r1=r[n];
}

int main() {
	Suit my_suit[52];
	Rank my_rank[52];
	int num;

	num=52;
	for(int i=1; i<5; i++){
		for(int j=1; j<14; j++){
			my_suit[(i-1)*13+(j-1)]=static_cast<Suit>(i);
			my_rank[(i-1)*13+(j-1)]=static_cast<Rank>(j);
		}
	}

	for(int i=0; i<52; i++){
		cout << "["<<Suit_name(my_suit[i]) << ", " <<Rank_name(my_rank[i]) << "]" <<endl;
	}

	return 0;
}
