#include <libxml/parser.h>
#include <libxml/tree.h>
#include "./stack.c"
#include "./math_utils.c"
#include "../lib/State.h"

//mudar dependendo da quantidade de itens 
#define INDICE 13
#define MAX_WORD_SIZE 10
#define MIN_INITIAL_VAL 99999
#define STACK_SIZE 5
int SOMA = 0;
int K = 0;

int find_sum_loop() {
   while (K < INDICE) {
      K += 1;
      SOMA += K;
      printf("K = %d, SOMA = %d\n", K, SOMA);
   }
return SOMA;
}


/* 
https://pt.stackoverflow.com/questions/294676/qual-a-forma-mais-r%C3%A1pida-de-se-calcular-a-sequencia-de-fibonacci
*/
void print_sequence(int aux, int anterior) {
   if (aux == 0) printf("%d", aux);
   else printf(" - %d", aux ==1 ? aux : anterior);
}

int check_is_fibonacci(int n) {
   int proximo = 1;
   int anterior = 0;
   while(proximo < n) {
      int aux = anterior; // n-2
      anterior = proximo; // n-1
      proximo = proximo + aux; // novo n

      if(n < 0) return 0;
      print_sequence(aux, anterior);
   }
   return n == proximo;
}

void is_fib() {
   int num;
   printf("\n\nEscreva um numero: ");
   scanf("%d", &num);
   check_is_fibonacci(num) ? printf("\n%d pertence a sequencia de Fibonacci.\n", num) :   printf("\n%d nao pertence a sequencia de Fibonacci.\n", num);
}


void find_min_max_mean(double *arr) {

   double media =0.0;
   double min = arr[0];
   double max = arr[0];
   double soma = arr[0];

   printf("Itens da lista: [%.2f,", arr[0]);
   for (int i = 1; i < STACK_SIZE; i++) {
      char* val = i < STACK_SIZE -1 ? "%.2f," : "%.2f";
      printf(val, arr[i],i);
      soma += arr[i];
      min = arr[i] < min ? arr[i] : min;
      max = arr[i] > max ? arr[i] : max;
   }
   printf("];\n");
   media = soma/STACK_SIZE;
   
   printf("Minimo: %.2f; Maximo: %.2f\n", min,max);
   printf("Media: %.2f; Amplitude: %.2f\n", media, max-min);
   printf("Variancia: %.2f; Desvio Padrao: %.2f\n", variancia(arr,media, STACK_SIZE), desvio_padrao(arr,media,STACK_SIZE));
}

void inverter_s() {
   char s[MAX_WORD_SIZE];
   printf("Escreva uma palavra de ate %d caracteres: ", MAX_WORD_SIZE );
   scanf("%s", s);
   /*ponteiros que percorrem o array de char (string)*/
   int pont_fim = strlen(s) - 1; // remove o /0
   int pont_ini = 0;

   for (pont_ini, pont_fim; pont_ini < pont_fim; pont_ini++, pont_fim--) {
      int temp = s[pont_ini];
      s[pont_ini] = s[pont_fim];
      s[pont_fim] = temp;
   }

   printf("Palavra invertida: %s \n", s);
}

int parse_xml() {
   xmlDoc *doc = NULL;
   xmlNode *root_element = NULL;
   xmlNode *item = NULL;
   State *st = malloc(STACK_SIZE * sizeof(State));
   double monthly_averages[STACK_SIZE];
   double *stack_top = monthly_averages;
   double soma = 0;
   double min = MIN_INITIAL_VAL;
   double max = monthly_averages[0];
   int current_state = 0;
   // Load the XML document
   doc = xmlReadFile("medias_mensais.xml", NULL, 0);

   if (doc == NULL) {
      fprintf(stderr, "Failed to parse XML file\n");
      return 1;
   }

   printf("\n[INFO] Doc loaded successfully\n");

   // Get the root element
   root_element = xmlDocGetRootElement(doc);
   if (root_element == NULL) {
      fprintf(stderr, "Empty XML document\n");
      xmlFreeDoc(doc);
      return 1;
   }

   printf("[INFO] Root element loaded successfully\n");

   // Iterate through the average elements
   for (item = root_element->children; item; item = item->next) {

      if (item->type == XML_ELEMENT_NODE && !xmlStrcmp(item->name, (const xmlChar *)"average")) {

         // Get the state_name and value elements
         for (xmlNode *state = item->children; state; state = state->next) {

            if (state->type == XML_ELEMENT_NODE && !xmlStrcmp(state->name, (const xmlChar *)"state_name")) {
               st[current_state].id = current_state;
               st[current_state].name = strdup((char*)state->children->content);
            } else if (state->type == XML_ELEMENT_NODE && !xmlStrcmp(state->name, (const xmlChar *)"value")) {    

               double value = strtod((char*)state->children->content, NULL);
               st[current_state].value=value;
               soma += value;
               current_state++;
            }
         }
      }
   }

   printf("\n[INFO] Parsing completed successfully\n\n");
   
   printf("Respectiva porcentagem de cada estado perante montante total: \n\n");
   for(int i=0; i < STACK_SIZE; i++) {
      st[i].percentage = regra_de_tres(st[i].value, soma);
      printf("[%d] %s: R$ %.2f --> %d%% do total;\n",st[i].id +1, st[i].name,st[i].value, st[i].percentage);
   }

   // Free the XML document
   free(st);
   xmlFreeDoc(doc);
   return 0;
}



void parse_xml_or_json() {
   int opt = 0;
   do {
      printf("\nOpcoes disponiveis: \n");
      printf("\n1 - Ler XML\n");
      printf("2 - Ler JSON\n");
      printf("Ecolha uma opcoao: ");
      scanf("%d", &opt);
      switch(opt) {
         case 1:
            parse_xml();
         break;
         case 2:
         break;
         default:
         break;
      }
   } while(opt <1 && opt > 2);
}