#include <bits/stdc++.h>
using namespace std;
int calculateValue(int big,int small)
{   
   int final = (big*11) + (small*7) ;
   int second = 0;
   if(final > 99)
   {
       second = final/10;
       final = (second%10) * 10 ;
       final += (final%10);
   }   
   return final;
}
bool checkIndex(int i,int j)
{
    if((i%2==0 && j%2==0) || (i%2!=0 && j%2!=0) )
        return true;
     return false;
}
void countFrequency(vector<int> store, int n,unordered_map<int , int> &count)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((store[i] != -9999) && (i!=j))
            {
                int valuei = store[i]/10;
                int valuej = store[j]/10; 
                if( (valuei == valuej) &&  checkIndex(i,j))
                {
                    if(count.find(valuei) != count.end())
                    {
                        count[valuei]++;
                    }
                    else
                    {
                        count[valuej] = 2;
                    }
                    
                    store[j] = -9999;
                }
            }
        }
    }
}
int main() {
	// your code goes here
	int n;
	
	cin>>n;
	
	int a[n];
	std::vector<int> store;
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];

        // calculating large and small
        int rem;
        int smallerValue=999;
        int largeValue=0;
        int num = a[i];
        while (num > 0) {
        rem = num % 10;
        if (smallerValue > rem) {
            smallerValue = rem;
        }
        if (largeValue < rem) {
            largeValue = rem;
        }
        num = num / 10;
        }
        //cout<<largeValue<<" "<<smallerValue<<endl;
	    store.push_back(calculateValue(largeValue,smallerValue));
	}
	
	unordered_map<int , int> count;
	countFrequency(store,n,count);

    int finalCount=0;

    unordered_map<int , int>::iterator it;    
	for(it=count.begin();it!=count.end();it++)
	{
      int temp = it->second;
      
	   if(temp > 2)
	        finalCount = finalCount + 2;
	   else if(temp ==2)
	        finalCount++;
	}
    cout<<finalCount;
    return 0;
}
