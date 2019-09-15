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
    //Add a print all function?
};

void readPlayerData(struct RugbyPlayer[], int, string); 
void printAllData(struct RugbyPlayer[], int);
void printSingleData(int, struct RugbyPlayer[]); 
void SearchForPlayerData(string, struct RugbyPlayer[], int);

int main()
{
     //10 rugby players
    const int maxPlayers = 10;
    RugbyPlayer players[maxPlayers]; 

      //input filename
    const string nameOfInputFile = "rugby.txt"; 

     //read in data from file
    readPlayerData(players, maxPlayers, nameOfInputFile); 
    //printAllData(players, maxPlayers);
    SearchForPlayerData("Jones", players, maxPlayers);

    return 0;
}

void printSingleData(int index, struct RugbyPlayer dataSet[] ){
    cout << "Name" << setw(15) 
         << "Position" << setw(12) 
         << "Tries" << setw(13) 
         << "Cov" << setw(20) 
         << "Pts/Game" << setw(10) 
         << "GS" << setw(15) 
         << "YC" << endl;

    cout << left << setw(12) 
             << dataSet[index].playerName << setw(15) 
             << dataSet[index].position << setw(15)
             << dataSet[index].tries << setw(15)  
             << dataSet[index].conversion << setw(15)
             << dataSet[index].points << setw(15)
             << dataSet[index].games << setw(15)
             << dataSet[index].yellowCards << endl;   
    
}

void SearchForPlayerData(string searchName, struct RugbyPlayer dataSet[], int size){
    int indexFound; 
    bool isFound = false;
    for(int i = 0; i < size; i++){
        if(dataSet[i].playerName == searchName){
            indexFound = i;
            isFound = true; 
            printSingleData(indexFound, dataSet); 
        }
    }
    if(isFound == false)
        cout << "Player not found...";

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