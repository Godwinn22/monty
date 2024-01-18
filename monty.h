#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct transpD - the struct
 * @argmt: the arguments
 * @f_ptr: the file pointer
 * @data_ct: the data content
 * @trficIdx: the traffic index
 */
typedef struct transpD
{
        char *argmt;
        FILE *f_ptr;
        char *data_ct;
        int trficIdx;
} transpD_t;

extern transpD_t transpInfo;
void m_push(stack_t **head, unsigned int c);
void addnode(stack_t **head, int n);
void m_add(stack_t **head, unsigned int c);
void m_pall(stack_t **head, unsigned int c);
int m_execute(stack_t **head, char *current, unsigned int line, FILE *f_ptr);
int main(int argc, char *argv[]);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *file);
void free_stack(stack_t *head);
void f_pint(stack_t **head, unsigned int c);
void m_nop(stack_t **head, unsigned int c);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void m_pop(stack_t **head, unsigned int c);
void m_swap(stack_t **head, unsigned int c);
void m_sub(stack_t **head, unsigned int c);
void m_div(stack_t **head, unsigned int c);
void m_mul(stack_t **head, unsigned int c);
void m_mod(stack_t **head, unsigned int c);
void m_pchar(stack_t **head, unsigned int c);
void m_pstr(stack_t **head, unsigned int c);
void m_rotl(stack_t **head, unsigned int c);
void m_rotr(stack_t **head, unsigned int c);
void m_stack(stack_t **head, unsigned int c);

#endif
