#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortString(char* word) {  //sorts the words in array for comparasion
    int len = strlen(word);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (word[i] > word[j]) {  //compares the ASCII values of the characters
                char temp = word[i];  // sorts out the character (for eg: eta and ate both become aet)
                word[i] = word[j];
                word[j] = temp;
            }
        }
    }
}

void group(int num, char transactions[][100], char sorted[][100]){
    int grouped[num]; // Array to mark printed items 
	memset(grouped, 0, sizeof(grouped)); // Initialize grouped array to 0
   
    printf("[");
	for (int i = 0; i < num; i++) {
        if (grouped[i]) continue;  
        printf("['");
        printf("%s", transactions[i]); // Print original transaction
        grouped[i] = 1;  
        
        for (int j = i + 1; j < num; j++) {
            if (strcmp(sorted[i], sorted[j]) == 0) {  //if all the characters of the word match
                printf("', '%s ", transactions[j]);  //prints the word in a group
                grouped[j] = 1;  //confirms that the word has been grouped
            }
        }
        
        if (i < num - 1) {
            printf("'], "); //print comma if not the last group
        } else{
        	printf("]");  //print only the bracket if all values printed
		}
    }
    printf("]\n"); // Final output
}

int main() {
    int num;
    printf("Enter number of transactions: ");  //asks the user to enter the num of words
    scanf("%d", &num);

    char transactions[num][100];  //storing the transactions in an array
    printf("Enter each transaction:\n");
    for (int i = 0; i < num; i++) {
        scanf("%s", transactions[i]);
    }
    
    char sorted[num][100];  //stores sorted version of transactions in an array
    for (int i = 0; i < num; i++) {
        strcpy(sorted[i], transactions[i]);
        sortString(sorted[i]);
    }

    group(num, transactions, sorted);  //prints the output by grouping anagrams together

    return 0;
}
