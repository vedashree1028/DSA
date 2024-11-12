//9a
#include <iostream>
#include <string>
using namespace std;

string queue[1000];
int n = 4;
int front = -1, rear = -1;

void add_party_to_waitlist(string c) {
    if ((rear + 1) % n == front) {
        cout << "The waiting list is full." << endl;
    } else {
        if (front == -1 && rear == -1) { 
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % n; 
        }
        queue[rear] = c;
    }
}

void seat_party() {
    if (front == -1) {
        cout << "Waiting list is empty." << endl;
    } else {
        cout << "Seating party: " << queue[front] << endl;
        if (front == rear) { 
            front = -1;
            rear = -1; 
        } else {
            front = (front + 1) % n; 
        }
    }
}

void display_list() {
    if (front == -1) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    cout << "Waiting list: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % n; 
    }
    cout << endl;
}

int main() {
    add_party_to_waitlist("acb");
    add_party_to_waitlist("opq");
    add_party_to_waitlist("xyz");
    display_list();
    cout << endl;

    seat_party();
    display_list();

    return 0;
}

//9b
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int d) {
        data = d;
        next = NULL;
    }
    node() {
        data = 0;
        next = NULL;
    }
};

class circular_queue {
public:
    node* front =NULL;
    node* rear = NULL;

    void Customer_arrival(int val) {
        node* nn = new node(val);
        if (front == NULL) {
            
            front = nn;
            rear = nn;
            rear->next = front; 
        } else {
            rear->next = nn;
            rear = nn;
            rear->next = front;
        }
      //  cout << val<< endl;
    }

    void Customer_checkout() {
        if (front == NULL) {
            cout << "Queue is empty. You can't checkout any customer." << endl;
        } else if (front == rear) {
            
            delete front;
            front = NULL;
            rear = NULL;
            cout << "Queue is now empty after deletion." << endl;
        } else {
            node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
            cout << "after checkouting the customer  from the queue." << endl;
        }
    }

    void peek() {
        if (front != NULL) {
            cout << "First customer: " << front->data << endl;
        } else {
            cout << "Queue is empty." << endl;
        }
    }

    void View_customer() {
        if (front ==NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front); 
        cout << endl;
    }
};

int main() {
    circular_queue q;
    q.Customer_arrival(10);
    q.Customer_arrival(20);
    q.Customer_arrival(30);
    q.Customer_arrival(40);

    cout << "Current customer queue: ";
    q.View_customer();

    q.Customer_checkout();
    cout << "After checkout of customer: ";
    q.View_customer();

    return 0;
}
