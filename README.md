# ENGG1340_Project
ENGG1340 Project ( Group 60 )


Team Members:
1. Winson Sutanto Kasman (UID:3035946095)
2. Mao Shuai Yao (UID:3035945998)



GAME - SNEK AND LADDER

DESCRIPTION :

The minimum number of players will be 2 and maximum number of players is 4. The board will be printed and the snakes and ladders in random positions. The board will be printed on to the screen and the players will be asked to take turns to roll dices. when a player lands on a block of board with a snake head, the players will be moved to the block which has the tail of the same snake. When a player lands on a block of board with the base of a ladder, the player will climb the ladder and land on the block which has the top of the ladder. The first player to reach the top most block of the board wins. The game will continue until there is one more person left who has not reach the top. The game is played blindly, which means the ladders and snakes will not be displayed on the board, and when a player reaches a snake or ladder, a surprise message will be displayed, and the player will be moved according to the value that was saved in the memory.


1. Generation of random game sets or events - The positions of snakes and ladder in the board of each game is different.

2. Data structures for storing game status - the status of the board will be saved after every player's move. Stored in an array. 

3. Dynamic memory management - use of pointers to allocate and save the data in memory for future times.

4. File input/output (e.g., for loading/saving game status) - The players and the position the payer is in will be updated to a separate file to enable the player to save the current game status and continue it in a later date. The text in the file can be read to load the progress of the unfinished game.

5. Program codes in multiple files - storing various functions in different files. Functions like isSnakeHead(), isLadderBase(), eatenBySnake(), climbLadder() et cetera will be stored in a separate file to be used in the main program which is in a different file. [The names can be subject to change]



How to play:
1. the game will desplay a menu to ask the user whether he/she wants to start a new game or load a previously saved game
2. When a player starts a new game. he/she will be asked for the number of players in the game.
3. The players will then be asked to roll the dice in an organzied manner.
4. if a player lands on a snake or ladder, a surprise message will appear and the corresponding position the player is in will be displayed
5. A winning message will be displayed when the player reaches 100.
6. if a player chooses to not roll the dice, he/she can choose if they want to save the game or not
7. if yes, the user must name the name of the save file. Which they can then open in the future if they choose to load game (he/she must type in the name of the save file when load game).
8. When there is only one player left who havent won, the game will end and the placements will be displayed to the user.
