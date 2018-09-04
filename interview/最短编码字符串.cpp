#include<iostream>
#include<string>
#include<vector>
#include<cstdlib> 
using namespace std;

// ����ַ������� �󳤶�

/*

����'abcdefabcdefabc'�ɱ�ʾΪ'2[abcdef]abc', ����'aaa'���ܱ����'aaa', 
��Ϊlen('3[a]')>len('aaa').

1. kΪ������, []�ڵ�encoding_string���ú��пո񲻵�Ϊ��;
2. []�ڵ�encoding_string �������Ϊ��������ַ���, ����'abcdabcdeabcdabcde' ���Ա���Ϊ '2[abcdabcde]'(����󳤶ȴ�18���ٵ�12), []�ڵ�'abcdabcde'�ֿ��Ա���Ϊ '2[abcd]e', ���ձ���Ϊ '2[2[abcd]e]', ����󳤶�Ϊ11, Ӧ����11; �������·��Ҳ����: 'abcdabcdeabcdabcde' -> '2[abcd]e2[abcd]e' -> '2[2[abcd]e]';
2. �����ַ���ΪȫСдӢ����ĸ, ����<=160;
3. �������󳤶�û�и�С, ����ԭ���ַ���;


����˵��2:
5[a]������4

��������3:
aabcaabcd

�������3:
8

����˵��3:
2[aabc]d������8
*/ 

string temp;
string ll(string s){
	int len=s.length();	
	//dp[i][j]  ��i��j���ַ��������ĸ�ʽ 
	vector< vector<string> >dp(len,vector<string>(len,""));
	
	int step;
	
	for(step=1;step<=len;step++){
		for(int i=0;i+step-1<len;i++){
			
			temp=s.substr(i,step);
			dp[i][i+step-1]=temp;
			
			//���ѹ�����Ӵ��ĳ��Ⱥ��Ƿ����С��temp���� 
			for(int j=1;j<step;j++){
				
				if((dp[i][i+j-1].length()+dp[i+j][i+step-1].length())<dp[i][i+step-1].length()){
					dp[i][i+step-1]=dp[i][i+j-1]+dp[i+j][i+step-1];
				}
				
			}
			
			//���temp�Ƿ����ѹ��
			string hebing=temp+temp;
			
			//��� �ҳ�ȥ�� �ڲ�û���ظ��Ĵ�(�����޷�ѹ�� С���ֵ�ѹ�� ͨ����̬�滮 ֮ǰ�Ѿ�������� �Ҳ���ȥ �Ļ�  ���ظ��Ĵ�
			int pos=hebing.find(temp,1); 
			if(pos<temp.length()){
				//����ѹ����ĳ���  �������Ҫ������  һ���Ǻ�������ѹ�� [ ���Ҫȥ�� 
 				 //������� ѹ�������ظ��� ԭ�����ظ�   2[a2c]2[a2c]
				int count=temp.length()/pos;  //���Ӵ� �ظ� count��
				char *tt;
				sprintf(tt,"%d",count);
				string ttt=string(tt);
		//	string result= ttt+'['+temp.substr(0,pos)+']';
			//cout<<result<<endl;
				//����ط�������temp
				//abcdabcdeabcdabcde
				//���������
				//ȡ���ظ����ַ����������Ѿ�ѹ������  ���� aaaaaaccccc  ����aaaaa�Ѿ�Ϊ5[a]
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
	
	string temp;  //�ظ����ַ��� 
	string cmp;
	int rl=0;  // �ظ��ַ��� ���� 
	int rc=0; // �ظ����� 
	while(flag){
		
		for(int i=0;i<len;i++){
			temp+=s[i];
			for(int j=i+1;j<len;j++){
				if(s[j]==temp[0]){ //��һ���ַ��غ� 
										
					 for(int k=0;k<temp.length()&&(j+k)<len;k++){
						cmp+=s[j+k];
					 }
					  if(cmp==temp){
					  	rc+=1;
					  	rl=temp.length();
					  	cmp="";
					  	
					  	
					  	//����Ƿ�����С����
					  	string extra=to_string(rc);
					  	if(rc*rl>())
						   
					  }else{
					  	cmp="";
					  	//break;
					  }//����� 
				    
				}//��һ���ַ��غ� 
			}
		} 
		
	} 
	
}*/
