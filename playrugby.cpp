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

void readPlayerData(struct RugbyPlayer[], int, string); 


int main()
{
     //10 rugby players
    const int maxPlayers = 10;
    RugbyPlayer players[maxPlayers]; 

      //input filename
    const string nameOfInputFile = "rugby.txt"; 


    readPlayerData(players, maxPlayers, nameOfInputFile); 

    for(int i =0; i < 10; i++)
        cout << players[i].playerName << players[i].position << players[i].tries << players[i].conversion << players[i].points << players[i].games << players[i].yellowCards <<  endl;


    return 0;
}

void readPlayerData(struct RugbyPlayer players[], int max, string fileName){
    ifstream inputFile; 
    inputFile.open(fileName);
    int incrPlayers = 0; 

    for(int i =0; i < max; i++){
         inputFile >> players[i].playerName
                   >> players[i].position
                   >> players[i].tries
                   >> players[i].conversion
                   >> players[i].points
                   >> players[i].games
                   >> players[i].yellowCards; 
    
    }
    inputFile.close(); 
}