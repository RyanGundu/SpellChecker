#include "HashTableAPI.h"

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, void *data),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted, int index), void (*add) (struct HTable *hashTable, void *data), int (*compare)(const void *first,const void *second)) {


	HTable *newTable = malloc(sizeof(HTable));

	newTable->add = add;
	newTable->hashFunction = hashFunction;
	newTable->destroyData = destroyData;
	newTable->printNode = printNode;
	newTable->compare = compare;
	newTable->size = size;

	newTable->table = malloc(sizeof(Node*)*size);
	for (int i = 0; i < size; ++i) {
		newTable->table[i] = malloc(sizeof(Node));
		newTable->table[i] = NULL;
	}

	return newTable;
}


Node *createNode(int key, void *data) {

	Node *newNode = malloc(sizeof(Node));
	newNode->key = key;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void destroyTable(HTable *hashTable) {

	if (hashTable == NULL)
		return;

	Node *temp;
	for (int i = 0; i<hashTable->size;++i) {
		temp = hashTable->table[i];
		while (temp != NULL) {
			removeData(hashTable, i, temp->data);
			temp = temp->next;
		}
	}
	free(hashTable->table);
	hashTable->table = NULL;
	free(hashTable);
	hashTable = NULL;
	
}


void insertData(HTable *hashTable, int key, void *data) {

	if (hashTable == NULL || (key > hashTable->size)) 
		return;

	Node *newNode = createNode(key,data);

	if (hashTable->table[key] == NULL) {

		hashTable->table[key] = newNode;

	} else if (hashTable->table[key] != NULL) {

		Node *temp = hashTable->table[key];
		hashTable->table[key] = newNode;
		hashTable->table[key]->next = temp;

	}


	
}

void removeData(HTable *hashTable, int key, void *data) {

	Node *temp = hashTable->table[key];
	Node *temp2;

	/* if nothing at given index */
	if (hashTable->table[key] == NULL) 
		return;

	/* If first Node */
	if (hashTable->compare(data,temp->data) == 0) {
		hashTable->destroyData(temp->data);
		hashTable->table[key] = temp->next;
		free(temp);
		temp = NULL;
		return;
	}


	while (temp != NULL) {
		if (hashTable->compare(data,temp->next->data) == 0) {
			/* if in the middle of list */
			if (temp->next->next != NULL) {
				hashTable->destroyData(temp->next->data);
				temp2 = temp->next;
				temp->next = temp2->next;
				free(temp2);
				temp2 = NULL;
				break;
			/* if at the end of list */
			} else if (temp->next->next == NULL) {
				hashTable->destroyData(temp->next->data);
				free(temp->next);
				temp->next = NULL;
				break;
			}
		}
		temp = temp->next;
	}

}


void *lookupData(HTable *hashTable, int key, void *data) {

	if (key > hashTable->size)
		return NULL;

	Node *temp = hashTable->table[key];
	while (temp != NULL) {

		if (hashTable->compare(data,temp->data) == 0)
			return hashTable->table[key]->data;

		temp = temp->next;
	}

	return NULL;
}

void displayData (HTable *hashTable) {

	if (hashTable == NULL)
		return;

	int i = 0;
	Node *temp;
	while (i < hashTable->size) {
		temp = hashTable->table[i];
		while (temp != NULL) {
			hashTable->printNode(temp->data,temp->key);
			temp = temp->next;
		}
		++i;
	} 
}


