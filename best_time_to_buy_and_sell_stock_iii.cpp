/*Say you have an array for which the i th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: 
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

#include<iostream>
#include<vector>
using namespace std;
/* 忘记了最多两次交易 
int maxProfit(vector<int> &prices) {
        if(prices.size()==0)
            return 0;
        if(prices.size()==1)
            return 0;
        int result=0;
	int lastbuy=0;
		int flag=0; //当前是否持股 
	int i;
	//先买第一股 顺序选择 价格比之后低的一天 
	for(i=0;i<prices.size()-1;i++){
		if(prices[i]<prices[i+1]){
		
			lastbuy=prices[i];
			flag=1;
			break;	
		}
	}
	//cout<<lastbuy<<endl;
	if(flag==0)
		return 0;
	//cout<<i<<endl;
	for(int j=i;j<prices.size();j++){
		
		//到最后一天 如果没卖必须处理 
		if(j==prices.size()-1){
			if(flag==1){
				result+=prices[j]-lastbuy;
				flag=0;
			}else{
				break;
			}
		}
		//第二天会跌 直接卖了 
		if(prices[j]>prices[j+1] && flag==1){
			result+=(prices[j]-lastbuy);
			flag=0;
		}
		//第二天会涨 当天没有股 买入 
		if(prices[j]<prices[j+1] && flag==0){
			lastbuy=prices[j];
			flag=1;
		}
		
		
	}
	
	return result;
    }*/
    //一点小疑问 第一次买卖最优 第二次 会随其最优吗 
  /*int maxProfit(vector<int> &prices) {
      int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for(int i = 0; i < prices.size(); i++) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
            cout<<buy1<<"  "<<sell1<<"  "<<buy2<<"  "<<sell2<<endl; 
        }
        return sell2;
    }*/

int maxProfit(vector<int>&prices){
	int buy1=INT_MIN,sell1=0;
	for(int i=0;i<prices.size();i++){
		buy1=max(buy1,-prices[i]);
		sell1=max(sell1,buy1+prices[i]);
	}
	return sell1;
}
int main(){
	
	vector<int>prices;
	
	
	prices.push_back(2);
	prices.push_back(7);
	prices.push_back(-4);
	prices.push_back(9);
	prices.push_back(-10);
	prices.push_back(20);
	cout<<maxProfit(prices)<<endl; 
} 
