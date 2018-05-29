#include<iostream>
#include<vector> 
using namespace  std;

struct Point{
	int x;
	int y;
	Point() :x(0),y(0){}
	Point(int a,int b):x(a),y(b){}
	
};

void printp(Point p){
	cout<<"("<<p.x<<","<<p.y<<")"<<endl;
}
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
        		
        		
				int temp=2;
        		        		
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
				
        		for(int t=j+1;t<l;t++){
        		
					if(temp>12){
        				cout<<"Point 1:	";
        				printp(points[i]);
        				cout<<"Point 2:	";
        				printp(points[j]);
        				cout<<"Point 3:	";
        				printp(points[t]);
					}
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


	points.push_back(Point(0,9));
points.push_back(Point(138,429));
points.push_back(Point(115,359));
points.push_back(Point(115,359));
points.push_back(Point(-30,-102));
points.push_back(Point(230,709));
points.push_back(Point(-150,-686));
points.push_back(Point(-135,-613));
points.push_back(Point(-60,-248));
points.push_back(Point(-161,-481));
points.push_back(Point(207,639));
points.push_back(Point(23,79));
points.push_back(Point(-230,-691));
points.push_back(Point(-115,-341));
points.push_back(Point(92,289));
points.push_back(Point(60,336));
points.push_back(Point(-105,-467));
points.push_back(Point(135,701));
points.push_back(Point(-90,-394));
points.push_back(Point(-184,-551));
points.push_back(Point(150,774));

	
	Solution s=Solution();
	cout<<s.maxPoints(points);
	return 0;
}
