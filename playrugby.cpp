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
int SearchForPlayerData(string, struct RugbyPlayer[], int); //change S to lowercase
void updatePlayerTries(int, struct RugbyPlayer[]); //we can overload this later 
void sortPlayers(struct RugbyPlayer[], int, char); 
void swapData(struct RugbyPlayer[], int); 
void saveDataToFile(struct RugbyPlayer[], int, string); 

int main()
{
     //10 rugby players
    const int maxPlayers = 10;
    int index; 
    RugbyPlayer players[maxPlayers]; 
    char menuChoice; 
    string searchName, fileName; 

    while(true){
        cout << "[A] Upload player data" << endl;
        cout << "[B] Search for a player" << endl;
        cout << "[C] Display all player data" << endl; 
        cout << "[D] Sort players by Tries" << endl; 
        cout << "[E] Update a player Tries" << endl;
        cout << "[F] Quit" << endl; 
        cout << "Please enter a character to select an option:" << endl;
        cin >> menuChoice;

        
        switch (menuChoice)
        {
            case 'A':
                cout << "Enter name of file: " << endl;
                //cin >> fileName;
                readPlayerData(players, maxPlayers, "rugby.txt");
                
                break;
            
            case 'B':
                cout << "Enter name of player: " << endl;
                cin >> searchName;
                index = SearchForPlayerData(searchName, players, maxPlayers); 
                printSingleData(index, players);
                break; 
            
            case 'C':
                printAllData(players, maxPlayers);
                break; 
            
            case 'D':
                cout << "[H] Highest to lowest " << endl;
                cout << "[L] Lowest to Highest " << endl;
                cout << "Please enter a character to select an option:" << endl;
                cin >> menuChoice; 
                sortPlayers(players, maxPlayers, menuChoice);
                break;
            
            case 'E':
                cout << "Enter name of player: " << endl;
                cin >> searchName; 
                index = SearchForPlayerData(searchName, players, maxPlayers); 
                updatePlayerTries(index, players);
                printSingleData(index, players);
                break;
            
            case 'F':
                cout << "Save data to a file? Enter Y or press any key to quit: " << endl;
                cin >> menuChoice; 

                if(menuChoice == 'Y'){
                    //code to save to file
                    cout << "Save file as: " << endl; 
                    cin >> fileName;
                    saveDataToFile(players, maxPlayers, fileName);
                    //then exit program 
                    exit(0); 
                }
                else{
                    //exit program 
                    exit(0); 
                }
                


            default:
                cout << "Not a valid option..." << endl;
        }
    }

    return 0;
}

void saveDataToFile(struct RugbyPlayer dataSet[], int max, string fileName){
    ofstream outputFile; 
    outputFile.open(fileName);

    outputFile << left << setw(12)
         << "Name" << setw(15) 
         << "Position" << setw(15) 
         << "Tries" << setw(15) 
         << "Cov" << setw(15) 
         << "Pts/Game" << setw(15) 
         << "GS" << setw(15) 
         << "YC" << endl;

    for(int i= 0; i < max; i++){
        outputFile << left << setw(12) 
                << dataSet[i].playerName << setw(15) 
                << dataSet[i].position << setw(15)
                << dataSet[i].tries << setw(15)  
                << dataSet[i].conversion << setw(15)
                << dataSet[i].points << setw(15)
                << dataSet[i].games << setw(15)
                << dataSet[i].yellowCards << endl;   

    }
    outputFile.close(); 
    cout << "File saved." << endl; 
}

void swapData(struct RugbyPlayer players[], int j){
    RugbyPlayer temp; 
      //store in temp struct
    temp.playerName = players[j].playerName;
    temp.position = players[j].position;
    temp.tries = players[j].tries;
    temp.conversion = players[j].conversion; 
    temp.points = players[j].points;
    temp.games = players[j].games;
    temp.yellowCards = players[j].yellowCards;
      //now we write 
    players[j].playerName = players[j + 1].playerName;      
    players[j].position = players[j + 1].position;
    players[j].tries = players[j + 1].tries; 
    players[j].conversion = players[j + 1].conversion; 
    players[j].points = players[j + 1].points;
    players[j].games = players[j + 1].games; 
    players[j].yellowCards = players[j + 1].yellowCards;
      //transfer the data in temp back
    players[j + 1].playerName = temp.playerName;
    players[j + 1].position =  temp.position;
    players[j + 1].tries = temp.tries;
    players[j + 1].conversion =  temp.conversion;
    players[j + 1].points = temp.points;
    players[j + 1].games = temp.games;
    players[j + 1].yellowCards = temp.yellowCards; 

}

void sortPlayers(struct RugbyPlayer players[], int max, char sortType){
    int i, j;
    if(sortType == 'H'){
        for(i=0; i < max - 1; i++){
            for(j=0; j < max - i - 1; j++){
                if(players[j].tries < players[j + 1].tries){
                    swapData(players, j);
                }
            }
        }
    }
    else if(sortType == 'L'){
        for(i=0; i < max - 1; i++){
            for(j=0; j < max - i - 1; j++){
                if(players[j].tries > players[j + 1].tries){
                    swapData(players, j);
                }
            }
        }
    }
    else{
        cout << "Invalid sorting option..." << endl;
    }
    
    
    
    printAllData(players, max);
}

void updatePlayerTries(int index, struct RugbyPlayer players[]){
    int newNumber;
    cout << "Enter new number of tries:" << endl;
    cin >> newNumber; 
    players[index].tries = newNumber;
    cout << "Updated." << endl;

}

void printSingleData(int index, struct RugbyPlayer dataSet[] ){
    cout << left << setw(12)
         << "Name" << setw(15) 
         << "Position" << setw(15) 
         << "Tries" << setw(15) 
         << "Cov" << setw(15) 
         << "Pts/Game" << setw(15) 
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
   // updatePlayerTries(index, dataSet);  
}

int SearchForPlayerData(string searchName, struct RugbyPlayer dataSet[], int size){
    int indexFound; 
    bool isFound = false;
    for(int i = 0; i < size; i++){
        if(dataSet[i].playerName == searchName){
            indexFound = i;
            isFound = true; 
            return indexFound;
        }
    }
    if(isFound == false)
        cout << "Player not found..." << endl;

    return -1; 
}

void printAllData(struct RugbyPlayer players[], int max){
    cout << left << setw(12)
         << "Name" << setw(15) 
         << "Position" << setw(15) 
         << "Tries" << setw(15) 
         << "Cov" << setw(15) 
         << "Pts/Game" << setw(15) 
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