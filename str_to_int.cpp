 #include<iostream>
 using namespace std; 
 int StrToInt(string str) {
      int flag=0,start=0;
      if(str[0]=='-')
      {flag=1;start=1;}
      else if(str[0]=='+')
      {start=1;}
       
      long result=0;
      
      for(int i=start;i<str.length();i++){
      	 if(str[i]==' ')
		   cout<<' ';
		   //if(str[i]>)
		  else{
		  
		   if(str[i]>=48 && str[i]<=57)
          result=result*10+(str[i]-'0');
          else{
            result=0;
			break;  	
		  }
		  
	    }
      }  
      if(flag)
          result=-result;
       return result;
    }
    
int main(){

	cout<<StrToInt("    1a33");

}
