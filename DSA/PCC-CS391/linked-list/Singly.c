#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};
struct Node *start=NULL;

void createList(int val){
  struct Node *ptr, *new;
  new=malloc(sizeof(struct Node));
  new->data=val;
  new->next=NULL;
  if(start==NULL) {
    start=new;
  }
  else{
    ptr=start;
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next=new;
  }
}

void display(){
  if(start==NULL){
    printf("No linked list is created.\n");
  }
  else{
    struct Node *ptr=start;
    printf("Linked List: ");
    while(ptr!=NULL){
      printf("%d ",ptr->data);
      ptr=ptr->next;
    }
    printf("\n");
  }
}

void insert(int val, int pos){
  if(start==NULL){
    printf("No linked list is created.\n");
  }
  else{
    struct Node *new, *ptr, *preptr;
    new=malloc(sizeof(struct Node));
    new->data=val;
    if(pos==1){
      new->next=start;
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
}

void delete(int pos){
  if(start==NULL){
    printf("No linked list is created.\n");
  }
  else{
    struct Node *ptr, *preptr, *postptr;
    ptr=start;
    if(pos==1){
      start=ptr->next;
      free(ptr);
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
}

void search(int val){
  struct Node *ptr=start;
  int i=1;
  while(ptr!=NULL){
    if(ptr->data==val){
      printf("Element %d found at position %d.\n",val,i);
      return;
    }
    ptr=ptr->next;
    i++;
  }
  printf("Element %d does not exist in the list.\n",val);
}

void maxAndMin(){
  struct Node *ptr=start;
  int i=1;
  int max=ptr->data;
  int min=ptr->data;
  while(ptr!=NULL){
    if(ptr->data > max){
      max = ptr->data;
    }
    if(ptr->data < min){
      min = ptr->data;
    }
    ptr=ptr->next;
    i++;
  }
  printf("Max: %d and Min: %d\n",max,min);
}

int main(){
  int choice, val, pos, n;
  while(1){
    printf("\nChoose: \n1.Create\n2.Display\n3.Search\n4.Insert\n5.Delete\n6.Exit\n7. Max and Min Data\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        printf("Enter population: ");
        scanf("%d",&n);
        int i;
        printf("Enter elements: ");
        for(i=0;i<n;i++){
          scanf("%d",&val);
          createList(val);
        }
        break;
      case 2:
        display();
        break;
      case 3:
        printf("Enter the element to search: ");
        scanf("%d",&val);
        search(val);
        break;
      case 4:
        printf("Enter the element to insert: ");
        scanf("%d",&val);
        printf("Enter the position to insert: ");
        scanf("%d",&pos);
        insert(val,pos);
        break;
      case 5:
        printf("Enter position to delete: ");
        scanf("%d",&pos);
        delete(pos);
        break;
      case 6:
        printf("Exiting...\n");
        return 0;
      case 7:
        maxAndMin();
        break;
      default:
        printf("Invalid Input.\n");
    }
  }
}