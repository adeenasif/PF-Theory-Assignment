#include<stdio.h>
#include<stdlib.h>

struct Employee {
    int *ratings;
    int totalScore;
};

void inputEmployees(int **ratings, int numEmployees, int numPeriods){
	int rating;
	for (int i = 0; i < numEmployees; i++){
		printf("\nEnter ratings for Employee %d\n", i+1);
		for (int j = 0; j < numPeriods; j++){
			do {
                printf("Enter rating between 1-10 for period %d: ", j + 1);
                scanf("%d", &rating);
                if (rating >= 1 && rating <= 10) {
                    ratings[i][j] = rating; // Store valid rating
                } else {
                    printf("\nInvalid rating! Please try again.\n");
                }
            } while (rating < 1 || rating > 10); // Repeat until valid input
		}
	}
}

//function to display permformance for each employee
void displayPerformance(int** ratings, int numEmployees, int numPeriods){
	printf("\nEmployee Performance:\n");
	for (int i = 0; i < numEmployees; i++){
		printf("\nRatings for Employee %d\n", i+1);
		for (int j = 0; j < numPeriods; j++){
			printf("Rating for period %d: %d\n", j+1, ratings[i][j]);
		}
	}
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods){
	int index = 0;
	float highestAvg = 0.0, Avg;
	for (int i = 0; i < numEmployees; i++){
		int rating = 0;
		 
		for (int j = 0; j < numPeriods; j++){  //sums up the ratings in a period
			rating += ratings[i][j];		
		}
		Avg = (float)rating/numPeriods;  //calcs the average

		if (Avg > highestAvg){  //find the highest avg among all the periods
			highestAvg = Avg;
			index = i;  //stores the index of employee with highest avg in 'index'
		} 
	}
	return index;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods){
	int index = 0;
	float highestAvg = 0.0, Avg;
	for (int i = 0; i < numEmployees; i++){
		int rating = 0;
		 
		for (int j = 0; j < numPeriods; j++){
			rating += ratings[i][j];   //sums up the ratings in a period
		}
		Avg = (float)rating/numPeriods;  //calcs the average

		if (Avg > highestAvg){  //find the highest avg among all the periods
			highestAvg = Avg;
			index = i;  //stores the index of highest avg in 'index'
		} 
	}
	return index;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods){
	int index = 0;
	float lowestAvg = 0.0, Avg;
	for (int i = 0; i < numEmployees; i++){
		int rating = 0;
		 
		for (int j = 0; j < numPeriods; j++){
			rating += ratings[i][j];   //sums up the ratings in a period
		}
		Avg = (float)rating/numPeriods;  //calcs the average

		if (Avg < lowestAvg){  //find the lowest avg among all the periods
			lowestAvg = Avg;
			index = i;  //stores the index of employee with lowest avg in 'index'
		} 
	}
	return index;
}

int main(){
	int num, numPeriods;
	
	printf("Enter the number of employees: ");
	scanf("%d", &num);
	printf("Enter the number of periods: ");
	scanf("%d", &numPeriods);
	
	struct Employee* details = (struct Employee*)malloc(num * sizeof(struct Employee));
	
	inputEmployees(&details->ratings, num, numPeriods);
	displayPerformance(&details->ratings, num, numPeriods);
	
	int index = findEmployeeOfTheYear(&details->ratings, num, numPeriods);
	printf("\nIndex of Employee of the year: %d\n", index);
	
	int PeriodIndex = findHighestRatedPeriod(&details->ratings, num, numPeriods);
	printf("\nIndex of highest rated period: %d\n", PeriodIndex);
	
	int worst = findWorstPerformingEmployee(&details->ratings, num, numPeriods);
	printf("\nIndex of employee of worst rated period: %d\n", worst);
	
	free(details);
}

