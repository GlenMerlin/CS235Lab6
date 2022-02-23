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
            
            explicit Node(T data) : data(data), next(nullptr) {};
        };

        Node* head;
        int dataSize;
    public:
        LinkedList(){
            head = nullptr;
            dataSize = 0;
        };
        ~LinkedList(void) override{
            clear();
        };
        
        void insertHead(T value) override{
            cout << "inside the insertHead function" << endl;
            Node* headToInsert = new Node(value);
            if (!isEmpty()){
                head = headToInsert;
                dataSize++;
                cout << "inserting into an empty array" << endl;  
            }
            else if(!existCheck(value)) {

            }
        };
        void insertTail(T value) override{
            // TODO: Make this actually work
            cout << "inside the insetTail function" << endl;
            dataSize++;
            cout << "successfully completed the insertHead function" << endl;

        };
        void insertAfter(T value, T insertionNode) override{
            // TODO: Make this actually work
            dataSize++;
        };
        void remove(T value) override{
            // TODO: Make this actually work
            dataSize--;
        };
        void clear() override{
            cout << "Inside the clear function" << endl;
        // TODO: This probably doesn't work until the rest of the methods are implemented to make sure that it's actually incrementing and decrementing dataSize
        //     for (int i = 0; i < dataSize; i++){
        //         Node* temp = head;
        //         head = head->next;
        //         delete temp;
        //         dataSize--;
        //     }
         };
        T at(int index) override {
            cout << "inside the at function"<< endl;
            if (index >= dataSize || index < 0){
                throw std::out_of_range("AT Error");
            }
            else {
                // TODO: Make this actually work
                Node *pointer = head;
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
            cout << "Inside the size function. Size: " << dataSize << endl;
            return dataSize;
        };

        string toString() override{
            cout << "Inside the toString function" << endl;
            if (!isEmpty()){
                stringstream ss;
                for (Node *pointer = head; pointer != nullptr; pointer = pointer->next){
                    // TODO: refactor this into the proper format, this is just in this format for testing purposes
                    cout << "pointer " << pointer << " val " << pointer->data << " next " << pointer->next << endl;
                    ss << "pointer " << pointer << " val " << pointer->data << " next " << pointer->next << endl;
                }
                return (ss.str());
            }
            else {
                return "";
            }
            
        };

        bool isEmpty() const {
            cout << "Inside the isEmpty function" << endl;
            if (dataSize <= 0 || head == nullptr){
                return true;
            };
            return false;
        }

        bool existCheck(T value) const {
            cout << "Inside the existCheck function" << endl;
            for (Node *pointer = head; pointer != nullptr; pointer = pointer->next){
                if (pointer->data == value){
                    return true;
                };
            }
            return false;
        }
};