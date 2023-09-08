#include <iostream>
using namespace std;

class Node{
public:
    friend class Linked_list;
private:
    int data;
    Node *next;
    Node *last;
};

class Linked_list{
public:
    void output();
    void add_node(int x);
    void reverse();
    void insert(int i);
    void deleted(int i);
    Linked_list();
private:
    Node *head;
    Node *tail;
};

Linked_list::Linked_list(){
    head = NULL;
    tail = NULL;
}

void Linked_list::output(){
    if (head == NULL) {                     
        return;
    }
    Node *temp = tail;          
    while (tail != head) {                 // Traversal
        cout <<tail->data<<" ";
        tail = tail->last;
    }
    cout << tail->data;
    tail = tail->next;
    while (tail != temp) {                 // Traversal
        cout << " " << tail->data;
        tail = tail->next;
    }
    cout << " " << tail->data;

}
void Linked_list::add_node(int data){
    if (head == NULL || tail == NULL) {
        head = (Node*)malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
        head->last = NULL;
        tail = head;
    } else {
        tail->next = (Node*)malloc(sizeof(Node));
        tail->next->data = data;
        tail->next->next = NULL;
        tail->next->last = tail;
        tail = tail->next;
    }
}
void Linked_list::reverse(){
    Node *temp1, *temp2 = NULL, *newtail = head;
    temp1 = head->next;
    head->next = NULL;
    do{
        head->last = temp1;
        head = head->last;
        if (head->next != NULL) temp1 = head->next;
        head->next = head->last;
    }while(head != tail);
    head->last = NULL;
    tail = newtail;
}
void Linked_list::insert(int i){
    if (head == NULL) {
        return ;
    }
    Node *temp = (Node*)malloc(sizeof(Node)), *org_tail = tail;
    tail = head;
    for (int j = 0; j < i - 1; j++) {
        tail = tail->next;
    }
    tail->next->last = temp;
    temp->next = tail->next;
    temp->last = tail;
    tail->next = temp;
    tail = org_tail;
}
void Linked_list::deleted(int i){
    if (head == NULL) {
        return ;
    }
    Node *temp, *org_tail = tail;
    tail = head;
    for (int j = 0; j < i; j++) {
        tail = tail->next;
    }
    tail->last->next = tail->next;
    tail->next->last = tail->last;

    free(tail);
    tail = org_tail;
}


int main(){
    Linked_list my_list;

    int data, input_size, i;
    /* when you add a node, you add it at the tail */

    cin >> input_size;

    for (int i = 0; i < input_size; ++i) {
        cin >> data;
        my_list.add_node(data);
    }
    my_list.output();
    my_list.reverse();
    my_list.output();
    cin >> i;
    my_list.insert(i);
    my_list.output();
    cin >> i;
    my_list.deleted(i);
    my_list.output();

    return 0;
}