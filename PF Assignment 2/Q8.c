// Q8 of assignment
#include<stdio.h>
#include<string.h>
#include<math.h>  //included for built-in functions like POWER

//BINARY TO DECIMAL CONVERSION
int BinToDec(int num){
	int Dec = 0, flag = 1;
	int last = 0, last2 = 0, value = 1;
	int temp = num;
	
	while(temp >0){ 
		last2 = temp%10;
		temp /= 10;
		if(last2 != 1 && last2 != 0){   //validates that the num input is binary
			flag = 0;
			break;   // exits loop if digit is any number except 1 and 0
		}
	}
	if(flag == 1){
		while(num>0){
			last = num % 10;
			num = num /10;
			Dec += (last * value);
			value *= 2;
		}
		printf("Decimal number = %d", Dec);
	}else{   //number entered is already a decimal
		printf("Invalid value entered!!!\n");
	}
}

//DECIMAL TO BINARY CONVERSION
int DecToBin(int num){
	int Bin[32], rem;
	if(num < 0){
		printf("Invalid value entered!!!\n");
	}else{
		printf("binary: ");
		int i = 0;
		while(num > 0){   //remainder on dividing the num by 2 is either 0 or 1 which is stored in the array BIN
				rem = num % 2;
				num = num / 2;
				Bin[i] = rem;
				i++;
			}
		for (int j = i - 1; j >= 0; j--){  // prints the array in reverse order as binary numbers
			printf("%d", Bin[j]);
		}
	}

}

//DECIMAL TO HEXADECIMAL CONVERSION
void DecToHexa(int num){
	int rem, i = 19;
	char Hexa[20];
	if(num < 0){
		printf("Invalid value entered!!!\n");
	}else{	
		while(num > 0 && i >= 0){	
			rem = num % 16;
			num = num / 16;
			
			if (rem == 10){  //converts the decimal value acc to their alphabet in hexa
				Hexa[i] = 'A';
			}else if (rem == 11){
				Hexa[i] = 'B';
			}else if (rem == 12){
				Hexa[i] = 'C';
			}else if (rem == 13){
				Hexa[i] = 'D';
			}else if (rem == 14){
				Hexa[i] = 'E';
			}else if (rem == 15){
				Hexa[i] = 'F';
			}else{
				Hexa[i] = rem + '0';
			}
			i--;
		}
	}		
 	printf("Hexadecimal: ");
    for (int j = i + 1; j < 20; j++){
        printf("%c", Hexa[j]);
    }
    printf("\n");
}

//HEXADECIMAL TO DECIMAL CONVERSION
void HexaToDec(char num[]){
	int numLength = strlen(num);

	for (int i = 0; i < numLength; i++){
		if (num[i] == 'A'){  //converts the hexa alphabet acc to their value in decimal 
			num[i] = 10;
		}else if (num[i] == 'B'){
			num[i] = 11;
		}else if (num[i] == 'C'){
			num[i] = 12;
		}else if (num[i] == 'D'){
			num[i] = 13;
		}else if (num[i] == 'E'){
			num[i] = 14;
		}else if (num[i] == 'F'){
			num[i] = 15;
		}else if (num[i] >= '0' && num[i] <= '9') {
            num[i] = num[i] - '0'; // converts '0' to '9' to integers 0-9
        }
	}
	int count = 0, sum = 0;
	
	for(int j = numLength-1; j >= 0; j--){  //prints the sum by multiplying nums with the power of 16 in asc order
		sum = sum +(num[j] * pow(16, count));	
		count++;
	}
	printf("Sum: %d", sum);
}

//BINARY TO HEXADECIMAL CONVERSION
void BinToHexa(int num) {
    char Hexa[20];
    int rem, count = 0, i = 0, sum = 0;

    if (num < 0) {
        printf("Invalid value entered!!\n");
    } else {
        while (num > 0) {
            rem = num % 10;
            num = num / 10;

            if (rem == 1) {
                sum += pow(2, count); // add power of 2 if binary is 1
            }

            count++;
            if (count == 4 || num == 0) { // Process remaining bits at the end
                if (sum == 10){
				Hexa[i] = 'A';  //converts the decimal value acc to their alphabet in hexa
				}else if (sum == 11){
					Hexa[i] = 'B';
				}else if (sum == 12){
					Hexa[i] = 'C';
				}else if (sum == 13){
					Hexa[i] = 'D';
				}else if (sum == 14){
					Hexa[i] = 'E';
				}else if (sum == 15){
					Hexa[i] = 'F';
				}else{
					Hexa[i] = rem + '0';
				}
                i++;
                count = 0;
                sum = 0;
            }
        }

        printf("Hexadecimal: ");
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", Hexa[j]);
        }
        printf("\n");
    }
}

//HEXADECIMAL TO BINARY CONVERSION
void HexaToBin(char Hexa[]){
	int hexaLength = strlen(Hexa);
	char Binary[hexaLength*4 +1];
	int binaryLength = 0;
	
	for(int i = 0; i < hexaLength; i++){
		int num =0;
		if (Hexa[i] == 'A'){  //converts the hexa alphabet acc to their value in decimal 
			num = 10;
		}else if (Hexa[i] == 'B'){
			num = 11;
		}else if (Hexa[i] == 'C'){
			num = 12;
		}else if (Hexa[i] == 'D'){
			num = 13;
		}else if (Hexa[i] == 'E'){
			num = 14;
		}else if (Hexa[i] == 'F'){
			num = 15;
		}else if (Hexa[i] >= '0' && Hexa[i] <= '9') {
	        num = Hexa[i] - '0'; // converts '0' to '9' to integers 0-9
		}
		for (int j = 3; j >= 0; j--) {
            Binary[binaryLength + j] = (num % 2) + '0'; // Get the binary digit
            num /= 2; // Move to the next binary digit
        }
        binaryLength += 4;
	}
	Binary[binaryLength] = '\0'; // null-terminate the binary string

    printf("Binary equivalent: %s\n", Binary);
}

//main function to prompt the user and call the function accordingly
int main() {
	int num, Choice;
	printf("1. Binary To Decimal \n");
	printf("2. Decimal To Binary \n");
	printf("3. Decimal To Hexadecimal \n");
	printf("4. Hexadecimal To Decimal \n");
	printf("5. Binary To Hexadecimal \n");
	printf("6. Hexadecimal To Binary \n");
	printf("Which conversion do you want to perform? Enter Choice: ");	
	scanf("%d", &Choice);
	if(Choice == 1){
		printf("Enter binary number: ");
		scanf("%d", &num);
		BinToDec(num);
	}else if(Choice == 2){
		printf("Enter decimal number: ");
		scanf("%d", &num);
		DecToBin(num);
	}else if(Choice == 3){
		printf("Enter decimal number: ");
		scanf("%d", &num);
		DecToHexa(num);
	}else if(Choice == 4){
		char num[20];
		printf("Enter hexa decimal number: ");
		scanf("%s", num);
		HexaToDec(num);
	}else if(Choice == 5){
		printf("Enter binary number: ");
		scanf("%d", &num);
		BinToHexa(num);
	}else if(Choice == 6){
		char Hexa[20];
		printf("Enter hexadecimal number: ");
		scanf("%s", &Hexa);
		HexaToBin(Hexa);
	}else{
		printf("invalid input!");
	}
	return 0;
}