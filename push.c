#include "monty.h"
/**
 * addnode - add node to the stack
 * @head: head
 * @n: node
 * Return: void
 */
void addnode(stack_t **head, int n)
{
	stack_t *newnode, *aux;

	aux = *head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = newnode;
	newnode->n = n;
	newnode->next = *head;
	newnode->prev = NULL;
	*head = newnode;
}
/**
 * addqueue - add queue to the stack
 * @head: head
 * @n: node
 * Return: void
 */
void addqueue(stack_t **head, int n)
{
	stack_t *newnode, *aux;

	aux = *head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		printf("Error\n");
	newnode->n = n;
	newnode->next = NULL;
	if (aux)
		while (aux->next)
			aux = aux->next;
	if (!aux)
	{
		*head = newnode;
		newnode->prev = NULL;
	}
	else
	{
		aux->next = newnode;
		newnode->prev = aux;
	}
}
/**
 * f_push - add node
 * @head: head of stack
 * @counter: counter
 * Return: void
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n;
	int j = 0;
	int flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
