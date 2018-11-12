#include<iostream>
using namespace std;
//怎么解决贪婪 匹配的问题   aaa a*a
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
                else if(*(pattern-1)=='*'){  //尝试回退 back=0 未回退过 
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
//正解 

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
