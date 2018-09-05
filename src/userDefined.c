#include "userDefined.h"


void insertDataToMap(HTable* ht, void *data) {

	int key = ht->hashFunction(ht->size, data);
	insertData(ht, key, data);

}

int hashFunction(size_t tableSize, void* data) {

	int key = 0;
	int j = 1;
	char *word = (char*)data;
	for (int i=0; i<strlen(word); ++i) {
		key += word[i] * j;
		++j;
	}
	key = (word[0] * key) % tableSize;
	return key;
}

int compare (const void *first,const void *second) {

	char *a = (char*)first;
	char *b = (char*)second;
	
	/* returns 0 on match */
	return (strcmp(a,b));
}

void destroyNodeData(void *data) {

	char* word = (char*)data;
	free(word);
	word = NULL;

}

void printNodeData(void *toBePrinted, int index) {

	char* word = (char*)toBePrinted;
	printf("%d:%d: %s\n", index, index, word);
}

