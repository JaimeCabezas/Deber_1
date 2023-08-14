#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Para la funcion kbhit() y getch() en Windows

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h> // Para sistemas UNIX
#endif


void PrimeLetraMayus(char *text);
void trasfMinus(char *text);
void ConvertiraMayus(char *text);
double calcularPotencia(double,int);
int dividirConRestas(int,int);
void clearScreen();
void moveText(char[],int);
void animateText(char[],int,int);


void PrimeLetraMayus(char *text1) {
    int i = 0;
    int palabra = 1;

    while (text1[i] != '\0') {
        if ((text1[i] >= 'a' && text1[i] <= 'z') || (text1[i] >= 'A' && text1[i] <= 'Z')) {
            if (palabra) {
                if (text1[i] >= 'a' && text1[i] <= 'z') {
                    text1[i] = text1[i] - ('a' - 'A');
                }
                palabra = 0;
            } else {
                if (text1[i] >= 'A' && text1[i] <= 'Z') {
                    text1[i] = text1[i] + ('a' - 'A');
                }
            }
        } else if (text1[i] == ' ' || text1[i] == '\n' || text1[i] == '\t' || text1[i] == '\r') {
            palabra = 1;
        }
        i++;
    }
}


void trasfMinus(char *text2) {
    while (*text2 != '\0') {
        if (*text2 >= 'A' && *text2 <= 'Z') {
            *text2 = *text2 + 32;
        }
        text2++;
    }
}


void ConvertiraMayus(char *text3) {
    while (*text3 != '\0') {
        if (*text3 >= 'a' && *text3 <= 'z') {
            *text3 = *text3 - 32;
        }
        text3++;
    }
}


double calcularPotencia(double base, int exponente) {
    if (exponente == 0) {
        return 1; // Cualquier n�mero elevado a 0 es 1
    } else {
        return base * calcularPotencia(base, exponente - 1);
    }
}


int dividirConRestas(int dividendo, int divisor) {
    int cociente = 0;

    while (dividendo >= divisor) {
        dividendo -= divisor;
        cociente++;
    }

    return cociente;
}


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void moveText(char frase[], int pos) {
    if (pos > 0) {
        printf("\n");
        moveText(frase, pos - 1);
    } else {
        printf("%s", frase);
    }
}


void animateText(char frase[], int pos, int direccion) {
    clearScreen();
    moveText(frase, pos);

    pos += direccion;

    if (pos >= 25) {
        direccion = -1;
    } else if (pos <= 0) {
        direccion = 1;
    }
    if (!kbhit()) {
#ifdef _WIN32
        Sleep(100);
#else
        usleep(100000);
#endif
        animateText(frase, pos, direccion);
    } else {
        char tecla = getch();
        if (tecla == '\r') {
            return;
        }
    }
}
