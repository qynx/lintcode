#include<iostream>
#include<vector> 
using namespace  std;

struct Point{
	int x;
	int y;
	Point() :x(0),y(0){}
	Point(int a,int b):x(a),y(b){}
	
};
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
        
		if(l==1)
        return 1;
        
        int max=0;
        
        for(int i=0;i<l-1;i++){
        	
        	for(int j=i+1;j<l;j++){
        		int temp=2;
        		float k=((float)points[i].y-(float)points[j].y)/(points[i].x-points[j].x);
        		
        		for(int t=j+1;t<l;t++){
        			cout<<points[i].x-points[t].x<<endl;
        			float kn=((float)points[i].y-(float)points[t].y)/(points[i].x-points[t].x);
        			//cout<<kn<<endl;
        		//	float k1=((float)points[t].y-(float)points[i].y)*(points[j].x-points[i].x);
        		//	int k2=((float)points[j].y-(float)points[i].y)*(points[t].x-points[i].x);
        			if(k==kn){
						//cout<<kn<<endl;
        				temp+=1;}
				}
				
				max=max>temp?max:temp;
			}
		}
		
		return max;
    }
};

int main(){
	vector<Point> points;
	points.push_back(Point(0,0));
	points.push_back(Point(1,1));
	
	points.push_back(Point(0,0));
//	points.push_back(Point(1,5));
//	cout<<(float)1/0<<endl;
	Solution s=Solution();
	cout<<s.maxPoints(points);
	return 0;
}
