#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userDefined.h"
#include "HashTableAPI.h"
#include "commandLine.h"

/**
*function prompts user for a valid fileName if an invalid one is given 
*/
FILE* myOpenforReading (char fileName[]) {
	FILE* fileptr; 
	char newFile[50];
	fileptr = fopen(fileName, "r");
	if (fileptr == NULL) {
		char option[20];
      	printf("Could not open file %s.\n",fileName);
      	printf("Press 1 to exit or 2 to Enter a new file name:\n");
      	scanf("%s", option);
      	getchar();
      	if (option[0] == '1') {
      		return NULL;
      	} else if (option[0] == '2') {
	      	printf("Please enter a new file name:\n");
	      	scanf("%s",newFile);
	      	getchar();
	      	fileptr = myOpenforReading(newFile);
	      	return fileptr;
      }       
   }
   
   return fileptr;
}

int main (int arg, char*argv[]) {

	const size_t TABLE_SIZE = 103;
	FILE *fptr = NULL;
	fptr = myOpenforReading( argv[1] );
	if (fptr == NULL) {
		return 0;
	}

	char *text = malloc(sizeof(char) * 46);
	char *word;

	HTable *ht = createTable(TABLE_SIZE, &hashFunction, &destroyNodeData, &printNodeData, &insertDataToMap, &compare);

	while ( fgets ( text, 46, fptr ) ) {

		removeTrailingHardReturn(text);
		word = malloc(sizeof(char) *(strlen(text) +1));
		makeLowerCase(text);
		strcpy(word,text);
		insertDataToMap(ht, word);

	}
	commandLine(ht);

	free(text);
	destroyTable(ht);
	fclose(fptr);

	return 0;

}
