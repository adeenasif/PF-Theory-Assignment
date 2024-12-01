#include<stdio.h>
#include<string.h>

struct Player{
	int ballScores[12];
	char playerName[20];
	int totalScore;
};

 //makes sure the score is b/w 0-6 else marks them as 0
void validateScore(int *score){ 
	if (*score < 0 || *score > 6){
		*score = 0;
	}
}

void playGame(struct Player *player){
	for (int j = 0; j < 12; j++){
		printf("Enter score of ball %d: ", j+1);
		scanf("%d", &player->ballScores[j]);  //stores each score in the array in the struture
		validateScore(&player->ballScores[j]);
	}
}

void findWinner(struct Player *player1, struct Player *player2){
	for (int i = 0; i < 12; i++){
		player1->totalScore += player1->ballScores[i];  //calculates total score of player 1
	}
	for (int i = 0; i < 12; i++){
		player2->totalScore += player2->ballScores[i];  //calculates total score of player 2
	}
	if (player1->totalScore > player2->totalScore){  //compares total scores to find winner
		printf("\nPLAYER 1 WON!!\n");
	} else if (player1->totalScore < player2->totalScore){
		printf("\nPLAYER 2 WON!!\n");
	} else{
		printf("\nIT IS A DRAW!!\n");
	}
}

void displayMatchScoreboard(struct Player player1, struct Player player2){
	float avg1 = (float)player1.totalScore/12.0;  //calculates average score for player 1
	float avg2 = (float)player2.totalScore/12.0;  //calculates average score for player 2
	
    //prints details of player 1
	printf("\n\nDetails of Player 1\n");
	printf("Name: %s\n", player1.playerName);
	printf("Total Score: %d\n", player1.totalScore);
	printf("Average score: %.2f", avg1);
	printf("Scores of each ball: \n");
	for (int i = 0; i < 12; i++){
		printf("%d  ", player1.ballScores[i]);
	}

    //prints details of player 2
	printf("\n\nDetails of Player 2\n");
	printf("Name: %s\n", player2.playerName);
	printf("Total Score: %d\n", player2.totalScore);
	printf("Average score: %.2f", avg2);
	printf("Scores of each ball: \n");
	for (int i = 0; i < 12; i++){
		printf("%d  ", player2.ballScores[i]);
	}
	
}

int main(){
	struct Player player1;
	struct Player player2;

	printf("Enter player 1 name: ");
	scanf("%s", player1.playerName);
	printf("Enter player 2 name: ");
	scanf("%s", player2.playerName);

	printf("Enter score for player 1\n");
	playGame(&player1);  
	printf("\nEnter score for player 2\n");
	playGame(&player2);

	findWinner(&player1, &player2);
	displayMatchScoreboard(player1, player2);
	
	return 0;
}