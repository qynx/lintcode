#include<iostream>
#include<cstdlib> 
using namespace std;

#define pageSize 3
int *pages=(int *)malloc(pageSize*sizeof(int)); 

//��ѯ���ƶ� index 0 λ������ȼ� 
//ʹ��λ�ñ�ʾ���ʹ�õ�ʱ�� 
int query(int *a,int page){
	for(int i=0;i<pageSize;i++){
			
		//���� 
		if(a[i]==page){
			//return i;
			
			//�Ƶ���ǰ�� ֮���λ��Ԫ�ز��� 
			 for(int j=i;j>=1;j--){
			 	a[j]=a[j-1];
			 }
			 a[0]=page;
			 return 0;
		}
	}
	
	//û������,���û�����ݣ�ֱ�Ӵ��0��λ 
	if(a[0]==-1)
		{
		a[0]=page; 
		return -1;
	}
	//��������� �����һ��Ԫ���߳�����
	for(int i=pageSize-1;i>=1;i--){
		a[i]=a[i-1];
	} 
	a[0]=page;
	
	return -1;
}

//��ӡ��ǰ��� 
void print(int *a){
	for(int i=0;i<pageSize;i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
}
int main(){
	cout<<"��ʼģ��"<<endl;
	
	int page;
	int curr=0;
	for(int i=0;i<pageSize;i++){
		pages[i]=-1;
	}
	
	int missing=0; 
	int count=0;
	while(true){
		cout<<"����ҳ  ";
		cin>>page;
		if(page==-1){
			cout<<"����ѯ "<<count<<" ��  δ����"<<missing<<" ��"<<endl; 
			free(pages);
			return 0;
		}
		int result=query(pages,page);
		if(result==-1)
			missing++;
		count++;
		print(pages);
		
	}	
} 
