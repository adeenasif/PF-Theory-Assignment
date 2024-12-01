#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int validateEmail(char* email){
	int length = strlen(email);

    // Check if the email is non-empty
    if (length == 0) {
        return 0;  // Invalid email
    }

	int count = 0, dotIndex = -1, index = -1;
	for (int i = 0; i < length; i++){
		if (email[i] == '@'){
			count++;
			index = i;  // finds the index of '@'
		}
		if (index != -1 && email[i] == '.' && i > index){
			dotIndex = i;  // finds the index of '.'
		}
	}
	
	if (count == 1 && dotIndex > index){   //returns 1 if one @ and '.' after it found
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int size;
    printf("Enter the size of the email: ");
    scanf("%d", &size);

    char *email = (char *)malloc(size * sizeof(char));  //stores the email dynamically
    
    if (email == NULL) { // Check if allocation was successful
        printf("Memory allocation failed!\n");
        return 1;
    }
    
	printf("Enter email address: ");
	scanf("%s", email);
	
	if(validateEmail(email)){
		printf("Valid Email");
	} else {
		printf("Invalid Email");
	}
	
	free(email);
}