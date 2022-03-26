# ENGG1340Project
# Portfolio Management Game

Group 119

Team member:
- Pan, Yen Fu (3035667209)
- Shen, Yu Jun (3035780568)

**Portfolio Management Simulation**

Game Description:

This is a elementary game about managing a portfolio. 
The player is an asset manager, who will need to invest with the money from his/her client.
The player's goal is to increase the value of portfolio as much as possible

Game Rules:

An amount of 1,000,000 cash will be assigned to the player at the beginning of the game. 
The player can buy different securities and build up their own portfolio.
This game will last for 8 rounds (1 round = 1 quarter, 4 rounds = 1 year).
The player will have a chance to buy/ sell different securities before each round begins.
The goal of this game is to increase the value of the portfolio as much as possible.
                              
Game Features:
1. The player can freely buy/ sell securities to construct his/her own portfolio.
2. The magnitude of price movements of different securities will be randomly generated each round.
3. Before each round begins, the player will received a piece of news that might reveal the possible market movement in the next round.
4. By paying a fixed amount of money, player can hire an analyst, who analyses the news for the player.
5. To give player a sense of achievement and keep track of their growth on financial understanding, there will be rank, which store the result of each game.

Coding requirement:
1. Generation of random game sets or events
   - Random number generation will be largely involved in the game: By using rand() and srand(time(NULL)), we make sure that trend of markets and the pop-up news received will be random in each game. 
2. Data structures for storing game status
   - 1D float array is believed to satisfy our demand of data structure: During the game, 1D float  array can be used to keep track of the assets of player over different rounds. The historic results of player will be recorded in 1D float  array as well.
   - A 2D double/ float array will also be included to store the prices of the securities over different rounds.
   - A 1D string array will be used to store the names of different securities.
   - A 1D user-defined struct array will be used to store the informaiton about the random evnets, including description, tips, and the movement of different securities under the event.
3. Dynamic memory management
   - In order to improve efficiency of the program, we will use dynamic memory management to allocate the arrays mentioned above with a specific size, say if the game only runs for 8 rounds, the size of the array used to store the prices is 8 only (price at the very beginning + the price after each rounds).
   - A link list is used to store the ranking of the player at the end of the game.
4. File input/output (e.g., for loading/saving game status)
   - Information about different events will be loaded from an external txt file.
   - As it will be unrealistic if the prices of different securities are randomly generated given their real price in the real life. Their latest prices are stored in an external txt file. Before the game starts, the latest prices will be read from this file. 
   - The results of the player will be output to an external file to form a ranking.
5. Program codes in multiple files
   - Most of the functions used by the main program are stored in sepatate C++ files.

Compliation and Excution Instruction:
1. Download all the file under Branches FinalVersion.
2. Open the Terminal Emulator
3. Input "make Game".
4. Input "./Game"
5. Enjoy your game!
