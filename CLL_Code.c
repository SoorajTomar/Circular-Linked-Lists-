#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *next;
};
typedef struct node sn;
sn *tail=NULL;
sn* insertb(sn* h,int val){
    sn *t=(sn*)malloc(sizeof(sn));
    t->data=val;
    if(h==NULL)
    {t->next=t;
    h=t;}
    else
    {t->next=h->next;
    h->next=t;}
    return h;
}
sn* inserte(sn* h,int val){
    sn *t=(sn*)malloc(sizeof(sn));
    t->data=val;
    t->next=h->next;
    h->next=t;
    h=t;
    return h;
}
sn* delb(sn* h){
    sn* x=h->next;
    h->next=h->next->next;
    free(x);
    return h;
}
sn* dele(sn* h){
    sn* p=h->next;
    while(p->next!=h)p=p->next;
    sn* x=p->next;
    p->next=h->next;
    free(x);
    h=p;
    return h;
}
void print(sn* h){
    sn* p=h->next;
    while(p!=h){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("%d",p->data);
}
int main()
{
    int i;
    for(i=0;i<5;i++)
    tail=insertb(tail,i);
    print(tail);
    printf("\n");
    tail=inserte(tail,95);
    print(tail);
    printf("\n");
    tail=delb(tail);
    print(tail);
    printf("\n");
    tail=dele(tail);
    print(tail);
    printf("\n");
    return 0;
}
