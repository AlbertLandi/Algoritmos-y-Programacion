#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int main(){
       	char Respuesta='S', TipoDespacho, TipoEncomienda, DespachoRMas, DespachoVMas; 
       	int Cedula, Longitud, Ancho, Altura, Precio1, Precio2, TarifaDTotal=0, TarifaITotal=0, ArancelTotal=0, ImpuestoTotal=0, Arancel, Factura, Impuesto, CantDespachosD=0, CantDespachosI=0, ClientesD=0, ClientesI=0, CedMas=0, CedRMas=0,CedVMas=0, CantEncomiendaMenos2D=0, CantEncomiendaMas2D=0, CantEncomiendaMenos2I=0, CantEncomiendaMas2I=0; 
       	float Peso, PesoRound, PesoR, PesoV, PesoVMas=0, PesoRMas=0, PesoMas=0, PesoMenos=9999, PesoMayor, FacDTotal, FacITotal, FacturaS, FacturaC, TarifaD, TarifaI, PromD, PromI;
		int TarifaSobre(float PesoR, int Precio1, int Precio2, char TipoDespacho, int *CantEncomiendaMenos2D, int *CantEncomiendaMenos2I, int *CantEncomiendaMas2D, int *CantEncomiendaMas2I);
		int TarifaCaja(float PesoMayor, int Precio1, int Precio2, char TipoDespacho, int *CantEncomiendaMenos2D, int *CantEncomiendaMenos2I, int *CantEncomiendaMas2D, int *CantEncomiendaMas2I);
		int PesoVolumetrico();
		void Promedio(float FacDTotal, float FacITotal, int ClientesD, int ClientesI);
       	while(Respuesta == 'S'){
            // Ingreso del numero de cedula
            printf("Introduzca su numero de cedula:\n");
            scanf("%d",&Cedula);
            while(Cedula<=0 || Cedula>50000000){
                printf("ERROR:\n Numero de cedula invalido\nIntroduzca su numero de cedula:\n");
                scanf("%d",&Cedula);
                }
            // Ingreso del Tipo de Despacho                
            printf("Ingrese el tipo de despacho a utilizar:\n('D' para Domestico o 'I' para Internacional)\n");
            scanf(" %c", &TipoDespacho);
            if(isalpha(TipoDespacho))
				TipoDespacho = toupper(TipoDespacho);  	
            while(TipoDespacho != 'D' && TipoDespacho != 'I'){
                printf("ERROR:\n Tipo de Despacho invalido\nIntroduzca nuevamente el Tipo de Despacho:\n");
                scanf(" %c", &TipoDespacho);
                if(isalpha(TipoDespacho))
					TipoDespacho = toupper(TipoDespacho);  	
                }
            // Ingreso del Tipo de Encomienda
            printf("Ingrese el tipo de encomienda a utilizar:\n('C' para Caja o 'S' para Sobre)\n");
            scanf(" %c", &TipoEncomienda);
            if(isalpha(TipoEncomienda))
				TipoEncomienda = toupper(TipoEncomienda);  	
            while(TipoEncomienda != 'C' && TipoEncomienda != 'S'){
                printf("ERROR:\n Tipo de Encomienda invalido\nIntroduzca nuevamente el Tipo de Despacho:\n");
                scanf(" %c", &TipoEncomienda); 
				if(isalpha(TipoEncomienda))
					TipoEncomienda = toupper(TipoEncomienda);  	      
                }       
            //Ingreso del peso (Real) si la encomienda es Sobre 
            if(TipoEncomienda == 'S'){
                printf("Ingrese el peso del sobre:\n");
                scanf(" %f", &Peso);
                while(Peso<=0){
                    printf("ERROR:\n Peso invalido\nIntroduzca nuevamente el Peso:\n");
                    scanf(" %f", &Peso);
                    }
                //Peso mayor y Peso Menor
                if(Peso>PesoMas)
					PesoMas=Peso;
				if(Peso<PesoMenos)
					PesoMenos=Peso;
					
				//Condicion Peso
				if(Peso>0 && Peso<0.5)
					PesoRound=Peso;
				else
                	PesoRound = round(Peso);
				printf("Si Peso Real es mayor a la fraccion de 0.5Kgs, se le cobrara en base a: %f Kg.\n", PesoRound);
				
				//Si el Sobre es para despacho Domestico, menor o mayor-igual a 2Kgs
				if(TipoDespacho == 'D'){
					CantDespachosD++;
					ClientesD++;
					TarifaD = TarifaSobre( PesoRound, Precio1=10000, Precio2=20000, TipoDespacho, &CantEncomiendaMenos2D, &CantEncomiendaMenos2I, &CantEncomiendaMas2D, &CantEncomiendaMas2I);
					printf("El monto neto a pagar es: %f\n", TarifaD);
					TarifaDTotal=TarifaDTotal+TarifaD;
					Impuesto=TarifaD*0.12;
					ImpuestoTotal=ImpuestoTotal+Impuesto;
					FacturaS=TarifaD+Impuesto;
					FacDTotal=FacDTotal+FacturaS;
					printf("La factura total a pagar es: %f\n", FacturaS);
					}
				//Si el Sobre es para despacho Internacional, menor o mayor-igual a 2Kgs
				else if(TipoDespacho == 'I'){
					CantDespachosI++;
					ClientesI++;
					TarifaI = TarifaSobre( PesoRound, Precio1=25, Precio2=30, TipoDespacho, &CantEncomiendaMenos2D, &CantEncomiendaMenos2I, &CantEncomiendaMas2D, &CantEncomiendaMas2I);
					printf("El monto neto a pagar es %f\n", TarifaI);
					TarifaITotal=TarifaITotal+TarifaI;
					Arancel=TarifaI*0.1;
					ArancelTotal=ArancelTotal+Arancel;
					FacturaS=TarifaI+Arancel;
					FacITotal=FacITotal+FacturaS;
					printf("La factura total a pagar es: %f\n", FacturaS);
					}
				}
			//Ingreso del peso (Real y Volumetrico) si la encomienda es una caja
			else if(TipoEncomienda == 'C'){
				printf("Ingrese el peso real de la caja:\n");
                scanf(" %f", &PesoR);
                while(PesoR<=0){
                    printf("ERROR:\n Peso invalido\nIntroduzca nuevamente el Peso:\n");
                    scanf(" %f", &PesoR);
                    }
				PesoV = PesoVolumetrico();
				//Caja de mayor peso Volumetrico, cedula y tipo de despacho
				if(PesoV>PesoVMas){
					PesoVMas=PesoV;
					CedVMas=Cedula;
					DespachoVMas=TipoDespacho;
				}
				//Caja de mayor peso real, cedula y tipo de despacho
				if(PesoR>PesoRMas){
					PesoRMas=PesoR;
					CedRMas=Cedula;
					DespachoRMas=TipoDespacho;
				}
				//Determinacion del mayor entre los dos pesos
				if(PesoR>PesoV){
					PesoMayor=PesoR;
					if(PesoMayor>0 && PesoMayor<0.5)
						PesoMayor=PesoR;
					else
						PesoMayor = round(PesoMayor);
					}
				else if(PesoV>PesoR){
					PesoMayor=PesoV;
					if(PesoMayor>0 && PesoMayor<0.5)
						PesoMayor=PesoV;
					else
						PesoMayor = round(PesoMayor);
					}			
				else if(PesoR == PesoV){
					PesoMayor=PesoR;
					if(PesoMayor>0 && PesoMayor<0.5)
						PesoMayor=PesoR;
					else
						PesoMayor = round(PesoMayor);
					}	
					
				printf("NOTA:\nSe le cobrara en base al Pesor Mayor entre el real (en Kg) y volumetrico (en cm/kg).\n");	
				//Si la Caja es para despacho Domestico, menor-igual o mayor a 2Kgs
				if(TipoDespacho == 'D'){
					CantDespachosD++;
					ClientesD++;
					TarifaD = TarifaCaja( PesoMayor, Precio1=10000, Precio2=20000, TipoDespacho, &CantEncomiendaMenos2D, &CantEncomiendaMenos2I, &CantEncomiendaMas2D, &CantEncomiendaMas2I);
					printf("El monto neto a pagar es: %f\n", TarifaD);
					TarifaDTotal=TarifaDTotal+TarifaD;
					Impuesto=TarifaD*0.12;
					ImpuestoTotal=ImpuestoTotal+Impuesto;
					FacturaC=TarifaD+Impuesto;
					FacDTotal=FacDTotal+FacturaC;
					printf("La factura total a pagar es: %f\n", FacturaC);
					}
				//Si la Caja es para despacho Internacional, menor-igual o mayor a 2Kgs
				else if(TipoDespacho == 'I'){
					CantDespachosI++;
					ClientesI++;
					TarifaI = TarifaCaja( PesoMayor, Precio1=25, Precio2=30, TipoDespacho, &CantEncomiendaMenos2D, &CantEncomiendaMenos2I, &CantEncomiendaMas2D, &CantEncomiendaMas2I);
					printf("El monto neto a pagar es: %f\n", TarifaI);
					TarifaITotal=TarifaITotal+TarifaI;
					Arancel=TarifaI*0.1;
					ArancelTotal=ArancelTotal+Arancel;
					FacturaC=TarifaI+Arancel;
					FacITotal=FacITotal+FacturaC;
					printf("La factura total a pagar es: %f\n", FacturaC);
					}
            	}			
        	// Para continuar con otro cliente si asi se desea                
        	printf("Desea ingresar otro cliente? Ingrese 'S' para hacerlo, ingrese cualquier otra tecla para imprimir el Reporte del Dia.\n");
        	scanf(" %c",&Respuesta);
			if(isalpha(Respuesta))
				Respuesta = toupper(Respuesta);  	                                
        	}
        //Llamada al Reporte final del dia
        //ReporteDia();
        printf("\t REPORTE FINAL DEL DIA\n");
		printf("Cantidad de Encomiendas:\n \t%d Domesticos.\n \t%d Internacionales.\n", CantDespachosD, CantDespachosI);
		printf("Cantidad de Encomiendas menores a 2 Kg:\n \t%d Domesticos.\n \t%d Internacionales.\n", CantEncomiendaMenos2D, CantEncomiendaMenos2I);
		printf("Cantidad de Encomiendas mayores o iguales a 2 kg:\n \t%d Domesticos.\n \t%d Internacionales.\n", CantEncomiendaMas2D, CantEncomiendaMas2I);
		printf("Monto NETO facturado por tipo de Despacho:\n \t%d Bolivares (Domesticos).\n \t%d Dolares (Internacionales).\n", TarifaDTotal, TarifaITotal);
		printf("Monto de Impuestos cobrados por IVA para los despachos Domesticos: %d Bolivares\n", ImpuestoTotal);
		printf("Monto de Aranceles cobrado para los despachos Internacionales: %d Dolares\n", ArancelTotal);
		printf("Sobre mas pesado: %f Kg\nSobre mas liviano: %f Kg\n", PesoMas, PesoMenos);
		printf("Caja mayor peso: %f Kg\nTipo de Despacho: %c \nCedula %d \n", PesoRMas, DespachoRMas, CedRMas);
		printf("Caja mayor peso Volumetrico: %f Kg\nTipo de Despacho: %c \nCedula %d \n", PesoVMas, DespachoVMas, CedVMas);
		Promedio( FacDTotal, FacITotal, ClientesD, ClientesI);
        system("pause");
}

//Funcion para el calculo de la tarifa para los Sobres (domestico o internacional)
int TarifaSobre(float PesoRound, int Precio1, int Precio2, char TipoDespacho, int *CantEncomiendaMenos2D, int *CantEncomiendaMenos2I, int *CantEncomiendaMas2D, int *CantEncomiendaMas2I){
	int Monto;
    if(PesoRound<2){
        Monto=PesoRound*Precio1;
        if(TipoDespacho=='D')
    		*CantEncomiendaMenos2D=*CantEncomiendaMenos2D+1;
    	if(TipoDespacho=='I')
    		*CantEncomiendaMenos2I=*CantEncomiendaMenos2I+1;
		}
    else if(PesoRound>=2){			
        Monto=PesoRound*Precio2;
    	if(TipoDespacho=='D')
    		*CantEncomiendaMas2D=*CantEncomiendaMas2D+1;
    	if(TipoDespacho=='I')
    		*CantEncomiendaMas2I=*CantEncomiendaMas2I+1;
    	}
    return Monto;
}

//Funcion para el calculo de la tarifa para las cajas (Domestico o internacional)
int TarifaCaja(float PesoMayor, int Precio1, int Precio2, char TipoDespacho, int *CantEncomiendaMenos2D, int *CantEncomiendaMenos2I, int *CantEncomiendaMas2D, int *CantEncomiendaMas2I){
    int Monto;
    if(PesoMayor<2){
        Monto=PesoMayor*Precio1;
        if(TipoDespacho=='D')
    		*CantEncomiendaMenos2D=*CantEncomiendaMenos2D+1;
    	if(TipoDespacho=='I')
    		*CantEncomiendaMenos2I=*CantEncomiendaMenos2I+1;
			}
    else if(PesoMayor>=2){				
        Monto=PesoMayor*Precio2;
        if(TipoDespacho=='D')
    		*CantEncomiendaMas2D=*CantEncomiendaMas2D+1;
    	if(TipoDespacho=='I')
    		*CantEncomiendaMas2I=*CantEncomiendaMas2I+1;
    	}
    return Monto;
}

//Funcion para peso Volumetrico de caja
int PesoVolumetrico(){
	int Longitud, Ancho, Altura;
	float PesoVol;
	printf("Ingreso de medidas de la caja, recuerde que las medidas son cifras enteras positivas en centimetros:\n");
	printf("Longitud: ");
	scanf(" %d", &Longitud);
	while(Longitud<=0){
        printf("ERROR:\n Longitud invalida\nIntroduzca nuevamente la Longitud de la caja:\n");
        scanf(" %d", &Longitud);
        }
	printf("Ancho: ");
	scanf(" %d", &Ancho);
	while(Ancho<=0){
        printf("ERROR:\n Ancho invalido\nIntroduzca nuevamente el Ancho de la caja:\n");
        scanf(" %d", &Ancho);
        }
	printf("Altura: ");
	scanf(" %d", &Altura);
	while(Altura<=0){
        printf("ERROR:\n Altura invalida\nIntroduzca nuevamente la Altura de la caja:\n");
        scanf(" %d", &Longitud);
        }
	PesoVol=(Longitud*Ancho*Altura)/5000;
	printf("El peso volumetrico de la caja es %f\n", PesoVol);
	
	return PesoVol;			
}

//Funcion para el promedio
void Promedio(float FacDTotal, float FacITotal, int ClientesD, int ClientesI){
	float PromD, PromI;
	PromD=FacDTotal/ClientesD;
		if(ClientesD==0)
			PromD=0;
	PromI=FacITotal/ClientesI;
		if(ClientesI==0)
			PromI=0;
		printf("Promedio de pago de todos los Clientes por tipo de despacho:\n \t %f Bolivares (Domesticos).\n \t %f Dolares (Internacionales)\n", PromD, PromI);
	return;       
}
