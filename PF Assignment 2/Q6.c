//Q6 of assignment
#include<stdio.h>

int Game(int num){
	int rem = num % 5; 
	if(rem == 0){ // if N is a multiple of 5, A can't win, returns -1
		return -1;
	}
		
	return rem;  // returns the num of matchsticks A need to pick to win
}

int main(){
	int num;
	printf("Enter number of matchsticks: ");
	scanf("%d", &num);

	int result = Game(num);  // calls the function 

	if (result == -1){  
		printf("It is not possible for player A to win!");
	}else{
		printf("Player A can win the game by picking up %d matchsticks on first turn!", result);
	}
	return 0;
}