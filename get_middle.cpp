#include<iostream>
// 获取数据流 中位数
/*链接：https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1
来源：牛客网

如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
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
