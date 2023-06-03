#include <stdio.h>
#include <stdlib.h>
static int c=0;
struct node {
    int data;
    struct node* next;
};
struct node* add_beg(struct node* head,int d){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d; 
    ptr->next = NULL;
    ptr->next=head;
    head=ptr;
    return ptr;
}
void add_at_end(struct node *head,int data){
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}
void add_at_pos(struct node* head,int data,int pos){
    struct node *ptr=head;
    struct node *ptr2 =malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->next=NULL;
    for(int i=1;i<(pos-1);i++){
        ptr=ptr->next;
    }
    ptr2->next=ptr->next;
    ptr->next=ptr2;
}
struct node* del_first(struct node *head){
    if(head==NULL){
        printf("List is empty");
    }
    else{
        struct node *temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    return head;
}
struct node* del_last(struct node *head){
    if(head==NULL){
        printf("List is Empty");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        struct node *temp2 =head;
        while(temp->next!=NULL){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=NULL;
        free(temp);
        temp=NULL;
    }
    return head;
}
void delpos(struct node *head){
    int i=0;
    int pos;
    struct node *temp,*temp1;
    temp=head;
    printf("Enter the position of node to be deleted");
    scanf("%d",&pos);
    while(i<(pos-1)){
        temp=temp->next;
        i++;
    }
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
}
int length(struct node *head){
    struct node *l=head;
    int k=0;
    while(l->next!=NULL){
        l=l->next;
        k++;
    }
    return k;
}
struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next1 = NULL;

    while (curr != NULL) {
        next1 = curr->next; 
        curr->next = prev; 

        prev = curr;
        curr = next1;
    }
    head = prev;
    return head;
}
struct node* insertNode(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        if(c==0){
            head->next=newNode;
            c++;
        }
    }
    return head;
}

int main() {
    struct node* head = NULL;
    int a;
    struct node* ptr =malloc(sizeof(struct node));
    printf("Enter the number of data: ");
    scanf("%d",&a);
    int data;
    printf("Enter %d elements:\n",a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &data);
        head = insertNode(head, data);
    }

    printf("Linked List: ");
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("Enter 1 for adding an element at beginning \n");
    printf("Enter 2 for adding an element at end \n");
    printf("Enter 3 for adding an element at specified position \n");
    printf("Enter 4 for deleting an element at beginning \n");
    printf("Enter 5 for deleting an element at end \n");
    printf("Enter 6 for deleting an element at specified position \n");
    printf("Enter 7 for finding length \n");
    printf("Enter 8 for reversing \n");
    int b,c;
    scanf("%d",&b);
    switch(b){
        case 1:{
            printf("Enter the element: ");
            scanf("%d",&c);
            head=add_beg(head,c);
            ptr=head;
            while (ptr != NULL) {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        break;
        case 2:{
            printf("Enter the element: ");
            scanf("%d",&c);
            add_at_end(head,c);
            ptr=head;
            while (ptr != NULL) {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        break;
        case 3:{
            printf("Enter the element: ");
            int d;
            scanf("%d",&c);
            printf("Enter the position: ");
            scanf("%d",&d);
            add_at_pos(head,c,d);
            ptr=head;
            while (ptr != NULL) {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        break;
        case 4:{
            head=del_first(head);
            ptr=head;
            while (ptr != NULL) {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        break;
        case 5:{
            head=del_last(head);
            ptr=head;
            while (ptr != NULL) {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        break;
        case 6:{
            delpos(head);
            ptr=head;
            while (ptr != NULL) {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        break;
        case 7:{
            int i=length(head);
            printf("Length of linked-list is: %d",(i+1));
        }
        break;
        case 8:{
            head=reverse(head);
            ptr=head;
            while (ptr != NULL) {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        break;
        default: printf("Invalid Input");
    }
    return 0;
}