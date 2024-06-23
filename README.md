# Projeto de Criptografia e Hashing em C - SIN414

Este é um projeto simples em C para criptografar mensagens usando um algoritmo XOR e calcular hashes usando o algoritmo djb2. Ele consiste em dois programas: um para enviar mensagens criptografadas (sender) e outro para receber e validar essas mensagens (receiver).
Funcionalidades

    sender.c: Lê mensagens de um arquivo de entrada (input.txt), criptografa cada mensagem usando uma chave inserida pelo usuário, calcula o hash da mensagem criptografada e armazena a mensagem criptografada e o hash em um arquivo de saída (output.txt).

    receiver.c: Lê mensagens criptografadas e hashes de um arquivo de saída (output.txt), decifra as mensagens usando a chave correspondente inserida pelo usuário, recalcula o hash da mensagem decifrada e compara com o hash original para validar a integridade da mensagem.

## Compilação e Execução

Para compilar os programas sender e receiver, execute o seguinte comando na linha de comando:

```bash
make
```

Isso irá compilar os executáveis sender e receiver e gerar os arquivos objeto necessários.

## Enviando Mensagens Criptografadas

Antes de executar o programa, coloque o texto desejado em input.txt.

Com o input.txt contendo a mensagem desejada, execute então:

```bash
bin/sender
```

O programa solicitará uma chave de criptografia e criptografará a mensagens do arquivo input.txt, gerando um arquivo output.txt com as mensagens criptografadas e seus hashes correspondentes.

## Recebendo e Validando Mensagens

Para receber e validar as mensagens criptografadas, execute:

```bash
bin/receiver
```

O programa solicitará a mesma chave de criptografia usada para enviar as mensagens. Ele decifrará as mensagens do arquivo output.txt, calculará os hashes das mensagens decifradas e comparará com os hashes originais para validar a integridade das mensagens.

## Dependências

- Compilador GCC (ou outro compilador compatível com C)
- Sistema operacional Linux

## Autor

Nixon Moreira Silva
nixonmoreira@unifei.edu.br