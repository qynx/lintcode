#include<iostream>
using namespace std;

int main(){
	long normal,buffer,hp;
	cin>>hp>>normal>>buffer;
	
	long flag=((buffer-normal)>normal)?1:0;
	long count=0;
	
	long chu;
	long yu;
	if(flag){ //����һ�� 
		chu=hp/buffer;
		yu=hp%buffer;
		
		count+=chu*2;
		if(yu<=normal){ //��һ�� û����� Ӧ���� С�ڵ��� 
			count+=1;
		}else if(yu!=0){
			count+=2;
		}
	}else{  //�������� 
		chu=hp/normal;
		count+=chu;
		yu=hp%normal;
		//�������� 
		if(yu!=0){
			count+=1;
		}
	}
	cout<<count;
	/* ��ʱ  ѡ��ģ���������� 
	while(hp>0){
		//�߽���� һ���ܵ��� 
		if((hp-normal)<0){
			count+=1;
			hp-=normal;
		}else{
			//������幥�� ��������normal 
			if(flag){
				count+=2;
				hp-=buffer;
				
			}
			//���幥����û������normal�� 
			else{
				hp-=normal;
				count+=1;
			}
		}
	} 
	
	cout<<count; */
}
