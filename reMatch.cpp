#include<iostream>
using namespace std;
//��ô���̰�� ƥ�������   aaa a*a
bool match(char* str, char* pattern)
    {	
     if(*str=='\0'&&*pattern=='\0')
            return true;
     	
     	int back=0;
        char  *next;
        while(*pattern!='\0'){
            next=pattern+1;
            if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
            {	
            	back=0;
                str++;
                if(*next!='*')
                    pattern++;
            }else{
               if(*next=='*')
                  {
					 pattern=next+1; back=0; }
                else if(*(pattern-1)=='*'){  //���Ի��� back=0 δ���˹� 
                 	if(back==0){ 
					str--;
                 	back=1;} 
                 	else
					 return false;        	
				}
                else 
                    return false;
            }
        
        }
        if((*pattern!='\0'&&*next!='*')||*str!='\0')
            return false;
        return true;
    }
    
/*********************************************
//���� 

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        //if the next character in pattern is not '*'
        if (*(pattern+1) != '*')
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str+1, pattern+1);
            else
                return false;
        }
        //if the next character is '*'
        else
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str, pattern+2) || match(str+1, pattern);
            else
                return match(str, pattern+2);
        }
    }
};














**********************************************/
int main(){
	cout<<match("aaa","a*a")<<endl;
}
