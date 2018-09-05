#include "commandLine.h"

void commandLine (HTable *ht) {

	char *text = malloc(sizeof(char) * 30);	
	while (1) {
		printf("\n");
		printf("Enter an option (1,2,3,4,5)\n");
		printf("----------------------------\n");
		printf("1) Add a word to the Dictionary\n");
		printf("2) Remove a word from the Dictionary\n");
		printf("3) Spell check a file\n");
		printf("4) Show Dictionary Words\n");
		printf("5) Quit\n");
		printf("Option: ");	
		fgets (text, 10, stdin);
		removeTrailingHardReturn(text);
		if (strlen(text) > 1) {
			printf("Invalid Option\n");
		} else if (text[0] == '1') {
			addToDictionary(ht);
		} else if (text[0] == '2') {
			removeWord(ht);
		} else if (text[0] == '3') {
			spellCheckFile(ht);
		} else if (text[0] == '4') {
			displayDictionary(ht);
		} else if (text[0] == '5') {
			break;
		} else {
			printf("Invalid Option\n");
		}
	} 
	free(text);
	
}

void addToDictionary (HTable *ht) {

	char *newWord = malloc(sizeof(char) * 46);	
	printf("Enter a word to add: ");
	fgets (newWord, 46, stdin);
	removeTrailingHardReturn(newWord);
	makeLowerCase(newWord);
	if (checkWord(newWord) == -1) {
		printf("Invalid word\n");
		return;
	}
	char *word = malloc(sizeof(char) *(strlen(newWord) +1));
	strcpy(word,newWord);
	int key = ht->hashFunction(ht->size, word);
	if (strlen(word) > 0 && lookupData(ht,key,word) == NULL) {
		ht->add(ht, word);
		printf("%s has been successfully added to the Dictionary\n", word);
	} else if (strlen(word) > 0) {
		printf("The word %s already exists in the Dictionary\n", word);
	} else {
		printf("Invalid input\n");
	}
	free(newWord);

}

void displayDictionary (HTable *ht) {
	printf("\nDictionary:\n");
	printf("------------\n");
	displayData(ht);
}

void spellCheckFile (HTable *ht) {

	FILE *fptr = NULL;
	char *fileName = malloc(sizeof(char) * 30);
	printf("Enter a file to process: ");
	fgets ( fileName, 30, stdin);
	removeTrailingHardReturn(fileName);
	fptr = openFileToScan(fileName);
	if (fptr == NULL) 
		return;

	printf("\nFile processed by Spell Check %s:\n", fileName);
	printf("-------------------------------------------\n");
	char *word = malloc(sizeof(char) * 46);
	int incorrect = 0;
	int correct = 0;

	while (fgets ( word, 46, fptr)) {
		removeTrailingHardReturn(word);
		makeLowerCase(word);
		int key = ht->hashFunction(ht->size, word);
		if (lookupData(ht,key,word) == NULL) {
			printf("%s was not found in the dictionary\n", word);
			++incorrect;
		} else {
			++correct;
		}
	}
	printf("\nSummary:\n");
	printf("Correctly spelt words: %d\n", correct);
	printf("Incorrectly spelt words: %d\n\n", incorrect);
	free(fileName);
	free(word);
	fclose(fptr);

}

void removeWord (HTable *ht) {

	char *word = malloc(sizeof(char) * 30);
	printf("Enter a word to remove: ");
	fgets ( word, 30, stdin);
	removeTrailingHardReturn(word);
	makeLowerCase(word);
	int key = ht->hashFunction(ht->size, word);
	if (lookupData(ht,key,word) == NULL) {
		printf("The word %s does not exist in the Dictionary\n", word);
	} else {
		removeData(ht, key, word);
		printf("The word %s has been removed from the Dictionary\n", word);
	}
	free(word);

}

void removeTrailingHardReturn(char line[]) {

   if (line[strlen(line)-1] == '\n')
   {
      line[strlen(line)-1] = '\0';
   }
   return;
}

void makeLowerCase (char *text) {

	for (int i = 0; i<strlen(text); i++) 
		text[i] = tolower(text[i]);

}

int checkWord(char *word) {

	for(int i = 0; i<strlen(word); ++i) {
		if (isalpha(word[i]) == 0)
			return -1;
	}
	return 0;
}

FILE* openFileToScan (char fileName[]) {
	FILE* fileptr; 
	fileptr = fopen(fileName, "r");
	if (fileptr == NULL) {
      	printf("Could not open file %s\n",fileName);
      return NULL; 
   }
   return fileptr;
}




