#include <iostream>

using namespace std;

struct LinkedList {
    int num;
    LinkedList* next = nullptr;
};
struct double_linked_list{
    int num;
    double_linked_list* next = nullptr;
    double_linked_list* pervious = nullptr;
};

int menu() {
    int choice;
    while (true) {
        cout << "Enter a choice:\n"
            << "1. Single linked list\n"
            << "2. Double linked list\n"
            << "3. Exit\n";
        cin >> choice;
        if (choice >= 1 && choice <= 3) {
            return choice;
        }
        else {
            cout << "You entered an invalid choice. Please try again.\n";
        }
    }
}

void Addinfront(LinkedList*& head) {
    int value;
    cout << "Enter a value to add: ";
    cin >> value;

    LinkedList* newnode = new LinkedList;
    newnode->num = value;
    newnode->next = head;

    head = newnode;
}

void Addatend(LinkedList*& head) {
    int value;
    cout << "Enter a value to add at end: ";
    cin >> value;

    LinkedList* newnode = new LinkedList;
    newnode->num = value;
    newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
        return;
    }

    LinkedList* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void Addatanyposition(LinkedList*& head) {
    int value, pos;
    cout << "Enter a value to add: ";
    cin >> value;
    cout << "Please enter the position: ";
    cin >> pos;

    LinkedList* newnode = new LinkedList;
    newnode->num = value;
    newnode->next = nullptr;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    LinkedList* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == nullptr) {
            cout << "Position is out of bounds.\n";
            delete newnode;
            return;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void Deletefirst(LinkedList*& head) {
    if (head == nullptr) {
        cout << "The list is empty\n";
        return;
    }
    LinkedList* p = head->next;
    delete head;
    head = p;
}
 
void Deleteatend(LinkedList*& head) {
    if (head == nullptr) {
        cout << "The list is empty\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    LinkedList* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

static void Deleteatindex(LinkedList*& head) {
    int index;
    cout << "Please enter an index: ";
    cin >> index;

    if (head == nullptr) {
        cout << "The list is empty\n";
        return;
    }

    if (index == 1) {
        Deletefirst(head);
        return;
    }

    LinkedList* temp = head;
    for (int i = 1; i < index - 1; ++i) {
        if (temp->next == nullptr) {
            cout << "Out of range\n";
            return;
        }
        temp = temp->next;
    }

    LinkedList* q = temp->next;
    if (q == nullptr) {
        cout << "Out of range\n";
        return;
    }
    temp->next = q->next;
    delete q;
}

void Displayatpos(LinkedList*& head) {
    int value;
    cout << "Enter an index: ";
    cin >> value;

    if (head == nullptr) {
        cout << "The list is empty\n";
        return;
    }

    LinkedList* temp = head;
    for (int i = 1; i < value; i++) {
        if (temp->next == nullptr) {
            cout << "Out of range\n";
            return;
        }
        temp = temp->next;
    }
    cout << "The value is: " << temp->num << endl;
}


void singleLinkedListMenu(LinkedList*& head) {
    int choice;
    while (true) {
        cout << "Enter your choice:\n"
            << "1. Add in front\n"
            << "2. Add at the end\n"
            << "3. Add at any position\n"
            << "4. Delete first\n"
            << "5. Delete at the index\n"
            << "6. Delete the end\n"
            << "7. Display at any position\n"
            << "8. Go back to the main menu\n";
        cin >> choice;

        if (choice >= 1 && choice <= 8) {
            if (choice == 8) {
                cout << "Returning to the main menu...\n";
                break;
            }
            switch (choice) {
            case 1:
                Addinfront(head);
                break;
            case 2:
                Addatend(head);
                break;
            case 3:
                Addatanyposition(head);
                break;
            case 4:
                Deletefirst(head);
                break;
            case 5:
                Deleteatindex(head);
                break;
            case 6:
                Deleteatend(head);
                break;
            case 7:
                Displayatpos(head);
                break;
            default:
                cout << "You entered an invalid choice. Please try again.\n";
            }
        }
        else {
            cout << "You entered an invalid choice. Please try again.\n";
        }
    }
}
void Addfront(double_linked_list*& start) {
    int value;
    cout << "Enter a value: ";
    cin >> value;

    double_linked_list* newnode = new double_linked_list;
    newnode->num = value;
    newnode->next = start;
    newnode->pervious = nullptr;

    if (start != nullptr) {
        start->pervious = newnode;
    }

    start = newnode;
}
void Addend(double_linked_list*& start) {
    int value;
    cout << "Enter a value: ";
    cin >> value;

    double_linked_list* newnode = new double_linked_list;
    newnode->num = value;
    newnode->pervious = nullptr;
    if (start == nullptr) {
        start = newnode;
        newnode->next = nullptr;
        return;
    }
    double_linked_list* temp = start;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->pervious = temp;
}
void Addatposition(double_linked_list*& start) {
    int index, value;
    cout << "Enter the index to insert at: ";
    cin >> index;
    cout << "Enter the value to insert: ";
    cin >> value;

    double_linked_list* newnode = new double_linked_list;
    newnode->num = value;

    if (index == 1) {
        newnode->next = start;
        newnode->pervious = nullptr;
        if (start != nullptr) {
            start->pervious = newnode;
        }
        start = newnode;
        return;
    }

    double_linked_list* temp = start;
    for (int i = 1; i < index - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Index out of range.\n";
        delete newnode;
        return;
    }

    newnode->next = temp->next;
    newnode->pervious = temp;

    if (temp->next != nullptr) {
        temp->next->pervious = newnode;
    }

    temp->next = newnode;
}
void Deletefront(double_linked_list*& start) {
    if (start == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    double_linked_list* temp = start;
    start = start->next;

    if (start != nullptr) {
        start->pervious = nullptr;
    }

    delete temp;
}
void Deleteindex(double_linked_list*& start) {
    int index;
    cout << "Enter the index to delete: ";
    cin >> index;

    if (start == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    if (index == 0) {
        Deletefront(start);
        return;
    }

    double_linked_list* temp = start;
    for (int i = 0; i < index && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Index out of range.\n";
        return;
    }

    
    if (temp->next != nullptr) {
        temp->next->pervious = temp->pervious;
    }

    if (temp->pervious != nullptr) {
        temp->pervious->next = temp->next;
    }

    delete temp;
}
void Deletend(double_linked_list*& start) {
    if (start == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    if (start->next == nullptr) {
        delete start;
        start = nullptr;
        return;
    }

    double_linked_list* temp = start;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->pervious->next = nullptr;
    delete temp;
}
void Displaypos(double_linked_list* start) {
    int position;
    cout << "Enter the position to display: ";
    cin >> position;

    if (start == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    double_linked_list* temp = start;
    int current_pos = 1;

    while (temp != nullptr && current_pos < position) {
        temp = temp->next;
        current_pos++;
    }

    if (temp == nullptr) {
        cout << "Invalid position.\n";
    }
    else {
        cout << "The value at position " << position << " is: " << temp->num << endl;
    }
}

void doublelinkedListmenu(double_linked_list*& start) {
    int choice;
    while (true) {
        cout << "Enter your choice:\n"
            << "1. Add in front\n"
            << "2. Add at the end\n"
            << "3. Add at any position\n"
            << "4. Delete first\n"
            << "5. Delete at the index\n"
            << "6. Delete the end\n"
            << "7. Display at any position\n"
            << "8. Go back to the main menu\n";
        cin >> choice;

        if (choice >= 1 && choice <= 8) {
            if (choice == 8) {
                cout << "Returning to the main menu...\n";
                break;
            }
            switch (choice) {
            case 1:
                Addfront(start);
                break;
            case 2:
                Addend(start);
                break;
            case 3:
                Addatposition(start);
                break;
            case 4:
                Deletefront(start);
                break;
            case 5:
                Deleteindex(start);
                break;
            case 6:
                Deletend(start);
                break;
            case 7:
                Displaypos(start);
                break;
            default:
                cout << "You entered an invalid choice. Please try again.\n";
            }
        }
        else {
            cout << "You entered an invalid choice. Please try again.\n";
        }
    }
}
int main() {
    LinkedList* head = nullptr;
    double_linked_list* start = nullptr;
    while (true) {
        int choice = menu();

        if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        }

        switch (choice) {
        case 1:
            singleLinkedListMenu(head);
            break;
        case 2:
            doublelinkedListmenu(start);
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}