#include "circular_sorted_linked_list.h"

template <class T>
cslist<T>::cslist(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
cslist<T>::~cslist(){
    destroy();
}

template <class T>
cslist<T>::cslist(const cslist<T> &other){
    copy(other);
}

template <class T>
const cslist<T> & cslist<T>::operator= (const cslist<T> &other){
    if (this != &other){
        destroy();
        copy(other);
    }
    return *this;
}

template <class T>
int cslist<T>::get_length (){
    return size;
}

template <class T>
bool cslist<T>::is_empty(){
    return get_length() == 0;
}

template <class T>
void cslist<T>::destroy() {
    node<T> *current;
    while(head != NULL){
        current = head;
        head = head->next;
        delete current;
    }
    size = 0;
}

template <class T>
void cslist<T>::copy(const cslist<T> &other) {}

template <class T>
void cslist<T>::insert(T value){
    node<T> *new_node;
    new_node = new node<T>;
    new_node->value = value;
    if(is_empty()){
        head = new_node;
        tail = new_node;
        head->prev = tail;
        head->next = tail;
        tail->prev = head;
        tail->next = head;
    } else{
        if(new_node->value >= head->value){
            new_node->next = head;
            new_node->prev = tail;
            head->prev = new_node;
            tail->next = new_node;
            head = new_node;
        } else if(new_node->value <= tail->value){
            new_node->prev = tail;
            new_node->next = head;
            head->prev = new_node;
            tail->next = new_node;
            tail = new_node;
        }else {
            node<T> *current = head;
            for (int i = 0; i < get_length(); i++) {
                if (new_node->value >= current->value) {
                    new_node->next = current;
                    new_node->prev = current->prev;
                    new_node->prev->next = new_node;
                    current->prev = new_node;
                    break;
                }
                current = current->next;
            }
        }
    }
    size ++;
}

template <class T>
void cslist<T>::remove(T value){
    if(is_empty()){
        std::cout<<"The list is empty, nothing to remove"<<endl;
    } else{
        if(head->value == value && get_length() == 1){
            head = NULL;
            tail = NULL;
            size --;
        } else{
            bool found = false;
            node<T> *current = head;
            for(int i=0; i<get_length(); i++){
                if(current->value == value){
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    if(i == 0){
                        head = current->next;
                    } else if(i == get_length() - 1){
                        tail = current->prev;
                    }
                    found = true;
                    size --;
                    std::cout<<value<<" is removed from list"<<endl;
                    break;
                }
                current = current->next;
            }
            if(!found){
                std::cout<<"value "<<value<<" does not exited in list"<<endl;
            }
        }
    }
}

template <class T>
void cslist<T>::remove_all(T value){
    if(is_empty()){
        std::cout<<"The list is empty, nothing to remove"<<endl;
    } else{
        if(head->value == value && get_length() == 1){
            head = NULL;
            tail = NULL;
            size --;
        } else{
            bool found = false;
            node<T> *current = head;
            int l = get_length();
            for(int i=0; i<l; i++){
                if(current->value == value){
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    if(current == head){
                        head = current->next;
                    } else if(current == tail){
                        tail = current->prev;
                    }
                    found = true;
                    size --;
                    std::cout<<value<<" is removed from list"<<endl;
                }
                current = current->next;
            }
            if(!found){
                std::cout<<"value "<<value<<" does not exited in list"<<endl;
            }
        }
    }
}

template <class T>
void cslist<T>::search(T value){
    if(is_empty()){
        std::cout<<"The list is empty, nothing to search"<<endl;
    } else{
        bool found = false;
        node<T> *current = head;
        for(int i=0; i<get_length(); i++){
            if(current->value == value){
                found = true;
                std::cout<<"Found value "<<value<<" at index "<<i<<endl;
            }
            current = current->next;
        }
        if(!found){
            std::cout<<"value "<<value<<" does not exited in list"<<endl;
        }
    }
}

template <class T>
void cslist<T>::print_list(){
    if(is_empty()){
        std::cout<<"The list is empty, nothing to print"<<endl;
    } else{
        node<T> *current = tail;
        for(int i=get_length(); i>0; i--){
            std::cout<<" "<<current->value<<" ";
            current = current->prev;
        }
    }
}

template <class T>
int cslist<T>::duplicated(T value) {
    int result = 0;
    if(!is_empty()){
        node<T> *current = head;
        for(int i=0; i<get_length(); i++){
            if(current->value == value){
                result ++;
            }
            current = current->next;
        }
    }
    return result;
}

