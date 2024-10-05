#include "./exercises.c"

int show_menu() {
  char escolha;
  double arr[] = {67836.43, 36678.66, 29229.88, 27165.48, 19849.53};
  do {
    printf("\n==============================================");
    printf("\n         Exercicios disponiveis:          \n\n");
    printf("1 - Exercicio 1 - Valor da Soma               \n");
    printf("2 - Exercicio 2 - Checar se esta na Fibonacci \n");
    printf("3 - Exercicio 3 - Min,Max Media               \n");
    printf("4 - Exercicio 4 - Json e Xml                  \n");
    printf("5 - Exercicio 5 - Inversao String             \n");
    printf("0 - Sair\n");

    printf("\nEscolha um exercicio: ");
    scanf("%s%*c", &escolha);
    int teste =  atoi(&escolha);
    switch(teste) {
      case 1:
        find_sum_loop();
        break;
      case 2:
        is_fib();
        break;
      case 3:
        find_min_max_mean(arr);
        break;
      case 4:
        parse_xml_or_json();
        break;
      case 5:
        inverter_s();
        break;
      case 0:
        printf("\n\nAdeus. \n");
        return 0;
      default:
        break;
    }
  } while (escolha != 0);
}
