#ifndef COMMAND
#define COMMAND

#include <ctype.h>
#include <string.h>
#include "HashTableAPI.h"

/** Function to display the menu untill and exit is requested
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
*/
void commandLine (HTable *ht);

/** Function to add a word do the existing hash table
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
*/
void addToDictionary (HTable *HT);

/** Function removes a hard return if it exists
*@param line is an array of characters
*/
void removeTrailingHardReturn(char line[]);

/** Function makes andy array of characters to lowercase
*@param array of characters to make lowercase
*/
void makeLowerCase (char *text);

/** Function displays all the data in the hash table
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
*/
void displayDictionary (HTable *ht);

/** Function checks if the words in a file exist in the dictionary
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
*/
void spellCheckFile (HTable *ht);

/** Function checks if all characters in a word a alphabitical
*@param word is the word to check
*@return returns -1 if an invalid, otherwise 0 is returned
*/
int checkWord(char *word);

/** Function opens file specified by the user
*@param fileName is the file to open
*@return a file pointer to the file opened
*/
FILE* openFileToScan (char fileName[]);

/** Function removes a specified word from the dictionary
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
*/
void removeWord (HTable *ht);



#endif

