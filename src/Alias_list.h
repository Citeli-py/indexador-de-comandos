#include "Alias.h"

#define ALIAS_FILE "aliases.bin"

#define SUCESSO 1
#define ERRO 0


struct Alias_list_struct {
    Alias alias;
    struct Alias_list_struct *next;
};

// Essa lista de 
typedef struct Alias_list_struct Alias_list;


Alias_list* create_alias_list(){
    return NULL;
}


/*
    Salva alias em um arquivo binário
*/
int save_alias_list(Alias_list *alias_list) {
    FILE *file = fopen(ALIAS_FILE, "wb");
    if (!file) {
        perror("Erro ao abrir arquivo para escrita");
        return ERRO;
    }

    Alias_list *current = alias_list;
    while (current != NULL) {
        save_alias(&current->alias, file);
        current = current->next;
    }

    fclose(file);
    return SUCESSO;
}


Alias_list* load_alias_list() {
    FILE *file = fopen(ALIAS_FILE, "rb");
    if (!file) {
        perror("Erro ao abrir arquivo para leitura");
        return NULL;
    }

    Alias_list *list = NULL;

    while (1) {
        Alias alias;
        if (fread(alias.name, sizeof(char), MAX_ALIAS_LENGTH, file) != MAX_ALIAS_LENGTH) {
            break; // Fim do arquivo
        }

        alias.command_head = load_command(file);

        Alias_list *new_node = (Alias_list *)malloc(sizeof(Alias_list));
        if (!new_node) {
            perror("Erro ao alocar memória");
            fclose(file);
            return NULL;
        }

        new_node->alias = alias;
        new_node->next = list;
        list = new_node;
        printf("LOAD ALIAS: %s\n", alias.name);
    }

    fclose(file);
    return list;
}


Alias_list* add_alias(Alias_list* list, Alias alias){
    // Lista vazia
    if(list == NULL) {
        list = (Alias_list*)malloc(sizeof(Alias_list));
        list->alias = alias;
        list->next = NULL;
        return list;
    }

    Alias_list *aux = (Alias_list*) malloc(sizeof(Alias_list));
    aux->alias = alias;
    aux->next = list;

    // Criar arquivo de comando
    return aux;
}

void list_alias(Alias_list* list){

    if(list != NULL){
        print_alias(list->alias);
        list_alias(list->next);
    }
}

int exec_alias(char *alias, Alias_list *list){
    Alias_list *ptr = list;
    while (ptr!= NULL)
    {
        if(strncmp(alias, ptr->alias.name, MAX_ALIAS_LENGTH) == 0)
            break;

        ptr = ptr->next;
    }
    

    if(ptr == NULL)
        return ERRO;

    exec_alias_command(ptr->alias);
    return SUCESSO;
}

int remove_alias(Alias_list *list, char *alias){
    Alias_list *ptr = list;
    Alias_list *prev = NULL;

    while (ptr!= NULL)
    {
        if(strncmp(alias, ptr->alias.name, MAX_ALIAS_LENGTH) == 0)
            break;

        prev = ptr;
        ptr = ptr->next;
    }
    

    if(ptr == NULL)
        return ERRO;

    if(prev == NULL){
        list = ptr->next;
    } else {
        prev->next = ptr->next;
    }

    free_alias(&ptr->alias);
    free(ptr);
    return SUCESSO;
}


