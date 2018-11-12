#include<iostream>
using namespace std;

int yue(int n, int m)
    {
        int a[n];
        for(int i=0;i<n;i++)
            a[i]=1;
        int i=0;
        int count=0;
        int left=n;
        cout<<"HH"<<endl;
        while(left>1){
            if(a[i]==1)
            {count+=1;
            
            cout<<count<<endl;
             if(count==m)
             {left--;  a[i]=0; count=0;}
            } 
            i=(i+1)%n;
        }
        for(i=0;i<n;i++)
            if(a[i]!=0)
                break;
        return i;
    }
	
int main(){
	cout<<yue(5,3);
	
} 
