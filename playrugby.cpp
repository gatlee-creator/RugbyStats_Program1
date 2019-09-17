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
void SearchForPlayerData(string, struct RugbyPlayer[], int); //change S to lowercase
void updatePlayerTries(int, struct RugbyPlayer[]); //we can overload this later 
void sortPlayers(struct RugbyPlayer[], int); 

int main()
{
     //10 rugby players
    const int maxPlayers = 10;
    RugbyPlayer players[maxPlayers]; 
    char menuChoice; 
    string searchName, fileName; 

    while(true){
        cout << "[A] Search for a player" << endl;
        cout << "[B] View all player stats" << endl;
        cout << "[C] Upload player data" << endl; 
        cout << "[D] Sort players by # of Tries" << endl; 
        cout << "Please enter a character to select an option:" << endl;
        cin >> menuChoice;

        
        switch (menuChoice)
        {
            case 'A':
                cout << "Enter name of player: " << endl;
                cin >> searchName;
                SearchForPlayerData(searchName, players, maxPlayers); 
                break;
            
            case 'B':
                printAllData(players, maxPlayers);
                break; 
            
            case 'C':
                cout << "Enter name of file: " << endl;
                cin >> fileName;
                readPlayerData(players, maxPlayers, fileName);
                break; 
            
            case 'D':
                cout << "[H] Highest to lowest " << endl;
                cout << "[L] Lowest to Highest " << endl;
                cin >> menuChoice; 
                if(menuChoice == 'H'){
                    sortPlayers(players, maxPlayers);
                }
                
                break;
                    
            default:
                cout << "Not a valid option..." << endl;
        }
    }

    return 0;
}

void sortPlayers(struct RugbyPlayer players[], int max){
    int i, j;
    
    for(i=0; i < max - 1; i++){
        for(j=0; j < max - i - 1; j++){
            if(players[j].tries < players[j + 1].tries){
                int temp = players[j].tries;
                players[j].tries = players[j + 1].tries;
                players[j + 1].tries = temp; 
            }
        }
    }
    
    printAllData(players, max);
}

void updatePlayerTries(int index, struct RugbyPlayer players[]){
    string answer;  
    cout << "Update player's number of tries? [Y]" << endl;
    cin >> answer; 
    
    if(answer == "Y"){
        int newNumber; 
        cout << "Enter new number: " << endl; 
        cin >> newNumber; 
        players[index].tries = newNumber;
        cout << "Updated." << endl;
    }

}

void printSingleData(int index, struct RugbyPlayer dataSet[] ){
    cout << left << setw(12)
         << "Name" << setw(15) 
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

   //cout << setw(90) << setfill('=') << '=' << endl; //print break ====
   updatePlayerTries(index, dataSet);  
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
        cout << "Player not found..." << endl;

}

void printAllData(struct RugbyPlayer players[], int max){
    cout << left << setw(12)
         << "Name" << setw(15) 
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
    if(inputFile){
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
        cout << "file read." << endl;
    }
    else{
        cout << "file not found..." << endl; 
    }
    
}