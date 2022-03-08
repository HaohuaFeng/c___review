# include <iostream>
using namespace std;

#ifndef CIRCULAR_SORTED_LINKED_LIST_H
#define CIRCULAR_SORTED_LINKED_LIST_H

template <class  T>
struct node{
    T value;
    node *prev;
    node *next;
};

template <class T>
class cslist{
private:
    node<T> *head;
    node<T> *tail;
    int size;

public:
    cslist();
    ~cslist();
    cslist(const cslist<T> &);
    const cslist<T> & operator= (const cslist<T> &);
    void copy( const cslist<T> &);
    void destroy();
    void insert(T);
    void remove(T);
    void remove_all(T);
    void search(T);
    bool is_empty();
    int get_length();
    void print_list();
    int duplicated(T);
};

#endif
