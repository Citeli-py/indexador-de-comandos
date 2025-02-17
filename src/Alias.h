#define MAX_ALIAS_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include "CommandNode.h"

// Estrutura para representar um alias e seu comando (lista de linhas)
typedef struct {
    char name[MAX_ALIAS_LENGTH];
    CommandNode *command_head; // Lista encadeada de linhas do comando
} Alias;

Alias create_alias(char *name, char *comando){
    Alias new_alias;
    new_alias.command_head = create_command(comando);
    strncpy(new_alias.name, name, MAX_ALIAS_LENGTH);

    return new_alias;
}

void print_alias(Alias alias){
    printf("Alias: %s\n", alias.name);
    print_command(alias.command_head); 
}

void exec_alias_command(Alias alias){
    system(build_command(alias.command_head));
}

void free_alias(Alias *alias){
    free_commandNode(alias->command_head);
}

void save_alias(Alias *alias, FILE *file) {
    if (!alias) {
        printf("NULL pointer em save_ALIAS");
        return;
    }

    fwrite(alias->name, sizeof(char), MAX_ALIAS_LENGTH, file); // Salvar nome
    save_command(alias->command_head, file); // Salvar comandos corretamente
}
