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
        age = rand () % (MAX_AGE + 1 ) + MIN_AGE;
        name = names [rand () % NAMES_SIZE];
        color = color[rand() % COLORS_SIZE];
        
        

        Goat (int age, string name, string color)
        {
            this -> age = age;
            this -> name = name;
            this -> color = color;
        }

        int getAge() const {return age; }
        string getname() const {return name; }
        string getColor() const {return color;}

        string Goat::names[NAMES_SIZE] = {"Senior", "Godlike", "Old", "Mature", "Teen", "Kid", "Hero", "Brave", "Happy", "Clever", "Strong", "Graceful", "Mighty", "Friendly", "Cheerful"};
        string Goat::colors[COLORS_SIZE] = {"Yellow", "Red", "Gold", "Mauve", "White", "Blue", "Green", "Orange", "Purple", "Pink", "Gray", "Black", "Brown", "Silver", "Cyan"};


    }
}
class DoublyLinkedList {
private:
struct Node {
Goat data;
Node* prev;
Node* next;
Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
data = val;
prev = p;
next = n;
}
};
Node* head;
Node* tail;
public:
// constructor
DoublyLinkedList() { head = nullptr; tail = nullptr; }
void push_back(Goat value) {
Node* newNode = new Node(value);
if (!tail) // if there's no tail, the list is empty
head = tail = newNode;
else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}
void push_front(Goat value) {
Node* newNode = new Node(value);
if (!head) // if there's no head, the list is empty
head = tail = newNode;
else {
newNode->next = head;
head->prev = newNode;
head = newNode;
}
}
void insert_after(int value, int position) {
if (position < 0) {
cout << "Position must be >= 0." << endl;
return;
}
Node* newNode = new Node(value);
if (!head) {
head = tail = newNode;
return;
}
Node* temp = head;
for (int i = 0; i < position && temp; ++i)
temp = temp->next;
if (!temp) {
cout << "Position exceeds list size. Node not inserted.\n";
delete newNode;
return;
}
newNode->next = temp->next;
newNode->prev = temp;
if (temp->next)
temp->next->prev = newNode;
else
tail = newNode; // Inserting at the end
temp->next = newNode;
}
void delete_node(int value) {
if (!head) return; // Empty list
Node* temp = head;
while (temp && temp->data != value)
temp = temp->next;
if (!temp) return; // Value not found
if (temp->prev) {
temp->prev->next = temp->next;
} else {
head = temp->next; // Deleting the head
}
if (temp->next) {
temp->next->prev = temp->prev;
} else {
tail = temp->prev; // Deleting the tail
}
delete temp;
}
void print() {
Node* current = head;
if (!current) return;
while (current) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}
void print_reverse() {
Node* current = tail;
if (!current) return;
while (current) {
cout << current->data << " ";
current = current->prev;
}
cout << endl;
}
~DoublyLinkedList() {
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
}
};
// Driver program
int main() {
DoublyLinkedList list;
int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;
for (int i = 0; i < size; ++i)
list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
cout << "List forward: ";
list.print();
cout << "List backward: ";
list.print_reverse();
cout << "Deleting list, then trying to print.\n";
list.~DoublyLinkedList();
cout << "List forward: ";
list.print();
return 0;
}