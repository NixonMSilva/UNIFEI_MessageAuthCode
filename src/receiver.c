//
// Created by Nixon on 23/06/2024.
//

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cipher.h"
#include "hash.h"

#define BUFFER_SIZE 256
#define HASH_RESULT_SIZE 8
#define MAX_LINE_LENGTH 270
#define MAX_TEXT_SIZE 262144

int main ()
{
    FILE *outputFile;
    int lineNumber = 0;
    char line[MAX_LINE_LENGTH], msgBuffer[BUFFER_SIZE], key[BUFFER_SIZE];
    char hashBuffer[MAX_TEXT_SIZE + 1], decipheredHash[MAX_TEXT_SIZE + 1], msgHashBuffer[MAX_TEXT_SIZE + 1];
    char fullText[MAX_TEXT_SIZE] = "";

    outputFile = fopen("output.txt", "r");

    if (!outputFile)
    {
        perror("Error opening output.txt\n");
    }

    // Read key from stdin
    printf("Insert a deciphering key (max. %d characters): ", (BUFFER_SIZE - 1));
    scanf("%[^\n]", key);

    // Reads file until EOF pointer
    while (fgets(line, MAX_LINE_LENGTH, outputFile))
    {
        // Empties the deciphered hash buffer string
        memset(decipheredHash, '\0', sizeof decipheredHash);

        if(sscanf(line, "%[^\t]\t%s\n", msgBuffer, hashBuffer) == 2)
        {
            // Deciphers the Hash
            char *decipheredHashTemp = decipher(hashBuffer, key, HASH_RESULT_SIZE);
            strcpy(decipheredHash, decipheredHashTemp);

            // Hashes the message
            uint64_t hashedMessage = hashText(msgBuffer);

            // Prints the hashed message onto a string
            sprintf(msgHashBuffer, "%08x", hashedMessage);

            // printf("%s - %08x\n", decipheredHash, hashedMessage);

            if (strcmp(decipheredHash, msgHashBuffer) != 0)
            {
                printf("Error validating hash in line no. %d!\n", (lineNumber + 1));
            }
            else
            {
                printf("Hash validated for line no. %d!\n", (lineNumber + 1));
            }

            // Appends buffer to full plain text
            strcat(fullText, msgBuffer);
        }

        lineNumber++;
    }

    // Prints the plain text
    printf("Full text:\n%s\n", fullText);

    return 1;
}