#include "LinkedListInterface.h"
#include <string>
#include <sstream>


using namespace std;
template<typename T>
class LinkedList : public LinkedListInterface<T>{
    private: 
        struct Node {
            T data;
            Node *next;
            Node(const T& the_data, Node* head = NULL, Node* next_val = NULL, Node* tail = NULL) : data(the_data) {next = next_val;}
        };
            Node* list;
            int items;
    public:
        LinkedList(){
            list = NULL;
            items = 0;
        };
        ~LinkedList(void) override{
            while(list != NULL) {
			    Node *current = list;
			    list = list->next;
			    delete current;
		    }
        };
        
        void insertHead(T value) override{
            cout << "inside the insertHead function" << endl;
            if (items == 0){
              cout << "inserting into an empty array" << endl;  
            }
            Node *pointer = list;
            list = new Node(value);
            list->next = pointer;
            items++;
            cout << "successfully completed the insertHead function" << endl;

        };
        void insertTail(T value) override{
            cout << "inside the insetTail function" << endl;
            Node *pointer = list;
            list = new Node(value);
            items++;
            cout << "successfully completed the insertHead function" << endl;

        };
        void insertAfter(T value, T insertionNode) override{
            items++;
        };
        void remove(T value) override{
            items--;
        };
        void clear() override{
            list = NULL;
            items = 0;
        };
        T at(int index) override {
            cout << "inside the at function"<< endl;
            if (index >= items || index < 0){
                throw std::out_of_range("AT Error");
            }
            else {
                Node *pointer = list;
                for (int i = 0; i < index; i++){
                    if (i == index){
                        return pointer->data;
                    }
                    else {
                        pointer = pointer->next;
                    }
                }
                
                cout << "successfully completed the at function" << endl;
                return pointer->data;
            }
            
        };
        int size() override {
            int size = 0;
            for (Node *pointer = list; pointer != NULL; pointer = pointer->next){
                size++;
            }
            cout << size << endl;
            return size;
        };
        string toString() override{
            stringstream ss;
            for (Node *pointer = list; pointer != NULL; pointer = pointer->next){
                // TODO: refactor this into the proper format, this is just in this format for testing purposes
                ss << "pointer " << pointer << " val " << pointer->data << " next " << pointer->next << endl;
                cout << "pointer " << pointer << " val " << pointer->data << " next " << pointer->next << endl;
            }
            return (ss.str());
        };
        
};