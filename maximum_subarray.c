#include<stdio.h>
// const int m=-1e9;
// int max=m;
int sub(int a[],int n){
    const int m=-1e9;
    int max=m;
    int cur=0;
    for(int i=0;i<n;i++){
        cur+=a[i];
        if(cur>max){
            max=cur;
        }
        if(cur<0){
            cur=0;
        }
    }
    return max;
}
int main(){
    int a[]={1,3,8,-2,6,-8,5};
    printf("%d\n" ,sub(a,7));

}