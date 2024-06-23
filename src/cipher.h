//
// Created by Nixon on 23/06/2024.
//

#include <stdint.h>

#ifndef TRABAUDITORIA_CIPHER_H
#define TRABAUDITORIA_CIPHER_H

char* cipher (char* plainText, char* key, uint16_t textSize);

char* decipher (char* cipheredText, char* key, uint16_t textSize);

#endif //TRABAUDITORIA_CIPHER_H
