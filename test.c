#include<stdio.h>
#include <malloc.h>

/*
��GCC�������ϣ����ָô������Ҫԭ���ǣ���C������û��C++��ν�ġ������ô��ݡ�������C++����д����һ��������

void func(int &a)
{
//��������
}

��C�����޷�����ʹ�ã�������Ҫ��Ϊ��ַ���ã�

void func(int *a)
{
//��������
}
*/
int * l(){
	
	int *p=malloc(sizeof(int)*1);
	*p=1;
	return p;
}



int lll(){
	
	return 1;
}

int main(){
	int *a;
	a=l();
	printf("%p\n",a);
	free(a);
	//int b=ll();
//	printf("%d\n",b);
} 
