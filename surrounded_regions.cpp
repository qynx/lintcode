/*
Given a 2D board containing'X'and'O', capture all regions surrounded by'X'.

A region is captured by flipping all'O's into'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/ 

#include<iostream>
#include<vector>
using namespace std;

// 从 i，j开始遍历 寻找字符c的连通域 flag判断区域是否被围
// 通过观察可发现 只要连通域有点是在边界上 就不是被围的 
void dfs(vector< vector<char> > &board,int i,int j,char c,char newc,int &flag){
	
	//边界检查 
	if(i<board.size()&&i>=0&&j>=0&&j<board[i].size()&&board[i][j]==c){
		//当前点在边界上 
		if(i==0||i==(board.size()-1)||j==0||j==(board[i].size()-1))
			flag=1; //此区域没有被包裹 
 	  board[i][j]=newc;
	  dfs(board,i-1,j,c,newc,flag);
	  dfs(board,i,j-1,c,newc,flag);
	  dfs(board,i,j+1,c,newc,flag);
	  dfs(board,i+1,j,c,newc,flag);
    }
	
}
  void solve(vector< vector<char> > &board) {
       int flag; 
	    for(int i=0;i<board.size();i++){
	    	for(int j=0;j<board[i].size();j++){
	    		
	    		//寻找此O的连通区域 
	    		if(board[i][j]=='O'){ 
	    		flag=0;
	    			//把O 转为F防止重复计算dfs 
	    			dfs(board,i,j,'O','F',flag);
	    		   
				//判断此区域是否被X surround
				
				//被包裹 转换F为X 
				if(!flag){
					dfs(board,i,j,'F','X',flag);		
				}
				
				 
			  }
			}
		}
		
		for(int i=0;i<(int)board.size();i++){
	    	for(int j=0;j<board[i].size();j++){
	    	  //把所有的F恢复原样
			  if(board[i][j]=='F')
			  	dfs(board,i,j,'F','O',flag);	
	    		}
			} 
 }
    
int main(){
	
	
}
