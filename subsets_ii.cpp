#include"header.h"
using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &S) {
	
	sort(S.begin(),S.end());
	set< vector<int> >s;
	vector<int>temp;
	s.insert(temp);
	for(int j=1;j<=S.size();j++){
		for(int i=0;i+j-1<S.size();i++){
			
			for(int k=0;k<j;k++){
				temp.push_back(S[k+i]);
			}
			s.insert(temp);
			print_Intvector(temp);
			temp.clear();
			
		} 
	}
	
	set< vector<int> >::iterator it=s.begin();
	vector< vector<int> >result;
	for(it;it!=s.end();it++){
		
		result.push_back(*it);
	}
	
	return result;
}

int main(){
	vector<int>s;
	s.push_back(1);
	s.push_back(2);
	subsetsWithDup(s);
	return 0;
}
