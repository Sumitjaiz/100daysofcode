#include<stdio.h>
int Ternary_search(int a[],int l,int r,int key){
  while(l <= r){
    int mid1,mid2;
    mid1=l+(r-l)/3;
    mid2=r-(r-l)/3;
    if(key== a[mid1]){
      return mid1;
    }
    if(key== a[mid2]){
      return mid2;
    }
      if (key<a[mid1]){
        r=mid1 - 1;
      }
      else if (key > a[mid2]) {
        l=mid2 + 1;
      }
      //in between mid1  and mid2
        else if(key> a[mid1] && key < a[mid2]){
          l=mid1 + 1;
          r=mid2 - 1;
        }

    }
    return -1;
}
void main(){
  int i,l=0,r,n ,a[100],key,index;
  printf("Enter the no. of elements\n" );
  scanf("%d",&n);
  r=n-1;
  for (i = 0; i < n; i++){
    printf("Enter a[%d] element\n", i+1 );
    scanf("%d",&a[i] );
  }
  printf("Enter element to be search\n" );
  scanf("%d",&key );
  index=Ternary_search(a,l,r,key);
  if(index==-1){
    printf("not found\n" );
  }
  else{
  printf("Element fount at %d index\n", index+1);
  }
}
