#include<iostream>
#include<vector>
using namespace std;

#include<stdio.h>
class A
{
    public:
      virtual void f(){}
    public :
       A()
       {
           f();
        }
};
class B1:public A
{
    private:
        char *_s;
    public:
        B1()
        {
            _s=new char[1024];
        }
    private:
        void f()
        {
            delete _s;
            _s=NULL;
        }
};
class B2:public A
{
    private:
    int * _m;
    public:
        B2()
        {
            _m=new int(2016);
        }
    private:
        virtual void f()
        {
            delete _m;
            _m=NULL;
        }
};
class cTest{
	virtual void v(){
	}
};
int main()
{	
/*cout<<sizeof(cTest)<<endl;
    A*a1=new B1();
    A*a2=new B2();
    delete a1;
    delete a2;*/ 
    vector<int>a;
    a.push_back(1);
    a.push_back(3);
    a.erase(1);
    return 0;
}
