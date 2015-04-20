#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;
int  D[1000][1000];
int find_k_ary_neighbors(int from , int hopes);
int find_d_radius_neighbors(int from , int distance);

int total_neighbors;
int visited[1000];
int NUM_CITY = 100;
int MAX_HOPS = 3;
int MAX_DISTANCE = 100;

int main()
{ 
    ifstream in_file ("highway_map");
    string line;
    int	first, second, third,total=0;
    char	c_line[1000];
    if (!in_file.is_open()) exit(-1);

    for(int m=1; m<=NUM_CITY; m++){
        for(int n=1; n<=NUM_CITY; n++){
            D[m][n] = INT_MAX;
        }
    }
    int total_link = 0;
    while ( getline (in_file,line) ){
        // cout << line << '\n';
        strcpy(c_line, line.c_str());
        sscanf(c_line, "(%d,%d,%d)", &first, &second, &third);
        printf("(%d, %d, %d)\n", first, second, third);
        D[first][second] = third;
        D[second][first] = third;
        total_link++;
    }

    // Copy D[m][n] to D[n][m]
    for(int m=1; m<=NUM_CITY; m++){
        for(int n=1; n<=NUM_CITY; n++){
            if(m!=n && m < n && D[m][n] != INT_MAX)
                D[n][m] = D[m][n];
        }
    }

    cout<<"for 3-ary neighbors:"<<endl;

    // find_out_k_ary_neighbors
    for(int from=1; from<=NUM_CITY; from++){
        find_k_ary_neighbors(from, MAX_HOPS);
        if(from==3||from==29||from==75)
        {
            cout<<"C"<<from<<" is linked to :";
            for(int a=1;a<=NUM_CITY;a++)
                if(visited[a]==1&&a!=3&&a!=29&&a!=75){
                    cout<<a<<" ";
                    total++;
                }
            cout<<endl<<"total neighbors:"<<total<<endl<<endl;
            total=0;
        }
        for(int a=1;a<=1000;a++)
        {
            visited[a]=0;
        }
    }
    cout<<"for 100 radius neighbors:"<<endl;

    // find_out_d_radius_neighbors
    for(int from=1; from<=NUM_CITY; from++){
        find_d_radius_neighbors(from, MAX_DISTANCE);
        if(from==3||from==29||from==75)
        {
            cout<<"C"<<from<<" is linked to :";
            for(int a=1;a<=NUM_CITY;a++)
                if(visited[a]==1&&a!=3&&a!=29&&a!=75){
                    cout<<a<<" ";
                    total++;
                }
            cout<<endl<<"total neighbors:"<<total<<endl<<endl;
            total=0;
        }
        for(int a=1;a<1000;a++)
        {
            visited[a]=0;
        }
    }

    return 0;
}


int  find_k_ary_neighbors(int from,int hopes)
{
    visited[from]=1;
    for(int m=1; m<=NUM_CITY; m++){
        if(D[from][m]!=INT_MAX)
        {
            visited[m]=1;
            hopes--;
            if(hopes>0){
                find_k_ary_neighbors(m,hopes);
                hopes++;
            }
        }
    }
}

int  find_d_radius_neighbors(int from ,int distance)
{
    int distance1=0;
    visited[from]=1;
    for(int m=1;m<=NUM_CITY;m++)
    {
        if(D[from][m]!=INT_MAX)
        {
            if(visited[m]==1)
            {
                continue;
            }
            else
            {
                distance1=distance-D[from][m];
            }

            if(distance1>0)
            {
                visited[m]=1;
                //cout<<distance<<endl;
                find_d_radius_neighbors(m,distance1);
                distance1=distance1+D[from][m];
            }
            else
            {
                distance1=distance1+D[from][m];
            }
        }
    }
}

