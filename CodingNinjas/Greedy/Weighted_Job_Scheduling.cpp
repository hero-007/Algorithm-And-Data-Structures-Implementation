/**
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 

Output
Output one integer, the maximum profit that can be achieved.

Constraints
1 = N = 10^6
1 = ai, di, p = 10^6

Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200

Sample Output
250

**/
#include<bits/stdc++.h>
using namespace std;

struct J{
    int st,ft,profit;
};


bool compare(J j1, J j2)
{
    return j1.ft < j2.ft;
}

int getIndex(vector<J> &job,int s,int e,int i)
{
    int st = s;
    int ed = e;
    int temp = -1;
    
    while(st <= ed)
    {
        int mid = (st+ed)/2;
        if(job[mid].ft == job[i].st)
            return mid;
        
        if(job[mid].ft < job[i].st)
        {
            temp = mid;
            st = mid + 1;
        }
        else
        {
            ed = mid - 1;
        }
    }
    
    return temp;
}

int main()
{
    int n;
    cin>>n;
    
    vector<J> job(n);
    int profit_array[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>job[i].st;
        cin>>job[i].ft;
        cin>>job[i].profit;
    }
    
    sort(job.begin(),job.end(),compare);
    
    profit_array[0] = job[0].profit;
    
    for(int i=1;i<n;i++)
    {
        int include_profit = job[i].profit;
        int exclude_profit = profit_array[i-1];
        
        int sr = getIndex(job,0,i-1,i);
        
        if(sr != -1)
        {
            include_profit += profit_array[sr];
        }
        
        profit_array[i] = max(include_profit,exclude_profit);
    }
    
    cout<<profit_array[n-1]<<endl;
    
    return 0;
}
