#include<iostream>
#include<vector>
using namespace  std;
/*
There are N gas stations along a circular route, where the amount of gas at station i isgas[i].

You have a car with an unlimited gas tank and it costscost[i]of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note: 
The solution is guaranteed to be unique.


*/
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int len=gas.size();
        int leftgas=0;
        
        for(int i=0;i<len;i++){
            leftgas=0;
            for(int j=i;(j%len)!=i||j<len;j++){
                leftgas+=(gas[j%len]-cost[j%len]);
                cout<<"Ñ­»·"; 
                if(leftgas<0)
                    break;                
            }
            if(leftgas>=0)
                return i;
        }
        return -1;
    }
int main(){
	
	vector<int>gas;
	vector<int>cost;
	
	gas.push_back(4);
	cost.push_back(5);
	
	cout<<canCompleteCircuit(gas,cost);
}
