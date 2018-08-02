#include<iostream>
#include<string>
using namespace std;

void reverse(char* s,int len){
	char* q=s+len;
	
	char*p;
	
	while(--q){
		if(*q==' '){
			p=q+1;
			while(*p!='\0' && *p!=' '){
				cout<<*p;
				p++;
			}
			cout<<' ';
		}else if(q==s){
			p=q;
			while(*p!='\0' && *p!=' '){
				cout<<*p;
				p++;
			}
			break;
		}
		
	}
}
int main(){
	
	string str;
	
	getline(cin,str);
	
	char s[str.length()+1];
	
	int length=str.copy(s,str.length());
	
	s[length]='\0';
	
	reverse(s,length);
	
}
