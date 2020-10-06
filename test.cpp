#include <iostream>
#include "List.h"

int main(){
    try{
        myList<int> onetest;
        // int a;
        // onetest.popFrout(a);
        for(int i=0;i<5;i++){
            onetest.pushBack(i);
        }
        onetest.showList();
        onetest.Insert(1,3);
        onetest.showList();
        std::cout<<onetest.Size()<<"\n";
        int a;
        onetest.Delete(3);
        onetest.showList();
        a = onetest.find(0);
        std::cout<<a<<std::endl;
        myList<int> cop(onetest);
        cop.showList();
    }
    catch(NoMen){
        std::cout<<"is empty\n";
    }
    catch(OutOfBounds){
        std::cout<<"out of bounds\n";
    }
    return 0;
}