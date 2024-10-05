#include "./exercises.c"

int show_menu() {
  int escolha = -1;
  double arr[] = {67836.43, 36678.66, 29229.88, 27165.48, 19849.53};
  int n = sizeof(arr) / sizeof(arr[0]);
  do {
    printf("\nExercicios disponiveis: \n");
    printf("\n1 - Exercicio 1 - Valor da Soma\n");
    printf("2 - Exercicio 2 - Checar se esta na Fibonacci\n");
    printf("3 - Exercicio 3 - Min,Max Media\n");
    printf("4 - Exercicio 4 - Json e Xml\n");
    printf("5 - Exercicio 5 - Inversao String\n");
    printf("0 - Sair\n");

    printf("\nEscolha um exercicio: ");
    scanf("%d", &escolha);

    switch(escolha) {
      case 1:
        find_sum_loop();
        break;
      case 2:
        is_fib();
        break;
      case 3:
        find_min_max_mean(arr, n);
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
