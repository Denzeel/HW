#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//referencia: https://www.youtube.com/watch?v=YjxKYxpf51E
typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);


int main(void)
{
  Queue *queue = create_queue();
  
  if (is_empty(queue)) printf("Queue is empty.\n");
  
  enqueue(queue, 4);
  
  if (!is_empty(queue)) printf("Queue is not empty.\n");
  
  enqueue(queue, 5);
  enqueue(queue, 6);
  
  printf("Queue size: %d\n", size(queue));
  
  bool status = false;
  int value = 0;
  
  value = peek(queue, &status);
  if (status) printf("Peek successful: %d\n", value);
  
  value = dequeue(queue, &status);
  if (status) printf("Dequeue succesful: %d\n", value);
  

  value = peek(queue, &status);
  if (status) printf("Peek successful: %d\n", value);
  
  value = dequeue(queue, &status);
  if (status) printf("Dequeue succesful: %d\n", value);
  
  value = peek(queue, &status);
  if (status) printf("Peek successful: %d\n", value);
  
  value = dequeue(queue, &status);
  if (status) printf("Dequeue succesful: %d\n", value);
  
  
  value = peek(queue, &status);
  if (!status) printf("Peek unsuccessful.\n");
  
  value = dequeue(queue, &status);
  if (!status) printf("Dequeue unsuccesful.\n");
  

  destroy_queue(queue);
  
  return 0;
}

Queue *create_queue()
{
    Queue *queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    //al principio no tenemos nada
    return queue;
}

int size(Queue *queue)
{
    return queue->size;
}
bool is_empty(Queue *queue)
{
    if(queue->size == 0);
}

int peek(Queue *queue, bool *status)
{
    if(is_empty(queue))
    {
        *status = false;
        return 0;
    }
    *status = true;
    return queue->head->value;
}

void enqueue(Queue *queue, int value)
{
    Node *newNode = malloc(sizeof(Node)); //le damos malloc por el valor de la memoria total de Node
    newNode->value = value;
    newNode->next =NULL; //significa que este es el nuevo tail node

    if(is_empty(queue))
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode; //ponemos al corriente a la queue para que apunte al nuevo valor
        queue->tail = newNode;
    }
    queue->size++;
}


int dequeue(Queue *queue, bool *status)
{
    if(is_empty(queue))
    {
        *status = false;
        return 0;
    }

    *status = true;

    int value = queue->head->value;

    Node *oldHead = queue->head;

    if(queue->size == 1)
    {
        queue->head=NULL;
        queue->tail=NULL;
    }
    else
    {
        queue->head = queue->head->next;
    }

    free(oldHead);

    queue->size--;

    return value;
}

void destroy_queue(Queue *queue)
{
    Node *currentNode = queue->head;

    while(currentNode != NULL)
    {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(queue);
}