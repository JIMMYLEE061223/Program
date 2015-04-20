#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;
int  D[1000][1000]; 
int find_k_ary_neighbors(int, int);
int find_d_radius_neighbors(int, int);

int total_neighbors;
int visited[1000];
int NUM_CITY = 100;
int MAX_HOPS = 3;
int MAX_DISTANCE = 100;

int main()
{
ifstream in_file ("highway_map");
string line;
int	first, second, third;
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
  
    // find_out_k_ary_neighbors
   for(int from=1; from<=NUM_CITY; from++){
       find_k_ary_neighbors(from, MAX_HOPS);
   }

   // find_out_d_radius_neighbors
    for(int from=1; from<=NUM_CITY; from++){
       find_d_radius_neighbors(from, MAX_DISTANCE);
   }
}
