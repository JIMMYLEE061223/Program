#ifndef MAP_H
#define MAP_H

#include <vector>
#include <fstream>
#include <string>
#include "Square.hpp"
using namespace std;


class Map {
  private:
    enum IslandType {Beginning, Snow, Jungle, City, Beach, IslandNum};

  public:
    Map();
    ~Map();
    void LoadMap(string mapFileName = "Map.txt");
    void CheckMap();
    Square* StartSquare();

  private:
    void ReadIsland(string islandName);
    void ReadMapError();
    Square* ReadSquare();
    IslandType IslandNameToType(string islandName);
    void LinkIslandSquares(IslandType islandType);
    unsigned SquareNumOfIslane(IslandType islandType); 
    Square* SearchSquareInIslandWithID(IslandType islandType, int target_id);
    void CheckMap_(Square *current, int branch_level);


  private:
    //use 2-D vector to store the map.
    //the first dimension is the islands and the second dimension is squares 
    vector< vector<Square*> > islands_;  
    ifstream mapFile;
    
};


#endif /* end of include guard: MAP_H */

