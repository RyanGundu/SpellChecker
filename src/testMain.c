#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userDefined.h"
#include "HashTableAPI.h"
#include "commandLine.h"

int main (int arg, char*argv[]) {

	const size_t TABLE_SIZE = 103;

	HTable *ht = createTable(TABLE_SIZE, &hashFunction, &destroyNodeData, &printNodeData, &insertDataToMap, &compare);
	HTable *testTable = NULL;

	/* NOTE: a few cases use the wrapper function to call insert data which also calls the hashfunction */
	/* regular case */
	/* consider that the malloc needs do be done because destroyTable frees the data */
	char *word = malloc(sizeof(char) * 6);
	strcpy(word,"hello");
	insertDataToMap(ht, word);
	printf("Expected Output: 72:72: hello\n");
	printf("Actual Output: ");
	displayData(ht);

	/* Checks if look up data can actually locate existing data */
	printf("\n");
	printf("Expected Output (When looking for data): 72:72: hello\n");
	printf("Actual Output: ");
	ht->printNode(lookupData(ht, 72, word), 72);
	/* considering it did not return Null, the data was found */

	/* Tests collision handling */
	/* Although "hey" does not generate 72 we will assume it does for the test */
	word = malloc(sizeof(char) * 4);
	strcpy(word,"hey");
	insertData(ht,72, word);
	printf("\n");
	printf("Expected Output (With collision): 72:72: hey\n");
	printf("Actual Output: \n");
	displayData(ht);

	/* tests the remove function */
	printf("\n");
	removeData(ht, 72, word);
	printf("Expected Output (After removing \"hey\"): 72:72 hello\n");
	printf("Actual Output: ");
	displayData(ht);
	printf("\n");



	/* sends an int as the data */
	// int x = 12;
	// insertDataToMap(ht, &x);
	/* causes segfault as the hashfunction only manages strings */


	/* sends an empty string */
	word = malloc(sizeof(char) * 6);
	strcpy(word,"");
	printf("\n");
	insertDataToMap(ht, word);
	printf("Expected Output: 0:0: \n");
	printf("Actual Output: \n");
	displayData(ht);

	word = malloc(sizeof(char) * 14);
	strcpy(word,"testNullTable");
	/* Trys to send an un initialized table to insertData */
	/* and then print a NULL table */
	insertData(testTable,0, word);
	displayData(testTable);
	/*expected to print nothing */
	/* Success */


	/* tests the detroy table function */
	destroyTable(ht);
	//displayData(ht);
	/* attempts to print the table after freeing it leading to a segfault */
	/* this proves the table has been freed */
	printf("\n");


	return 0;

}
