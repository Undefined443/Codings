#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    char character;
    struct Node *next;
} Node;

class LinkList {
public:
    Node *head;

    LinkList() {
        head = new Node;
        head->next = NULL;
    }

    void push(char character) {
        Node *newNode = new Node;
        newNode->character = character;
        newNode->next = head->next;
        head->next = newNode;
    }

    bool pop(char &character) const {
        if (!head->next)
            return true;
        character = head->next->character;
        Node *temp = head->next;
        head->next = head->next->next;
        delete temp;
        return false;
    }
};

class LinkQueue {
public:
    Node *front;
    Node *rare;

    LinkQueue() {
        front = rare = new Node;
        front->next = rare->next = NULL;
    }

    void enQueue(char character) {
        rare->next = new Node;
        rare = rare->next;
        rare->character = character;
        rare->next = NULL;
    }

    bool deQueue(char &character) const {
        if (front->next == NULL)
            return true;
        character = front->next->character;
        Node *temp = front->next;
        front->next = front->next->next;
        delete temp;
        return false;
    }
};

int main() {
    LinkList list;
    LinkQueue queue;
    string str;
    cin >> str;
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        list.push(*it);
    }
    char temp;
    while (!list.pop(temp)) {
        switch (temp) {
            case 'A':
                cout << "sae";
                break;
            case 'B':
                cout << "tsaedsae";
                break;
            case '(':
                while (!list.pop(temp), temp != ')') {
                    queue.enQueue(temp);
                }
                char first;
                queue.deQueue(first);
                list.push(first);
                while (!queue.deQueue(temp)) {
                    list.push(temp);
                    list.push(first);
                }
                break;
            default:
                cout << temp;
        }
    }
}