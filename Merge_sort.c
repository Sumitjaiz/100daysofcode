#include<stdio.h>
void Merge(int a[], int l, int m , int r){
  int n1=m-l+1;
  int n2=r-m;
  // creating temp arrays
  int L[n1+1];
  int R[n2+1];
  //copying data to temp arrays
  for(int i=0 ; i<n1 ; i++){
      L[i]=a[l+i];   //initially l=0 then l[i]=a[0]
  }for(int j=0 ; j<n2 ; j++){
      R[j]=a[m+j+1];   //initially m=0 then R[j]=a[1]
  }
  L[n1]=999;
  R[n2]=999;
  int i=0,j=0;
  int k;
  for(k=l;k<=r;k++){// loop will run from 0 to r+1 as r is n-1
    if(L[i]<=R[j]){
      a[k]=L[i];
      i++;
    }
    else{
      a[k]=R[j];
      j++;
    }
  }

}
void MergeSort(int a[],int l, int r){
  int m =(l+r)/2;
  if(l<r){
    MergeSort(a,l,m);
    MergeSort(a,m + 1,r);
    Merge(a,l,m,r);
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
  int i,l=0,r,n ,a[100];
  printf("Enter the no. of elements\n" );
  scanf("%d",&n);
  r=n-1;
  for (i = 0; i < n; i++){
    printf("Enter a[%d] element\n", i+1 );
    scanf("%d",&a[i] );
  }
  printf("Given array is \n");
    printArray(a, n);
    MergeSort(a,l,r);

    printf("\nSorted array is \n");
    printArray(a, n);
}
