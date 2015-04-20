#include <iostream>
#include "Map.hpp"
#include "Player.hpp"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>
class opportunity_cards//simple opportunity
{
private:
    int lose100money=-100;
    int lose200money=-200;
    int lose300money=-300;
    int lose400money=-400;
    int lose500money=-500;
    int earn100money=100;
    int earn200money=200;
    int earn300money=300;
    int earn400money=400;
    int earn500money=500;
public:
    int Getlose100money(){ return lose100money;}
    int Getlose200money(){ return lose200money;}
    int Getlose300money(){ return lose300money;}
    int Getlose400money(){ return lose400money;}
    int Getlose500money(){ return lose500money;}
    int Getearn100money(){ return earn100money;}
    int Getearn200money(){ return earn200money;}
    int Getearn300money(){ return earn300money;}
    int Getearn400money(){ return earn400money;}
    int Getearn500money(){ return earn500money;}

};

using namespace std;

int rollDice() {
    return (rand()%6) + 1;
}
string jobname(int r)//random the job
{
    string buffer;
    if(r==1)
        buffer="explorer";
    else if(r==2)
        buffer="stuntDouble";
    else if(r==3)
        buffer="trapezeArtist";
    else if(r==4)
        buffer="popStar";
    else if(r==5)
        buffer="movirStar";
    else if(r==6)
        buffer="jetPilot";
    return buffer;
}

void PlayerGobackstart(Map& map, Player& player,Square *Start)//reset player to the start position
{
    player.setPosition(Start);
}

void PlayerForward(Map& map, Player& player, int numStep) {
    Square *current, *next;
    for (int i=0; i<numStep; i++) {
        current = player.Position();
        next = current->NextSquare();
        player.setPosition(next);
    }
}
void Getopportunity_cards(Player &player,int i,opportunity_cards opportunitycards);
int main() {
    int endgame=0,number;
    srand(time(NULL));
    opportunity_cards opportunitycards;
    Map map;
    cout<<"  Rules:  "<<endl;
    cout<<"1.The max number of one families is four."<<endl;
    cout<<"2.One player can only have one house and a wife."<<endl;
    cout<<"3.In this game,wife can't be computed in your property."<<endl;
    cout<<"4.When the number 6 throwed by rolldice appear over six times,then the game over."<<endl;
    cout<<"Now game start,how many players do you want to generate:"<<endl;
    cin>>number;
    vector<Player> player(number);
    //Load map from Map.txt and print first ten squares
    map.LoadMap();
    map.CheckMap();

    Square sq(Square::House, 0, "New House", 1000);//set the value of one house

    //Place player to the start square
    Square *Start = map.StartSquare();
    if (Start == NULL) {
        cerr << "Cannot find Start square in the map...." << endl;
        return 1;
    }
    for(int i=0;i<player.size();i++)
    {
        player[i].setPosition(Start);
        cout << "Player "<<i<<" is at: " <<  player[i].Position()->Description() << endl;
    }

    cout << "There are four players,all the player now has ";
    cout << player[0].ComputeTotalValue() << endl;
    cout << "random the job for the player:"<<endl;
    for(int i=0;i<player.size();i++){
        int r;
        string name;
        r=rand()%6+1;
        switch(r){
        case 1:{player[i].GetaJob(new Explorer);break;}  //get a job randomly
        case 2:{player[i].GetaJob(new StuntDouble);break;}
        case 3:{player[i].GetaJob(new TrapezeArtist);break;}
        case 4:{player[i].GetaJob(new PopStar);break;}
        case 5:{player[i].GetaJob(new MovirStar);break;}
        case 6:{player[i].GetaJob(new JetPilot);break;}
        }
        name=jobname(r); //get the name of the job
        cout<<"Player "<<i<<" is a "<<name<<endl;
    }
    cout<<endl;
    do{
        for(int i=0;i<player.size();i++){
            cout << "Player "<<i<<" is at: " <<  player[i].Position()->Description() << endl;

            //Roll a dice and make player foward
            int numStep = rollDice();
            if(numStep==6)endgame++;

            cout << "Player "<<i<<" foward " << numStep << " steps!" << endl;
            PlayerForward(map, player[i], numStep);
            cout << "Player "<<i<<" now is at: " <<  player[i].Position()->Description() << endl;

            if(player[i].Position()->Description()=="You get married with a woman!")//if the Square's Description correspond to the string,enter it and judge
            {
                if(player[i].Reportmarried().Reportmarry()!=true)//if this player haven't married before,then he can get married
                    player[i].GetMarry();
                else
                    cout<<"you have already have a wife so you can't married with another woman."<<endl;
            }
            else if(player[i].Position()->Description()=="You buy a new new house for your family.")
            {
                if(player[i].GetHouse().Getrecord()!=0)//if this player have had a house,then he can't buy the house again,but he still have to pay 1000 money
                {
                    cout<<"You have already had a house,so you give the new house to the poor man."<<endl;
                    player[i].EarnMoney(-1000);
                }
                else{
                    player[i].BuyHouse(&sq);
                    cout<<"You pay 1000 dollars to buy a house"<<endl;}
            }
            else if(player[i].Position()->Description()=="You have a baby with your wife!")
            {
                if(player[i].Reportmarried().Reportmarry()!=true)//if this player doesn't get married first,he must not have a baby
                    cout<<"sorry, you have to get married first."<<endl;
                else
                    player[i].HaveABaby();
            }
            else if(player[i].Position()->Description()=="You collect a stamp when you are traveling.")
            {
                int s=rand()%4+1;
                switch(s){
                case 1:{cout<<"you get a Stamp Snow!"<<endl;player[i].GetAStamp(Stamp::Snow);}break;
                case 2:{cout<<"you get a Stamp Jungle!"<<endl;player[i].GetAStamp(Stamp::Jungle);}break;
                case 3:{cout<<"you get a Stamp Beach!"<<endl;player[i].GetAStamp(Stamp::Beach);}break;
                case 4:{cout<<"you get a Stamp City!"<<endl;player[i].GetAStamp(Stamp::City);}break;
                }
            }
            else if(player[i].Position()->Description()=="You pick a vagrant dog back and take care of it.")
            {
                player[i].GetAPet();
            }
            else if(player[i].Position()->Description()=="Get pay!!")
            {
                cout << "Got the salary  " << player[i].GetSalary() << endl;
                player[i].EarnMoney(player[i].GetSalary());
            }
            else if(player[i].Position()->Description()=="Win Employee of the Year Award!!")
            {
                cout << "Got the Award  " << player[i].GetSalary()*3 << endl;
                player[i].EarnMoney(player[i].GetSalary()*3);
            }
            else if(player[i].Position()->Description()=="Earn a big bonus!!")
            {
                cout << "Got the bonus  " << player[i].GetSalary()*4 << endl;
                player[i].EarnMoney(player[i].GetSalary()*4);
            }
            else if(player[i].Position()->Description()=="Start up a company")
            {
                cout << "You can get " << 200 << endl;
                player[i].EarnMoney(200);
            }
            else if(player[i].Position()->Description()=="sorry, you have to go back to the start position!")
            {
                PlayerGobackstart(map, player[i],Start);//reset the player to the start position
                cout << "Player "<<i<<" is at: " <<  player[i].Position()->Description() << endl;
            }
            else if(player[i].Position()->Description()=="go to start position and get 100dollars!")
            {
                PlayerGobackstart(map, player[i],Start);
                cout << "You can get " << 100 << endl;
                player[i].EarnMoney(100);
            }
            else if(player[i].Position()->Description()=="Draw a Story Card.")
            {
                int k;
                k=rand()%10+1;
                Getopportunity_cards(player[i],k,opportunitycards);
            }
            /*if(player.Position()->Type()==Square::GetMoney){
            player.EarnMoney(player.Position()->Number());
            }*/
            player[i].ReportValues();//report the property item
            cout << "The player "<<i<<" now has ";
            cout << player[i].ComputeTotalValue() << endl;//report the total value of player's properties
            cout << endl;
        }
        //Demo other properties

        /* //Families
        player.GetMarry();
        player.HaveABaby();
        player.HaveABaby();
        player.GetAPet();
        player.GetAPet();
        cout << player.ComputeTotalValue() << endl;

        //Transport
        player.GetaVehicle(new Car);
        player.ReportValues();
        player.GetaVehicle(new Airplane);
        player.ReportValues();

        //Passport Stamp
        player.GetAStamp(Stamp::Beach);
        player.GetAStamp(Stamp::City);
        player.GetAStamp(Stamp::Snow);
        player.GetAStamp(Stamp::Jungle);
        cout << player.ComputeTotalValue() << endl;

        //House
        Square sq(Square::House, 0, "New House", 1000);
        player.BuyHouse(&sq);
        cout << player.ComputeTotalValue() << endl;

        //Get a Job
        player.GetaJob(new Explorer);
        cout << "My salary is " << player.GetSalary() << endl;

        //Education
        player.GotoCollage();
        //Switch job
        player.GetaJob(new Vet);
        cout << "My salary now is " << player.GetSalary() << endl;
        player.Promote();
        cout << "I got promoted and my salary now is " << player.GetSalary() << endl;*/
    }while(endgame<6);//When the number 6 throwed by rolldice appear over six times,then the game over.
    return 0;
}
void Getopportunity_cards(Player &player,int i,opportunity_cards opportunitycards)
{
    switch(i){
    case 1:
    {cout<<"you pay 100 dollars for building a park!"<<endl;
        player.EarnMoney(opportunitycards.Getlose100money());
        break;}
    case 2:
    {cout<<"you lose 200 dollars because you was robbed by thief!"<<endl;
        player.EarnMoney(opportunitycards.Getlose200money());
        break;}
    case 3:
    {cout<<"you submit 300 dollars for your forfeit of overspeed!"<<endl;
        player.EarnMoney(opportunitycards.Getlose300money());
        break;}
    case 4:
    {cout<<"you lose 400 dollars because your investment failed!"<<endl;
        player.EarnMoney(opportunitycards.Getlose400money());
        break;}
    case 5:
    {cout<<"you pay 500 dollars for the charities' activities!"<<endl;
        player.EarnMoney(opportunitycards.Getlose500money());
        break;}
    case 6:
    {cout<<"you find 100 dollars when you are walking on the road!"<<endl;
        player.EarnMoney(opportunitycards.Getearn100money());
        break;}
    case 7:
    {cout<<"you get 200 dollars by helping an old woman cross the road!"<<endl;
        player.EarnMoney(opportunitycards.Getearn200money());
        break;}
    case 8:
    {cout<<"you get 300 dollars because you win a prize in a invoice!"<<endl;
        player.EarnMoney(opportunitycards.Getearn300money());
        break;}
    case 9:
    {cout<<"you get 400 dollars by excavating a gold in your yard!"<<endl;
        player.EarnMoney(opportunitycards.Getearn400money());
        break;}
    case 10:
    {cout<<"you get 500 dollars because you win the lottery"<<endl;
        player.EarnMoney(opportunitycards.Getearn500money());
        break;}
    }
}
