//============================================================================
// Name        : cards.cpp
//============================================================================

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Card{
public:
    enum Suit {None, Club, Diamond, Heart, Spade};
    enum Rank {Unknown, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
    Card()
    {
        my_suit=None;
        my_rank=Unknown;
    }

    void setCard(Suit s, Rank r)
    {
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
void check(vector<Card>& player,vector<Card>& table);
void check2(vector<Card>& player,vector<Card>& table);
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
        srand(time(NULL));
        for(int i=0;i<1000;i++)
        {

            int random1=rand()%52;
            int random2=rand()%52;
            Card temp;
            temp.setCard(cards[random1].suit(),cards[random1].rank());
            cards[random1].setCard(cards[random2].suit(),cards[random2].rank());
            cards[random2].setCard(temp.suit(),temp.rank());
        }
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
void playoption();
int record(vector<Card> point);
void shownowcards();
void gameplayer(int& option,vector<Card>& player,vector<Card>& playerpoint,vector<Card>& table,vector<Card>& plate);
bool player1call=false,player2call=false;
int option,sequence;
int n=1;
vector<Card> player1(4),player2(4),table(4),player1point,player2point,plate,board;
int main() {
    Deck d1;
    d1.Shuffle();    //Randomize the sequence of the cards
    // don't let the deck be detected
    /*for(int i=0; i<52; i++){
        cout << "[" << d1.card(i).suit_name() << ", " << d1.card(i).rank_name() << "]" <<endl;
    }*/
    cout << endl;
    //deal the cards to player1,player2
    for(int i=0;i<2;i++)
    {
        player1[i]=d1.Deal() ;
    }
    for(int i=0;i<2;i++)
    {
        table[i]=d1.Deal() ;
    }
    for(int i=0;i<2;i++)
    {
        player2[i]=d1.Deal() ;
    }
    for(int i=2;i<4;i++)
    {
        player1[i]=d1.Deal() ;
    }
    for(int i=2;i<4;i++)
    {
        table[i]=d1.Deal() ;
    }
    for(int i=2;i<4;i++)
    {
        player2[i]=d1.Deal() ;
    }
    cout<<"the player1's cards are:"<<endl;     //show the handcards and table cards
    for(int i=0; i<4; i++){
        cout << "["<<player1[i].suit_name() << ", " <<player1[i].rank_name() << "]";
    }
    cout<<endl;
    cout<<"the table's cards are:"<<endl;
    for(int i=0; i<4; i++){
        cout << "["<<table[i].suit_name() << ", " <<table[i].rank_name() << "]" ;
    }
    cout<<endl;
    cout<<"the player2's cards are:"<<endl;
    for(int i=0; i<4; i++){
        cout << "["<<player2[i].suit_name() << ", " <<player2[i].rank_name()<< "]" ;
    }
    cout<<endl<<endl;
    check(player1,table);     //check if player can use pair
    check2(player1,table);    //check if player can use combine
    cout<<"First is the player1"<<endl;
    playoption();             //show the methods how to play
    cout<<"Now throw the card:"<<endl;
    cin>>option;
    for(int k=0;k<6;k++)        //use for loop to finish the whole deck
    {
        for(int i=0;i<4;i++)
        {
            gameplayer(option,player1,player1point,table,plate);  //to verify the option and cards when player is playing game
            cout<<endl;
            cout<<"now turn to player2"<<endl;
            check(player2,table);          //check if player can use pair
            check2(player2,table);         //check if player can use combine
            playoption();
            cin>>option;
            gameplayer(option,player2,player2point,table,board);  //to verify the option and cards when player is playing game
            cout<<endl;
            cout<<"now turn to player1"<<endl;
            check(player1,table);
            check2(player1,table);
            playoption();
            cin>>option;
        }
        cout<<"Now deals new cards to player1 and player2"<<endl;
        for(int i=0;i<2;i++)
        {
            player1.push_back(d1.Deal());   //deal the new cards to both players
            player1.push_back(d1.Deal());
            player2.push_back(d1.Deal());
            player2.push_back(d1.Deal());
        }
        shownowcards();
    }
    cout<<"After calculating,the player1's scores are:"<<record(player1point)<<endl;
    cout<<"the player2's scores are:"<<record(player2point);
    return 0;
}
void shownowcards()   //print out the cards when game is running
{
    cout<<"Now player1's cards are: "<<endl;
    for(int i=0;i<player1.size();i++)
    {
        cout << "[" << player1[i].suit_name() << ", " << player1[i].rank_name() << "]";
    }
    cout<<endl;
    cout<<"Now table's cards are: "<<endl;
    for(int i=0;i<table.size();i++)
    {
        cout << "[" << table[i].suit_name() << ", " << table[i].rank_name() << "]";
    }
    cout<<endl;
    cout<<"Now player2's cards are: "<<endl;
    for(int i=0;i<player2.size();i++)
    {
        cout << "[" << player2[i].suit_name() << ", " << player2[i].rank_name() << "]";
    }
}
//use the reference to make player1 and player2 can use the same function to run the game
void gameplayer(int& option,vector<Card>& player,vector<Card>& playerpoint,vector<Card>& table,vector<Card>& plate)
{
    switch (option) {
    case 1:
        cout<<"Choose card you want to use"<<endl;
        cout<<"the card's sequence:";
        cin>>sequence;    //sequence means the card's sequence on the screen
        playerpoint.push_back(player[sequence-1]);  //store the card in graveyard you throw because you have eat this card
        for(int j=1,length=table.size() ;j<table.size();j++,length--) //length is to make the i not to over the table cards quantities
        {
            int i;
            for(i=0;i<length;i++)
            {
                if((table[i].rank()+table[i+j].rank())==player[sequence-1].rank()) //check the combine
                {
                    playerpoint.push_back(table[i]);   //store the cards in graveyard
                    playerpoint.push_back(table[i+j]); //store the cards in graveyard
                    Card change=table[i];    // change the combine two cards to the forward place and then I can pop_back after
                    table[i]=table[0];
                    table[0]=change;
                    Card change1=table[i+j];
                    table[i+j]=table[1];
                    table[1]=change1;

                    if(playerpoint[playerpoint.size()-1].rank()==table[i+j].rank()) //jump out of this loop
                        break;
                }
            }
            if(playerpoint[playerpoint.size()-1].rank()==table[i+j].rank())   //jump out of this loop
                break;
        }
        for(int i=0,n=1;i<table.size();i++)
        {
            if(table[i].rank()==playerpoint[playerpoint.size()-1].rank()||(table[i].rank()==playerpoint[playerpoint.size()-2].rank())) //check if the graveyard's bottom is one of the combine two card
            {
                table[i]=table[table.size()-1];   //if yes,then change them to the end place and pop_back them to move them from the table
                table.pop_back();
                n++;
            }
            if(n>2)  //move the first two cards out,then we can break this loop
                break;
        }
        player[sequence-1]=player[player.size()-1]; // move the card you throw to the handcard's end,then I can pop_back it from handcard
        player.pop_back();
        shownowcards();
        break;
    case 2:
        if(player1call==false)
        {
            cout<<"Choose card you want to call"<<endl;
            cout<<"the card's sequence:";
            cin>>sequence;
            cout<<"now the card you called is: "<<sequence<<endl;
            player1call=true; //to make me enter the else if loop in the next round
            table.push_back(player[sequence-1]);
            player[sequence-1]=player[player.size()-1];
            player.pop_back();
            shownowcards();
        }
        else if(player1call==true)
        {   player1call=false;  //revise it back to false then next time I can use it again
            cout<<"Choose card you want to call"<<endl;
            cout<<"the card's sequence:";
            cin>>sequence;
            playerpoint.push_back(player[sequence-1]);
            for(int i=0;i<table.size();i++)
            {
                if(table[i].rank()==player[sequence-1].rank())//find the last round card throw by player
                {
                    playerpoint.push_back(table[i]);//store the cards in graveyard
                }
                if(table[i].rank()!=player[sequence-1].rank())
                {
                    plate.push_back(table[i]);//the other cards stored to the temporary place
                }
            }
            player[sequence-1]=player[player.size()-1];
            player.pop_back();table.clear();//clean the primary table
            plate.swap(table);//store the things back from the temporary place
            plate.clear();//clean the temporary place
            for(int j=1,length=table.size();j<table.size();j++,length--)//so the following is same as combine
            {
                for(int i=0;i<length;i++)
                {
                    if((table[i].rank()+table[i+j].rank())==player[sequence-1].rank())
                    {
                        playerpoint.push_back(table[i]);
                        playerpoint.push_back(table[i+j]);
                        Card change=table[i];
                        table[i]=table[0];
                        table[0]=change;
                        Card change1=table[i+j];
                        table[i+j]=table[1];
                        table[1]=change1;
                        if(playerpoint[playerpoint.size()-1].rank()==table[i+j].rank())
                            break;
                    }
                    if(playerpoint[playerpoint.size()-1].rank()==table[i+j].rank())
                        break;
                }
            }
            for(int i=0,n=1;i<table.size();i++)
            {
                if(table[i].rank()==playerpoint[playerpoint.size()-1].rank()||(table[i].rank()==playerpoint[playerpoint.size()-2].rank()))
                {
                    table[i]=table[table.size()-1];
                    table.pop_back();
                    n++;
                }
                if(n>2)
                    break;
            }
            shownowcards();
            break;
        }
    case 3:
        cout<<"Choose card you want to pair"<<endl;
        cout<<"the card's sequence:";
        cin>>sequence;
        playerpoint.push_back(player[sequence-1]);
        for(int i=0;i<table.size();i++)
        {
            if(table[i].rank()==player[sequence-1].rank())//check if the numbers are same
            {
                playerpoint.push_back(table[i]);//store in the graveyard
            }
            if(table[i].rank()!=player[sequence-1].rank())
            {
                plate.push_back(table[i]);//the other cards stored to the temporary place
            }
        }
        player[sequence-1]=player[player.size()-1];
        player.pop_back();table.clear(); //do the same things as the case 2
        plate.swap(table);plate.clear();
        shownowcards();
        break;
    case 4:
        cout<<"Choose card you want to trail"<<endl;
        cout<<"the card's sequence:";
        cin>>sequence;
        table.push_back(player[sequence-1]); //add the handcard to the table
        player[sequence-1]=player[player.size()-1];
        player.pop_back();//move the card from handcard
        shownowcards();
        break;
    default:
        break;
        /*case 5:
        cout<<"Choose card you want to make build"<<endl;
        cout<<"the card's sequence:";
        cin>>sequence;
        table.push_back(player[sequence-1]);
        player[sequence-1]=player[player.size()-1];
        player.pop_back();
        for(int i=0;i<player.size();i++)
        {
            for(int j=0;j<table.size();j++)
            {
                if(player[i].rank()==(table[i].rank()+table[i+j].rank())
            }

        }*/
    }
}
void playoption()//show the method every round
{
    cout<<"Choose the method"<<endl;
    cout<<"1.combine"<<endl;
    cout<<"2.call"<<endl;
    cout<<"3.pair"<<endl;
    cout<<"4.Tail"<<endl;
    cout<<"5.Build(This function hasn't been designed yet,"<<endl;
    cout<<"please wait for the update version)"<<endl;
}
void check2(vector<Card>& player,vector<Card>& table)//check if player can use combine
{
    bool exam=false;
    for(int i=0;i<player.size();i++)
    {
        for(int j=0;j<table.size();j++)
        {
            if(player[i].rank()-table[j].rank()==table[table.size()-(j+1)].rank())
                exam=true;
        }
    }
    if(exam)
        cout<<"you can use combine"<<endl;
}
void check(vector<Card>& player,vector<Card>& table)//check if player can use pair
{
    bool exam=false;
    for(int i=0;i<player.size();i++)
    {
        for(int j=0;j<table.size();j++)
        {
            if(player[i].rank_name()==table[j].rank_name())
                exam=true;
        }
    }
    if(exam)
        cout<<"you can use pair"<<endl;
}
int record(vector<Card> point) //record how many scores can player get and return to the main ,pass player1point and player2point to calculate
{int score=0,spades=0;
    for(int i=0;i<point.size();i++)
    {
        if(point[i].suit()==static_cast<Card::Suit>(2)&&point[i].rank()==static_cast<Card::Rank>(10))
        {
            score=score+2;
        }
        if(point[i].suit()==static_cast<Card::Suit>(2)&&point[i].rank()==static_cast<Card::Rank>(2))
        {
            score=score+1;
        }
        if(point[i].rank()==static_cast<Card::Rank>(1))
        {
            score=score+1;
        }
        if(point[i].suit()==static_cast<Card::Suit>(4))
        {
            spades=spades+1;
        }
        if(point[i].suit()==static_cast<Card::Suit>(4)&&point[i].rank()==static_cast<Card::Rank>(2))
        {
            score=score+1;
        }
    }
    if(spades>=7)
        score=score+1;
    if(point.size()>=27)
        score=score+3;

    return score;
}
