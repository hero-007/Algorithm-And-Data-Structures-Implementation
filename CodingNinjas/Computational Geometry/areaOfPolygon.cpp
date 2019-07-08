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

int main()
{
	int n;
	cout<<"Enter the number of points in the polygon : ";
	cin>>n;
	
	Polygon p(n);
	
	cout<<"Enter the coordiantes of the points below : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p.points[i].x;
		cin>>p.points[i].y;
	}
	
	
	double area = Area(p,n);
	cout<<"Area of the polygon : "<<area<<endl;
	return 0;
}
