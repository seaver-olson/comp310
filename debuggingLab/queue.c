#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int value;
    struct element *next;
} ele;

void print_queue(ele* head);

//Enqueues an element in a given queue. 
void enqueue(ele* queue, ele* new){
    ele* tmp = queue;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = new;
}

//A method to dequeue an element from the queue.
ele* dequeue(ele* queue){
    if(queue){
        queue = queue->next;
        return queue;
    }else{
        return queue;
    }
}

//Method for printing out each element of a queue
//THERE ARE NO BUGS IN THIS METHOD
void print_queue(ele* head){
    if(head == NULL){
        printf("QUEUE EMPTY");
    }
    ele* tmp = head;
    while(tmp){
        printf("%d\t", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

//initalizes a queue structure
ele* create_element(int val){
    ele* tmp = malloc(sizeof(ele));
    tmp->value = val;
    tmp->next = NULL;
    return tmp;
}

//THERE ARE NO ERRORS IN THIS METHOD
int main(){
    //initalizes elements
    ele* head = create_element(0);
    ele* a = create_element(1);
    ele* b = create_element(2);
    ele* c = create_element(3);
    
    //enqueues elements
    print_queue(head);
    enqueue(head, a);
    print_queue(head);
    enqueue(head, b);
    print_queue(head);
    enqueue(head, c);
    print_queue(head);

    //empties queue
    head = dequeue(head);
    print_queue(head);
    head = dequeue(head);
    print_queue(head);
    head = dequeue(head);
    print_queue(head);
    head = dequeue(head);
    print_queue(head);
    return 0;
}

