#ifndef USER
#define USER

#include "HashTableAPI.h"
#include "commandLine.h"
#include <string.h>
#include <stdlib.h>

/** Function used to create a key and call insertData
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
*@param data is a generic pointer to any data type.
*/
void insertDataToMap(HTable *ht, void *data);

/** Function generates a key from a word
*@param tableSize is the size of the hash table used in algorithm
*@param data is a generic pointer to any data (to be casted and hashed)
*/
int hashFunction(size_t tableSize, void *data);

/** Function frees the data within a Node
*@param data is a generic pointer to any data type.
*/
void destroyNodeData(void *data);

/** Function prints the data within a Node
*@param toBePrinted is a generic pointer to any data type (to be casted and printed)
*@param index is the index of the data being printed
*/
void printNodeData(void *toBePrinted, int index);

/** Function used to compare data
*@param first is a generic pointer to any data type.
*@param second is a generic pointer to any data type.
*@return returns 0 if the data matches, otherwise returns a value less or grater than 0
*/
int compare (const void *first,const void *second);

#endif

