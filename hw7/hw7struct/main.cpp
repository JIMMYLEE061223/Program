//============================================================================
// Name        : cards_struct.cpp
//============================================================================
#include <iostream>
#include <time.h>
#include <stdlib.h>
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
    srand(time(NULL));

    for(int i=0;i<=1000;i++){
        int random1=rand()%52;
        int random2=rand()%52;
        Card change1,change;
        change1.my_suit=d.cards[random1].my_suit;
        d.cards[random1].my_suit=d.cards[random2].my_suit;
        d.cards[random2].my_suit=change1.my_suit;
        change.my_rank=d.cards[random1].my_rank;
        d.cards[random1].my_rank=d.cards[random2].my_rank;
        d.cards[random2].my_rank=change.my_rank;
    }
}

Card& Deal(Deck& d){
    //Hand out the next card on top
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
    Shuffle(d1);
    for(int i=0; i<52; i++){
        cout << "["<<Suit_name(d1.cards[i]) << ", " <<Rank_name(d1.cards[i]) << "]" <<endl;
    }
    Card player[4],dealer[4],table[4];
    for(int i=0;i<2;i++)
    {
        player[i]=Deal(d1) ;

    }
    for(int i=0;i<2;i++)
    {
         table[i]=Deal(d1) ;
    }
    for(int i=0;i<2;i++)
    {
        dealer[i]=Deal(d1) ;
    }
    for(int i=2;i<4;i++)
    {
        player[i]=Deal(d1) ;

    }
    for(int i=2;i<4;i++)
    {
         table[i]=Deal(d1) ;
    }
    for(int i=2;i<4;i++)
    {
        dealer[i]=Deal(d1) ;
    }
    cout<<"the player's cards are:"<<endl;
    for(int i=0; i<4; i++){
        cout << "["<<Suit_name(player[i]) << ", " <<Rank_name(player[i]) << "]" <<endl;
    }
    cout<<"the table's cards are:"<<endl;
    for(int i=0; i<4; i++){
        cout << "["<<Suit_name(table[i]) << ", " <<Rank_name(table[i]) << "]" <<endl;
    }
    cout<<"the dealer's cards are:"<<endl;
    for(int i=0; i<4; i++){
        cout << "["<<Suit_name(dealer[i]) << ", " <<Rank_name(dealer[i]) << "]" <<endl;
    }

    return 0;
}
