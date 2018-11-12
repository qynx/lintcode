#include<iostream>
using namespace std;

int matrix[3][4];

void print_matrix(int matrix[3][4],int m,int n){
    
    for(int s=0;s<m+n-1;s++){
        for(int i=0;i<m;i++){
                if(s-i>=0&&s-i<n)
                cout<<matrix[i][s-i]<<" ";           
        }
       cout<<endl;
    }
}
int main(){
    
    //int m,n;
    //cin>>m>>n;
    int ele=1;
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++){
            matrix[i][j]=ele++;
        }
   /* for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }*/
    print_matrix(matrix,3,4);
     
}
