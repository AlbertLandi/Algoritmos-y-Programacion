#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void Calculadora(float a, float b, int respuesta, float resultado);
//Landi, Alberto. C:20151110119
main(){
    
    float resultado, a, b;
    int respuesta; 
    char ciclo='S';
    while(ciclo=='S'){
    	printf("Ingrese 1 si desea sumar, ingrese 2 si desea multiplicar, ingrese 3 si desea restar, ingrese 4 si desea dividir.\n");
    	scanf("%d", &respuesta);
    	while(respuesta<1 || respuesta>4){
    		printf("\tERROR:\n Ingrese su respuesta nuevamente:\n \t1.Suma.\n \t2.Multiplicacion.\n \t3.Resta.\n \t4.Division.\n");
    		scanf("%d", &respuesta);
    		}
    	printf("Ingrese el primer numero:\n");
    	scanf("%f", &a);
    	printf("Ingrese el segundo numero:\n");
    	scanf("%f", &b); 
		Calculadora( a, b, respuesta, resultado);
		printf("Desea realizar otro calculo?\nIngrese S para realizar otro calculo, ingrese cualquier otra tecla para terminar el programa.\n");
		scanf(" %c", &ciclo);
		if(isalpha(ciclo))
			ciclo=toupper(ciclo);
	}
	printf("Gracias Por usar el programa.");
	system("pause");
}
    
void Calculadora(float a, float b, int respuesta, float resultado){
    if(respuesta==1){
        resultado=a+b;
        printf("El resultado de la suma es: %f\n", resultado);
    	}
    else if(respuesta==2){
        resultado=a*b;
        printf("El resultado de la multiplicacion es: %f\n", resultado);
    	}
    else if(respuesta==3){
    	resultado=a-b;
    	printf("El resultado de la resta es: %f\n", resultado);
		}
    else if(respuesta==4){
    	resultado=a/b;
    	printf("El resultado de la division es: %f\n", resultado);
	}
	return; 
}
