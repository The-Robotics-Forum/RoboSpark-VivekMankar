#include <stdio.h>
#include <stdlib.h>

typedef struct Students{
   char name[30];
    int Roll;
}students;
typedef struct Queue
{
    int arr[10];
    int front,rear;

}Queue;

void initialize(Queue* q){
    q->front=0;
    q->rear=0;
}

void enqueue(Queue* q,students *ptr1,int s){
 int j;
  for(j=0;j<s;++j){
    if(((ptr1+j)->Roll)%2==0){
      q->arr[q->rear++]=(ptr1+j)->Roll;
      }
     else{
      printf("\n Odd Numbers not allowed");
     }
    }
 }
void print(Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty");
        return;
    }
    printf("\nfront->");
    for(int i=q->front;i<q->rear;i++){
        printf("%d->",q->arr[i]);


    }
    printf("Rear\n");
}


int dequeue(Queue* q){
    return q->arr[q->front++];
}

int isEmpty(Queue* q){
    return q->front==q->rear;
}

int main(){
students *ptr;
   int i, n;

   printf("Enter the number of students: ");
   scanf("%d", &n);

   ptr = (students*) malloc(n * sizeof(students));

   for(i = 0; i < n; ++i)
   {
       printf("Enter name and Roll no.respectively: ");

       scanf("%s %d", (ptr+i)->name, &(ptr+i)->Roll);
   }


   Queue* q1=(Queue*)malloc(sizeof(Queue));
    initialize(q1);
    enqueue(q1,ptr,n);
     print(q1);
    return 0;
}
