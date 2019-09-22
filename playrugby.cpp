/*
    Name: Graham Atlee
    Course: csc1720-01
    Location of Program: ~/csc1720/Programs/program1

    This program is designed to take input data on rugby players and then 
    give the user menu options to manipulate that data. 

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//define the data structure for a rugby player
struct RugbyPlayer{
    string playerName;
    string position; 
    int tries; 
    int conversion;
    float points;
    int games;
    int yellowCards; 
};

//function prototypes
void readPlayerData(struct RugbyPlayer[], int, string); 
void printAllData(struct RugbyPlayer[], int);
void printSingleData(int, struct RugbyPlayer[]); 
int searchForPlayerData(string, struct RugbyPlayer[], int); 
void updatePlayerTries(int, struct RugbyPlayer[]); 
void sortPlayers(struct RugbyPlayer[], int, char); 
void swapData(struct RugbyPlayer[], int); 
void saveDataToFile(struct RugbyPlayer[], int, string); 
void printSeperator(int);
void printTableHeading(); 
const int maxColWidth = 15; //global var used for table column width 

int main()
{
      //declaring our data struct 
    const int maxPlayers = 10; //we will only accept 10 players for now
    RugbyPlayer players[maxPlayers]; 

      //declaring vars that will be used in menu 
    int index;
    char menuChoice; 
    string searchName, fileName; 

    while(true){
          //this is where the main menu begins 
        cout << "RUGBY TEAM MANAGER" << endl;
        printSeperator(30);
        cout << "[A] Upload player data" << endl;
        cout << "[B] Search for a player" << endl;
        cout << "[C] Display all player data" << endl; 
        cout << "[D] Sort players by tries" << endl; 
        cout << "[E] Update a player's tries" << endl;
        cout << "[F] Quit" << endl; 
        printSeperator(30);
        cout << "Please enter a character to select an option:" << endl;
        cin >> menuChoice;

        
        switch (menuChoice)
        {
              //Upload player data 
            case 'A':  
                cout << "Enter name of file: " << endl;
                cin >> fileName;
                readPlayerData(players, maxPlayers, fileName);
                break;

              //Search for a player
            case 'B': 
                cout << "Enter name of player: " << endl;
                cin >> searchName;
                index = searchForPlayerData(searchName, players, maxPlayers); 
                cout << endl;
                printSingleData(index, players);
                break; 
            
             //Display all player data 
            case 'C': 
                printAllData(players, maxPlayers);
                break; 
            
              //Sort the player data by tries 
            case 'D':
                cout << "[H] Highest to lowest " << endl;
                cout << "[L] Lowest to Highest " << endl;
                cout << "Please enter a character to select an option:" << endl;
                cin >> menuChoice; 
                sortPlayers(players, maxPlayers, menuChoice);
                break;
            
              //Update a player's tries 
            case 'E':
                cout << "Enter name of player: " << endl;
                cin >> searchName; 
                index = searchForPlayerData(searchName, players, maxPlayers); 
                updatePlayerTries(index, players);
                printSingleData(index, players);
                break;
            
              //Quit - exit the main menu/program
            case 'F':
                cout << "Save data to a file? Enter Y to save or press any key to quit: " << endl;
                cin >> menuChoice; 

                if(menuChoice == 'Y'){
                    //save the player data to file
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
                

              //default idiot proofing 
            default:
                cout << "Not a valid option..." << endl;
                cout << endl; 
        }
    }

    return 0;
}

//function to save data to a new file 
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
                << dataSet[i].playerName << setw(maxColWidth) 
                << dataSet[i].position << setw(maxColWidth)
                << dataSet[i].tries << setw(maxColWidth)  
                << dataSet[i].conversion << setw(maxColWidth)
                << dataSet[i].points << setw(maxColWidth)
                << dataSet[i].games << setw(maxColWidth)
                << dataSet[i].yellowCards << endl;   

    }
    outputFile.close(); 
    cout << "File saved." << endl; 
    cout << endl;
}

//function that swaps all the players in part of resorting 
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
      //transfer the data in temp back to next index 
    players[j + 1].playerName = temp.playerName;
    players[j + 1].position =  temp.position;
    players[j + 1].tries = temp.tries;
    players[j + 1].conversion =  temp.conversion;
    players[j + 1].points = temp.points;
    players[j + 1].games = temp.games;
    players[j + 1].yellowCards = temp.yellowCards; 

}

//function to sort players by number of tries 
void sortPlayers(struct RugbyPlayer players[], int max, char sortType){
    int i, j;
      //Bubble sort from highest to lowest 
    if(sortType == 'H'){
        for(i=0; i < max - 1; i++){
            for(j=0; j < max - i - 1; j++){
                if(players[j].tries < players[j + 1].tries){
                    swapData(players, j);
                }
            }
        }
    }
      //Bubble sort from lowest to highest 
    else if(sortType == 'L'){
        for(i=0; i < max - 1; i++){
            for(j=0; j < max - i - 1; j++){
                if(players[j].tries > players[j + 1].tries){
                    swapData(players, j);
                }
            }
        }
    }
      //Idiot proofing options
    else{
        cout << "Invalid sorting option..." << endl;
        cout << endl;
    }
    
    //after sort is comeplete we want to show the new data 
    printAllData(players, max);
}

//function to update a specific player's number of tries 
void updatePlayerTries(int index, struct RugbyPlayer players[]){
    int newNumber;
    cout << "Enter new number of tries:" << endl;
    cin >> newNumber; 
    players[index].tries = newNumber;
    cout << "Updated." << endl;
    cout << endl;

}

//function to print data about a specific player 
void printSingleData(int index, struct RugbyPlayer dataSet[] ){
    
    printTableHeading(); 

    cout << left << setw(12) 
             << dataSet[index].playerName << setw(maxColWidth) 
             << dataSet[index].position << setw(maxColWidth)
             << dataSet[index].tries << setw(maxColWidth)  
             << dataSet[index].conversion << setw(maxColWidth)
             << dataSet[index].points << setw(maxColWidth)
             << dataSet[index].games << setw(maxColWidth)
             << dataSet[index].yellowCards << endl;   

    cout << endl; //just some extra spacing (increase readability)    
}

//function that searchs for a specifc player by name 
int searchForPlayerData(string searchName, struct RugbyPlayer dataSet[], int size){
    int indexFound; 
    bool isFound = false;
     //using a simple selection search algo 
    for(int i = 0; i < size; i++){
        if(dataSet[i].playerName == searchName){
            indexFound = i;
            isFound = true; 
            return indexFound;
        }
    }
    if(isFound == false)
        cout << "Player not found..." << endl;
        cout << endl;

    return -1; 
}

//function to print all player data 
void printAllData(struct RugbyPlayer players[], int max){
    
    printTableHeading();   
    
    for(int i=0; i < max; i++){
        cout << left << setw(12) 
             << players[i].playerName << setw(maxColWidth) 
             << players[i].position << setw(maxColWidth)
             << players[i].tries << setw(maxColWidth)  
             << players[i].conversion << setw(maxColWidth)
             << players[i].points << setw(maxColWidth)
             << players[i].games << setw(maxColWidth)
             << players[i].yellowCards << endl; 
    }
    cout << endl;
}

//function to read data from a file and store it in data struct 
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
        cout << endl;
    }
    else{
        cout << "file not found..." << endl; 
        cout << endl;
    }
    
}

//function to print table heading to the console 
void printTableHeading(){
    cout << left << setw(12)
         << "Name" << setw(maxColWidth) 
         << "Position" << setw(maxColWidth) 
         << "Tries" << setw(maxColWidth) 
         << "Cov" << setw(maxColWidth) 
         << "Pts/Game" << setw(maxColWidth) 
         << "GS" << setw(maxColWidth) 
         << "YC" << endl;
}

//function to print line seperators. Increase readability in the terminal 
void printSeperator(int length){
    for(int i = 0; i < length; i++)
        cout << '=';
    cout << endl; 
}