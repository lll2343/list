#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <iostream>
#include "NoMen.h"
#include "OutOfBounds.h"

template<typename T>
class myList{
public:
    //构造函数，生成一个空的头结点
    myList() { head = new Node<T>; count = 0; }
    myList(myList<T>& another); 
    ~myList();
    myList<T>& pushBack(const T data);
    myList<T>& popBack(T &data);
    myList<T>& pushFrout(const T data);
    myList<T>& popFrout(T &data);
    myList<T>& Insert(const int i,const T& data);
    myList<T>& Delete(const int i,T &data);//按照下标删除，并将该下标处的内容保存到data中
    myList<T>& Delete(const T &data);//按照内容删除
    void showList();
    int Size() const { return count; }
    T find(const int i);
private:
    Node<T> *head;
    int count;
};

template<typename T>
myList<T>::myList(myList<T>& another){
    head = new Node<T>; 
    this->count = 0;
    int count_i = 0;
    while(count_i < another.count){
        T temp = another.find(count_i++);
        pushBack(temp);
    }
}

template<typename T>
myList<T>::~myList(){
    Node<T> *p = head;
    while(p != nullptr){
        head = head -> next;
        delete p;
        p = head;
    }
}

template<typename T>
myList<T>& myList<T>::pushBack(const T data){
    Node<T> *p = head;
    while(p->next!=nullptr)
        p=p->next;
    Node<T> *q = new Node<T>;
    q->data = data;
    p->next = q;
    count++;
    return *this;
}

template<typename T>
myList<T>& myList<T>::popBack(T &data){
    if(head->next == nullptr)
        throw NoMen();

    Node<T> *p = head;
    int i = 0;
    while(i++ < count-1)
        p = p->next;
    data = p->next->data;//保存data值
    delete p->next;
    p->next = nullptr;
    count--;
    return *this;
}

template<typename T>
myList<T>& myList<T>::pushFrout(const T data){
    Node<T> *temp = new Node<T>;
    temp->data = data;
    Node<T>* p = head->next;
    head->next = temp;
    temp->next = p;
    count++;
    return *this;
}

template<typename T>
myList<T>& myList<T>::popFrout(T &data){
    if(head->next == nullptr)
        throw NoMen();

    Node<T> *p = head->next;
    data = p->data;
    head->next = p->next;
    delete p;
    count--;
    return *this; 
}

template<typename T>
void myList<T>::showList(){
    Node<T> *p = head->next;
    int i = 0;
    while(p != nullptr){
        std::cout<<"index:"<<i++<<" "<<" data:"<<p->data<<"\t";
        p = p->next;
    }
    std::cout<<"\n";
}

template<typename T>
myList<T>& myList<T>::Insert(const int i,const T& data){
    if(i<0 || i > count)
        throw OutOfBounds();
    
    Node<T> *p = head;
    int count_i = 0;
    while(count_i++ < i)
        p = p->next;
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
    count++;

    return *this;
}

template<typename T>
myList<T>& myList<T>::Delete(const int i,T &data){
    if(i<0 || i > count)
        throw OutOfBounds();

    int count_i = 0;
    Node<T> *p = head;
    while(count_i++ < i)
        p = p->next;
    Node<T>* temp = p->next;
    data = temp->data;
    p->next = temp->next;
    delete temp;
    count--;

    return *this;
}

template<typename T>
myList<T>& myList<T>::Delete(const T& data){
    //按照内容查找，删除链表中所有值为data的节点
    Node<T>* p =  head;
    Node<T>* q = p->next;
    int num = count;
    for(int count_i = 0;count_i < num && q->next != nullptr;count_i++){
        if(q->data  == data){
            p->next = q->next;
            delete q;
            count--;
            q = p->next;
        }
        else{
            p = q;
            q = q->next;
        }
    }

    return *this;
}

template<typename T>
T myList<T>::find(const int i){
    if(i<0 || i > count)
        throw OutOfBounds();

    Node<T> *p = head->next;
    int count_i = 0;
    while(count_i++ < i)
        p = p->next;
    return p->data;
}

#endif //LIST_H