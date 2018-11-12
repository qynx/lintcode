#include<iostream>
using namespace std;
int i=1;
class MyCls{
public:
    MyCls():m_nFor(m_nThd),m_nSec(i++),m_nFir(i++),m_nThd(i++){
    	cout<<i<<endl;
    	cout<<m_nFor<<endl;
        m_nThd=i;
        cout<<m_nThd<<endl; 
    }
    void echo(){
    	m_nThd=1000;
        cout<<"result:"<<m_nFir<<m_nSec<<m_nThd<<m_nFor<<endl;
    }
private:
    int m_nFir;
    int m_nSec;
    int m_nThd;
    int &m_nFor;
};
int main()
{
   int *ip=new int(12);

for(int i=0;i<12;++i){

ip[i]=i;

}

delete []ip;
    
}



