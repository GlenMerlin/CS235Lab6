#include "LinkedListInterface.h"

using namespace std;
template<typename T>
class LinkedList: public LinkedListInterface {
    public:
        LinkedList();
        ~LinkedList() override;
        void insertHead(T value) override;
        void insertTail(T value) override;
        void insertAfter(T value, T insertionNode) override;
        void remove(T value) override;
        void clear() override;
        T at(int index) override;
        int size() override;
        string toString() override;
        
};