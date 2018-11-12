#include <iostream>
#include<vector>
using namespace std;

void reverse(string ss){
    char *s=(char *)ss.data();
    int len=ss.length();
    char* p=s;
    char* q=s+len-1;
  
    char temp;
    while(p!=q){
      temp=*q;
      *q=*p;
       *p=temp;
        p++;
        q--;
    }
    
    p=s;
    q=s;
    while(*q!='\0'){
        
        if(*q=='.'){
           char*t=q-1;
           
            while(p<t){
                temp=*t;
                *t=*p;
                *p=temp;
                p++;
                t--;
            }//½»»»
            
            q++;
            p=q;
        }
        else
        q++;
        
    }
}

int main() {
    // cout<<"11";
    string s="www.toutiao.com";
    //cout<<"11";
    //cout<<s;
    reverse(s);
    cout<<s;
}
