#include<iostream>
using namespace std;

void max_heapify(int a[] , int n , int i);
void min_heapify(int a[] , int n , int i);
void delete_max_heapify(int a[] , int n, int i );
void delete_min_heapify(int a[] , int n, int i );
void max_insert(int a[] , int &n , int key){

    n=n+1;
    a[n-1]=key;
    max_heapify(a , n , n-1);
    
}
void min_insert(int a[] , int &n , int key){

    n=n+1;
    a[n-1]=key;
    min_heapify(a , n , n-1);
    
}
void max_heapify(int a[] , int n , int i){

    int parent =(i-1)/2;

    if(a[i] > a[parent]){ // maxheap

        int temp = a[parent];
        a[parent]=a[i];
        a[i]=temp;
        max_heapify(a,n,parent);
    }
    
}
void min_heapify(int a[] , int n , int i){

    int parent = (i - 1) / 2;

    if (a[i] < a[parent]) {
        swap(a[i], a[parent]); 
        min_heapify(a, n, parent); 
    }
}
void display(int a[] , int n){

    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
}
void min_delete(int a[] , int &n ){

    cout<<"Delete the root:"<<a[0]<<endl;
    a[0]=a[n-1];
    n=n-1;

    delete_min_heapify( a, n,0);
}
void delete_min_heapify(int a[] , int n, int i ){
    int smallest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;
    
    if(a[left] < a[smallest]){
        smallest=left;
    }
    else if(a[right] < a[smallest]){
        smallest=right;
    }
     if(smallest!=i){
        swap(a[i],a[smallest]);
        delete_min_heapify( a, n,smallest);
    }
}
void max_delete(int a[] , int &n ){

    cout<<"Delete the root:"<<a[0]<<endl;
    a[0]=a[n-1];
    n=n-1;

    delete_max_heapify( a, n,0);
}
void delete_max_heapify(int a[] , int n, int i ){
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;
    
    if(a[left] > a[largest]){
        largest=left;
    }
    else if(a[right] > a[largest]){
        largest=right;
    }
     if(largest!=i){
        swap(a[i],a[largest]);
        delete_max_heapify( a, n,largest);
    }
}
int main() {
    int a[20];
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    display(a, n);
    cout << endl;

    int choice;
    do {
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                int choice1;
                do {
                    cout << "1. MAX_INSERT\n2. MIN_INSERT" << endl;
                    cin >> choice1;

                    switch (choice1) {
                        case 1:
                            max_insert(a, n, 100);
                            break;
                        case 2:
                            min_insert(a, n, 70);
                            break;
                    }

                    cout << "Do you want to continue (1 for Yes, any other key for No): ";
                    cin >> choice1;
                } while (choice1 == 1);
                break;
            }

            case 2:
            int choice1;
            do {
                cout << "1. MAX_Delete\n2. MIN_DELETE" << endl;
                cin >> choice1;

                switch (choice1) {
                    case 1:
                        max_delete(a, n);
                        break;
                    case 2:
                        min_delete(a, n);
                       break;
                }

                cout << "Do you want to continue (1 for Yes, any other key for No): ";
                cin >> choice1;
            } while (choice1 == 1);
                break;

            case 3:
                display(a, n);
                break;

            case 4:
                cout << "Exit" << endl;
                break;
        }
        cout << "Do you want to continue (1 for Yes, any other key for No): ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}
