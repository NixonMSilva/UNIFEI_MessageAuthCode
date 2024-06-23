#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cipher.h"
#include "hash.h"

#define BUFFER_SIZE 256
#define HASH_RESULT_SIZE 8

int main ()
{
    FILE *inputFile, *outputFile;
    char buffer[BUFFER_SIZE], key[BUFFER_SIZE], hashBuffer[HASH_RESULT_SIZE + 1];
    size_t bytesRead;

    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (!inputFile)
    {
        perror("Error opening input.txt\n");
        return -1;
    }

    if (!outputFile)
    {
        perror("Error opening output.txt\n");
    }

    // Read key from stdin
    printf("Insert a ciphering key (max. %d characters): ", (BUFFER_SIZE - 1));
    scanf("%[^\n]", key);

    // Reads file until EOF pointer
    while ((bytesRead = fread(buffer, sizeof(char), (BUFFER_SIZE - 1), inputFile)) > 0)
    {
        // Append end of string token onto buffer
        buffer[bytesRead] = '\0';

        // Hashes the message
        uint64_t resultHash = hashText(buffer);

        // Prints the hexadecimal hash result onto a string
        sprintf(hashBuffer, "%08x", resultHash);

        // Ciphers the Hash
        char* resultCipher;
        resultCipher = cipher(hashBuffer, key, HASH_RESULT_SIZE);

        // Prints the Result in the Output File in a Line
        fprintf(outputFile, "%s\t%s\n", buffer, resultCipher);

        free(resultCipher);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

