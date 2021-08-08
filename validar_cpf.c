#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define CPF_TAM 11

bool receber_cpf(int arr[]);

int main(void) {
    int digitos[CPF_TAM];

    printf("Insira seu CPF: ");
    if (receber_cpf(digitos)) {
        printf("CPF armazenado com sucesso.\n");
    } else {
        printf("CPF invalido.\n");
    }

    return 0;
}

// Recebe e valida CPF, pontuação opcional
bool receber_cpf(int arr[]) {
    const int tamanho = 11;
    int primeiro, segundo, anterior, soma, *p = arr;
    char c;

    while ((c = getchar()) != '\n') {
        if (p >= &arr[tamanho]) {   // Mais de 11 dígitos inseridos
            return false;
        }

        if (isdigit(c)) {   // Armazenar dígito atual
            *p++ = c - '0';
        }
    }

    // Número correto de dígitos após coleta.
    if (p != &arr[tamanho]) {
        return false;
    }
    
    primeiro = arr[tamanho-2];
    segundo = arr[tamanho-1];

    // Validar primeiro dígito
    soma = 0;
    p = arr;
    for (int i = 10; i >= 2; i--) {
        soma += (*p * i);
        p++;
    }

    if ((((soma * 10) % 11) % 10) != primeiro) { 
        return false;
    }

    // Validar segundo dígito
    soma = 0;
    p = arr;
    for (int i = 11; i >= 2; i--) {
        soma += (*p * i);
        p++;
    }

    if ((((soma * 10) % 11) % 10) != segundo) {
        return false;
    }

    // Checar se todos os algarismos são iguais
    for (int i = 0, anterior = arr[0]; i < tamanho; i++) {
        if (anterior != arr[i]) {
            return true;
        }
        anterior = arr[i];
    }

    return false;
}