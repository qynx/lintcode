#include<iostream>
#include<string>
#include<vector>
#include<cstdlib> 
using namespace std;

// 最短字符串编码 后长度

/*

例如'abcdefabcdefabc'可表示为'2[abcdef]abc', 但是'aaa'仅能编码成'aaa', 
因为len('3[a]')>len('aaa').

1. k为正整数, []内的encoding_string不得含有空格不得为空;
2. []内的encoding_string 本身可以为编码过的字符串, 例如'abcdabcdeabcdabcde' 可以编码为 '2[abcdabcde]'(编码后长度从18减少到12), []内的'abcdabcde'又可以编码为 '2[abcd]e', 最终编码为 '2[2[abcd]e]', 编码后长度为11, 应返回11; 这个编码路径也能是: 'abcdabcdeabcdabcde' -> '2[abcd]e2[abcd]e' -> '2[2[abcd]e]';
2. 输入字符串为全小写英文字母, 长度<=160;
3. 如果编码后长度没有更小, 则保留原有字符串;


例子说明2:
5[a]，长度4

输入例子3:
aabcaabcd

输出例子3:
8

例子说明3:
2[aabc]d，长度8
*/ 

string temp;
string ll(string s){
	int len=s.length();	
	//dp[i][j]  从i到j的字符串编码后的格式 
	vector< vector<string> >dp(len,vector<string>(len,""));
	
	int step;
	
	for(step=1;step<=len;step++){
		for(int i=0;i+step-1<len;i++){
			
			temp=s.substr(i,step);
			dp[i][i+step-1]=temp;
			
			//检查压缩后子串的长度和是否可以小于temp长度 
			for(int j=1;j<step;j++){
				
				if((dp[i][i+j-1].length()+dp[i+j][i+step-1].length())<dp[i][i+step-1].length()){
					dp[i][i+step-1]=dp[i][i+j-1]+dp[i+j][i+step-1];
				}
				
			}
			
			//检查temp是否可以压缩
			string hebing=temp+temp;
			
			//如果 找出去了 内部没有重复的串(整体无法压缩 小部分的压缩 通过动态规划 之前已经计算过） 找不出去 的话  有重复的串
			int pos=hebing.find(temp,1); 
			if(pos<temp.length()){
				//计算压缩后的长度  这里必须要做区分  一种是含有两个压缩 [ 这个要去掉 
 				 //如何区分 压缩编码重复与 原来的重复   2[a2c]2[a2c]
				int count=temp.length()/pos;  //有子串 重复 count次
				char *tt;
				sprintf(tt,"%d",count);
				string ttt=string(tt);
		//	string result= ttt+'['+temp.substr(0,pos)+']';
			//cout<<result<<endl;
				//这个地方不能用temp
				//abcdabcdeabcdabcde
				//如这种情况
				//取得重复的字符串可能是已经压缩过的  比如 aaaaaaccccc  可能aaaaa已经为5[a]
				string result=ttt+'['+dp[i][i+pos-1]+']'; 
				if(result.length()<dp[i][i+step-1].length())
					dp[i][i+step-1]=result;
				
			}
			
		}
	}
	
	return dp[0][len-1];
}
int main(){
	string ss;
    cin>>ss;
    string result=ll(ss);
    cout<<result.length();
	return 0;
}
/* 
int main(){
	
	string s;
	cin>>s;
	
	int flag=1;
	int len=s.length();
	
	string temp;  //重复的字符串 
	string cmp;
	int rl=0;  // 重复字符串 长度 
	int rc=0; // 重复次数 
	while(flag){
		
		for(int i=0;i<len;i++){
			temp+=s[i];
			for(int j=i+1;j<len;j++){
				if(s[j]==temp[0]){ //第一个字符重合 
										
					 for(int k=0;k<temp.length()&&(j+k)<len;k++){
						cmp+=s[j+k];
					 }
					  if(cmp==temp){
					  	rc+=1;
					  	rl=temp.length();
					  	cmp="";
					  	
					  	
					  	//检查是否能缩小长度
					  	string extra=to_string(rc);
					  	if(rc*rl>())
						   
					  }else{
					  	cmp="";
					  	//break;
					  }//向后检查 
				    
				}//第一个字符重合 
			}
		} 
		
	} 
	
}*/
