/*
# Author: Ioannis Davanos
# Academic ID: 4622
# E-mail: csd4622@csd.uoc.gr
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_INPUT 1024
#define MAX_PARAM 100
#define MAX_TOKENS 512
#define MAX_DIRNAME 500
#define PIPE '|'
#define READ '<'
#define WRITE '>'
#define APPEND_STR ">>"
#define PIPE_STR "|"
#define READ_STR "<"
#define WRITE_STR ">"
#define SPACE ' '
#define DEBUG_PRINT 0

typedef struct command
{
    char *params[MAX_PARAM]; // we store the arguments of the command
    int read;                // we store the index of the argument that is the input file
    int write;               // we store the index of the argument that is the output file
    int ap;                  // we store the index of the argument that is the append file
    int pipes;               // we store the number of pipes
    struct command *next;    // we store the next command in the pipeline(if there is a pipe)
} command;

char *removeQuotes(char *);// function that removes the quotes from the input(in the beginning and in the end)
int cmd_checker(char *);// function that checks if the command is echo,mkdir or cat
command *create_node();// function that creates a node of the linked list
int pipe_counter(char *); // function that counts the number of pipes in the input
void addSPaces(char *); // function that adds spaces before and after the special characters(<<,<,>,|)
command *initialize(command *c, char **, int );  // function that creates the linked list
void initialize_tokens(char *[MAX_TOKENS]); // Initialize the tokens array
void tokenize(char *command, char **, char *); // Tokenize the input command(command is the input command,tokens is the array that we store the tokens,dm is the delimiter)
command *execute_command(command *); // Execute the command
command *clear_list(command *); // free the memory of the linked list
command *run_command(command *); // run the command
void display_prompt();
void get_command(char *, size_t ); // gets the input from the user (stdin)
void array_copy(char *[MAX_TOKENS], char *[MAX_TOKENS]); // copy the tokens array to the copy array
void print_list(command *);
void execute(char *); // execute the command (main function)