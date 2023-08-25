#include "monty.h"
/**
 * f_sub - substraction
 * @head: head
 * @counter: line nbr
 * Return: void
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int su, nod;

	aux = *head;
	for (nod = 0; aux != NULL; nod++)
		aux = aux->next;
	if (nod < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	su = aux->next->n - aux->n;
	aux->next->n = su;
	*head = aux->next;
	free(aux);
}

