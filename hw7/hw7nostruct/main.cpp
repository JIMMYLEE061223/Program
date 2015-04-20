//============================================================================
// Name        : cards_nostruct.cpp
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

enum Suit {None, Club, Diamond, Heart, Spade};
enum Rank {Unknown, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

const string Suit_Names[]={"None", "Club", "Diamond", "Heart", "Spade"};
const string Rank_Names[]={"Unknown", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

string Suit_name(Suit s) {return Suit_Names[s];}
string Rank_name(Rank r) {return Rank_Names[r];}

void Shuffle(Suit s[], Rank r[])
{
    srand(time(NULL));

    for(int i=0;i<=1000;i++){
        int random1=rand()%52;
        int random2=rand()%52;
        Suit temp=s[random1];
        s[random1]=s[random2];
        s[random2]=temp;
        Rank change=r[random1];
        r[random1]=r[random2];
        r[random2]=change;
    }
}

void Deal(Suit& s1, Rank& r1, Suit s[], Rank r[], int& n){
    //Hand out the next card on top
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
    Shuffle(my_suit,my_rank);
    for(int i=0; i<52; i++){
        cout << "["<<Suit_name(my_suit[i]) << ", " <<Rank_name(my_rank[i]) << "]" <<endl;
    }
    Suit player[4],dealer[4],table[4];
    Rank player1[4],dealer1[4],table1[4];
    for(int i=0;i<2;i++)
    {
        Deal(player[i],player1[i],my_suit,my_rank,num);
    }
    for(int i=0;i<2;i++)
    {
        Deal(table[i],table1[i],my_suit,my_rank,num);
    }
    for(int i=0;i<2;i++)
    {
        Deal(dealer[i],dealer1[i],my_suit,my_rank,num);
    }
    for(int i=2;i<4;i++)
    {
        Deal(player[i],player1[i],my_suit,my_rank,num);
    }
    for(int i=2;i<4;i++)
    {
        Deal(table[i],table1[i],my_suit,my_rank,num);
    }
    for(int i=2;i<4;i++)
    {
        Deal(dealer[i],dealer1[i],my_suit,my_rank,num);
    }
    cout<<"the player's cards are "<<endl;
    for(int i=0; i<4; i++){
        cout << "["<<Suit_name(player[i]) << ", " <<Rank_name(player1[i]) << "]" <<endl;
    }
    cout<<"the table's cards are "<<endl;
    for(int i=0; i<4; i++){
        cout << "["<<Suit_name(table[i]) << ", " <<Rank_name(table1[i]) << "]" <<endl;
    }
    cout<<"the dealer's cards are "<<endl;
    for(int i=0; i<4; i++){
        cout << "["<<Suit_name(dealer[i]) << ", " <<Rank_name(dealer1[i]) << "]" <<endl;
    }

    return 0;
}
