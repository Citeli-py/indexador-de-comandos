#include "src/Alias_list.h"
#include <string.h>

/*
printf("Uso: %s <comando> [alias] [comando]\n", argv[0]);
printf("Comandos:\n");
printf("  add <alias> <comando> - Adiciona um novo alias\n");
printf("  list - Lista todos os aliases\n");
printf("  exec <alias> - Executa o comando associado ao alias\n");
printf("  rm <alias> - Remove um alias\n");
*/

int main(int argc, char *argv[]){

    Alias_list *list = load_alias_list();

    // Alias_list *list = NULL;
    // char *comando = "cd ~/Programação/JavaScript/Residência/Reforma && code . && echo \"Vai trabalhar na residencia campeão, você é foda!\"";

    // Alias api_back;
    // api_back = create_alias("api", comando);

    // list = add_alias(list, api_back);

    // char *comando_motivacional = "echo \"Vai trabalhar na residencia campeão, você é foda!\"";

    // Alias motivacional;
    // motivacional = create_alias("motivacional", comando_motivacional);

    // list = add_alias(list, motivacional);

    list_alias(list);
    exec_alias("motivacional", list);
    save_alias_list(list);
}