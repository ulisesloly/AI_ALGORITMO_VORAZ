/*
Problema de la mochila (fraccionada)
Implentación de un Algoritmo Voraz
*/
#include<iostream>
#include<iomanip>
using namespace std;
int i, j;
//Vector de selección
float x[' '];

void mostrarD(int nObjetos, float peso[], float valor[], string nombre[], float w);
void mostrarR(int nObjetos, float peso[], float valor[], string nombre[]);
int seleccionVoraz(float x[], float peso[], float valor[], int n);

main(){
    /* Declaración de variables */
    int nObjetos;
    float peso[' '], valor[' '];
	string nombre[' '];
    float suma=0, w;
    char res;

    /* Función */
    do{
        nObjetos=0;
        suma=0, w=0;
        system("cls");
        cout<<"\nImplementacion de un algoritmo Voraz"<<endl;
        cout<<"Compra de producto para una tienda\n"<<endl;

    /* Entrada de datos */
        cout<<"Ingrese el presupuesto maximo para las compras: ";
            cin>>w;
        cout<<"\nIngrese el numero de productos que habra en total: ";
            cin>>nObjetos;

        /*Ciclo para guardar el peso y valor de cada objeto*/
        for(j=1; j<=nObjetos; j++){
        	cout<<"\nIngrese el nombre del producto "<<j<<": ";
                cin>>nombre[j];
            cout<<"Ingrese el precio del producto por pza/kg: ";
                cin>>peso[j];
            cout<<"Ingrese la cantidad del producto vendido en la semana (pza/kg): ";
                cin>>valor[j];
        }

        system("cls");
        cout<<"\nImplementacion de un algoritmo Voraz"<<endl;
        cout<<"Compra de producto para una tienda\n"<<endl;

    /* Mostrar datos */
        cout<<"\tDatos registrados\n"<<endl;
            mostrarD(nObjetos, peso, valor,nombre, w);
        cout<<"\n"<<endl;

    /*Inicialización del vector de solución*/
        for(j=1; j<=nObjetos; j++){
            x[j]=0;}

    /* Algoritmo Voraz */
        while(suma<w){
            i=seleccionVoraz(x, peso, valor, nObjetos);
            if (suma + peso[i]*valor[i] <= w){
                x[i]=1;
                suma=suma+ (peso[i]*valor[i]);
            }else{
                x[i]=((w-suma)/(peso[i]*valor[i]));
                suma=w;
            }
        }

        cout<<"\n\n";
        cout<<"\tResultados: "<<endl;
            mostrarR(nObjetos, peso, valor, nombre);
        cout<<"\n"<<endl;
        cout<<"Volver a ejecutar, s/n? ";
            cin>>res;

    }while(res == 's' || res == 'S');
}
/* Funciones */
void mostrarD(int nObjetos, float peso[], float valor[],string nombre[], float w){
    /* Mostrar datos */
    cout<<"Peso maximo que soportara la mochila: "<<w<<endl;
    cout<<"Numero de objetos que habra en total: "<<nObjetos<<endl;
    /*Ciclo para mostrar el peso y valor de cada objeto*/
    cout<<"\nObjeto: ";
        for(j=1; j<=nObjetos; j++){
    cout<<"\t"<<j;}

    cout<<"\nNombre: ";
        for(j=1; j<=nObjetos; j++){
    cout<<"\t"<<nombre[j];}

    cout<<"\nPrecio:   ";
        for(j=1; j<=nObjetos; j++){
            cout<<"\t"<<peso[j];}
    cout<<"\nP. vendido:   ";
        for(j=1; j<=nObjetos; j++){
            cout<<"\t"<<valor[j];}
}
/* Criterio: Objeto mas valioso */
int seleccionVoraz(float x[], float peso[], float valor[], int n){
    int aux=0, indice=0;
    for(j=1; j<=n; j++){
            /*Vector selección, busca el objeto de maximo valor que no haya sido utilizado*/
        if(x[j]==0){
            if(aux<valor[j]){
                aux=valor[j];
                indice=j;
            }
        }
    }
    return indice;
}
/* función para mostrar resultados */
void mostrarR(int nObjetos, float peso[], float valor[], string nombre[]){
    /* Mostrar resultados */
    cout<<"\nNombre: ";
        for(j=1; j<=nObjetos; j++){
            cout<<"\t"<<nombre[j];}
    cout<<"\nPrecio: ";
        for(j=1; j<=nObjetos; j++){
            cout<<"\t"<<peso[j];}
    cout<<"\nP. vendido: ";
        for(j=1; j<=nObjetos; j++){
            cout<<"\t"<<valor[j];}
    cout<<"\n\t      -----------------------------------------------------"<<endl;
    cout<<"\ntotal/producto:";
        for(j=1; j<=nObjetos; j++){
            cout<<"\t"<<peso[j]*valor[j]*x[j];}

    cout<<"\n\nVector: ";
        for(j=1; j<=nObjetos; j++){
            cout<<"\t"<<fixed<<setprecision(3)<<x[j];}

        float valorT=0, pesoT=0;
        /*Valor total*/
        for(j=1; j<=nObjetos; j++){
            valorT = valorT + (x[j]*valor[j]);
            pesoT = pesoT + (x[j]*peso[j]*valor[j]);
        }

        cout<<"\n\n\tProductos comprados: "<<fixed<<setprecision(2)<<valorT<<endl;
        cout<<"\tPrecio total: "<<fixed<<setprecision(2)<<pesoT<<endl;
}
