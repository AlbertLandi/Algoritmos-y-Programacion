#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Landi, Alberto. C:20151110119
//Este Pokemon no sigue precisamente los tipos de ataques segun los pokemones, asi como sus puntos de vida. Es solo un ejemplo de Porgramacion.
int Seleccion(int Pokemon);
void Pelea(int VidaA, int VidaB);

main(){
	int Bulbasaur, Charmander, Squirtle, Rattata, VidaA=100, VidaB=100, Pokemon, PokeEleccion;
	char Revancha='S';
	
	while(Revancha=='S'){
		printf("\tBIENVENIDOS A POKEMON\n");
		printf("Escoja su pokemon inicial:\n \t1.Bulbasaur\n \t2.Charmander\n \t3.Squirtle\n");
		scanf(" %d", &Pokemon);
		while(Pokemon<1 || Pokemon>3){
			printf("\tERROR: Escoja su pokemon inicial nuevamente:\n \t1.Bulbasaur\n \t2.Charmander\n \t3.Squirtle\n");
			scanf(" %d", &Pokemon);
			}
		PokeEleccion=Seleccion( Pokemon);
		Pelea( VidaA, VidaB);
		printf("Desea revancha? Ingrese S para hacer revancha, ingrese cualquier otro numero para salir del juego.\n");
		scanf(" %C", &Revancha);
		if(isalpha(Revancha))
			Revancha=toupper(Revancha);
	}
printf("Gracias por participar en el juego.");	
system("pause");
}

//Seleccion pokemon
int Seleccion(int Pokemon){
	if(Pokemon==1){
		printf("Has escojido a Bulbasaur.\n");
	}
	else if(Pokemon==2){
		printf("Has escojido a Charmander.\n");
	}
	else if(Pokemon==3){
		printf("Has escojido a Squirtle.\n");
	}
	return Pokemon;
}

//Sub Programa de la Pelea
void Pelea(int VidaA, int VidaB){
	int Scratch=50, QuickAttack=40, Slam=30, HeadCharge=20, Ataque;
	printf("Un Rattata Salvaje se ha aparecido.");
	printf("Escoja su ataque inicial:\n \t1.Scratch\n \t2.Quick Attack\n \t3.Slam\n \t4.Head Charge\n");
	scanf(" %d", &Ataque);
	while(Ataque<1 || Ataque>4){
		printf("\tERROR: Escoja su ataque inicial nuevamente:\n \t1.Scratch\n \t2.Quick Attack\n \t3.Slam\n \t4.Head Charge\n");
		scanf(" %d", &Ataque);
	}
	if(Ataque==1){
		VidaB=VidaB-Scratch;
		printf("has usado SCRATCH. Es muy efectivo.\n");
		printf("\tVida Restante = %d \n \tVida Rattata = %d\n", VidaA, VidaB);
	}
	else if(Ataque==2){
		VidaB=VidaB-QuickAttack;
		printf("Has usado QUICK CHARGE.\n");
		printf("\tVida Restante = %d \n \tVida Rattata = %d\n", VidaA, VidaB);
	}
	else if(Ataque==3){
		VidaB=VidaB-Slam;
		printf("Has usado SLAM.\n");
		printf("\tVida Restante = %d \n \tVida Rattata = %d\n", VidaA, VidaB);
	}
	else if(Ataque==4){
		VidaB=VidaB-HeadCharge;
		printf("Has usado HEAD CHARGE.\n");
		printf("\tVida Restante = %d \n \tVida Rattata = %d\n", VidaA, VidaB);
	}
	printf("Rattata ha usado SCRATCH. Es muy efectivo.\n");
	VidaA=VidaA-Scratch;
	printf("\tVida Restante = %d \n \tVida Rattata = %d\n", VidaA, VidaB);
	printf("Rattata ha escapado.\n");
	return;
}
