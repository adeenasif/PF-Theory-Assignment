#include <stdio.h>
#include <string.h>

struct Employee{  
	int employeeCode;
	char employeeName[30];
	char dateOfJoining[3];
};

void assignData(struct Employee info[]){
	for (int i = 0; i < 2; i++){
		printf("Enter data for Employee [%d]\n", i+1);
		printf("Enter employee code: ");
		scanf("%d", &info[i].employeeCode);
		getchar();
		
		printf("Enter employee name: ");
		fgets(info[i].employeeName, 30, stdin);
		info[i].employeeName[strcspn(info[i].employeeName, "\n")] = '\0';
		
		printf("Enter date of joining: (XX YY ZZZZ) "); //stores date/month/year in different indexes of array
		scanf("%d %d %d", &info[i].dateOfJoining[0], &info[i].dateOfJoining[1], &info[i].dateOfJoining[2])	;
		getchar();
	}
}

void calcTenure(struct Employee info[]){
	char currDate[3];
	int tenure;
	printf("Enter current date: (XX YY ZZZZ)");
	scanf("%d %d %d", &currDate[0], &currDate[1], &currDate[2]);
	
	for (int i = 0; i < 2; i++){
		tenure = currDate[2] - info[i].dateOfJoining[2]; 
		
	    // Adjust tenure for incomplete years 
		//(subtract 1yr from calculated tenure if currDate hasn’t reached joining date in the curr year)
	    if (currDate[1] < info[i].dateOfJoining[1] || 
		(currDate[1] == info[i].dateOfJoining[1] && currDate[0] < info[i].dateOfJoining[0])) {
	        tenure--;
	    }

		if (tenure > 3){  //printing in loop all the employees that have a tenure greater then 3yrs
			printf("Employee with tenure greater then 3 years:\n");
			printf("Code: %d\n", info[i].employeeCode);
			printf("Name: %s\n", info[i].employeeName);
			printf("Tenure: %d\n", tenure);
		} 
	}
}

int main(){
	struct Employee info[2];
	assignData(info);
	calcTenure(info);
	return 0;
}