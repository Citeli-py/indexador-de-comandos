#include "src/Alias_list.h"
#include <string.h>

// Exibe o uso do programa
void exibir_uso() {
    printf("Uso: idx <comando> [alias] [comando]\n");
    printf("Comandos:\n");
    printf("  add <alias> \"<comando>\"       - Adiciona um novo alias\n");
    printf("  list                          - Lista todos os aliases\n");
    printf("  run <alias>                   - Executa o comando associado ao alias\n");
    printf("  rm <alias>                    - Remove um alias\n");
}

int main(int argc, char *argv[]){

    Alias_list *list = load_alias_list();

    if(argc < 2){
        exibir_uso();
        return 1;
    }

    // ./idx <comando> [alias] [comando]
    if (strncmp(argv[1], "add", 3) == 0) {
        Alias alias = create_alias(argv[2], argv[3]);
        list = add_alias(list, alias);
        save_alias_list(list);

    } else if (strncmp(argv[1], "list", 4) == 0) {
        int command_print = 0;
        if( (argc>2) && (strncmp(argv[2], "-c", 2) == 0))
            command_print = 1;

        list_alias(list, command_print);

    } else if (strncmp(argv[1], "run", 3) == 0 && argc == 3) {
        exec_alias(argv[2], list);

    } else if (strncmp(argv[1], "rm", 2) == 0 && argc == 3) {
        remove_alias(&list, argv[2]);
        save_alias_list(list);

    } else {
        exibir_uso(argv[0]);
        return 1;
    }
    
    return 0;
}