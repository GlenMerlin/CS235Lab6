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
        int location = 0;
        void insertHead(T value) override{
            // cout << "inside the insertHead function" << endl;
            Node* headToInsert = new Node(value);
            if (!isEmpty()){
                head = headToInsert;
                dataSize++;
                cout << "insertHead is increasing the count: " << dataSize << endl;
                // cout << "inserting into an empty array" << endl;  
            }
            else if(!existCheck(value)) {
                headToInsert->next = head;
                head = headToInsert;
                dataSize++;
                cout << "insertHead is increasing the count: " << dataSize << endl;
            }
        };
        void insertTail(T value) override{
            // TODO: Make this actually work
            // cout << "inside the insetTail function" << endl;
            if (!isEmpty()){
                Node* tailToInsert = new Node(value);
                dataSize++;
                cout << "insertTail is increasing the count: " << dataSize << endl;
            }
            else {
                if (!existCheck(value) && location < dataSize){

                    Node* tailToInsert = new Node(value);
                    Node *pointer;
                    for (pointer = head; pointer != nullptr; pointer = pointer->next);
                    pointer->next = tailToInsert;
                    dataSize++;
                    cout << "insertTail is increasing the count: " << dataSize << endl;
                }
            }
            // cout << "successfully completed the insertHead function" << endl;

        };
        void insertAfter(T value, T insertionNode) override{
            if (!existCheck(insertionNode)){
                cout << "location is: " << location << endl;
                cout << "dataSize is: " << dataSize << endl;
                if (location < dataSize){
                    Node* valToInsert = new Node(value);
                    Node* pointer = head;
                    pointer->next = valToInsert;
                    valToInsert->next = pointer;
                    dataSize++;
                    cout << "insertafter is increasing the count: " << dataSize << endl;
                }
                else return;
            }
            
        };
        void remove(T value) override{
            // TODO: Make this actually work
            // cout << "inside the remove function" << endl;
            if (!isEmpty()){
                return;
            }
            else{
                if (existCheck(value)){
                    if (location < 0){
                        return;
                    }
                    else if (location == 0){
                        Node* temp = head;
                        head = head->next;
                        delete temp;
                        cout << "delete is lowering the counter to: " << dataSize << endl;
                        dataSize--;
                        return;
                    }
                    else {
                        Node* pointer = head;
                        for (int i = 0; i < location; i++){
                            pointer->next;
                        }
                        delete pointer;
                    }
                }
            }
            dataSize--;
        };
        void clear() override{
            // cout << "Inside the clear function" << endl;
            if (!isEmpty()){
                for (int i = 0; i < dataSize; i++){
                    Node* temp = head;
                    if (head->next != nullptr){
                        head = head->next;
                        delete temp;
                        dataSize--;
                    }
                    else {
                        head = nullptr;
                        dataSize = 0;
                        return;
                    }
                }
            }
         };
        T at(int index) override {
            // cout << "inside the at function"<< endl;
            if (index >= dataSize || index < 0 || !isEmpty()){
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
                
                // cout << "successfully completed the at function" << endl;
                return pointer->data;
            }
            
        };
        
        int size() override {
            // cout << "Inside the size function. Size: " << dataSize << endl;
            return dataSize;
        };

        string toString() override{
            cout << "Inside the toString function" << endl;
            if (!isEmpty()){
                stringstream ss;
                cout << "Head is: " << head << " head data is: " << head->data << endl;
                Node* pointer = head;
                for (int i = 0; i < dataSize; i++){
                    ss << pointer->data;
                    if (pointer->next != nullptr)
                    {
                        ss << " ";
                    }
                    pointer = pointer->next;
                }
                return ss.str();
            }
            else return "";
            
        };

        bool isEmpty() const {
            // cout << "Inside the isEmpty function" << endl;
            return (dataSize <= 0 || head == nullptr);
        }

        bool existCheck(T value) {
            location = 0;
            // cout << "Inside the existCheck function" << endl;
            for (Node *pointer = head; pointer != nullptr; pointer = pointer->next){
                if (pointer->data == value){
                    return true;
                };
                location++;
            }
            return false;
        }
};