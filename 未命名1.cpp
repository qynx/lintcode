#include "header.h"
using namespace std;

 int    a[20000]={0};
    int removeDuplicates(int A[], int n) {
        
         if(n<=2)
             return n;
        for(int i=0;i<n;i++){
            a[A[i]+10000]+=1;
        }
        //return 0;
        int l=0;
        for(int i=0;i<n;i++){
            l+=a[A[i]+10000]>2?2:a[A[i]+10000];
            cout<<a[A[i]+10000]<<endl;
        }
        return l;
    }

int main(){
int A[10]={1,1,1,1}; 
removeDuplicates(A,4);
}
