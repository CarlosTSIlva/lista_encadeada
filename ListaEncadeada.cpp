#include <iostream>

using namespace std;

class Node {
public:
    int data; 
    Node* next; 
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = nullptr;
    }
    
    // método para adicionar um nó no final da lista
    void addNode(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) { 
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    // método para remover um nó da lista pelo valor
    void removeNode(int value) {
        if (head == nullptr) { 
            return;
        } else if (head->data == value) { 
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data != value) {
                current = current->next;
            }
            if (current->next != nullptr) { 
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }
    
    // método para imprimir a lista
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// exemplo de uso
int main() {
    LinkedList myList;
    // adiciona itens ao final da lista
    myList.addNode(1);
    myList.addNode(2);
    myList.addNode(3);
    myList.addNode(4);
    myList.addNode(5);
    
    myList.printList(); // saída 1 2 3 4 5
    
    return 0;
}
