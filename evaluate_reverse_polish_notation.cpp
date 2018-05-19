#include<iostream> 
#include<vector>
#include<stack>
#include<cstdlib>
#include<string>
using namespace std;
/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are+,-,*,/. Each operand may be an integer or another expression.

Some examples

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/


class Solution{
	public:
		int evalRPN(vector<string> &tokens) {
        	stack<int>ss;
        	string op="+-*/";
        	int isop;
			for(int i=0;i<tokens.size();i++){
        		cout<<tokens[i]<<endl;
				isop=op.find(tokens[i]);
        		int result;
                
        		if(isop==-1)
        			ss.push(atoi(tokens[i].c_str()));
        		
        		else{
        			string temp_op=tokens[i];
        			
					int number_right=ss.top();
                    ss.pop();
                    int number_left=ss.top();
                    ss.pop();
                    
					switch(isop){
						
						case 0:
							result=number_left+number_right;
							break;
							
						case 1:
							result=number_left-number_right;
							break;
						
						case 2:	
							result=number_left*number_right;
							break;
						
						case 3:
							result=number_left/number_right;
							break;
						
						default:
							result=-1;
							break;
					
					}
					
					ss.push(result);
										        			
				}				
        		
			}
			
			int final_result=ss.top();
			
       		return final_result;
    }
};


int main(){
	
	Solution s=Solution();
	
	vector<string>token;
	
	string test1[]={"2", "1", "+", "3", "*"};
	string test2[]={"4", "13", "5", "/", "+"};
	
//	cout<<sizeof(test1)<<endl;
	for(int i=0;i<5;i++){
			
		token.push_back(test1[i]);
	//	cout<<test1[i]<<endl;
	}
	
	int result;
		cout<<"ca"<<endl;
	result=s.evalRPN(token);
		cout<<"ca"<<endl;
	cout<<result<<endl;
	
	return 0;
} 
