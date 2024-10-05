#include <math.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


/* 
https://stackoverflow.com/questions/399704/xml-parser-for-c
https://www.ime.usp.br/~belitsky/wiki/lib/exe/fetch.php?media=mae121:denominadornoestimadordavariancia.pdf
*/
double variancia(double* itens, double media, int size) {
   double p = 0.0;
   for(int i = 0; i < size; i++){
        p = p+pow(itens[i] - media,2); 
   }
   return (p/ (size-1));
}
double desvio_padrao(double* itens, double media, int size) {
   double var = variancia(itens,media,size);
   return sqrt(var);
}
/*
    100% - total
    x    - valor do estado
    x = 100valor/total

 */
double regra_de_tres(double val, double total) {
    return (100.f * val) / total;
}