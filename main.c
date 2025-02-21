#include "src/Alias_list.h"
#include <string.h>

// Exibe o uso do programa
void exibir_uso(const char *prog) {
    printf("Uso: %s <comando> [alias] [comando]\n", prog);
    printf("Comandos:\n");
    printf("  add <alias> \"<comando>\"       - Adiciona um novo alias\n");
    printf("  list                          - Lista todos os aliases\n");
    printf("  exec <alias>                  - Executa o comando associado ao alias\n");
    printf("  rm <alias>                    - Remove um alias\n");
}

int main(int argc, char *argv[]){

    Alias_list *list = load_alias_list();

    if(argc < 2){
        exibir_uso(argv[0]);
        return 1;
    }

    // ./idx <comando> [alias] [comando]
    if (strncmp(argv[1], "add", 3) == 0) {
        Alias alias = create_alias(argv[2], argv[3]);
        print_alias(alias);
        printf("argc: %d\n", argc);
        list = add_alias(list, alias);

    } else if (strncmp(argv[1], "list", 4) == 0) {
        list_alias(list);

    } else if (strncmp(argv[1], "exec", 4) == 0 && argc == 3) {
        exec_alias(argv[2], list);

    } else if (strncmp(argv[1], "rm", 2) == 0 && argc == 3) {
        remove_alias(list, argv[2]);

    } else {
        exibir_uso(argv[0]);
        return 1;
    }

    printf("Salvando lista de aliases\n");
    save_alias_list(list);
    return 0;
}