#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Folder{
public:
    friend class Tree;
private:
    Folder *child[10];
    File *file[10];
    int child_num = 0;
    int file_num = 0;
    string name;
};
class File{
public:
    friend class Tree;
private:
    string name;
    int index;
};
class BinaryTree{
public:
    friend class Tree;
private:
    BinaryTree *left;
    BinaryTree *right;
    string name;
    int index;
};

class Tree{
public:
    Tree();
    void input(Folder *ptr, string name);
    void inputfile(Folder *ptr, string name);
    void output(Folder *ptr);
    void turntobinarytree(Folder *ptr);
    Folder *find(Folder *ptr);
    Folder *head;
    Folder *tail;
    BinaryTree *headb;
    BinaryTree *tailb;
private:
    int rnull = 0;
    int lnull = 0;
};
Tree::Tree(){
    head = NULL;
    tail = NULL;
}
void Tree::input(Folder *ptr, string name){
    if (tail == NULL) {
        ptr = new Folder;
        ptr->name = name;
        tail = head = ptr;
        for (int i = 0; i < 10; i++) {
            ptr->child[i] = NULL;
        }
        
    } else {
        ptr->child[ptr->child_num] = new Folder;
        ptr->child[ptr->child_num]->name = name;
        for (int i = 0; i < 10; i++) {
            ptr->child[ptr->child_num]->child[i] = NULL;
        }
        ptr->child_num++;       
    }
    return ;
}
void Tree::inputfile(Folder *ptr, string name){
    if (ptr == NULL) {
        return ;
    }
    ptr->file[ptr->file_num] = new File;
    ptr->file[ptr->file_num]->name = name;
    cout << "input index: ";
    cin >> ptr->file[ptr->file_num]->index;
    ptr->file_num++;
    return ;
}
void Tree::output(Folder *ptr){
    if (ptr == NULL) {
        return ;
    }
    cout << "parent: " << ptr->name << endl << "childs: ";
    for (int i = 0; i < ptr->child_num; i++) {
        cout << ptr->child[i]->name << " ";
    }
    return ;
}
Folder* Tree::find(Folder *ptr){
    string dir;
    char slash;
    cin >> slash >> dir;
    if (dir == ptr->name) {
        while (ptr->child_num > 0) {
            cin >> slash >> dir;
            for (int i = 0; i < ptr->child_num; i++) {
                if (dir == ptr->child[i]->name) {
                    ptr = ptr->child[i];
                }
            }
        }
        cout << "location: " << ptr->name;
        return ptr;
    } else {
        cout << "false location: " << ptr->name;
        return tail;
    }
}
void Tree::turntobinarytree(Folder *ptr){//not finish, cant connect right child with parent in binary tree. 
    queue<Folder*> temp;
    BinaryTree *root = headb;

    headb = new BinaryTree;
    temp.push(ptr);
    
    while (!temp.empty()) {
        ptr = temp.front();
        
        tailb->name = ptr->name;
        while (ptr->child_num > 0) {
            temp.push(ptr->child[ptr->child_num]);
            if (ptr->child_num == 0) {
                tailb->left = new BinaryTree;
                tailb->left->name = ptr->child[ptr->child_num]->name;
                root = tailb;
            } else {
                tailb->right = new BinaryTree;
                tailb->right->name = ptr->child[ptr->child_num]->name;
                tailb = tailb->right;
            }
            ptr->child_num++;
        }
        while (ptr->file_num > 0) {
            tailb->right = new BinaryTree;
            tailb->right->name = ptr->file[ptr->file_num]->name;
            tailb = tailb->right;
            ptr->file_num++;
        }
        temp.pop();
    }
    return ;
}

int main(){
    Tree my_list;
    string commend, name;
    
    while (1) {
        cin >> commend;

        if (commend == "mkdir") {
            cin >> name;
            my_list.input(my_list.tail, name);
        } else if (commend == "mkf") {
            cin >> name;
            my_list.inputfile(my_list.tail, name);
        } else if (commend == "list") {
            my_list.output(my_list.tail);
        } else if (commend == "cd") {
            my_list.tail = my_list.find(my_list.tail);
        } else if (commend == "cd.") {
            my_list.tail = my_list.head;
        } else if (commend == "turn_to_binary_tree") {
            my_list.turntobinarytree(my_list.head);
        }
    }

    return 0;
}