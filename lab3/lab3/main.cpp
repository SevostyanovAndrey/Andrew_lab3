//
//  main.cpp
//  lab3
//
//  Created by user on 17.05.2021.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
 
struct node {
    int val;
    node* next;
    node(int v, node* st):val(v), next(st){}
};
 
void  stack_push(node*& st, int val);
void  stack_pop(node*& st);
node* stack_min(node* st);
 
int main(void){
    srand(static_cast<unsigned int>(time(NULL)));
 
    node* st = NULL;
    for(int i = 0; i < 10; ++i)
        stack_push(st, rand() % 10);
    

    for(const node* j = st; j != NULL; j = j->next)
        std::cout << j->val << ' ';
    std::cout << std::endl;
 
    
    node* p   = stack_min(st);
    node* st1 = NULL;
    if(p != st){
        st1 = st;
        st  = p->next;
        p->next = NULL;
    }
 
    
    while(st1 != NULL){
        std::cout << st1->val << ' ';
        stack_pop(st1);
    }
    std::cout << std::endl;
 
    //вывести оставшиеся элементы в исходном стеке
    while(st != NULL){
        std::cout << st->val << ' ';
        stack_pop(st);
    }
    std::cin.get();
    return 0;
}
 
void stack_push(node*& st, int val){
    st = new node(val, st);
}
 
//вытолкнуть
void stack_pop(node*& st){
    node* t;
    if(st != NULL){
        t  = st;
        st = st->next;
        delete t;
    }
}
 
node* stack_min(node* st){
    node* p = st;
    for(; st != NULL; st = st->next){
        if(st->val < p->val)
            p = st;
    }
    return p;
}
