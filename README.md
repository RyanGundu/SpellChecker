# SpellChecker

Program Description

- This program reads a provided dictionary of words and stores it in a hash table for quick access. It can be used to scan user provided files and check for spelling based on the words contained in the dictionary file.

Additional Features

- The program will not let you input a word with any spaces or non alpha characters 

Hash Function and Resolution Strategy

- My hash function performs these 3 steps to hash data
- Consider the word "test"

Step 1: (1)'t' + (2)'e' + (3)'s' + (4)'t'
- each characters ASCII value is multiplied by its index + 1 
- Accounts for order "abc" and "bca" would generate different keys

Step 2: (step1 value)'t'
- it then multiplies the value created in step one by the ASCII value of the first character, which a word will always have.
- This step allows 2 letter words to have different indexes, for example "hi" and "ih" would be multiplied by 'h' and 'i' respectively

Step 3: (step 2) % (table_size)
- The final step to generate the key takes the value created in step 2 mod the table size. This is to assure that the final value falls within the range of the table size.

- In addition the table size used was 103. This is because the maximum data was said to be roughly 100. Also, by using an odd prime number you are limiting the number of repeating values which is important when hashing data.


- To handle collision, I used the separate chaining method 
- Although this may increase the complexity in some cases, if the data size increases, it contains more open room in the table compared to other methods


To run the program
##################
- To run the test main run "make" , and then "make runTest" , this runs the 
line "./bin/runTest"

- To run the main run "make" and then "make run" , this will run 
the line "./bin/runMe dictionary.txt" which includes the name of the file it reads
