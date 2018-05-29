#include<iostream>
#include<vector> 
using namespace  std;

struct Point{
	int x;
	int y;
	Point() :x(0),y(0){}
	Point(int a,int b):x(a),y(b){}
	
};

/*void printp(Point p){
	cout<<"("<<p.x<<","<<p.y<<")"<<endl;
}*/
/**
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line. 
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        
        int l=points.size();
       // cout<<l<<endl;
		if(l==1)
        	return 1;
        
        int max=0;
        
        bool flag=false;  //标记点是否一样
		int repeatcount=0; //标记重复点的个数
		 
        for(int i=0;i<l-1;i++){
        
        	
        	for(int j=i+1;j<l;j++){
        	//	cout<<i<<"	"<<j<<"	"<<l<<endl;      		
				int temp=2;
        		flag=false;       		
				if((points[j].y==points[i].y) &&(points[j].x==points[i].x)){
        			//因为公式是基于 i，j点计算的，所以只需要计算这两个点是否重复既可以 
					//repeatcount+=1;
					flag=true;
					temp=1;
				//	temp=1;
				//	max=max>temp?max:temp; 
					repeatcount+=1;
				
					temp+=repeatcount;        	
				}
        		
        		//int k=((float)points[i].y-(float)points[j].y)/(points[i].x-points[j].x);
        		if(!flag){
				//cout<<"Jinaliale";
			
        		for(int t=j+1;t<l;t++){
        		
        		//	cout<<points[i].x-points[t].x<<endl;
        		//	int kn=((float)points[i].y-(float)points[t].y)/(points[i].x-points[t].x);
        			float k1=((float)points[t].y-(float)points[i].y)*(points[j].x-points[i].x);
        			float k2=((float)points[j].y-(float)points[i].y)*(points[t].x-points[i].x);
        			if(k1==k2){
						//cout<<kn<<endl;
        				temp+=1;}
				}
				//cout<<max<<endl;
				temp+=repeatcount;
				cout<<repeatcount;
				}
				
		
				max=max>temp?max:temp;
			//	cout<<"max  "<<max<<endl;
			}
			

			flag=false;
			repeatcount=0;
		}
		
		return max;
    }
};

int main(){
	vector<Point> points;


	points.push_back(Point(1,1));
	points.push_back(Point(1,1));
	points.push_back(Point(2,3));

	
	Solution s=Solution();
	cout<<s.maxPoints(points);
	return 0;
}
