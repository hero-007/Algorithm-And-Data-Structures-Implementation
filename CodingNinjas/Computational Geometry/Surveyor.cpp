/**
Surveyor

A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.

Input Format
String s
Array of length of string

Output Format
Area

Constraints
direction will have between 4 and 50 characters inclusive.
length will have the same number of elements as the number of characters in direction.
Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
Each element of length will be between 1 and 1000 inclusive.
The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).

Sample Test Case
"NWWSE"
10 3 7 10 10
Returns: 100


"NESWNWSW"
{20,200,30,100,20,30,10,70}
Returns: 4700
Download Test Cases

**/
#include<bits/stdc++.h>
using namespace std;
class Point{
	public:
		double x,y;
};

class Polygon{
	public:
		Point *points;
		
		Polygon(int npoints)
		{
			points = new Point[npoints];
		}
		
		void printPoints(int npoints)
		{
			for(int i=0;i<npoints;i++)
			{
				cout<<points[i].x<<" "<<points[i].y<<endl;
			}
		}
};


double Area(Polygon p,int npoints)
{
	double farea = 0;
	for(int i=1;i<npoints-1;i++)
	{
		double x1 = p.points[i].x - p.points[0].x;
		double y1 = p.points[i].y - p.points[0].y;
		
		double x2 = p.points[i+1].x - p.points[0].x;
		double y2 = p.points[i+1].y - p.points[0].y;
		
		double cross_p = (x1*y2) - (x2*y1);
		farea += cross_p;
	}
	
	return abs(farea/2);
}


int main() {
    string st;
    cin>>st;
    int l = st.length();
    int *arr = new int[l];
    for(int i=0;i<l;i++){
        cin>>arr[i];
    }
    
    int x1=0,y1=0;
    int ul = 0;
    
    Polygon p(l);
    p.points[0].x = 0;
    p.points[0].y = 0;
    
    for(int i=1;i<l;i++)
    {
        char ch = st[i-1];
        int a = arr[i-1];
        
        if(ch == 'N')
        {
            y1 = y1 + a;
        }
        else if(ch == 'E')
        {
            x1 = x1+a;
        }
        else if(ch == 'S')
        {
            y1 = y1-a;
        }
        else
        {
            x1 = x1-a;
        }
        
        p.points[i].y = y1;
        p.points[i].x = x1;
    }
    
    double res = Area(p,l);
    cout<<res<<endl;
    return 0;
}
