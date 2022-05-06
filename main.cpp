#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include "snekNLadder.h"

using namespace std;



int main(){
    int board[100];
    int numOfPlayers;
    for ( int i = 0 ; i < 100 ; i++ ){
        board[i] = i + 1;
    }

    int flag = false;
    int counter = 0;
    int temp = 0;
    int mainInput;

    Menu();
    cin >> mainInput;

    if (mainInput == 1)
    {
        string input;
        string hiddenBoard[100];
        for ( int i = 0 ; i < 100 ; i++ ){
            hiddenBoard[i] = to_string(i+1);
        }
        setUpSnake(hiddenBoard);
        setUpLadder(hiddenBoard);
        cout << "Enter the number of players (2-4): ";
        cin >> numOfPlayers;

        int *player = new int[numOfPlayers];
        for (int i = 0; i<numOfPlayers; i++)
        {
            player[i] = 1;
        }
        cout << "Board: " << endl;
        printBoard(board);
        game(numOfPlayers, player, flag, counter, input, temp, hiddenBoard);

        for (int i = 0; i < numOfPlayers; i++)
        {
            if (player[i] > 0)
            {
                player[i] == -1 * numOfPlayers;
            }
        }

        printWinner(numOfPlayers,player);
        cout << "Thank you for playing !!!" << endl;
    }
    else if(mainInput == 2)
    {
        string str;
        string input;
        string line;
        string name;
        int counter;
        int i = 0;
        string hiddenBoard[100];
        cout << "Name of the file to be open: ";
        cin >> name;
        ifstream fin(name+".txt");
        if (fin.fail())
        {
            cout << "file does not exist" << endl;
            exit(1);
        }
        while (getline(fin,line))
        {
            if (i == 0)
            {
                numOfPlayers = stoi(line);
            }
            else if (i == 1)
            {
                str = line;
            }
            else if (i == 2)
            {
                counter = stoi(line);
            }
            else if (i == 3)
            {
                istringstream iss(line);
                for (int x = 0; x<100 ; x++)
                {
                    iss >> hiddenBoard[x];
                }
            }
            i++;
        }

        int *player = new int[numOfPlayers];
        istringstream iss(str);
        for (int x = 0; x<numOfPlayers; x++)
        {
            iss >> player[x];
        }
        
        cout << "Game status from save file " << name << ".txt is successfully loaded!" << endl;
        cout << "CURRENT STANDINGS:" << endl;
        for ( int i = 0 ; i < numOfPlayers ; i++ ){
            if (player[i] > 0 ){
                cout << "Player " << i+1 << ": " << "to be determined [Position: " << player[i] << " ]" << endl;
            }else if (player[i] == -1){ 
                cout << "Player " << i+1 << ": " << player[i]*-1 << "st Place" << endl;
            }else if (player[i] == -2){
                cout << "Player " << i+1 << ": " << player[i]*-1 << "nd Place" << endl;
            }
        }
        cout << "Board: " << endl;
        printBoard(board);
        game(numOfPlayers, player, flag, counter, input, temp, hiddenBoard);

        for (int i = 0; i < numOfPlayers; i++)
        {
            if (player[i] > 0)
            {
                player[i] == -1 * numOfPlayers;
            }
        }

        printWinner(numOfPlayers,player);
        cout << "Thank you for playing !!!" << endl;


    }
    else if (mainInput == 9)
    {
        exit;
    }

    return 0;
}