// Q5 of assignment
#include<stdio.h>

int Histogram(int count){

	int Values[count];
	for(int i = 0; i < count; i++){  //taking input in the array
		printf("Enter value %d: ", i+1);
		scanf("%d", &Values[i]);
	}
	
    //to print the horizontal histogram
	printf("\nHorizontal Histogram: \n");
	for(int i = 0; i < count; i++){  //outer loop through rows
		printf("Value %d: ",i+1);
		for(int j = 0; j < Values[i]; j++ ){  //inner loop through cols
			printf("*");
		}
		printf("\n");
	}
	
	int maxHeight = Values[0];  // finding max height in the histogram
	for(int i = 1; i < count; i++){
		if(Values[i] > maxHeight){
			maxHeight = Values[i];
		}
	}
	
    //to print the vertical histogram
	printf("\nVertical Histogram: \n");
	for(int i = maxHeight; i > 0; i--){ //represents a single row, starting from the top
		for(int j = 0; j < count; j++){
			if (Values[j] >= i) {
	            printf("* ");
	        } else {
	            printf("  ");
	        }
		}
		printf("\n");
	}
	for (int i = 0; i< count; i++){
		printf("%d ", Values[i]);
	}
}

int main(){
	int count;
	
	printf("Enter the total number of values in the histogram: ");
	scanf("%d", &count);
	Histogram(count);
	
	return 0;
}
