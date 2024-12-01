// Q7 of assignment
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int Search(char Word[6][5], char *SearchWord){  // funtion that searches the word in the array
	
	int len = strlen(SearchWord);
	
	//checks the grid horizontally
	for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 5 - len; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (Word[i][j + k] != SearchWord[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;
    	}	
	}
	
	//checks the grid vertically
	for (int i = 0; i < 6 - len; i++) {
        for (int j = 0; j < 5; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (Word[i + k][j] != SearchWord[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;  
        }
	}
    return 0;
}

int main() {
    srand(time(0)); // Seed the random character generator
	char Word[6][5];
	char SearchWord[5];
	int score = 0;
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j< 5; j++){
			char letter = 'A' + (rand() % 26); // Generate a random character
			Word[i][j] = letter;
		}
	}
	Word[5][0] = '0'; 
	Word[5][1] = '6';
	Word[5][2] = '2';
	Word[5][3] = '8';
				
    for(int i = 0; i < 6; i++){  //displays the grid
		for(int j = 0; j< 5; j++){
			printf("%c ", Word[i][j]);
		}
		printf("\n");
	}
	
	do{
		printf("Enter word to search: ");  //prompts the user to enter word to search
		scanf("%s", &SearchWord);
	 	
		 if (strcmp(SearchWord, "END") == 0) {
            break;
        }
        if(Search(Word, SearchWord)) {  // calls the function to check if the word is present
            score++;
            printf("%s is present! Score %d\n", SearchWord , score);
        }else{
            score--;
            printf("%s is not present! Score %d\n", SearchWord , score);
        }
	}while(1);
	
	printf("Final Score = %d", score);
    return 0;
}