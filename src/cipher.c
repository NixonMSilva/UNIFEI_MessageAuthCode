//
// Created by Nixon on 23/06/2024.
//

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "cipher.h"

#define BUFFER_SIZE 256

char* cipher (char* plainText, char* key, uint16_t textSize)
{
    char* cipheredText = (char*)malloc(textSize + 1);;

    if (!cipheredText)
    {
        return NULL;
    }

    for (uint16_t i = 0; i < textSize; ++i)
    {
        cipheredText[i] = plainText[i] ^ key[i % strlen(key)];
        if (cipheredText[i] < 0x20 || cipheredText[i] > 0x7E)
        {
            cipheredText[i] = (cipheredText[i] % (0x7E - 0x20 + 1)) + 0x20;
        }
    }

    cipheredText[textSize] = '\0';

    return cipheredText;
}

char* decipher (char* cipheredText, char* key, uint16_t textSize)
{
    cipher(cipheredText, key, textSize);
}