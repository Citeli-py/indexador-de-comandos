#define MAX_LINE_LENGTH 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma linha do comando
typedef struct CommandNode {
    char line[MAX_LINE_LENGTH];
    struct CommandNode *next;
} CommandNode;


CommandNode *create_command(char *command){
    CommandNode *head = NULL;
    CommandNode *tail = NULL;

    char *str_pointer = command;

    while(*str_pointer != '\0'){
        CommandNode *node = (CommandNode *) malloc(sizeof(CommandNode));
        node->next = NULL;

        strncpy(node->line, str_pointer, MAX_LINE_LENGTH-1);
        node->line[MAX_LINE_LENGTH-1] = '\0';

        str_pointer += strlen(node->line);

        if(head == NULL)
            head = node;
        else
            tail->next = node;

        tail = node;
    }
    
    return head;
}

char *build_command(CommandNode *head){

    size_t cmd_length = 0;
    CommandNode *node_atual = head;
    while (node_atual != NULL){
        cmd_length += strlen(node_atual->line);
        node_atual = node_atual->next;
    }

    char *command = (char*)malloc(cmd_length+1);
    if(command == NULL){
        perror("Erro ao alocar memoria!");
        return NULL;
    }

    command[0] = '\0';
    node_atual = head;
    while (node_atual != NULL){
        strcat(command, node_atual->line);
        node_atual = node_atual->next;
    }

    return command;
}


void print_command(CommandNode *cmd_node){

    if(cmd_node != NULL){
        printf("%s", cmd_node->line);
        print_command(cmd_node->next);
    }
}

void free_commandNode(CommandNode *node){
    for(CommandNode *pointer=node; pointer != NULL;){
        CommandNode *next_pointer = pointer->next;
        free(pointer);
        pointer = next_pointer;
    }
}

void save_command(CommandNode *comand_head, FILE *file) {
    CommandNode *pointer = comand_head;

    while (pointer != NULL) {
        size_t length = strlen(pointer->line) + 1; // +1 para incluir o '\0'
        fwrite(&length, sizeof(size_t), 1, file); // Salva o tamanho da string
        fwrite(pointer->line, sizeof(char), length, file); // Salva a string
        pointer = pointer->next;
    }

    // Escrever um tamanho especial (0) para indicar o fim da lista
    size_t end_marker = 0;
    fwrite(&end_marker, sizeof(size_t), 1, file);
}


CommandNode *load_command(FILE *file) {
    CommandNode *head = NULL;
    CommandNode *tail = NULL;
    size_t length;

    while (fread(&length, sizeof(size_t), 1, file)) {
        if (length == 0) // Se o marcador de fim for encontrado, para de ler
            break;

        CommandNode *node = (CommandNode *)malloc(sizeof(CommandNode));
        if (!node) {
            perror("Erro ao alocar memória");
            return NULL;
        }

        fread(node->line, sizeof(char), length, file);
        node->next = NULL;

        if (head == NULL)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    return head;
}

