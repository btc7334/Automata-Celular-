/*Juego de la vida Conway */

#include <stdio.h>//libreria basica de entrada salida
#include <time.h>//libreria para generar srand
#include <stdlib.h> //libreria para borrar 
#define x 10   //el numero de filas declarado en una constante
#define y 10    //el numero de columnas declarado en una constante
char tabla[x][y],tablanueva[x][y]; //En una tabla se mostrará, en la otra se aplicarán los cambios 

void pantalla(void)
{
   int i,j,iteracion=1;
   srand((time(NULL)));

  for (i=0;i<x;i++)// generamos la matriz
  {
  for (j=0;j<y;j++)//generamos la matriz
          {
          tabla[i][j]=rand()%2;// Se genera aleatoriamente 0 o 1 y se comoca en matriz
          }

  }
  //imprimimos la matriz
  printf ("Iteracion %d",iteracion);
   printf ("\n\n\n\n\n");
  for (i=0;i<x;i++)
    {
  for (j=0;j<y;j++)
      {
      printf ("%d ",tabla[i][j]); //se genera la matriz con 0 y 1 
      }
 
    printf ("\n");// es para que me salte a la siguente linea y se vea como matriz
    }

}


void definirreglas(void){
     int i,j,v;
// empezamos a contar todos los vecinos para saber si los vecinos están vivos o muertos
for (i=0;i<x;i++)
{

for (j=0;j<y;j++)
{
     v=0;


                     if(tabla[i-1][j-1]==1)v++; //no fue necesario utilizar llave ya que es una sola linea
                     if(tabla[i-1][j]==1)v++; 
                     if(tabla[i-1][j+1]==1)v++;
                     if(tabla[i][j-1]==1)v++;  
                     if(tabla[i][j+1]==1)v++;
                     if(tabla[i+1][j-1]==1)v++;
                     if(tabla[i+1][j]==1)v++;
                     if(tabla[i+1][j+1]==1)v++;

// definos la regla de conway condicional para determinar si la casilla vive o muere
if (tabla[i][j]==1)//si esta vivo al inicio
{
                      
if (v<=1)//se muere de soledad
  {
   tablanueva[i][j]=0;
  }
if (v>=2 && v<=3)//sobrevive
  {
   tablanueva[i][j]=1; 
  }
   if (v>=4)//se muere 
                  {
                   tablanueva[i][j]=0;
                  }
}
if (tabla[i][j]==0)//si  esta muerta
 {
                      
if (v==3)//nace por que tiene tre vecinos
     {
                  
tablanueva[i][j]=1;
     }
  else
      {
             
     tablanueva[i][j]=0;
     }
 }
  } //fin j
}// fin i

}
              
void imprimirtablero (void){
     int i,j;
     printf ("\n\n\n\n\n"); 
//Empezamos a imprimir la matriz resultante

  for (i=0;i<x;i++)
    {
  for (j=0;j<y;j++)
       {
   if (tablanueva[i][j]==0)
            {
    printf ("0 ");// cero es muerta
            }
    else
        {
      printf ("1 ");// 1 es viva 
        }
      
      } 
    printf ("\n");
     }
   
}


     
void nueva(void){
     int i,j;
    // actualiza la matriz original con la matriz temporal
     for (i=0;i<x;i++)
    {
          for (j=0;j<y;j++)
          {
          tabla[i][j]=tablanueva[i][j];
          }
       
    }
     
}
             
main ()//inicio del programa 
{
    int iteracion=2;
      pantalla();
  do{// para que me cuente la iteracion 
     
      sleep(7000);// me hace que vea el movimiento 
      definirreglas();  
      system("cls");//esta es para borrar la matriz anterior y poner la nueva 
       printf ("Iteracion %d",iteracion);
      imprimirtablero();
      nueva();
   iteracion++;  
  }while (iteracion<=10); // iteracion al menos 10 
  
 system("PAUSE");//PARA QUE NO ME CIERRE EL EJECUTABLE
}

