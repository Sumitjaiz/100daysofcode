#include<stdio.h>
int Ternary_search(int l,int r,int a[],int key){
  if(l<=r){
    int mid1= l + (r - l)/3;
    int mid2 = r - (r - l)/3;
    if(key==a[mid1]){
      return mid1;
    }
    if(key==a[mid2]){
      return mid2;
    }
    if(key<a[mid1]){
      return Ternary_search(l,mid1-1,a,key);
    }
    else if(key>a[mid2]){
      return Ternary_search(mid2+1,r,a,key);
    }
   //between mid1 and mid2
    else{
      return Ternary_search(mid1+1,mid2-1,a,key);
    }
  }
  // key not found
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
  index=Ternary_search(l,r,a,key);
  if(index==-1){
    printf("not found\n" );
  }
  else{
  printf("Element fount at %d index\n", index+1);
  }
}
