#include "LinkedListInterface.h"

using namespace std;
template<typename T>
class LinkedList : public LinkedListInterface<T>{
    private: 
        struct Node {
            T data;
            Node* next;
            Node(const T& d) : data(d), next(NULL) {}
            Node(const T& d, Node* n = NULL) : data(d), next(n) {}
        };
            Node* temp;
            Node* next;
            Node* head;
            int items;
    public:
        LinkedList(){
            // list = NULL;
            items = 0;
        };
        ~LinkedList(void) override{
            
        };
        
        void insertHead(T value) override{

        };
        void insertTail(T value) override{

        };
        void insertAfter(T value, T insertionNode) override{

        };
        void remove(T value) override{

        };
        void clear() override{

        };
        T at(int index) override {
            cout << "In at"<<endl;
            return head->data;
        };
        int size() override {
            return 0;
        };
        string toString() override{
            return "";
        };
        
};