/**
Convex Hull

Given a set of points in the plane. the convex hull of the set is the smallest convex polygon that contains all the points of it.
Find out the convex hull for the given set of points.

Input Format
Integer N(Number Of points)
Array of X coordinates
Array of Y coordinates

Output Format
X coordinate and Y coordinate of all the points seperated by space. Order doesn't matter.

Sample Testcase
Input
7
2 1 6 5 3 7 9
2 5 1 5 7 6 4
Output
1 5
2 2
6 1
9 4
7 6
3 7

**/
#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
        int x,y;
        
        Point()
        {
            x = 0;
            y = 0;
        }
};

bool isChange(Point p,Point q,Point r)
{
    // check if r lies to the left of pq then return true
    int x1 = q.x - p.x;
    int y1 = q.y - p.y;
    int x2 = r.x - p.x;
    int y2 = r.y - p.y;
    
    int cross_p = x1*y2 - x2*y1;
    return (cross_p < 0);
}

void convexHull(Point points[],int n)
{
    vector<Point> Hull;
    
    // find the leftmost element 
    int left = 0;
    for(int i=1;i<n;i++)
    {
        if(points[left].x > points[i].x)
            left = i;
    }
    
    int r = left;
    do{
        Hull.push_back(points[r]);
        int p = (r+1)%n;
        
        for(int i=0;i<n;i++)
        {
            if(isChange(points[r],points[p],points[i]))
            {
                p = i;
            }
        }
        
        r = p;
    }while(r != left);
    
    // print the Hull vector
    for(int i=0;i<Hull.size();i++)
    {
        cout<<Hull[i].x<<" "<<Hull[i].y<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    
    Point p[n];
    
    // insert x coordinate
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x;
    }
    
    // insert y coordinate
    for(int j=0;j<n;j++)
    {
        cin>>p[j].y;
    }
    
    convexHull(p,n);
}
