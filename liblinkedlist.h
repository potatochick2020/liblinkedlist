#include <vector>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
/* 
All method will simply return and do nothing for all invalid input, e.g. out of range index.  
*/
template <typename T>
class node {
    public:
    node* next;
    node* prev;
    T val;
    node(T x): val(x),next(nullptr),prev(nullptr){};
};

class linkedlist{
    
    public:
    node* head;
    node* tail;
    size_t total_size;
        linkedlist(){
            head->prev = nullptr;
            head->next = tail; 
            tail->prev = head;
            tail->next = nullptr;
            total_size = 0;
        };
        ~linkedlist(){
            while (total_size>=0){
                node* temp = head;
                head = head->next
                delete temp;
                total_size--;
            }
            delete head;
            delete tail;
            delete total_size;
        }; 
        void push_back(T val){
            insertAtIndex(total_size,val);
        };
        void push_front(T val){
            insertAtIndex(0,val);
        };
        void pop_back(){
            removeAtIndex(total_size-1); 
        };
        void pop_front(){
            removeAtIndex(0);
        };  
        void removeAtIndex(size_t index){
            if (index >= total_size) return;
            if (total_size - index > index){
                node* pointer = tail->prev;
                for (int i = 0;i<total_size - index;i++){
                    pointer=pointer->prev;
                }
            } else {
                node* pointer = head->next;
                for (int i = 0;i<index;i++){
                    pointer=pointer->next;
                }
            } 
            pointer->next->prev = pointer->prev;
            pointer->prev->next = pointer->next;
            delete poitner;
            total_size--;
        };  
        void insertAtIndex(size_t index, T value ){
            if (index>total_size) return;
            node* pointer = head;
            node* to_insert = new node(val);
            for (int i = 0;i<index;i++){
                pointer=pointer->next;
            }
            if (index == 0){ 
                to_insert->prev = pointer;
                to_insert->next = pointer->next;
                head->next->prev = to_insert;
                head->next = to_insert; 
            } 
            total_size++;
        };  
        bool empty(){
            return total_size == 0;
        };
        size_t size(){
            return total_size;
        }; 
        bool ishead(node* curr){
            return curr == head->next;
        };
        bool istail(node* curr){
            return curr == tail->prev;
        }; 
        void display(){
            
        }
        // add class for initialise with vector
        // iterator template
        // iterator begin(){

        // }
        // 
};

 
//overwrite operator of == 