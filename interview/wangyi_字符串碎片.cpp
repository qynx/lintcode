/*
一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。例如,"aaabbaaac"是由下面碎片组成的:'aaa','bb','c'。牛牛现在给定一个字符串,请你帮助计算这个字符串的所有碎片的平均长度是多少。

输入描述:
输入包括一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),s只含小写字母('a'-'z')


输出描述:
输出一个整数,表示所有碎片的平均长度,四舍五入保留两位小数。

如样例所示: s = "aaabbaaac"
所有碎片的平均长度 = (3 + 2 + 3 + 1) / 4 = 2.25

输入例子1:
aaabbaaac

输出例子1:
2.25
*/

#include<iostream>
#include<vector> 
#include<iomanip>
using namespace std;

int main(){
	string s;
	cin>>s;
	
	int i=0;  
	int len=s.length();
	int temp; //当前碎片长度 
	vector<int>result;
	//count=1;
	temp=1;
	while(i<(len-1)){
		if(s[i]==s[i+1])
		{
			temp+=1;
		}else{
			result.push_back(temp);
			temp=1; 
		}
		i++;
	}
	
	//移到倒数第一个元素时是特殊情况会被while循环终止 
	if(s[len-1]==s[len-2])
		result.push_back(temp);
	else
		result.push_back(1);
	
	int sum=0;
	for(int i=0;i<result.size();i++){
		sum+=result[i]; 
	} 
	cout<<fixed<<setprecision(2)<<(float)sum/result.size();
} 
