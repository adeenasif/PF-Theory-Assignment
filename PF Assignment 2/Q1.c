//Q1 of Assignment
#include<stdio.h>
int main() {
	int array[5];
	int num;
	
	for (int i = 0; i<5; i++) {  //Taking values input in array
		printf("enter element[%d]: ", i+1);
		scanf("%d", &num);
		if (num < 9999){   // checking that value is smaller than 9999
			array[i] = num;
		}
	}
	int min = array[0];
	int second = array[1];
	for (int i = 1; i < 5; i++) { //finds the minimum value in array
		if (min > array[i]){
			min = array[i];  //stores the minimum value in min
		}
	}
	
	for (int i = 0; i < 5; i++){ // finds second smallest value in array
		if(array[i] != min && second > array[i] ){  // ignoring the min value in array
			second = array[i];  //stores second smallest value in second
		}
	}
	printf("The second smallest element in the array is: %d", second);

	return 0;
}



