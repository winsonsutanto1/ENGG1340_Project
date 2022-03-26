# ENGG1340_Project
ENGG1340 Project ( Group 60 )


Team Members:
1. Winson Sutanto Kasman (UID:3035946095)
2. Mao Shuai Yao (UID:3035945998)



GAME - SNAKE AND LADDER

DESCRIPTION :

The minimum number of players will be 2 and maximum number of players is 4. The board will be printed and the snakes and ladders in random positions. The baord will be printed on to the screen and the players will be asked to take turns to roll dices. when a player lands on a block of board with a snake head, the players will be moved to the block which has the tail of the same snake. When a player lands on a block of board with the base of a ladder, the player will climb the ladder and land on the block which has the top of the ladder. The first player to reach the top most block of the board wins. The game will continue until there is one more person left who has not reach the top.


1. Generation of random game sets or events - The positions of snakes and ladder in the board of each game is different.

2. Data structures for storing game status - the status of the board will be saved after every player's move. Stored in an array. 

3. Dynamic memory management - 

4. File input/output (e.g., for loading/saving game status) - The players and the position the payer is in will be updated to a separate file to enable the player to save the current game status and continue it in a later date. The text in the file can be read to load the progress of the unfinished game.

5. Program codes in multiple files - storing various functions in different files. Functions like isSnakeHead(), isLadderBase(), eatenBySnake(), climbLadder() et cetera will be stored in a separate file to be used in the main program which is in a different file.
