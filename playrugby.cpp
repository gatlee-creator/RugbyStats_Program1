#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//define the data structure 
struct RugbyPlayer{
    string playerName;
    string position; 
    int tries; 
    int conversion;
    float points;
    int games;
    int yellowCards; 
};

void readPlayerData(RugbyPlayer players[], fstream& file, int max); 


int main()
{
     //10 rugby players
    RugbyPlayer players[10]; 

      //input file 
    ifstream inputFile; 
    const string nameOfInputFile = "rugby.txt"; 



    return 0;
}

void readPlayerData(RugbyPlayer players[], fstream& file, int max){
    
}