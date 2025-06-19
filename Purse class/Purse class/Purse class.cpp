#include <iostream>
using namespace std;

class Purse {
private:
    int Purse_id;
    int capacity;
    int contents;

public:
    // Initialize data members
    void init_Purse(int id, int cap, int cont) {
        Purse_id = id;
        capacity = cap;
        contents = (cont <= cap) ? cont : cap; // avoid overflow
    }

    // Return Purse ID
    int Get_number() {
        return Purse_id;
    }

    // Return Purse capacity
    int Get_capacity() {
        return capacity;
    }

    // Insert money into purse
    int Insert_Money(int amount) {
        if (contents + amount <= capacity) {
            contents += amount;
        }
        else {
            contents = capacity; // Fill to max
        }
        return contents;
    }

    // Remove money from purse
    int Remove_Money(int amount) {
        if (contents >= amount) {
            contents -= amount;
        }
        else {
            contents = 0; // Can't go below 0
        }
        return contents;
    }
};

// Test program
int main() {
    Purse p1, p2;

    // Initialize purses
    p1.init_Purse(101, 100, 30);
    p2.init_Purse(102, 50, 10);

    // Testing Purse 1
    cout << "Purse ID: " << p1.Get_number() << endl;
    cout << "Capacity: " << p1.Get_capacity() << endl;
    cout << "Inserted Money: " << p1.Insert_Money(50) << endl;
    cout << "Removed Money: " << p1.Remove_Money(20) << endl;

    // Testing Purse 2
    cout << "\nPurse ID: " << p2.Get_number() << endl;
    cout << "Capacity: " << p2.Get_capacity() << endl;
    cout << "Inserted Money: " << p2.Insert_Money(60) << endl;
    cout << "Removed Money: " << p2.Remove_Money(15) << endl;

    return 0;
}
