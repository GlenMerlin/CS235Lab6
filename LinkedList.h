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
            cout << "value is: " << value << endl;
            Node* headToInsert = new Node(value);
            if(!existCheck(value)) {
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

                // This reset's location's value to match the amount of steps needed to get too the insertion point
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
            if (index >= dataSize || index < 0 || !isEmpty()){
                throw std::out_of_range("AT Error");
            }
            else {
                Node *pointer = head;
                for (int i = 0; i < index; i++){
                    if (i == index){
                        return pointer->data;
                    }
                    else {
                        pointer = pointer->next;
                    }
                }
                
                return pointer->data;
            }
            
        };
        
        int size() override {
            return dataSize;
        };

        string toString() override{
            cout << "Inside the toString function" << endl;
            if (!isEmpty()){

                stringstream ss;

                cout << "Head is: " << head << " head data is: " << head->data << endl;
                
                for (Node* pointer = head; pointer != nullptr; pointer = pointer->next){ 


                    if (pointer->next == nullptr)
                    {
                        ss << pointer->data;
                        cout << "finished with the string stream" << endl;
                        break;
                    }
                    else {
                        ss << pointer->data << " ";
                    }
                }
                return ss.str();
                
            }
            else return "";
            
        };

        bool isEmpty() const {
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