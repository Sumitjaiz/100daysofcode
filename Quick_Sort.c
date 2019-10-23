#include<stdio.h>
int Partition(int arr[],int p ,int r){//p=start element and r = last element
  int temp;
  int  x=arr[r];
  int  i = p-1;//initially i will -1
    for( int j=p;j<r;j++){
      if(arr[j]<=x){
        i=i+1;
        temp=arr[i];//swap a[i] and a[j]
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return (i+1);
}
void QuickSort(int a[],int p,int r){
  if(p<r){
    int q=Partition(a,p,r);
    QuickSort(a,p,q-1);
    QuickSort(a,q+1,r);
  }
}
void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void main(){
  int i,p=0,n ,a[100];
  printf("Enter the no. of elements\n" );
  scanf("%d",&n);
  for (i = 0; i < n; i++){
    printf("Enter a[%d] element\n", i+1 );
    scanf("%d",&a[i] );
  }
  printf("Given array is \n");
    printArray(a, n);
    QuickSort(a,p,n-1);
    printf("\nSorted array is \n");
    printArray(a, n);
}
