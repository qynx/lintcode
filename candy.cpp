#include<iostream>
#include<vector>

using namespace std;

int candy(vector<int> &ratings) {
	
	vector<int>newr=ratings;
	int temp;
	
	for(int i=0;i<newr.size();i++)
		for(int j=i+1;j<newr.size();j++){
			if(newr[j]<newr[i]){
				temp=newr[j];
				newr[j]=newr[i];
				newr[i]=temp;
			}
		}
	temp=1;
	int result=1;
	 
	for(int i=1;i<newr.size();i++){
		if(newr[i]!=newr[i-1])
			temp+=1;
		result+=temp;
	}
	
	return result;        
}
//  通过 18/8/8 13:17 
 int candy(vector<int> &ratings) {
       int len=ratings.size();
        if(len==1) return 1;
          
        int sum=0;
        vector<int> v(len,1);//初始将每个孩子的糖果数都设为1
          
        //从左向右扫描，保证一个方向上分数更大的糖果更多
        for(int i=1;i<len;i++){
            if(ratings[i] > ratings[i-1])
                v[i]=v[i-1]+1;
        }
        //从右向左扫描，保证另一个方向上分数更大的糖果更多
        for(int i=len-2;i>=0;i--){
            if(ratings[i] > ratings[i+1] && v[i] <= v[i+1])
                v[i]=v[i+1]+1;
        }
          
        for(int i=0;i<len;i++){
            sum+=v[i];
        }
        return sum;
    }
int main(){
	vector<int>r;
	r.push_back(0);
//	r.push_back(2);
	//r.push_back(3);
	cout<<candy(r);
	
}
