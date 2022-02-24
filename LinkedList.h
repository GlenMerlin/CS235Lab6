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
        int location;
        
    public:
        LinkedList(){
            head = nullptr;
            dataSize = 0;
            location = 0;
        };
        ~LinkedList(void) override{
            clear();
        };
 

        void insertHead(T value) override{
            // cout << "inside the insertHead function" << endl;
            cout << "value is: " << value << endl;
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
            else {
                delete headToInsert;
            }
        };

        void insertTail(T value) override{
            // TODO: Make this actually work
            // cout << "inside the insetTail function" << endl;
            cout << "value is: " << value << endl;
            if (isEmpty()){
                insertHead(value);
            }
            else if (!existCheck(value)){
                    
                    Node* tailToInsert = new Node(value);
                    Node* pointer;

                    for (pointer = head; pointer->next != nullptr; pointer = pointer->next);
                        
                    pointer->next = tailToInsert;
                    dataSize++;

                    cout << "insertTail is increasing the count: " << dataSize << endl;
            }

        };

        void insertAfter(T value, T insertionNode) override{
            if (existCheck(insertionNode) && !existCheck(value)){
                cout << "value is: " << value << endl;
                cout << "location is: " << location << endl;
                cout << "dataSize is: " << dataSize << endl;
                existCheck(insertionNode);
                cout << "after location is: " << location << endl;
                cout << "after dataSize is: " << dataSize << endl;
                if (location <= dataSize){

                    Node* valToInsert = new Node(value);
                    Node* insertLoc = head;

                    for (int i = 0; i < location; i++){
                        insertLoc = insertLoc->next;
                    }

                    valToInsert->next = insertLoc->next;
                    insertLoc->next = valToInsert;

                    dataSize++;

                    cout << "insertafter is increasing the count: " << dataSize << endl;
                }
                else return;
            }
            
        };

        void remove(T value) override{
            // TODO: Make this actually work
            // cout << "inside the remove function" << endl;
            if (isEmpty()){
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
                
                for (Node* pointer = head; pointer != nullptr; pointer = pointer->next){ 

                    ss << pointer->data << ", ";

                    if (pointer->next == nullptr)
                    {
                        cout << "whyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy" << endl;
                        ss << " ";
                        break;
                    }
                    pointer = pointer->next;
                }
                return ss.str();
                
            }
            else return "";
            
        };

        bool isEmpty() const {
            cout << "Inside the isEmpty function" << endl;
            return (dataSize <= 0 || head == nullptr);
        }

        bool existCheck(T value) {
            location = 0;
            for (Node* pointer = head; pointer != nullptr; pointer = pointer->next){
                if (pointer->data == value){
                    return true;
                };
                location++;
            }
            return false;
        }
};