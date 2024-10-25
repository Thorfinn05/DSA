#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};
struct Node *start=NULL;

void create(int val){
  struct Node *new, *ptr;
  new=malloc(sizeof(struct Node));
  new->data=val;
  if(start==NULL){
    start=new;
  }
  else{
    ptr=start;
    while(ptr->next!=start){
      ptr=ptr->next;
    }
    ptr->next=new;
  }
  new->next=start;
}

void display(){
  struct Node *ptr, *postptr;
  ptr=start;
  printf("Linked List: ");
  while(postptr!=start->next){
    printf("%d ",ptr->data);
    ptr=ptr->next;
    postptr=ptr->next;
  }
  printf("\n");
}

void insert(int val, int pos){
  struct Node *new, *ptr, *preptr;
  new=malloc(sizeof(struct Node));
  new->data=val;
  if(pos==1){
    new->next=start;
    ptr=start;
    while(ptr->next!=start){
      ptr=ptr->next;
    }
    ptr->next=new;
    start=new;
  }
  else{
    int i=1; ptr=start; preptr=ptr;
    while(i<pos){
      preptr=ptr;
      ptr=ptr->next;
      i++;
    }
    preptr->next=new;
    new->next=ptr;
    }
  }

void delete(int pos){
  struct Node *ptr, *preptr, *postptr, *temp=start;
  
  if(pos==1){
    ptr=start;
    start=ptr->next;
    while(ptr->next!=temp){
      ptr=ptr->next;
    }
    ptr->next=start;
  }
  else{
    int i=1; ptr=start; preptr=ptr;
    while(i<pos){
      preptr=ptr;
      ptr=ptr->next;
      postptr=ptr->next;
      i++;
    }
    preptr->next=postptr;
    free(ptr);
    }
  }

void search(int val){
  struct Node *ptr=start, *postptr;
  int i=1;
  while(postptr!=start->next){
    if(ptr->data==val){
      printf("Element %d found at position %d.\n",val, i);
      return;
    }
    ptr=ptr->next;
    postptr=ptr->next;
    i++;
  }
  printf("Element %d does not exist in the list.\n",val);
}

int main(){
  int pos, val, choice, n;
  while(1){
    printf("*Choose\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n6. Exit\nEnter Choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        printf("Enter population: ");
        scanf("%d",&n);
        printf("Enetr elements: ");
        for(int i=0; i<n; i++){
          scanf("%d",&val);
          create(val);
        }
        break;
      case 2:
        display();
        break;
      case 3:
        printf("Enter element to insert: ");
        scanf("%d",&val);
        printf("Enter position to insert: ");
        scanf("%d",&pos);
        insert(val, pos);
        break;
      case 4:
        printf("Enter position to delete: ");
        scanf("%d",&pos);
        delete(pos);
        break;
      case 5: 
        printf("Enter element to search: ");
        scanf("%d",&val);
        search(val);
        break;
      case 6:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid input.\n");
        return 0;
    }
  }
}