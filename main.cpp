#include <iostream>
using namespace std;

struct Node {
    int ticketNo;
    string movieName;
    Node *next;
};

Node *head = NULL;

void addTicket() {
    Node *n = new Node;
    cout << "Enter Ticket No and Movie Name: ";
    cin >> n->ticketNo >> n->movieName;
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        Node *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}

void display() {
    Node *t = head;
    while (t != NULL) {
        cout << t->ticketNo << " " << t->movieName << endl;
        t = t->next;
    }
}

void searchTicket() {
    int no;
    cout << "Enter Ticket No to Search: ";
    cin >> no;

    Node *t = head;
    while (t != NULL) {
        if (t->ticketNo == no) {
            cout << "Found: " << t->movieName << endl;
            return;
        }
        t = t->next;
    }
    cout << "Ticket Not Found\n";
}

void deleteTicket() {
    int no;
    cout << "Enter Ticket No to Delete: ";
    cin >> no;

    Node *t = head, *prev = NULL;
    while (t != NULL && t->ticketNo != no) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        cout << "Ticket Not Found\n";
        return;
    }

    if (prev == NULL)
        head = t->next;
    else
        prev->next = t->next;

    delete t;
    cout << "Ticket Deleted\n";
}

void updateTicket() {
    int no;
    cout << "Enter Ticket No to Update: ";
    cin >> no;

    Node *t = head;
    while (t != NULL && t->ticketNo != no)
        t = t->next;

    if (t == NULL)
        cout << "Ticket Not Found\n";
    else {
        cout << "Enter New Movie Name: ";
        cin >> t->movieName;
        cout << "Ticket Updated\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n1.Add 2.Display 3.Search";
        cout << "\n4.Delete 5.Update 0.Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTicket(); break;
            case 2: display(); break;
            case 3: searchTicket(); break;
            case 4: deleteTicket(); break;
            case 5: updateTicket(); break;
            case 0: cout << "Exit\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 0);

    return 0;
}
