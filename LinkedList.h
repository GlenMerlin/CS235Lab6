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
            cout << "this is a test" << endl;
            if(!existCheck(value)) {
                Node* headToInsert = new Node(value);
                headToInsert->next = head;
                head = headToInsert;
                dataSize++;
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
                    if (value == head->data){
                        Node* valToDelete = head;
                        head = head->next;
                        delete valToDelete;
                        dataSize--;
                    }
                    else {
                        Node* pointer = head;
                        while (pointer!=nullptr){
                            if (pointer->next->data == value){
                                Node* nextVal = pointer->next;
                                pointer->next = nextVal->next;
                                delete nextVal;
                                dataSize--;
                                return;
                            }
                            else {
                                pointer = pointer->next;
                            }
                        }
                    }
                }
            }
        };

        void clear() override{
            while (head != nullptr){
                remove(head->data);
            }
            dataSize = 0;
         };

        T at(int index) override {
            if (index >= dataSize || index < 0 || isEmpty()){
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
                T returnVal = pointer->data;
                return returnVal;
            }
            
        };
        
        int size() override {
            return dataSize;
        };

        string toString() override{
            if (!isEmpty()){

                stringstream ss;
                
                for (Node* pointer = head; pointer != nullptr; pointer = pointer->next){ 


                    if (pointer->next == nullptr)
                    {
                        ss << pointer->data;
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