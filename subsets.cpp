#include "header.h"

class Solution {
public:
    vector<int> temp;
    vector< vector<int> > result;
    void backtrack(vector<int>&list,int start ,int k){
        if(start>=list.size())
            return;
        for(int i=start;i<list.size();i++){
            temp.push_back(list[i]);
            if(temp.size()==k)
            {
                result.push_back(temp);
                temp.pop_back();
                continue;
            }
            else{
                backtrack(list,i+1,k);
                temp.pop_back();
            }
        }
    }
    vector<vector<int> > combine(int n, int k) {
         vector<int>list;
        for(int i=1;i<=n;i++)
            list.push_back(i);
        backtrack(list,0,k);
        return result;
    }
};
vector<vector<int> > subsets(vector<int> &S) {
        
}
    
int main(){
	
		
	
}

 
