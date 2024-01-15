#include <stdio.h>
#include <math.h>

float f(float);
float midpoint(float (*)(float), float, float, int);

int main()
{
  float a, b, acc, tmp;
  float in, i2n;
  int n;

  printf("Programma per il calcolo del valore di un integrale\n");
  printf("       usando il metodo del punto medio\n");

  printf("Entra gli estremi dell'intervallo ");
  scanf("%f %f",&a,&b);
  if (a > b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  if (a == b) {
    printf("Errore! Gli estremi devono essere diversi\n");
    return 1;
  }

  printf("Entra l'accuratezza ");
  scanf("%f",&acc);
  if (acc <= 0) {
    printf("Errore! L'accuratezza deve essere positiva\n");
    return 1;
  }

  n = 1;
  while(1) {
    in  = midpoint(f,a,b,n);
    i2n = midpoint(f,a,b,2*n);
    if (fabs(in-i2n) < acc) break;
    n = 2*n;
  }

/*
  do {
    in  = midpoint(f,a,b,n);
    i2n = midpoint(f,a,b,2*n);
    n = 2*n;
  } while(fabs(in-i2n) < acc);
*/

  printf("L'integrale (calcolato con %d sottointervalli) vale %f\n",n,i2n);
  return 0;
}

float f(float x)
{
  return sin(x);
}

float midpoint(float func(float), float a, float b, int n)
{
  float sum=0.;
  float h, xi, xi1;
  int i;

  h = (b - a)/n;
  for (i=0; i<n; i++) {
    xi = a + i*h;
    xi1 = xi + h;
    sum = sum + func( (xi+xi1)/2 );
  }

  sum = sum*h;
  return sum;
}

/*
  Per compilare questo programma:

    cc midpoint.c -o midpoint -lm

*/
