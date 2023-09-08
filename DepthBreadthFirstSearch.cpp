#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100
#define TRUE 1
#define FALSE 0

using namespace std;


class Node{
public:
    friend class Queue;
// private:
    Node *next;
    int data;
};
class Queue{
public:
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
void Queue::pop(Node *list_ptr){
    if (head != NULL) {
        printf("V%d ", head->data);
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

typedef struct node_tag{
    int vertex;
    struct node_tag *link;
} node;

class G_search{
    private:
        node *adjlist[MAX_V + 1];
        int visited[MAX_V + 1];
        int total_vertex;
    public:
        void build_adjlist();
        void show_adjlist();
        void dfs(int);
        void bfs(Queue queue);
        void clear_visited();
        node *searchlast(node *);
};
void G_search::build_adjlist()
{
    ifstream fin;
    node *node, *lastnode;
    int vi, vj, weight;
    fin.open("graph_data.dat", ios::in);
    if (!fin.good()) {
        perror("graph_data.dat");
        exit(0);
    }

    fin >> total_vertex;
    for (vi = 1; vi <= total_vertex; vi++) {
        visited[vi] = FALSE;
        adjlist[vi] = new node_tag;
        adjlist[vi]->vertex = vi;
        adjlist[vi]->link = NULL;
    }

    for (vi = 1; vi <= total_vertex; vi++) {
        for (vj = 1; vj <= total_vertex; vj++) {
            fin >> weight;
            if (weight != 0) {
                node = new node_tag;
                node->vertex = vj;
                node->link = NULL;
                lastnode = searchlast(adjlist[vi]);
                lastnode->link = node;
            }
        }
    }
    fin.close();
}
void G_search::show_adjlist()
{
    int index;
    node *ptr;

    cout << "Head   adjacency nodes\n";
    cout << "-----------------------\n";
    for (index = 1; index <= total_vertex; index++) {
        cout << "V" << adjlist[index]->vertex << " ";
        ptr = adjlist[index]->link;
        while (ptr != NULL) {
            cout << "--> V" << ptr->vertex << " ";
            ptr = ptr->link;
        }
        cout << "\n";
    }
}
void G_search::dfs(int v)
{
    node *ptr;
    int w;

    cout << "V" << adjlist[v]->vertex << " ";
    visited[v] = TRUE;
    ptr = adjlist[v]->link;
    do {
        w = ptr->vertex;
        if (!visited[w]) {
            dfs(w);
        } else {
            ptr = ptr->link;
        }
    } while (ptr != NULL);
}
void G_search::bfs(Queue queue)
{
    node *ptr;
    visited[1] = TRUE;

    while (queue.head != NULL) {
        ptr = adjlist[queue.head->data]->link;
        while (ptr != NULL) {
            if (visited[ptr->vertex] == FALSE) {
                queue.push(queue.head, ptr->vertex);
                visited[ptr->vertex] = TRUE;
            }
            ptr = ptr->link;
        }
        queue.pop(queue.head);
    }
}

node *G_search::searchlast(node *linklist)
{
    node *ptr;

    ptr = linklist;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    return ptr;
}
void G_search::clear_visited()
{
    for (int i = 1; i <= total_vertex; i++) {
        visited[i] = FALSE;
    }
}

int main()
{
    Queue queue;
    G_search obj;

    obj.build_adjlist();
    obj.show_adjlist();
    cout << "\n---Depth First Search---\n";
    obj.dfs(1);
    obj.clear_visited();
    cout << "\n---Breadth First Search---\n";
    queue.push(queue.head, 1);
    obj.bfs(queue);

    system("PAUSE");
    return 0;
}