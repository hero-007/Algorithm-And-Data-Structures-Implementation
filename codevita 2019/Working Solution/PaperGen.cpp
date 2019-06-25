#include<bits/stdc++.h>
using namespace std;

int fact(int n);

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}


int main()
{

    int x,a,y,b,z,c;


    cin>>x>>a>>y>>b>>z>>c;
    char p1,p2,include;
    cin>>p1>>p2>>include;


    int sNeed=a,mNeed=b,hNeed=c;
    int sTotal=x,mTotal=y,hTotal=z,flag=0;
    int t=a+b+c,ind=0;
    int arr[t]{0};

    arr[p1-'A']=1;
    arr[p2-'A']=1;

    ind=include-'A';

    for(int i=0;i<t;i++)
    {
        if(arr[i]==1 && i<x)
        {
            sNeed-=1;
            sTotal-=1;

        }
        if(arr[i]==1 && (i>=x && i<x+y) )
        {
            mNeed-=1;
            mTotal-=1;

        }
        if(arr[i]==1 && (i>=x+y && i<x+y+z) )
        {
            hNeed-=1;
            hTotal-=1;

        }

    }
     if(ind<x) {sTotal-=1; flag=1; }
     else if(ind>=x && ind<x+y){ mTotal-=1;flag=2;}
     else if(ind>=x+y && ind<x+y+z){ hTotal-=1; flag=3;}

    //cout<<sTotal<<" "<<mTotal<<" "<<hTotal<<" ";

     int p1p2Together=nCr(sTotal,sNeed) * nCr(mTotal,mNeed) * nCr(hTotal,hNeed);
     cout<<p1p2Together;


     sTotal=x;
     mTotal=y;
     hTotal=z;
     sNeed=a;
     mNeed=b;
     hNeed=c;

     if(ind<x) {sTotal-=1;sNeed-=1; flag=1; }
     else if(ind>=x && ind<x+y){ mTotal-=1;mNeed-=1;flag=2;}
     else if(ind>=x+y && ind<x+y+z){ hTotal-=1;hNeed-=1; flag=3;}

     int includeTogether=nCr(sTotal,sNeed) * nCr(mTotal,mNeed) * nCr(hTotal,hNeed);

     int totalC=nCr(x,a) * nCr(y,b) * nCr(z,c);

	//cout<<includeTogether;
   cout<<totalC-(p1p2Together+includeTogether-1);







    return 0;
}
