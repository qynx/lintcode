#include "header.h"

 int maximalRectangle(vector<vector<char> > &matrix) {
        
        if(matrix.size()==0)
        	return 0;
        int n=matrix[0].size();
        int height[n];
        for(int i=0;i<n;i++) height[i]=0;
        int maxc=0;
        
        stack<int>s; //存储递增 索引
            	 s.push(-1);
            	 
        for(int i=0;i<matrix.size();i++){
            
            //重新计算高度
            
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1')
                    height[j]+=1;
                else
                    height[j]=0;
               // cout<<"高度 "<<height[j]<<endl;
            }
            
           
            
      		 
            
            for(int j=0;j<matrix[i].size();j++){
            
                while(s.top()!=-1&&height[s.top()]>height[j]){
                	int t=s.top();
                	s.pop();
                    maxc=max(maxc,(j-s.top()-1)*height[t]);
                   // cout<<height[s.top()]<<" "<<maxc<<endl;
                    
                }
                s.push(j);
            }
            
            while(s.top()!=-1){
                maxc=max(maxc,(n-s.top())*height[s.top()]);
               // cout<<"结算 "<<maxc<<endl;
                s.pop();
            }
            
            
        }
        
        return maxc;
    } 

int main(){
	
	vector< vector<char> >p;
	int n;
	cin>>n;
	char c;
	vector<char>temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c;
			temp.push_back(c);
		}
		p.push_back(temp);
		temp.clear();
	}
	cout<<maximalRectangle(p);
	
}
