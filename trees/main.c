#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    int c;
    struct Element* leftchild;
    struct Element* rightchild;

}Element;
typedef struct pile{
    int c;
    struct pile* suivant;

}pile;

pile *createpile(int data){
    pile *p;
    p=(pile*)malloc(sizeof(pile));
    p->c=data;
    p->suivant=NULL;
    return p;

}
void push(pile**p,int data){
    pile *newel;
    newel=createpile(data);
    newel->suivant=*p;
    *p=newel;
}
void pop(pile**p){
    pile *tmp;
    if(*p==NULL) return;
    tmp=*p;
    *p=tmp->suivant;
    tmp=NULL;

}
int peek(pile*p){
    if(p==NULL) return -1;
        return p->c;
}

Element *CreateElement(int a){
    Element *nouv;
    nouv=(Element*)malloc(sizeof(Element));
    nouv->c=a,
    nouv->leftchild=NULL;
    nouv->rightchild=NULL;

    return nouv;
}
int Count(Element *BT){
    if(BT)
        return (1+Count(BT->leftchild)+Count(BT->rightchild));
    return 0;
}
void cutright(Element *BST,int a)
{
    if(!BST)
        return;
    while(BST){
        if(BST->c==a)
        {
             BST->rightchild=NULL;
             return ;
        }
        if(a > BST->c)
        {
            BST=BST->rightchild;
        }else
            BST=BST->leftchild;

    }
    return ;


}

void prefixe(Element *BT){
    Element *ptr=BT;
    pile *p=NULL;
    while(ptr!=NULL){

        printf("%d ",ptr->c);
        if(ptr->rightchild)
            push(&p,ptr->rightchild->c);
        ptr=ptr->leftchild;
        if(ptr==NULL)
        {
            ptr=peek(p);
            pop(&p);
        }

    }


}
//void infixe(Element *BT){
//    Element *ptr=BT;
//    while(ptr){
//        if(ptr->leftchild){
//            push(&pile,ptr);
//            ptr=ptr->leftchild
//        }
//        else {
//            printf("%d ",ptr->c);
//            if(ptr->rightchild)
//                ptr=ptr->rightchild;
//            else {
//                ptr=pop(&pile);
//                printf("%d ",ptr->c);
//                ptr=ptr->rightchild;
//            }
//        }
//    }
//
//}


int main()
{
    Element *BT;
    BT=NULL;
    Element *e1=CreateElement(5);
    Element *e2=CreateElement(3);
    Element *e3=CreateElement(7);
    Element *e4=CreateElement(1);
    Element *e5=CreateElement(4);
    Element *e6=CreateElement(6);
    Element *e7=CreateElement(10);
    Element *e8=CreateElement(2);
    Element *e9=CreateElement(8);
    Element *e10=CreateElement(9);
    BT=e1;
    e1->leftchild=e2;
    e1->rightchild=e3;

    e2->leftchild=e4;
    e2->rightchild=e5;

    e3->leftchild=e6;
    e3->rightchild=e7;

    e4->rightchild=e8;
    e4->leftchild=NULL;

    e6->rightchild=NULL;
    e6->leftchild=NULL;

    e7->leftchild=e9;
    e7->rightchild=NULL;

    e9->rightchild=e10;
    e9->rightchild=NULL;

    prefixe(BT);
    //printf("\n\t %d",Count(BT));

    return 0;
}
