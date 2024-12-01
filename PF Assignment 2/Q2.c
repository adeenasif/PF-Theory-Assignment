//Q2 of Assignment
#include<stdio.h>
#include<string.h>

int Frequency(char Slogan[]){
	int SloganSize = strlen(Slogan);
	int done[SloganSize];	// checks if the character has already been counted
	int SloganCount[SloganSize];
	
	printf("For %s:  \n", Slogan);
	printf("{");
	
	for(int i = 0 ; i< SloganSize; i++){ 
		if(done[i] != 1){
			int Count = 0;
			char First = Slogan[i];
			for(int j = 0; j < SloganSize; j++){    //nested loop for comparasion
				if(First == Slogan[j]){    // to check if the characters are same
					Count++;   //increament count if character is repeated
					done[j] = 1;
				}
				SloganCount[i] = Count;  // storing the count in new array
			}
			
			if(i == SloganSize-1){  // checking if end of array reached so that no comma is added at the end
				printf("'%c': %d", First, SloganCount[i]);
			}else{
				printf("'%c': %d, ", First, SloganCount[i]);
			}
		}
	}	
	printf("} \n");
}

int main() {
    char Slogan[100];
    int numSlogans;
    
    printf("Enter the number of slogans: ");
    scanf("%d", &numSlogans);
    getchar(); //clear newline character left by scanf
    
    for (int i = 0; i < numSlogans; i++) {
        printf("Enter the slogan: ");
        fgets(Slogan, sizeof(Slogan), stdin);  //reads the slogan into Slogan Array
        
        Slogan[strcspn(Slogan, "\n")] = '\0';  //replace '\n' with '\0' if found
        Frequency(Slogan); // Call the function
    }
    
    return 0;
}