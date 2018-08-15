/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start ="hit"
end ="cog"
dict =["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:

All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include<iostream>
#include<vector>
#include<unordered_set>
 // unordered_Set : find count insert erase empty size
using namespace std;
//从end 开始 因为一次只能变换一个字母 
void dfs(string&start,string end,vector< vector<string> >&result,vector<string>&temp);
 vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        vector<string> temp;
        vector< vector<string> >result;
        dfs(start,end,result,temp);
} 

void dfs(string &start,string end,vector< vector<string> >&result,vector<string>&temp){
	
	
}
int main(){
	unordered_set<string>dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("a");
	//cout<<dict.count();
	
	return 0;
}
