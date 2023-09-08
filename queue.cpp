#include <stdio.h>
#include <stdlib.h>

class Node{
public:
    friend class Queue;
    
private:
    Node *next;
    int data;
};
class Queue{
public:
    void output_list(Node *ptr_list);
    void pop(Node *list_ptr);
    void push(Node *list_ptr, int data);
    Queue();
    Node *head;
    Node *tail;
};

Queue::Queue(){
    head = NULL;
    tail = NULL;
}
void Queue::output_list(Node *ptr_list){

    tail = head;
    while(tail->next != NULL) {
        printf("%d ", tail->data);
        tail = tail->next;
    }
    printf("%d\n", tail->data);
}
void Queue::pop(Node *list_ptr){
    if (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
void Queue::push(Node *list_ptr, int data){

    if(head == NULL || tail == NULL){
        list_ptr = new Node;
        list_ptr->data = data;
        list_ptr->next = NULL;
        tail = head = list_ptr;
    }
    else{
        tail->next = new Node;
        tail->next->data = data;
        tail->next->next = NULL;
        tail = tail->next;
    }
}

int main(){
    Queue queue;

    int data, run = 1;
    char commend; 
    /* when you add a node, you add it at the tail */

    while (run) {
        scanf("%c", &commend);
        if (commend == 'i') {
            scanf("%d", &data);
            queue.push(queue.head, data);
        } else if (commend == 'o') {
            queue.pop(queue.head);
        } else if (commend == 'l') {
            queue.output_list(queue.head);
        } else if (commend == 'e') {
            run = 0;
        }
    }

    return 0;
}
