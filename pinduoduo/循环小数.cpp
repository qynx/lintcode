#include<iostream>
#include<cstdlib>
using namespace std;

int *array=(int *)malloc(1000*sizeof(int));
int *right=(int *)malloc(1000*sizeof(int));
int len=1000;
//
int getarray(int a,int b){
	for(int i=0;i<len;i++){
		a*=10;
		array[i]=a/b;
		a%=b;
	}
} 

//

//�ж��Ƿ��ܳ���  �Ƿ���Ϊ�� 
bool test(int num) {
        while (num % 2 == 0)
            num /= 2;
 
        while (num % 5 == 0)
            num /= 5;
 
        return (num == 1 || num == -1);
}

//�ж�С��λ��
int bits(float a){
	 a = a -(int)a;
	 int i;
    for(i=0;i<10;i++){
        a *=10;
        if(a-(int)a==0){
            //cout<<i+1<<endl;  //i+1����С��λ��
            break;
        }
    }
    return i+1;
} 


int main(){
	int a,b;
	cin>>a>>b;
	//cout<<bits(2.25);
	
	//�������� 
	if(test(b)){
		cout<<bits((float)a/b)<<" "<<0; 
	}else{
		cout<<1<<endl;
	}
	
	free(array);
//	free(right);
	
} 
