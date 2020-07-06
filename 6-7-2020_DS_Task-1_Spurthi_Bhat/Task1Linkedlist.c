#include<stdio.h>
struct node{
 int data;
 struct node *next;
};

void display(struct node *head1){
 struct node *temp=head1;
   while (temp->next!=NULL)
   {

    printf("%d -> ",temp->data);
    temp=temp->next;

   }
   printf("%d -> NULL\n ",temp->data);

}

struct node* front(struct node *head,int val){
 struct node *p;
 p=(struct node*)malloc(sizeof(struct node));
 p->data=val;
 p->next=head;
 return p;
}

struct node* end(struct node *head1,int val1){
 struct node* p,*q;
 p=(struct node*)malloc(sizeof(struct node));
 p->data=val1;
 p->next=NULL;
 q=head1;
 while(q->next!=NULL){
  q=q->next;
  }
  q->next=p;
  return p;
}

struct node*  insert(struct node *a,int val2){
 struct node *p;
 p=(struct node*)malloc(sizeof(struct node));
 p->data=val2;
 p->next=a->next;
 a->next=p;
 return p;
}

void del(struct node *b){
 struct node *temp1;
 temp1=b->next;
 b->next=temp1->next;
 free(temp1);
}



int main(){
 struct node *end_link=(struct node*)malloc(sizeof(struct node));
 struct node *middle_link=(struct node*)malloc(sizeof(struct node));
 struct node *head=(struct node*)malloc(sizeof(struct node));
 head->data=100;
 head->next=NULL;

 struct node *second_link=(struct node*)malloc(sizeof(struct node));
 second_link->data=120;
 second_link->next=NULL;

 head->next=second_link;

 struct node *third_link=(struct node*)malloc(sizeof(struct node));
 third_link->data=130;
 third_link->next=NULL;

 second_link->next=third_link;

 struct node *fourth_link=(struct node*)malloc(sizeof(struct node));
 fourth_link->data=140;
 fourth_link->next=NULL;

 third_link->next=fourth_link;

printf("\n The linked list is:");
 display(head);
 printf("\n Node insertion at head/first position:");
 head=front(head,50);
 display(head);
 printf("\n Node insertion at the end of linked list:");
 end_link=end(head,150);
 display(head);
 printf("\n Node insertion at some random position:");
 middle_link=insert(second_link,125);
 display(head);
 printf("\n Deletion of a Node:");
 del(middle_link);//passing the node before the node to be deleted
 display(head);


}
