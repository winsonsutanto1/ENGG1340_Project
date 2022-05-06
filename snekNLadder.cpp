#include "snekNLadder.h"

void printBoard(int board[100])
{

    bool flag = false;
    for (int i = 10; i>0 ; i--)
    {
        if (flag == false)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << setw(4) << board[i*10-j-1];
            }
        }
        else
        {
            for (int x = 9; x > -1; x--)
            {
                cout << setw(4) << board[i*10-x-1];
            }
        }

        cout << endl;

        if (flag == true)
        {
            flag = false;
        }
        else
        {
            flag = true;
        }

    }
}

void setUpSnake(string (&hiddenBoard)[100]){
    srand((unsigned) time(0));
    int numOfSnake = 5;
    string snakeHeads[5] = {"sh1", "sh2","sh3","sh4","sh5"};
    string snakeTails[5] = {"st1", "st2","st3","st4","st5"};
    for ( int i = 0 ; i < numOfSnake ; i++ ){
        bool flag = false;
        while( flag == false){
            int snakePos = rand()%100;
            int snakeLength = rand()%10 + 5;
            if ( snakePos - snakeLength >= 0 ){
                if ( hiddenBoard[snakePos] == to_string(snakePos + 1) && hiddenBoard[snakePos-snakeLength] == to_string(snakePos - snakeLength + 1)){
                    hiddenBoard[snakePos] =  snakeHeads[i]; 
                    hiddenBoard[snakePos-snakeLength] = snakeTails[i];
                    flag = true;
                }else{
                    continue;
                }
            }
        }
    }
}


void setUpLadder(string (&hiddenBoard)[100]){
    srand((unsigned) time(0));
    int numOfLadder = 4;
    string ladderBase[4] = {"lb1", "lb2","lb3","lb4"};
    string ladderTop[4] = {"lt1", "lt2","lt3","lt4"};
    for ( int i = 0 ; i < numOfLadder ; i++ ){
        bool flag = false;
        while( flag == false){
            int ladderPos = rand()%98 + 1;
            int ladderLength = rand()%10 + 5;
            if ( ladderPos + ladderLength < 99 ){
                if ( hiddenBoard[ladderPos] == to_string(ladderPos+1) && hiddenBoard[ladderPos + ladderLength] == to_string(ladderPos + ladderLength + 1)){
                    hiddenBoard[ladderPos] =  ladderBase[i]; 
                    hiddenBoard[ladderPos + ladderLength] = ladderTop[i];
                    flag = true;
                }else{
                    continue;
                }
            }
        }
    }
}

int numOfPlayerLeft(int numOfPlayer , int *player){
    int playersLeft = 0;
    for ( int i = 0 ; i < numOfPlayer ; i++ ){
        if (player[i] > 0 ){
            playersLeft++;
        }
    }
    return playersLeft;
}


int rollDice(){
    int totalMoves=0 , diceRoll;
    diceRoll = rand()%6 + 1;
    while(diceRoll == 6){
        totalMoves += diceRoll;
        diceRoll = rand()%6 + 1;
    }
    totalMoves+=diceRoll;
    return totalMoves;
}

void Menu()
{
    cout << "=======================SNAKE N LADDER=========================="<< endl;
    cout << "1. START NEW GAME" << endl;
    cout << "2. LOAD GAME" << endl;
    cout << "9. EXIT" << endl;
    cout << "Number Input: ";
}

void checkWinner(int numOfPlayer,int *player){
    int position = -1;
    for(int i = 0 ; i < numOfPlayer ; i++){
        if ( player[i] < 0){
            position--;
        }
    }
    for(int i = 0 ; i < numOfPlayer ; i++){
        if (player[i] >= 100){
            player[i] = position;
        }
    }
}

void printWinner(int numOfPlayer, int * player){
    int count = 0 , order = -1;
    while ( count != numOfPlayer){
        for (int i = 0 ; i < numOfPlayer ; i++ ){
            if(player[i] == order){
                if ( order == -1 ){
                    cout << "1st Place: Player " << i+1 << endl;
                    break;
                }else if ( order == -2 ){
                    cout << "2nd Place: Player " << i+1 << endl;
                    break;
                }else if ( order == -3 ){
                    cout << "3rd Place: Player " << i+1 << endl;
                    break;
                }
            }
            if (count == numOfPlayer-1){
                if (player[i] > 0){
                    cout << "Last Place: Player " << i+1 << endl;
                    break;
                }
            }
        }
        count++;
        order--;
    }
}


void checkHiddenBoard( int * player , int counter, string hiddenBoard[]){
    string snakeHeads[5] = {"sh1", "sh2","sh3","sh4","sh5"};
    string snakeTails[5] = {"st1", "st2","st3","st4","st5"};
    string ladderBase[4] = {"lb1", "lb2","lb3","lb4"};
    string ladderTop[4] = {"lt1", "lt2","lt3","lt4"};
    int destination = player[counter] ;
    bool isSnake = false;
    bool isLadder = false;
    //check if land on snake head 
    for ( int i = 0 ; i < 5 ; i++ ){
        if (hiddenBoard[player[counter]] == snakeHeads[i]){
            isSnake = true;
            for ( int j = 0 ; j < 100 ; j++ ){
                if (hiddenBoard[j] == snakeTails[i]){
                    destination = j+1;
                    break;
                }
            }
        }
    }
    //check if land on ladder base
    for ( int i = 0 ; i < 4 ; i++ ){
        if (hiddenBoard[player[counter]] == ladderBase[i]){
            isLadder = true;
            for ( int j = 99 ; j > 0 ; j--){
                if (hiddenBoard[j] == ladderTop[i]){
                    destination = j+1;
                    break;
                }
            }
        }
    }
    player[counter] = destination;
    if (isSnake == true){
        cout << "Landed on snake :( Player " << counter+1 << " is now in position " << destination << endl; 
    }else if(isLadder == true){
        cout << "Landed on Ladder :) Player " << counter+1 << " is now in position " << destination << endl;
    }
}


void game(int numOfPlayers, int *player, bool flag, int counter, string input, int temp, string hiddenBoard[])
{
    string name;
    while (numOfPlayerLeft(numOfPlayers,player) != 1)
    {
        if (counter > numOfPlayers - 1)
        {
            counter = 0;
        }

        while (player[counter] < 0)
        {
            counter += 1;
            if (counter > numOfPlayers - 1)
            {
                counter = 0;
            }
        }

        if (flag == false)
        {
            cout << "Player "<< counter+1 << ", Do you want to roll the dice? (Y/N): ";
            cin >> input;
        }

        if (input == "N" || flag == true)
        {
            cout << "Do you want to save? (Y/N): ";
            cin >> input;
            if (input == "Y")
            {
                cout << "Name your file to be saved: ";
                cin >> name;
                // saves player array, counter , and hiddenBoard
                ofstream fout(name+".txt");
                if(fout.fail()){
                    cout << "Error in file opening!" << endl;
                    exit(1);
                }
                //saves number of players (numOfPlayers) in the first line of the text file
                fout << numOfPlayers << endl;
                //saves the player array into the second line of the text file
                string line = "";
                for ( int i = 0 ; i < numOfPlayers ; i++){
                    line = line + to_string(player[i]) + " ";
                }
                fout << line << endl;
                //saves the counter to the third line of the file ( counter helps determine which player's turn is it when the user chooses to laod the file)
                fout << counter << endl;
                //saves the hiddenBoard data to the fourth line of the text file
                line = "";
                for ( int i = 0 ; i < 100 ; i++ ){
                    line = line + hiddenBoard[i] + " ";
                }
                fout << line << endl;
                fout.close();
                cout << "Game status successfully saved in " << name << ".txt !!" << endl;
                exit(1);
            }
            else if (input == "N")
            {
                break;
            }
            else
            {
                flag = true;
                cout << "Error Input, Try again" << endl;
            }
        }
        else if (input == "Y")
        {
            cout << "Rolling Dice...." << endl;
            temp = rollDice();
            cout << "Player " << counter+1 << " Got " << temp << endl;
            player[counter] += temp;
            checkHiddenBoard(player,counter,hiddenBoard);
            checkWinner(numOfPlayers,player);
            if (player[counter] < 0)
            {
                cout << "Congratulation, You Won" << endl;
            }
            else
            {
                cout << "Player " << counter+1 << "'s current position is "<< player[counter] << endl;
                counter++;
            }
        }
        else
        {
            cout << "Error Input, Try again" << endl;
        }
    }   
}