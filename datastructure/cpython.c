#include<Python.h>
#include<structmember.h>

typedef struct{
	PyObject_HEAD
	PyObject* name;
	PyObject* value;
	
}record_object;

int main(){
	
	printf("%d",offsetof(record_object,name));
	printf("%d",offsetof(record_object,value));
}
