#include<iostream>
using namespace std;

void replaceSpace(char *&str,int length) {
        char* newstr=(char* )malloc(sizeof(char)*length);
        
        int j=0;
        for(int i=0;str[i]!='\0';i++){
            if(str[i]!=' '){
                newstr[j++]=str[i];
            }else{
            
                newstr[j++]='%';
                newstr[j++]='2';
                newstr[j++]='0';
            }
        }
        for(int i=0;newstr[i]!='\0';i++)
		cout<<newstr[i];
		cout<<endl; 
		//char* s=str;
		//free(str);
		printf("%p\n",str);
        str=newstr;
        printf("%p\n",str);
        	for(int i=0;str[i]!='\0';i++)
		cout<<str[i]; 
		cout<<endl;
	}

int main(){
	
	char * str="12 2";
	replaceSpace(str,10);
	for(int i=0;str[i]!='\0';i++)
		cout<<str[i]; 
	
} 
