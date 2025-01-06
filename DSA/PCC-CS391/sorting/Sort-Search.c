#include<stdio.h>

void insertionSort(int arr[], int n){
  int i, j, temp, k;
  for(i=1;i<n;i++){
    k=arr[i];
    j=(i-1);
    while(j>=0 && arr[j]>k){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=k;
  }
}

void bubbleSort(int arr[], int n){
  int i,j, temp;
  for(i=0;i<n;i++){
    for(j=0;j<n-i;j++){
      if(arr[j+1]<arr[j]){
        temp=arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=temp;
      }
    }
  }
}

void selectionSort(int arr[], int n){
  int i,j,k,temp,min;
  for(i=0;i<n;i++){
    min=arr[i];
    // k=i;
    for(j=i+1;j<n;j++){
      if(arr[j]<min){
        min=arr[j];
        k=j;
      }
    }
    temp=arr[i];
    arr[i]=arr[k];
    arr[k]=temp;
  }
}

void linearSearch(int arr[], int n){
  int i,a,count=0;
  printf("Enter element to search: ");
  scanf("%d",&a);
  for(i=0;i<n;i++){
    if(arr[i]==a){
      printf("Element found at position %d.\n",i+1);
      count++;
      break;
    }
  }
  if(!count){
    printf("Element does not exist in array.\n");
  }
}

void binarySearch(int arr[], int n){
  int i,a,ub,lb,mid,count=0; lb=0; ub=n-1;
  printf("Enter element to search: ");
  scanf("%d",&a);
  for(i=0;i<n;i++){
    mid=(ub+lb)/2;
    if(arr[mid]==a){
      printf("Element found at position %d.\n",mid+1);
      count++;
      break;
    }
    else if(arr[mid]>a){
      ub=mid-1;
    }
    else if(arr[mid]<a){
      lb=mid+1;
    }
  }
  if(!count){
    printf("Element does not exist in the array.\n");
  }
}

void print(int arr[], int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int main(){
  int n, i, choice; 
  printf("Enter array length: ");
  scanf("%d",&n);
  int arr[100];
  printf("Enter array elements: ");
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("Original array: ");
  print(arr,n);
  while(1){
    printf("\nChoose:\n1. Insertion Sort\n2. Bubble Sort\n3. Selection Sort\n4. Linear Search\n5. Binary Search\n6. Exit\nEnter Choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        insertionSort(arr,n);
        printf("Sorted Array: ");
        print(arr,n);
        break;
      case 2:
        bubbleSort(arr,n);
        printf("Sorted Array: ");
        print(arr,n);
        break;
      case 3:
        selectionSort(arr,n);
        printf("Sorted Array: ");
        print(arr,n);
        break;
      case 4:
        print(arr,n);
        linearSearch(arr,n);
        break;
      case 5:
        selectionSort(arr,n);
        print(arr,n);
        binarySearch(arr,n);
        break;
      case 6:
        printf("Exiting...");
        return 0;
      default:
        printf("Invalid Input.\n");
        break;
    }
  }
}