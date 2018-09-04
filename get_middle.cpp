#include<iostream>
// ��ȡ������ ��λ��
/*���ӣ�https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1
��Դ��ţ����

��εõ�һ���������е���λ����
������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����
*/ 
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> stream;
    
    void Insert(int num)
    {
        if(stream.size()==0){
		
            stream.push_back(num);
            return;}
        vector<int>::iterator ends=stream.end();
        for(;ends!=stream.begin();ends--){
            if(num>*(ends-1)){
                stream.insert(ends,num);
                return;
            }
        }
        stream.insert(ends,num);
        return;
    }

    double GetMedian()
    { 
      if(stream.size()%2!=0)
          return stream[stream.size()/2];
      else
          return (double)(stream[stream.size()/2-1]+stream[stream.size()/2])/2;
    }

};

int main(){
	Solution s=Solution();
	int n;
	while(cin>>n){
		s.Insert(n);
		cout<<s.GetMedian()<<endl;
	}
} 
