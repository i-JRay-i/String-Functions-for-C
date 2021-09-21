#include<stdio.h>
#include<stdlib.h>
/*
This program gets at mowt 1024 character sentence and
counts the number of the letter and the word. 
*/
int countWord(char *sentence){
	int numWords = 0;
	int i = 0;
	while(*(sentence+i)!='\0'){
		if(*(sentence+i+1)==' ' || *(sentence+i+1)=='\0'){
			numWords++;
		}
		i++;
	}
	return numWords;
}
int countLetter(char *sentence){
	int numLetters = 0;
	int i = 0;
	while(*(sentence+i)!='\0'){
		if(*(sentence+i) > 96 && *(sentence+i) < 123){
			numLetters++;
		}else if(*(sentence+i) > 64 && *(sentence+i) < 91){
			numLetters++;
		}
		i++;
	}
	return numLetters;
}
int main(void){
	char *entry = malloc(1024);
	printf("Enter a sentence:\n");
	scanf("%[^\n]%*c", entry);
	printf("%s\n", entry);
	printf("Number of words: %d\n",countWord(entry));
	printf("Number of letters: %d\n",countLetter(entry));
	free(entry);
	return 0;
}