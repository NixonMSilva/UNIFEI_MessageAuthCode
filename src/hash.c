//
// Created by Nixon on 23/06/2024.
//

#include <stdint.h>

uint64_t hashText (char *str)
{
    uint64_t hashValue = 5381;
    int c;
    while ((c = (unsigned char)*str++))
    {
        hashValue = ((hashValue << 5) + hashValue) + c; // hashValue * 33 + c
    }
    return hashValue;
}
