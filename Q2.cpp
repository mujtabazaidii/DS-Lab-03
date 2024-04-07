#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int dat){
        data = dat;
        next = nullptr;
    }
};
void PrintList(Node* H) {
    Node* ptr = H;
    int i = 1;
    while (ptr != nullptr) {
        cout << "Value " << i << " : " << ptr->data << endl;
        i++;
        ptr = ptr->next;
    }
}
void NextMaxElement(Node* H) {
    Node* h = H;
    Node* ptr = nullptr;
    Node* ptrr = nullptr;
    do {
        Node* present = H;
        int value = -1;
        do {
            if (H->data < present->data)
            {
                value = present->data;
                break;
            }
            present = present->next;
        } while (present != H);
        if (ptr == nullptr) {
            ptr = new Node(value);
            ptrr = ptr;
        }
        else {
            ptrr->next = new Node(value);
            ptrr = ptrr->next;
        }
        H = H->next;
    } 
    while (H != h);
    PrintList(ptr);
}
int main(){
    Node* ptr = new Node(10);
    ptr->next = new Node(20);
    ptr->next->next = new Node(30);
    ptr->next->next->next = new Node(40);
    ptr->next->next->next->next = new Node(50);
    ptr->next->next->next->next->next = ptr;
    NextMaxElement(ptr);
    return 0;
}