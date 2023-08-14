#include "funciones.cpp"

#define ANSI_BACKGROUND_RED "\033[41m"
#define ANSI_BACKGROUND_RESET "\033[0m"


void mostrarMenu(int opcionActual){
    printf("\t Menu \n\n");

    for (int i = 1; i <= 7; i++) {
        if (i == opcionActual) {
            printf("%s", ANSI_BACKGROUND_RED);
        } else {
            printf("%s", ANSI_BACKGROUND_RESET);
        }

        switch (i) {
            case 1:
                printf("1.-Converir Mayuscula\n");
                break;
            case 2:
                printf("2.-Division con resta\n");
                break;
            case 3:
                printf("3.-Calcular potencia\n");
                break;
            case 4:
                printf("4.-Convertir minuscula\n");
                break;
            case 5:
                printf("5.-Frase Movil\n");
                break;
            case 6:
                printf("6.-Primera letra mayuscula\n");
                break;
            case 7:
            printf("7. -Salir\n");
                break;
        }
    }
}

void regresarMenu() {
    while (1) {
        if (_kbhit()) {
            int tecla = _getch();
            if (tecla == 27) {
                break;
            }
        }
    }
}

int operarMenu() {
    int opcionActual = 1;
    //declaracion datos
   	char input1[100],input2[100],input3[100],frase[] = "Hola, esta es una frase que se mueve!";
	int dividendo,divisor,exponente,pos = 0,direccion = 1;
    double base;
    
    while (1) {
        system("cls");
        mostrarMenu(opcionActual);
        char tecla = _getch();

        switch (tecla) {
            case 72:
                opcionActual = (opcionActual > 1) ? opcionActual - 1 : 7;
                break;
            case 80:
                opcionActual = (opcionActual < 7) ? opcionActual + 1 : 1;
                break;
            case 13:
                system("cls");

                switch (opcionActual) {
                    case 1:
                    	printf("1.-Convertir Mayuscula\n");
                        printf("Ingresa un texto en minusculas: ");
    					fgets(input1, sizeof(input1), stdin);
    					ConvertiraMayus(input1);
    					printf("Texto en mayusculas: %s\n", input1);
                        break;
					case 2:
                		printf("2.-Division con resta\n");
                		printf("Ingrese el dividendo: ");
    					scanf("%d", &dividendo);
    					printf("Ingrese el divisor: ");
    					scanf("%d", &divisor);
   						if (divisor == 0) {
        				printf("No se puede dividir por cero.\n");
    					} else {
        				int cociente = dividirConRestas(dividendo, divisor);
        				printf("El cociente de %d dividido por %d es %d\n", dividendo, divisor, cociente);
    					}
                		break;
            		case 3:
               		   printf("3.-Calcular potencia\n");
               		   printf("Ingrese la base: ");
                       scanf("%lf", &base);
                       printf("Ingrese el exponente: ");
                       scanf("%d", &exponente);
                       calcularPotencia(base, exponente);
                       printf("El resultado de %.2lf elevado a la potencia %d es %.2lf\n", base, exponente, calcularPotencia(base, exponente));
                		break;
            		case 4:
                	 	printf("4.-Convertir minuscula\n");
                        printf("Ingresa un texto en mayusculas: ");
                        fgets(input2, sizeof(input2), stdin);
                        trasfMinus(input2);
                        printf("Texto en minusculas: %s\n", input2);
                		break;
            		case 5:
                		printf("5.-Frase Movil\n");
                		animateText(frase, pos, direccion);
                		break;
            		case 6:
                		printf("6.-Primera letra mayuscula\n");
                        printf("Ingresa un texto: ");
                        fgets(input3, sizeof(input3), stdin);
                        PrimeLetraMayus(input3);
                        printf("Texto con primeras letra en mayuscula: %s\n", input3);
                		break;
            			return 0;
                }

                _getch();
                regresarMenu();
                break;
        }
    }

    return 0;
}