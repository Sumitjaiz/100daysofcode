#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,n,z=0;
  scanf("%d",&n );
  if(n<=100000 && n>0){
    int a[n],b[n];
    for ( i = 0; i < n; i++) {
      /* code */
      scanf("%d",&a[i] );
      if(a[i]<1 || a[i]>1000000000){
        exit(0);
      }
    }
    for(i=0;i<n;i++){
      int y=0;
      z= a[i];
      while(z>0){
      z=z/5;
      y= y+z;
      }
      b[i]=y;
    }
    for(i=0;i<n;i++)
    printf("%d\n",b[i] );
  }
  return 0;
}
