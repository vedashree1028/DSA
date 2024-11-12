#include <iostream>
using namespace std;
class HashTable {
private:
    int* table;
    int size;

public:
    HashTable(int size) {
        this->size = size;
        table = new int[size];
        for (int i = 0; i < size; i++) table[i] = -1;
    }
    int hashFunction(int key) {
        return key % size;
    }

    void insert(int empID) {
        int index = hashFunction(empID);
        while (table[index] != -1) index = (index + 1) % size;
        table[index] = empID;
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": " << (table[i] != -1 ? to_string(table[i]) : "Empty") << endl;
        }
    }

    bool search(int empID) {
        int index = hashFunction(empID);
        int startIndex = index;
        while (table[index] != -1) {
            if (table[index] == empID) return true;
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        return false;
    }
};

int main() {
    int tableSize, numEmployees, empID;

    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    HashTable hashTable(tableSize);

    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    cout << "Enter employee ID numbers:\n";
    for (int i = 0; i < numEmployees; i++) {
        cout << "Employee ID " << i + 1 << ": ";
        cin >> empID;
        hashTable.insert(empID);
    }

    hashTable.display();

    cout << "Enter an employee ID to search: ";
    cin >> empID;
    if (hashTable.search(empID)) {
        cout << "Employee ID " << empID << " found in the hash table.\n";
    } else {
        cout << "Employee ID " << empID << " not found in the hash table.\n";
    }

    return 0;

}
