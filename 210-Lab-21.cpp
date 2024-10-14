#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
const int MIN_AGE = 1, MAX_AGE = 20;
const int NAMES_SIZE = 15, COLORS_SIZE = 15;

class Goat {
private:
    int age;
    string name;
    string color;
    static string names[NAMES_SIZE];
    static string colors[COLORS_SIZE];

public:
    Goat() {
        age = rand() % (MAX_AGE + 1) + MIN_AGE;
        name = names[rand() % NAMES_SIZE];
        color = colors[rand() % COLORS_SIZE];
    }

    Goat(int age, string name, string color) {
        this->age = age;
        this->name = name;
        this->color = color;
    }

    int getAge() const { return age; }
    string getName() const { return name; }
    string getColor() const { return color; }
};

// Initialize static arrays for Goat names and colors
string Goat::names[NAMES_SIZE] = {"Senior", "Godlike", "Old", "Mature", "Teen", "Kid", "Hero", "Brave", "Happy", "Clever", "Strong", "Graceful", "Mighty", "Friendly", "Cheerful"};
string Goat::colors[COLORS_SIZE] = {"Yellow", "Red", "Gold", "Mauve", "White", "Blue", "Green", "Orange", "Purple", "Pink", "Gray", "Black", "Brown", "Silver", "Cyan"};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) : data(val), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail) { // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head) { // If the list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data.getName() << " (" << current->data.getColor() << ", " << current->data.getAge() << ")" << endl;
            current = current->next;
        }
    }

    void print_reverse() {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = tail;
        while (current) {
            cout << current->data.getName() << " (" << current->data.getColor() << ", " << current->data.getAge() << ")" << endl;
            current = current->prev;
        }
    }
};

// Driver program
int main() {
    srand(time(0)); // Seed random number generator
    DoublyLinkedList goatHerd;
    
    int listSize = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;
    for (int i = 0; i < listSize; ++i) {
        Goat randomGoat;
        goatHerd.push_back(randomGoat);
    }

    cout << "List forward:" << endl;
    goatHerd.print();

    cout << "List backward:" << endl;
    goatHerd.print_reverse();

    return 0;
}
