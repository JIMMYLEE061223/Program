#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <fstream>
using namespace std;
int Population(int i);
int EconomicFlow(int i);
int CostFlow(int i);
void Initialdata();
void ReadParameters(ifstream&);
void Simulate();
int a,b;
double birthrate[4][4],deathrate[4][4],economicrate[4][4],livingrate[4][4];
int population1[4][4],population[4][4];
int main()
{
    int i,j,s,selection;
    bool examine;
    cout<<"Please choose one way to generate the cities population array"<<endl;
    cout<<"1.Read the file"<<endl<<"2.Generate all initial parameters randomly"<<endl;
    cin>>selection;

    switch(selection)
    {
    case 1:
    {
        ifstream inputfile;
        inputfile.open("hw6.txt");
        ReadParameters(inputfile);
        inputfile.close();
        Initialdata();
        break;
    }

    case 2:
    {
        srand(time(NULL));
        for(a=0;a<4;a++)
        {
            for(b=0;b<4;b++)
            {
                population[a][b]=(rand()%10000)+10000;
                cout<<setw(8)<<population[a][b];

            }
            cout<<endl;
        }

        Initialdata();
        break;
    }

    }
    cout<<"I can predict the city's population next year:"<<endl;
    //cin>>i;
    cout<<"if we only consider the birthrate and deathrate,the population will be:"<<endl;
    for(i = 0 ; i < 4 ; i++)
    {Population(i);}
    cout<<"if we add the economic rate to consider,the population will be:"<<endl;
    for(i=0;i<4;i++)
    {EconomicFlow(i);}
    cout<<"if we add the living cost rate to consider,the population will be:"<<endl;
    for(i=0;i<4;i++)
    {CostFlow(i);}

    cout<<"if you want to look the future for these cities,please enter y"<<endl;
    cin>>s;
    for(a=0;a<100;a++)
    {
        Simulate();
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(population1[i][j]==population[i][j])
                {
                    examine=false;
                    break;
                }
            }
            if(!examine)
                break;
        }
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(population1[i][j]<0)
                    population1[i][j]=0;
            }
        }
        if(!examine&&a!=99)
        {
            for(int i=0;i<4;i++){
                for(j=0;j<4;j++)
                {
                    population[i][j]=population1[i][j];
                }
            }
        }
        else
            break;
    }
    system("cls");
    cout<<"these are the cities' population after "<< a <<"year"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<setw(9)<<population[i][0]<<setw(9)<<population[i][1]
           <<setw(9)<<population[i][2]<<setw(9)<<population[i][3]<<endl;
    }
    cout<<"these are the cities' population after "<< a+1 <<"year"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<setw(9)<<population1[i][0]<<setw(9)<<population1[i][1]
           <<setw(9)<<population1[i][2]<<setw(9)<<population1[i][3]<<endl;
    }
    return 0;
}
void Simulate(){
    int i,j;
    for(i=0;i<4;i++){

    Population(i);
    EconomicFlow(i);
    CostFlow(i);}
}
void ReadParameters(ifstream& infile)
{

    for(a=0;a<4;a++)
    {
        for(b=0;b<4;b++)
        {
            infile>>population[a][b];
            cout<<setw(8)<<population[a][b];
        }
        cout<<endl;
    }

}

int CostFlow(int i)
{
    int  j;
    for(j=0;j<4;j++)
    {
        if(j!=3&&i!=3){
            if(livingrate[i][j]>livingrate[i][j+1])
            {
                population1[i][j]=population1[i][j]+(livingrate[i][j]-livingrate[i][j+1])*population[i][j+1];
                population1[i][j+1]=population1[i][j+1]-(livingrate[i][j]-livingrate[i][j+1])*population[i][j+1];
                //cout << "tp1: " << population1[i][j] << " " << population1[i][j+1] << " " << i << " " << j << endl;
            }
            else
            {
                population1[i][j]=population1[i][j]-(livingrate[i][j+1]-livingrate[i][j])*population[i][j];
                population1[i][j+1]=population1[i][j]+(livingrate[i][j+1]-livingrate[i][j])*population[i][j];
                //cout << "tp2: " << population1[i][j] << " " << population1[i][j+1] << " " << i << " " << j << endl;
            }
            if(livingrate[i+1][j]>livingrate[i][j])
            {
                population1[i][j]=population1[i][j]+(livingrate[i][j]-livingrate[i+1][j])*population[i+1][j];
                population1[i+1][j]=population1[i+1][j]-(livingrate[i][j]-livingrate[i+1][j])*population[i+1][j];
                //cout << "tp3: " << population1[i][j] << " " << population1[i][j+1] << " " << i << " " << j << endl;
            }
            else
            {
                population1[i+1][j]=population1[i+1][j]+(livingrate[i+1][j]-livingrate[i][j])*population[i][j];
                population1[i][j]=population1[i][j]-(livingrate[i+1][j]-livingrate[i][j])*population[i][j];
                //cout << "tp4: " << population1[i][j] << " " << population1[i][j+1] << " " << i << " " << j << endl;
            }
        }
        cout <<setw(8)<<population1[i][j];
    }
    cout<<endl;
}
int EconomicFlow(int i)
{
    int  j;

    for(j=0;j<4;j++)
    {
        if(j!=3&&i!=3){
            if(economicrate[i][j]>economicrate[i][j+1])
            {
                //cout << "OLDpopulation[" << i << "][" << j << "]=" << population1[i][j] << endl << "OLDpopulation[" << i << "][" << j+1 << "]=" << population1[i][j+1] << endl;
                population1[i][j]=population1[i][j]+(economicrate[i][j]-economicrate[i][j+1])*population[i][j+1];
                population1[i][j+1]=population1[i][j+1]-(economicrate[i][j]-economicrate[i][j+1])*population[i][j+1];
                //cout << "population[" << i << "][" << j << "]=" << population1[i][j] << endl << "population[" << i << "][" << j+1 << "]=" << population1[i][j+1] << endl << "[MOVING]:" << economicrate[i][j] << "-" << economicrate[i][j+1] << "*" << population1[i][j+1] << "=" << (economicrate[i][j]-economicrate[i][j+1])*population1[i][j+1] << endl << endl;
            }
            else
            {
                //cout << "OLDpopulation[" << i << "][" << j << "]=" << population1[i][j] << endl << "OLDpopulation[" << i << "][" << j+1 << "]=" << population1[i][j+1] << endl;
                population1[i][j+1]=population1[i][j+1]+(economicrate[i][j+1]-economicrate[i][j])*population[i][j];
                population1[i][j]=population1[i][j]-(economicrate[i][j+1]-economicrate[i][j])*population[i][j];
                //cout << "population[" << i << "][" << j << "]=" << population1[i][j] << endl << "population[" << i << "][" << j+1 << "]=" << population1[i][j+1] << endl << "[MOVING]:" << economicrate[i][j] << "-" << economicrate[i][j+1] << "*" << population1[i][j+1] << "=" << (economicrate[i][j]-economicrate[i][j+1])*population1[i][j+1] << endl << endl;
            }
            if(economicrate[i][j]>economicrate[i+1][j])
            {
                //cout << "OLDpopulation[" << i << "][" << j << "]=" << population1[i][j] << endl << "OLDpopulation[" << i+0 << "][" << j << "]=" << population1[i+1][j] << endl;
                population1[i][j]=population1[i][j]+(economicrate[i][j]-economicrate[i+1][j])*population[i+1][j];
                population1[i+1][j]=population1[i+1][j]-(economicrate[i][j]-economicrate[i+1][j])*population[i+1][j];
                //cout << "population[" << i << "][" << j << "]=" << population1[i][j] << endl << "population[" << i+1 << "][" << j << "]=" << population1[i+1][j] << endl << "[MOVING]:" << economicrate[i][j] << "-" << economicrate[i+1][j] << "*" << population1[i+1][j] << "=" << (economicrate[i][j]-economicrate[i+1][j])*population1[i+1][j] << endl << endl;
            }
            else
            {
                //cout << "OLDpopulation[" << i << "][" << j << "]=" << population1[i][j] << endl << "OLDpopulation[" << i+0 << "][" << j << "]=" << population1[i+1][j] << endl;
                population1[i+1][j]=population1[i+1][j]+(economicrate[i+1][j]-economicrate[i][j])*population[i][j];
                population1[i][j]=population1[i][j]-(economicrate[i+1][j]-economicrate[i][j])*population[i][j];
                //cout << "population[" << i << "][" << j << "]=" << population1[i][j] << endl << "population[" << i+1 << "][" << j << "]=" << population1[i+1][j] << endl << "[MOVING]:" << economicrate[i][j] << "-" << economicrate[i+1][j] << "*" << population1[i+1][j] << "=" << (economicrate[i][j]-economicrate[i+1][j])*population1[i+1][j] << endl << endl;
            }
        }
        cout <<setw(8)<<population1[i][j];
    }
    cout<<endl;

}
int Population(int i)
{
    int a;
    for(a=0;a<4;a++){
        population1[i][a]=population[i][a]+birthrate[i][a]*population[i][a]-deathrate[i][a]*population[i][a];
        cout <<setw(8)<<population1[i][a];
    }
    cout<<endl;
    //return 1//population1[a][i-1];

}

void Initialdata()
{
    cout<<"we have Birth rate,Death rate,Economic growth rate and Living cost rate:"<<endl<<"birthrate:"<<endl;
    srand(time(NULL));
    for(a=0;a<4;a++)
    {
        for(b=0;b<4;b++)
        {
            birthrate[a][b]=(rand()%100)*0.001;
            cout<<setw(8)<<birthrate[a][b];

        }
        cout<<endl;
    }
    cout<<"deathrate:"<<endl;

    for(a=0;a<4;a++)
    {
        for(b=0;b<4;b++)
        {
            deathrate[a][b]=(rand()%100)*0.001;
            cout<<setw(8)<<deathrate[a][b];

        }
        cout<<endl;
    }
    cout<<"economicrate:"<<endl;

    for(a=0;a<4;a++)
    {
        for(b=0;b<4;b++)
        {
            economicrate[a][b]=(rand()%100)*0.001;
            cout<<setw(8)<<economicrate[a][b];

        }
        cout<<endl;
    }
    cout<<"livingrate:"<<endl;

    for(a=0;a<4;a++)
    {
        for(b=0;b<4;b++)
        {
            livingrate[a][b]=(rand()%100)*0.001;
            cout<<setw(8)<<livingrate[a][b];

        }
        cout<<endl;
    }
}

