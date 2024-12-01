#include <stdio.h>
#include<stdlib.h>
#include<conio.h>  

#define Height 5
#define Width 5

void DisplayGrid(char grid[Height][Width]){  // function to display the grid of the game
	for (int i = 0; i < Height; i++){
		for(int j = 0; j < Width; j++){
			printf("%c ",grid[i][j]);
		}
		printf("\n");
	}
}

//function for player movement
void movePlayer(char grid[Height][Width], int *playerRow, int *playerCol, char direction, int *itemsCollected) { 
    int newRow = *playerRow;
    int newCol = *playerCol;

    switch (direction) {  // to determine new position of the player P based on direction
        case 'W':
        case 'w':
            newRow--; //move up
            break;
        case 'S':
        case 's':
            newRow++; //move down
            break;
        case 'A':
        case 'a':
            newCol--; //move left
            break;
        case 'D':
        case 'd':
            newCol++; //move right
            break;
        default:
            printf("Invalid input! Use W, A, S, D to move or Q to quit.\n");
            return;
    }

    if (newRow < 0 || newRow >= 5 || newCol < 0 || newCol >= 5) {  //makes sure that the player does not move outside the grid
        printf("You can't move outside the grid!\n");
        return;
    }

    if (grid[newRow][newCol] == 'X') {  //makes sure that the player does not move on the obstacle
        printf("Obstacle ahead!\n");
        return;
    }
    
    if (grid[newRow][newCol] == 'I') {  //when the player collects an item
        printf("You found an item!\n");
        (*itemsCollected)++;  //counts the num of items collected
	
	}
	grid[*playerRow][*playerCol] = ' ';  //clears old position of the player
	grid[newRow][newCol] = 'P';  //sets new position of the player
	*playerRow = newRow;  //updates the players position
	*playerCol = newCol;
}

int main(){
	printf("Instructions: \n");
	printf("w: up, s: down, a: left, d: right, q: quit");
	
	int playerRow = 4, playerCol = 4;  //player is positioned at 4th row & 4th col of the grid
    int itemsCollected = 0;
    char move;
    
	char grid[Height][Width] = {  //initialization of the grid
	{' ',' ','I','X',' '}, 
	{' ','X',' ',' ',' '}, 
	{'I',' ','X','X',' '}, 
	{' ',' ',' ','I','X'}, 
	{' ','X',' ',' ','P'}};
	
	  while (1) {
        system("cls"); //clears the screen
        DisplayGrid(grid);  // prints the grid
        
        printf("Items collected: %d\n", itemsCollected);
        printf("Enter your move (W/A/S/D or Q to quit): ");

        move = getch();  // Get the player's move

        if (move == 'Q' || move == 'q') {  //game stops when user enters Q or q and displays the num of items collected
            printf("Thanks for playing! You collected %d items.\n", itemsCollected);
            break;
        }

        movePlayer( grid, &playerRow, &playerCol, move, &itemsCollected);
    }

    return 0;

}
