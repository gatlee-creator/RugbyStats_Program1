#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
void printAllData(struct RugbyPlayer[], int);

int main()
{
     //10 rugby players
    const int maxPlayers = 10;
    RugbyPlayer players[maxPlayers]; 

      //input filename
    const string nameOfInputFile = "rugby.txt"; 

     //read in data from file
    readPlayerData(players, maxPlayers, nameOfInputFile); 
    printAllData(players, maxPlayers);

    return 0;
}

void printAllData(struct RugbyPlayer players[], int max){
    cout << "Name" << setw(15) 
         << "Position" << setw(12) 
         << "Tries" << setw(13) 
         << "Cov" << setw(20) 
         << "Pts/Game" << setw(10) 
         << "GS" << setw(15) 
         << "YC" << endl;  
    
    
    for(int i=0; i < max; i++){
        cout << left << setw(12) 
             << players[i].playerName << setw(15) 
             << players[i].position << setw(15)
             << players[i].tries << setw(15)  
             << players[i].conversion << setw(15)
             << players[i].points << setw(15)
             << players[i].games << setw(15)
             << players[i].yellowCards << endl; 
    }
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