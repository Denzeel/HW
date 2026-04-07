#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//referencia: https://www.youtube.com/watch?v=Flk5yrlx5Qo&t=607s

//creamos el datatype base con los atributos necesarios
typedef struct
{
    int *collection;
    int capacity;
    int size;
} Stack;

//func prototypes
Stack *create_stack(int capacity);
void destroy_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);

//main func con demo de todos las funciones utilizables.
int main(void)
{
    Stack *stack = create_stack(5);

    if(stack == NULL){
        printf("err creating stack\n");
        return 1;
    }

    if(is_empty(stack)) printf("stack is empty\n");

    push(stack, 2);
    printf("Stack size: %d\n", stack->size);
    
    push(stack, 9);
    push(stack, 7);
    push(stack, 6);
    push(stack, 3);

    if(is_full(stack)) printf("stack is full\n");
    printf("Stack size: %d\n", stack->size);

    bool try_push = push(stack, 5);

    if(!try_push) printf("Push failed\n");

    int peek_val = 0;
    peek(stack, &peek_val);

    printf("peek val %d\n", peek_val);

    int pop_val = 0;
    
    for(int i = 0; i<5; i++)
    {
        pop(stack, &pop_val);
        printf("popped value: %d\n", pop_val);
    }

    destroy_stack(stack);
    return 0;
}


//creates stack on the heap and initializes members
Stack *create_stack(int capacity)
{
    if (capacity <= 0) return NULL;

    //allocate mem for stack 
    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    //allocate mem for int arr
    stack->collection = malloc(sizeof(int) * capacity);
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void destroy_stack(Stack *stack)
{
    free(stack->collection); //free data
    free(stack); //then free the struct itself
}

bool is_full(Stack *stack)
{
    return stack->capacity == stack->size;
}

bool is_empty(Stack *stack)
{
    return stack->size == 0;
}

bool push(Stack *stack, int item)
{
    if(is_full(stack)) return false;

    stack->collection[stack->size] = item;
    stack->size++;
    return true;
}

//return top item without deleting it
bool peek(Stack *stack, int *item)
{
    if(is_empty(stack)) return false;

    *item = stack->collection[stack->size - 1];

    return true;
}

bool pop(Stack *stack, int *item)
{
    if(is_empty(stack)) return false;

    stack->size--;
    *item = stack->collection[stack->size];

    return true;
}