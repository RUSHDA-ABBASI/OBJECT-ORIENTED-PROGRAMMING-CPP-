#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};
class LinkedList {
public:
    Node* head;
    LinkedList(const vector<int>& values) {
        head = nullptr;
        if (values.empty()) return;

        head = new Node(values[0]);
        Node* curr = head;

        for (int i = 1; i < values.size(); i++) {
            curr->next = new Node(values[i]);
            curr = curr->next;
        }
    }

    LinkedList(const LinkedList& other) {
        if (other.head == nullptr) { //deep copy
            head = nullptr;
            return;
        }
        head = new Node(other.head->val);
        Node* currThis = head;
        Node* currOther = other.head->next;

        while (currOther) {
            currThis->next = new Node(currOther->val);
            currThis = currThis->next;
            currOther = currOther->next;
        }
    }

    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list1({1, 2, 3});
    LinkedList list2 = list1; // deep copy

    list2.head->val = 99;

    cout << list1.head->val;
    return 0;
}
