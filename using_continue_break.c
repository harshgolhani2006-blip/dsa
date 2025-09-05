//#include<stdio.h>
//int main(){
   // for(int i=0;i<5;i++){
       // if(i==3){
           // break;
         //  continue;
      //  }
       // printf("%d\n",i);
   // }
//}
//#include<stdio.h>
//int main(){
//    int i,n;
  //  int isprime=1;
    //printf("Enter value of n:");
    //scanf("%d",&n);
    //if(n<=1){
      //  printf("it is not a prime number");
        //return 0;
    //}
    //for( i=2;i<n;i++){
      //  if(n%i==0){
        //    isprime=0;
          //  break;
        //}
        //if(isprime){
          ///  printf("it is a prime number");
        //}
        //else{
          //  printf("it is not a prime number");
        //}
   // }
//}
//#include<stdio.h>
//int main(){
  //  int n,t1=0,t2=1,next;
    //printf("Enter value of n:");
    //scanf("%d",&n);
    //for(int i=1;i<=n;i++){
      //  printf(" %d ",t1);
        //next=t1+t2;
        //t1=t2;
        //t2=next;
    //}
    //return 0;
//}
//#include<stdio.h>
//int main(){
//int n,t1=0,t2=1,next,i;
//printf("Enter vale of n:");
//scanf("%d",&n);
//i=0;
//while(i<=n){
  //printf("%d ",t1);
  //next=t1+t2;
  //t1=t2;
  //t2=next;
  ///i++;
///}
//return 1;
//}
#include<stdio.h>
int main(){
  int n,count=0;
  printf("Enter value of n:");
  scanf("%d",&n);
  if(n==0){
    count=1;
  }
  while(n>0){ 
    
    count++;
    n=n/10;
  }
  printf("%d\n",count);
}