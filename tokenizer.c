#include<stdio.h>
#include<stdlib.h>
/*
This program gets at most 1024 character long string entry and
prints its words. There is a function called tokenizer(), which
has a string array as an argument, and does all the job inside,
therefore anyone willing to use the implement the functionality
of the program can just copy and paste in their own application.
*/
void tokenize(char *sentence){
	int i = 0;int j = 0;
	char *word = malloc(32);
	do {
		if(*(sentence+i)==' '){
			*(word+j+1) = '\0';
			printf("%s\n", word);
			j = 0; i++;
			for(int k = 0; k < 32; k++){
				*(word+k) = 0;
			}
		} else if (*(sentence+i)=='.' ||  *(sentence+i)=='?' || *(sentence+i)=='!'){
			*(word+j+1) = '\0';
			printf("%s\n", word);
			j = 0; i++;
			for(int k = 0; k < 32; k++){
				*(word+k) = 0;
			}
		} else {
			*(word+j) = *(sentence+i);
			i++; j++;
		}
	} while (*(sentence+i) != '\0');
	*(word+j) = '\0';
	printf("%s\n",word);
	free(word);
}
int main(void){
	char *entry = malloc(1024);
	printf("Enter a sentence.\n");
	scanf("%[^\n]%*c",entry);
	tokenize(entry);
	free(entry);
	return 0;
}