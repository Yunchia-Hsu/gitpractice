#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int value;
	int index; //current_index
	int move_cost;
	
	struct s_stack_node *prev;
	struct s_stack_node *next;
	struct s_stack_node *target;
}	t_stack_node;

t_stack_node *find_last_node (t_stack_node *head)
{
    
    if (head == NULL)
        return (NULL);
    while (head->next != NULL) 
        head = head->next;   
    return (head);
}

static void    print_stack(t_stack_node *stack)
{
    t_stack_node *current = stack;

    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

      

int main()
{
    t_stack_node *b; 
    t_stack_node *last_n;

    b = malloc(sizeof(t_stack_node));
    b->next = malloc(sizeof(t_stack_node));
    b->next->next = malloc(sizeof(t_stack_node));
    //b->next->next->next = malloc(sizeof(t_stack_node));


    b->value = 2;
    b->next->value = 3;
    b->next->next->value = 52;
    b->next->next->next = NULL;
   
    b->prev = NULL;
    b->next->prev = b;
    b->next->next->prev = b->next;
    
    //sort_three(&b);
     print_stack(b);
     last_n =find_last_node (b);
    printf ("%d\n", last_n->value);
}