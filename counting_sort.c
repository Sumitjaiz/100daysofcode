#include<stdio.h>
void CountingSort(int a[],int b[], int k,int n){
  int i,j,c[k];
  for(i=0;i<=k;i++){
    c[i]=0;
  }
  //counting and storing each number to c array
  for(j=0;j<n;j++){//loop for a[]
    c[a[j]]=c[a[j]]+1;
  }

  //loop for c[]
  //c[] stores the number of elements less or equal to i
  for(i=1;i<=k;i++){
    c[i]=c[i]+c[i-1];
  }
  for(j=n-1;j>=0;j--){

    b[c[a[j]]-1] =a[j];
    printf("%d  ",b[j] );
    c[a[j]] = c[a[j]]-1;
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
  int i,n ,k;
  printf("Enter the no. of elements\n" );
  scanf("%d",&n);
  printf("Enter the max element\n" );
  scanf("%d",&k);
  int a[n],b[n];

  for (i = 0; i < n; i++){
    printf("Enter a[%d] element\n", i+1 );
    scanf("%d",&a[i] );
  }
  printf("Given array is \n");
    printArray(a, n);
    CountingSort(a,b,k,n);
    printf("\nSorted array is \n");
    printArray(b, n);
}
