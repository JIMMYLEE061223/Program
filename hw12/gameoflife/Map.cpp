//----------------
// Map Class
//----------------

#include <iostream>
#include <string>
#include "Map.hpp"

using namespace std;

Map::Map()
{
    islands_.resize(IslandNum);
}

Map::~Map()
{
    for (int i=0; i<IslandNum; i++) {
        for (int j=0; j<islands_[i].size(); i++) {
            delete islands_[i][j];
        }
    }
    mapFile.close();
}

void Map::LoadMap(string mapFileName) {
    mapFile.open(mapFileName.c_str());
    if (!mapFile) {
        cerr << "Cannot open " << mapFileName.c_str() << ".\n";
        exit(1);
    }

    string token;
    string islandName, sqType, sqDesc, sqNum;

    mapFile >> token;
    if (token != "MAP") ReadMapError();

    mapFile >> token;
    if (token != "ISLAND") ReadMapError();
    mapFile >> islandName;
    ReadIsland(islandName);
}

Map::IslandType Map::IslandNameToType(string islandName) {
    IslandType  islandType;
    if (islandName == "Beginning")   islandType = Beginning;
    else if (islandName == "Snow")   islandType = Snow;
    else if (islandName == "Jungle") islandType = Jungle;
    else if (islandName == "City")   islandType = City;
    else if (islandName == "Beach")  islandType = Beach;
    else {
        cerr << "Known island name.." << endl;
        exit(1);
    }

    return islandType;

}

Square* Map::StartSquare() {
    Square* sq = NULL;
    for (int i=0; i<islands_[Beginning].size(); i++) {
        if (islands_[Beginning][i]->Type() == Square::Start) {
            return islands_[Beginning][i];
        }
    }
    return NULL;
}

void Map::ReadIsland(string islandName) {
    IslandType islandType;
    islandType = IslandNameToType(islandName);

    while (1) {
        string token;
        mapFile >> token;
        if (token == "ISLAND_END") break;
        else if (token == "TYPE") {
            Square* sq = ReadSquare();
            islands_[islandType].push_back(sq);
        }
        else ReadMapError();
    }
    LinkIslandSquares(islandType);
}


Square* Map::ReadSquare() {
    string token, sqType_str, sqDesc;
    int sqID, sqNum, nextNum;
    Square::SquareType sqType;
    Square *sq;

    //TYPE token is read before this function called
    mapFile >> sqType_str;
    //
    //cout << "ReadSquare:\n";
    //cout << sqType_str << endl;
    if (sqType_str == "Start") sqType = Square::Start;
    else if (sqType_str == "Payday") sqType = Square::Payday;
    else if (sqType_str == "GetPromotion") sqType = Square::GetPromotion;
    else if (sqType_str == "CollegeFee") sqType = Square::CollegeFee;
    else if (sqType_str == "House") sqType = Square::House;
    else if (sqType_str == "SetSail") sqType = Square::SetSail;
    else if (sqType_str == "Exam") sqType = Square::Exam;
    else if (sqType_str == "MarriedOrCelebrate") sqType = Square::MarriedOrCelebrate;
    else if (sqType_str == "Port") sqType = Square::Port;
    else if (sqType_str == "Airport") sqType = Square::Airport;
    else if (sqType_str == "Empty") sqType = Square::Empty;
    else if (sqType_str == "GetMoney") sqType = Square::GetMoney;
    else if (sqType_str == "PayMoney") sqType = Square::PayMoney;
    else if (sqType_str == "Birthday") sqType = Square::Birthday;
    else if (sqType_str == "HaveBaby") sqType = Square::HaveBaby;
    else if (sqType_str == "SpinToWin") sqType = Square::SpinToWin;
    else if (sqType_str == "GetPet") sqType = Square::GetPet;
    else if (sqType_str == "GoToPort") sqType = Square::GoToPort;
    else ReadMapError();

    mapFile >> token;
    if (token != "ID") ReadMapError();
    mapFile >> sqID;
    //cout << token << ": " << sqID << endl;

    mapFile >> token;
    if (token != "DESC") ReadMapError();
    mapFile.ignore();
    getline(mapFile, sqDesc);
    //cout << "sqDesc: " << sqDesc << endl;

    mapFile >> token;
    if (token != "NUM") ReadMapError();
    mapFile >> sqNum;
    //cout << "sqNum: " << sqNum << endl;

    mapFile >> token;
    if (token != "NEXT") ReadMapError();
    mapFile >> nextNum;
    //cout << "nextNum: " << nextNum << endl << endl;

    sq = new Square(sqType, sqID, sqDesc, sqNum);
    for (int i = 0; i < nextNum; i++) {
        int nextID;
        mapFile >> nextID;
        sq->AddNextID(nextID);
    }

    return sq;
}

void Map::ReadMapError() {
    cerr << "Wrong map format.\n";
    exit(1);
}

Square* Map::SearchSquareInIslandWithID(IslandType islandType, int target_id) {
    Square* sq = NULL;
    for (int i=0; i<islands_[islandType].size(); i++) {
        if (islands_[islandType][i]->ID() == target_id) {
            sq = islands_[islandType][i];
            break;
        }
    }
    return sq;
}

void Map::LinkIslandSquares(IslandType islandType) {
    for (int i=0; i<islands_[islandType].size(); i++) {
        for (int j=0; j<islands_[islandType][i]->BranchNum(); j++) {
            int next_id = islands_[islandType][i]->NextID(j);
            Square* next_sq = SearchSquareInIslandWithID(islandType, next_id);
            if (next_sq != NULL) {
                islands_[islandType][i]->AddNextSquare(next_sq);

            }
        }
    }

}

void Map::CheckMap() {
    CheckMap_(islands_[0][0], 0);
}

void Map::CheckMap_(Square *current, int branch_level) {

    for (int i=0; i<branch_level; i++) cout << "  ";
    cout << "Description: " << current->Description() << endl;
    for (int i=0; i<branch_level; i++) cout << "  ";
    cout << "ID: " << current->ID() << endl;
    cout << "Next ID: ";
    for (int j = 0; j < current->BranchNum(); j++) {
        cout << current->NextID(j) << " ";
    }
    cout << endl;
    for (int j = 0; j < current->BranchNum(); j++) {
        if(current->NextSquare(j)->Type()!=Square::Start) {
            if (current->BranchNum() > 1)
                CheckMap_(current->NextSquare(j), branch_level+1);
            else
                CheckMap_(current->NextSquare(j), branch_level);
        }
    }

}

unsigned Map::SquareNumOfIslane(IslandType islandType) {
    return islands_[islandType].size();
}
