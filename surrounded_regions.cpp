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

// �� i��j��ʼ���� Ѱ���ַ�c����ͨ�� flag�ж������Ƿ�Χ
// ͨ���۲�ɷ��� ֻҪ��ͨ���е����ڱ߽��� �Ͳ��Ǳ�Χ�� 
void dfs(vector< vector<char> > &board,int i,int j,char c,char newc,int &flag){
	
	//�߽��� 
	if(i<board.size()&&i>=0&&j>=0&&j<board[i].size()&&board[i][j]==c){
		//��ǰ���ڱ߽��� 
		if(i==0||i==(board.size()-1)||j==0||j==(board[i].size()-1))
			flag=1; //������û�б����� 
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
	    		
	    		//Ѱ�Ҵ�O����ͨ���� 
	    		if(board[i][j]=='O'){ 
	    		flag=0;
	    			//��O תΪF��ֹ�ظ�����dfs 
	    			dfs(board,i,j,'O','F',flag);
	    		   
				//�жϴ������Ƿ�X surround
				
				//������ ת��FΪX 
				if(!flag){
					dfs(board,i,j,'F','X',flag);		
				}
				
				 
			  }
			}
		}
		
		for(int i=0;i<(int)board.size();i++){
	    	for(int j=0;j<board[i].size();j++){
	    	  //�����е�F�ָ�ԭ��
			  if(board[i][j]=='F')
			  	dfs(board,i,j,'F','O',flag);	
	    		}
			} 
 }
    
int main(){
	
	
}
