#include<iostream>
using namespace std;

char earth[10][10];
int m,n;  //行列数
int countOfEarth(){
    
    int count=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(earth[i][j]=='+'){
                dfs(i,j);
                count++;
            }
        }
    return count;
}

bool Validate(int i,int j){
     if(i>=0&&i<m&&j>=0&&j<n&&earth[i][j]=='+')
         return true;
}

void dfs(int i,int j){
    
    earth[i][j]='-';  //防止重复检测
    if(Validate(i,j-1))
        dfs(i,j-1);
    if(Validate(i,j+1))
        dfs(i,j+1);
    if(Validate(i+1,j))
        dfs(i+1,j);
    if(Validate(i-1,j))
        dfs(i-1,j);
}
int main(){
    
   // for()
    return 0;
}
