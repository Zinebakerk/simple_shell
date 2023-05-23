#include "main.h"
/**
 * add_node_end - Adds a new node at the end of a list_t list
 * @head: Head of the list
 * @str: New value for the node
 *
 * Return: Return the new node
 **/
list *add_node_end(list **head, char *str)
{
	list *new, *current;

	if (head == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(list));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	/* if the list is empty set the head to the new node */
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	/* Otherwise find the last node in the list and add new node */
	current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = new;
	return (*head);
}
/**
 *
 */
list *list_var_directories(char *var)
{
	list *var_dir = NULL:
	char *env_var;

	env_var = get_env(var);
	var_dir =









}
