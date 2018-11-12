#include "header.h"

int *x(int a){
	
	int *p=(int *)malloc(sizeof(int));
	printf("p, %p\n",&p);
	*p=a;
	return p;
}

int main(){
	int *o;
	printf("o, %p\n",&o);
	int *xx=x(1);
	
	int *yy=x(2);
	int a[10000]={0};
	printf("a, %p\n",&a);
	int *b=a+1;
	printf("%p\n",&xx);
	printf("%p\n",&yy);
	cout<<xx<<endl;
	cout<<yy<<endl;
	cout<<*xx;
}
