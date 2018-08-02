#include<stdio.h>
#include <malloc.h>

/*
在GCC编译器上：出现该错误的主要原因是：在C语言里没有C++所谓的“按引用传递”，例如C++可以写这样一个函数：

void func(int &a)
{
//函数功能
}

在C语言无法这样使用，所以需要改为地址引用：

void func(int *a)
{
//函数功能
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
