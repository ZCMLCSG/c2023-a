#include<stdio.h>
#include<stdlib.h>
struct List{
    int element;
    struct List* next;
};

typedef struct List* Node;

void init(Node node){
    node->next=NULL;
}

_Bool insert(Node head,int element,int a){
    if(a<1) return 0;
    while(--a){
        head=head->next;
        if(head==NULL) return 0;
    }
    Node node = malloc(sizeof (struct List));
    if(node==NULL) return 0;
    node->element=element;
    node->next=head->next;
    head->next=node;
    return 1;
}

struct List change(Node head, int sizeList){
    struct List head2;
    init(&head2);
    for(int i= sizeList;i>0;i--){
        head=head->next;
        insert(&head2,head->element,1);
    }
    return head2;
}

int findplace(Node head,int element){
    head=head->next;
    int i=1;
    while(head){
        if(head->element==element) return i;
        head=head->next;
        i++;
    }
    return -1;
}

int findplace2(Node head,int element){
    head=head->next;
    int i=1;
    int a=0;
    while(head){
        if(head->element==element) a+=1;
        head=head->next;
        if(a==2)return i;
        i++;
    }
    return -1;
}

void printList(Node head){
    while(head->next){
        head=head->next;
        printf(" %d",head->element);
    }
    printf("\n");
}

int main(){
    struct List numbers;
    init(&numbers);
    for(int i=5;i>=1;i--) {
        insert(&numbers, i, 1);
    }
    insert(&numbers, 5, 1);
    printf("初始的数字有：\n");
    printList(&numbers);
    struct List numbers2=change(&numbers, 6);
    printf("反序后的数字为：\n");
    printList(&numbers2);
    printf("请输入您要查找的数字\n");
    int a;
    scanf("%d",&a);
    if(1<=a&&a<=5)
    {
        printf("%d\n", findplace(&numbers2, a));
    }
    else
    {
        printf("-1\n");
    }
    printf("请输入您要查找的数字（将查找其第二次出现的位置）\n");
    int b;
    scanf("%d",&b);
    if(findplace2(&numbers2, b) != -1)
    {
        printf("%d\n", findplace2(&numbers2, b));
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
