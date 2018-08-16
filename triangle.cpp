 /*
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is11(i.e., 2 + 3 + 5 + 1 = 11).

Note: 
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


*/
#include<iostream>
#include<vector>
using namespace std; 
//不能选左下方的 
int mini(vector<vector<int> > &triangle,int row,int pos);
 int minimumTotal(vector<vector<int> > &triangle) {
        //递归 求每一层的下面所有层的最小值
        return mini(triangle,0,0);
    }
    
    //pos为上一行元素的位置 限制当前行能选择的元素
int mini(vector<vector<int> > &triangle,int row,int pos){
        int minr,minleft,minright;
       
        //最后一行时不需要递归
        if(row==(triangle.size()-1)){
           minr=triangle[row][pos];
           // if(pos>0)
        //  minr=min(triangle[row][pos-1],minr);
            if(pos<(triangle.size()-1))
           minr=min(minr,triangle[row][pos+1]);
            
          return minr;
        }
        
        //正下方
       minr=triangle[row][pos]+mini(triangle,row+1,pos);
       /* if(pos>0)//左下方
        {
            minleft=triangle[row][pos-1]+mini(triangle,row+1,pos-1);
            minr=minr<minleft?minr:minleft;}*/
        //右下方
        if(pos<(triangle[row].size()-1)){
         minright=triangle[row][pos+1]+mini(triangle,row+1,pos+1);
        minr=minr<minright?minr:minright;}
        
        return minr;
    }
int main(){
	vector<vector<int> >p;
	vector<int>a;
	a.push_back(1);
	vector<int>b;
	b.push_back(2);
	b.push_back(3);
	p.push_back(a);
	p.push_back(b);
	cout<<minimumTotal(p);
	return 0;
}
