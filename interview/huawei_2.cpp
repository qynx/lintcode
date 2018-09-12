#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
	
	string s;
	cin>>s;
	
	getline(cin,s);
	cout<<s<<" s"<<endl;
	int l=s.length();
	char*p=(char* )malloc((l+1)*sizeof(char));
	int i=0;
	while(l--){
		cout<<s[l-1]<<endl;
		*(p+i)=s[l-1];
		i++;	
	} //·´×ª×Ö·û´® 
	
	*(p+i)='\0';
	cout<<p[0]<<endl;
	char*q=q+i;
	i=0; 
	char*temp; 
	while(--q){
		if(q>p){
			if(*q==' '){
				for(temp=q;*temp!=' '&&*temp!='\0';temp++)
					{
						s[i++]=*temp;
					}
					s[i++]=' ';	
			}
		}else if(q==p){
				for(temp=q;*temp!=' '&&*temp!='\0';temp++)
					{
						s[i++]=*temp;
					}
					s[i++]='\0';	
		}else
		 break;
	}
	
	cout<<s;
	
	
}
