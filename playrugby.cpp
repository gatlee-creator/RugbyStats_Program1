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

void readPlayerData(RugbyPlayer players[], int max, string fileName); 


int main()
{
     //10 rugby players
    RugbyPlayer players[10]; 

      //input filename
    const string nameOfInputFile = "rugby.txt"; 


    readPlayerData(players, 10, nameOfInputFile); 

    for(int i = 0; i < 10; i++){
        cout << players[i].playerName << players[i].position << endl; 
    }
        


    return 0;
}

void readPlayerData(RugbyPlayer players[], int max, string fileName){
    ifstream inputFile; 
    inputFile.open(fileName);

    for(int i=0; i < max; i++){
        inputFile >> players[i].playerName >> players[i].position >> players[i].tries 
        >> players[i].conversion >> players[i].points >> players[i].games 
        >> players[i].yellowCards; 
    }

}