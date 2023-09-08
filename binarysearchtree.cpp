#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    friend class Linked_list;
    
private:
    Node *child[50];
    Node *right;
    Node *left;
    int data;
};

class Linked_list{
public:
    void in_binary_tree(Node *ptr, int data);
    void preoutput(Node *ptr);
    void output(Node *ptr);
    void posoutput(Node *ptr);
    Node *find(int data);
    void del(Node *ptr);
    void AVL(Node *ptr);
    Linked_list();
    Node *head;
    Node *tail;
private:
    int rnull = 0;
    int lnull = 0;
};

Linked_list::Linked_list(){
    head = NULL;
    tail = NULL;
}
void Linked_list::in_binary_tree(Node *ptr, int data){
    if (head == NULL) {
        ptr = new Node;
        ptr->data = data;
        head = tail = ptr;
        ptr->left = ptr->right = NULL;
    } else if (data < ptr->data) {
        if (ptr->left == NULL) {
            ptr->left = new Node;
            ptr = ptr->left;
            ptr->data = data;
            ptr->left = ptr->right = NULL;
        } else if (ptr->left != NULL) {
            ptr = ptr->left;
            in_binary_tree(ptr, data);
        }
    } else if (data >= ptr->data) {
        if (ptr->right == NULL) {
            ptr->right = new Node;
            ptr = ptr->right;
            ptr->data = data;
            ptr->left = ptr->right = NULL;
            return ;
        } else if (ptr->right != NULL) {
            ptr = ptr->right;
            in_binary_tree(ptr, data);
        }
    }
    return ;
}
void Linked_list::preoutput(Node *ptr){
    if (ptr == NULL) {                     
        return;
    }
    cout << ptr->data;
    preoutput(ptr->left);
    preoutput(ptr->right);
}
void Linked_list::output(Node *ptr){
    if (ptr == NULL) {
        return ;
    }
    output(ptr->left);
    cout << ptr->data;
    output(ptr->right);
    return ;
}
void Linked_list::posoutput(Node *ptr){
    if (ptr == NULL) {
        return ;
    }
    posoutput(ptr->left);
    posoutput(ptr->right);
    cout << ptr->data;
    return;
}
Node* Linked_list::find(int data){
    Node *ptr = head;
    while (1) {
        if (ptr == NULL) {
            cout << "doesn't have this node.\n";
            return NULL;
        } else if (ptr->data == data) {
            cout << "find";
            return ptr;
        } else if (data < ptr->data) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
}
void Linked_list::del(Node *ptr){
    if (ptr->left == NULL && ptr->right == NULL) {
        free(ptr);
    } else if (ptr->left == NULL && ptr->right != NULL) {
        ptr->data = ptr->right->data;
        free(ptr->right);
    } else if (ptr->right == NULL && ptr->left != NULL) {
        ptr->data = ptr->left->data;
        free(ptr->left);
    } else {
        Node *temp = ptr->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        ptr->data = temp->data;
        free(temp);
    }
}

void Linked_list::AVL(Node *ptr){
    if (ptr == NULL) {                     
        return;
    }
    if (ptr->left != NULL && ptr->right == NULL) {
        rnull += 1;
    } else if (ptr->right != NULL && ptr->left == NULL) {
        lnull += 1;
    } else {
        rnull = lnull = 0;
    }
    //cout << ptr->data;
    preoutput(ptr->left);
    preoutput(ptr->right);
}

int main(){
    Linked_list my_list;

    int data, i;
    string commend;
    
    while (1) {
        cin >> commend;

        if (commend == "in") {
            cin >> data;
            my_list.in_binary_tree(my_list.head, data);
        } else if (commend == "preout") {
            my_list.preoutput(my_list.head);
        } else if (commend == "out") {
            my_list.output(my_list.head);
        } else if (commend == "posout") {
            my_list.posoutput(my_list.head);
        } else if (commend == "del") {
            cin >> data;
            Node *ptr = my_list.find(data);
            if (ptr != NULL) {
                my_list.del(ptr);
            }
        } else if (commend == "add") {
            cin >> data;
            Node *ptr = my_list.find(data);
            if (ptr != NULL) {
                my_list.in_binary_tree(my_list.head, data);
            }
        } else if (commend == "AVL") {

        } 
    }

    return 0;
}