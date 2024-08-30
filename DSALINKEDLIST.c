#include <stdio.h>
#include <stdlib.h>

// Creating a structure  to understand singly linked list
struct node {
  int data;
  struct node *next;// Self refrential structure
};


// Function to traverse a singly linked list
void traverse(struct node *head){
    struct node *ptr=head;
    printf("Elements :\n");
    while(ptr->next!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }


}

// Inserting a node in the beginning of a singly linked list

struct node *insertFirst(struct node * head,int x){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->next=head;
    return ptr;
}
struct node *insertBetween(struct node *head,int x,int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=x;
    ptr->next=p->next;
    p->next=ptr;
    return head;
    
}


struct node *insertEnd(struct node *head,int x){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
        
    }
    ptr->data=x;
    
    ptr->next=NULL;
    
    return head;
    
}


struct node *deleteFirst(struct node *head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}



struct node *deleteBetween(struct node *head, int index){

    struct node *ptr1=head;
    struct node *ptr2=head->next;
    int i;
    for(i=0;i<index-1;i++){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        
    }

    ptr1->next=ptr2->next;
    free(ptr2);
    return head;
}



struct node *deleteEnd(struct node *head){
    struct node *ptr1=head;
    struct node *ptr2=head->next;
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1->next=NULL;
    free(ptr2);
    return head;   
}




int main(){
   struct node *current1=(struct node *)malloc(sizeof(struct node));
   struct node *current2=(struct node *)malloc(sizeof(struct node));
   struct node *current3=(struct node *)malloc(sizeof(struct node));

  // element 1
  struct node *head=(struct node *)malloc(sizeof(struct node));
  head->data=45;
  head->next=current1;

  // element 2
  current1->data=59;
  current1->next=current2;
  

  // element 3
  current2->data=88;
  current2->next=current3;

  // element 4
  current3->data=78;
  current3->next=NULL;


// Traversing a singly linked list 
  traverse(head);

  // Inserting element at front.

 head=insertFirst(head,99);
//  elements after inserting at front
 traverse(head);
// Inserting element in between.

 head=insertBetween(head,99,3);
 //  elements after inserting in between 
 traverse(head);


 // Inserting element at end.
// printf("Insertion");
//  head=insertEnd(head,123);

//   //  elements after inserting at end
//  traverse(head);


// Deletion at first


head=deleteFirst(head);
printf("Element after deletion \n");
traverse(head);



head=deleteBetween(head,1);
printf("Element after deletion \n");
traverse(head);


head=deleteEnd(head);
printf("Element after deletion \n");
traverse(head);





 

  
  
  return 0;
  
}