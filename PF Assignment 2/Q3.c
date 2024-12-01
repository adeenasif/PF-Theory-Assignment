//Q3 of Assignment
#include<stdio.h>
#include<string.h>

//for only one word compression
int Compress(char Word[], char NewWord[], int *RemovedCharCount){
	int WordSize = strlen(Word);
	int NewWordSize = 0;  
	int count = 0;
	
	for(int i = 0; i < WordSize; i++){  //loop until all the characters in the word are checked
		if(Word[i] == Word[i+1]){
			NewWord[NewWordSize] = Word[i];
			NewWordSize++;
			while(Word[i] == Word[i+1]){  //loop until the consecutive letters are same
				i++;
				count++;  //number of characters being removed
			}
		}else{
			NewWord[NewWordSize] = Word[i];  //storing the new word in a new array
			NewWordSize++;
		}	
	}
	NewWord[NewWordSize] = '\0';
	*RemovedCharCount += count;  // counts and stores the no.of characters removed
}

//for multiple words compression
void CompressWords(char Word[][100], int WordCount, char NewWord[][100], int *TotalRemovedChars){
    *TotalRemovedChars = 0;
    for (int i = 0; i < WordCount; i++) {   //loop until all the words in the list are checked
        Compress(Word[i],NewWord[i], TotalRemovedChars);  //calling Compress function to update the word
    }
}

int main(){
	int num;
	printf("How many words do you want to compress? ");
	scanf("%d", &num);
	getchar();
	char Word[num][100];
	
	for(int i = 0; i<num; i++){  //taking words as input
		printf("Enter word: ");
		scanf("%s", Word[i]);
	}
	char NewWord[num][100];
	int TotalRemovedChars = 0;
	
    CompressWords(Word, num, NewWord, &TotalRemovedChars); //old Word array, Number of words, New compressed Word, Total
    
    printf("\n");
    printf("Compressed Words: [");
    
    for (int i = 0; i < num; i++) {
        printf("\"%s\"", NewWord[i]);
        if (i != num - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("Total Characters Removed: %d\n", TotalRemovedChars);

	return 0;
}