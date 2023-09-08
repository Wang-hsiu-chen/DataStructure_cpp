#include <iostream>
#include <fstream>

using namespace std;

class Node{
public:
    friend class Sort;
private:
    Node *right;
    Node *left;
    int data;
};

class Sort{
public:
    void build_database();
    void bubble_sort();
    void cocktail_shacker_sort();
    void insertion_sort();
    void shell_sort();
    void heap_sort();
    void change_to_heap(int*, int);
    void selection_sort();
    void quick_sort(int, int);
    void merge_sort();
    void merge();
    void radix_sort();
    void gnome_sort();
    void bitonic_sort();
    void binary_tree_sort();
    void input_to_binarytree(Node *, int);
    void output_from_binarytree(Node *);
    void bucket_sort();
    void counting_sort();
    void pigeonhole_sort();
    void library_sort();
    void block_sort();
    void introsort_sort();
    void patience_sort();
    //std::sort
    //std::stable_sort
    int size = 1;
    Node *head = NULL;
    Node *tail = NULL;
private:
    int *data;
    int temp;
};

void Sort::build_database()
{
    ifstream fin;
    fin.open("sort_data.dat", ios::in);
    if (!fin.good()) {
        perror("sort_data.dat");
        exit(0);
    }

    fin >> size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        fin >> data[i];
    }
    fin.close();
}
void Sort::bubble_sort()
{
    int *arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = data[i];

    cout << "Bubble Sort: \n";
    int s = size;
    bool finish = false;
    while (s > 0 && !finish) {
        finish = true;
        for (int i = 0; i < s-1; i++) {
            if (arr[i] > arr[i+1]) {
                arr[i] = arr[i] + arr[i+1];
                arr[i+1] = arr[i] - arr[i+1];
                arr[i] = arr[i] - arr[i+1];
                finish = false;
            }
        }
        s--;
        for (int j = 0; j < size; j++)
            cout << arr[j] << " ";
        cout << endl;
    }
    free(arr);
}
void Sort::cocktail_shacker_sort()
{
    int *arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = data[i];

    cout << "Cocktail Shacker Sort: \n";
    int end = size, start = 0;
    bool finish = false;
    while (end > start) {
        finish = true;
        for (int i = start; i < end-1; i++) {
            if (arr[i] > arr[i+1]) {
                arr[i] = arr[i] + arr[i+1];
                arr[i+1] = arr[i] - arr[i+1];
                arr[i] = arr[i] - arr[i+1];
                finish = false;
            }
        }
        if (finish) break;
        end--;
        for (int j = 0; j < size; j++)
            cout << arr[j] << " ";
        cout << endl;
        for (int i = end - 1; i > start; i--) {
            if (arr[i] < arr[i-1]) {
                arr[i] = arr[i] + arr[i-1];
                arr[i-1] = arr[i] - arr[i-1];
                arr[i] = arr[i] - arr[i-1];
                finish = false;
            }
        }
        if (finish) break;
        start++;
        for (int j = 0; j < size; j++)
            cout << arr[j] << " ";
        cout << endl;
    }
    free(arr);
}
void Sort::insertion_sort()
{
    int *arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = data[i];

    cout << "Insertion Sort: \n";
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
        for (int j = 0; j < size; j++)
            cout << arr[j] << " ";
        cout << endl;
    }
    free(arr);
}
void Sort::shell_sort()
{
    int *arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = data[i];

    for (int gap = size/2; gap >= 1; gap /= 2) {
        for (int group = 0; group < gap; group++) {
            for (int i = group + gap; i < size; i += gap) {
                int temp = arr[i];
                int compare = i;
                while (compare > group && arr[compare - gap] > temp) {
                    arr[compare] = arr[compare - gap];
                    arr[compare - gap] = temp;
                    compare -= gap;
                }
            }
        }
        for (int i = 0; i < size; i++) 
            cout << arr[i] << " ";
        cout << endl;
    }
    free(arr);
}
void Sort::heap_sort()
{
    int *arr;
    arr = new int[size+1];
    for (int i = 1; i < size+1; i++) {
        arr[i] = data[i-1];
        change_to_heap(arr, i);
    }

    cout << "Heap Sort: \n";
    for (int i = size - 1; i > 0; i--) {
        int temp = arr[i+1];
        arr[i+1] = arr[1];
        arr[1] = temp;
        for (int j = 1; j <= i; j++)
            change_to_heap(arr, j);
        for (int j = 1; j < size + 1; j++) 
            cout << arr[j] << " ";
        cout << endl;
    }
    free(arr);
}
void Sort::change_to_heap(int *arr, int n)
{
    while (n > 1) {
        if (arr[n] <= arr[n/2]) break;
        else {
            int temp = arr[n];
            arr[n] = arr[n/2];
            arr[n/2] = temp;
        }
        n /= 2;
    }
}
void Sort::selection_sort()
{
    int *arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = data[i];

    cout << "Selection Sort: \n";
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
        for (int j = 0; j < size; j++)
            cout << arr[j] << " ";
        cout << endl;
    }
    free(arr);
}
void Sort::quick_sort(int left, int right)
{
    if (right - left == size-1) cout << "Quick Sort: \n";
    int lbase, rbase, i;
    if (left < right) {
        lbase = left + 1;
        while (data[lbase] < data[left]) lbase++;
        rbase = right;
        while (data[rbase] > data[left]) rbase--;
        while (lbase < rbase) {
            temp = data[lbase];
            data[lbase] = data[rbase];
            data[rbase] = temp;
            lbase++;
            while (data[lbase] < data[left]) lbase++;
            rbase--;
            while (data[rbase] > data[left]) rbase--;
        }
        temp = data[left];
        data[left] = data[rbase];
        data[rbase] = temp;
        for (i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        quick_sort(left, rbase-1);
        quick_sort(rbase+1, right);
    }
}
void Sort::merge_sort()
{

}
void Sort::merge()
{

}
void Sort::radix_sort()
{
    int *arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = data[i];

    int max = arr[0], digit = 1;
    for (int i = 1; i < size; i++) 
        if (arr[i] > max) max = arr[i];
    while (max > 9) {
        max /= 10;
        digit++;
    }
    for (int d = 1; d <= max; d *= 10) {
        int bucket_size = 1, bucket[10][bucket_size] = {-1};
        // 未完成，要想辦法動態配置二微陣列的大小
        for (int i = 0; i < size; i++) {
            while (bucket[arr[i]/d % 10][bucket_size - 1] >= 0) 
                bucket_size++;
            bucket[arr[i] % 10][bucket_size - 1] = arr[i];
        }
        int count = 0;
        for (int i = 0; i < 10; i++) 
            for (int j = 0; j < bucket_size; j++)
                if (bucket[i][j] >= 0) arr[count++] = bucket[i][j];
    }

}
void Sort::gnome_sort()
{

}
void Sort::bitonic_sort()
{

}
void Sort::binary_tree_sort()
{
    int *arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = data[i];

    cout << "Binary Tree Sort: \n";
    for (int i = 0; i < size; i++) {
        input_to_binarytree(head, arr[i]);
    }
    output_from_binarytree(head);
    cout << endl;
    free(arr);
}
void Sort::input_to_binarytree(Node *ptr, int data)
{
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
            input_to_binarytree(ptr, data);
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
            input_to_binarytree(ptr, data);
        }
    }
}
void Sort::output_from_binarytree(Node *ptr)
{
    if (ptr == NULL) return ;
    output_from_binarytree(ptr->left);
    cout << ptr->data << " ";
    output_from_binarytree(ptr->right);
    return ;
}
void Sort::bucket_sort()
{

}
void Sort::counting_sort()
{

}
void Sort::pigeonhole_sort()
{

}
void Sort::library_sort()
{

}
void Sort::block_sort()
{

}
void Sort::introsort_sort()
{

}
void Sort::patience_sort()
{

}

int main()
{
    Sort sort;
    sort.build_database();
    sort.bubble_sort();
    sort.cocktail_shacker_sort();
    sort.insertion_sort();
    sort.shell_sort();
    sort.selection_sort();
    sort.heap_sort();
    sort.quick_sort(0, sort.size-1);
    sort.build_database();
    sort.binary_tree_sort();
    
    system("PAUSE");
    return 0;
}