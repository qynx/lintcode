#include<iostream>
using namespace std;

int main(){
	long normal,buffer,hp;
	cin>>hp>>normal>>buffer;
	
	long flag=((buffer-normal)>normal)?1:0;
	long count=0;
	
	long chu;
	long yu;
	if(flag){ //蓄力一次 
		chu=hp/buffer;
		yu=hp%buffer;
		
		count+=chu*2;
		if(yu<=normal){ //第一次 没搞清楚 应该是 小于等于 
			count+=1;
		}else if(yu!=0){
			count+=2;
		}
	}else{  //并不蓄力 
		chu=hp/normal;
		count+=chu;
		yu=hp%normal;
		//不能整除 
		if(yu!=0){
			count+=1;
		}
	}
	cout<<count;
	/* 超时  选择不模拟整个过程 
	while(hp>0){
		//边界情况 一次能掉完 
		if((hp-normal)<0){
			count+=1;
			hp-=normal;
		}else{
			//如果缓冲攻击 高于两次normal 
			if(flag){
				count+=2;
				hp-=buffer;
				
			}
			//缓冲攻击并没有两次normal高 
			else{
				hp-=normal;
				count+=1;
			}
		}
	} 
	
	cout<<count; */
}
