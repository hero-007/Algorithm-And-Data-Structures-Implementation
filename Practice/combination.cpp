// arr - input array
// size - size of array
// x - sum of triplets
#include<bits/stdc++.h>
using namespace std;

void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    sort(arr,arr+size);
    
    for(int i=0;i<(size-2);i++)
    {
        int a1 = arr[i];
        if(a1 > x)
            continue;
        
        for(int j=i+1;j<(size-1);j++)
        {
            int a2 = arr[j];
            if((a1+a2)>x)
                continue;
            
            for(int k=j+1;k<size;k++)
            {
                int a3 = arr[k];
                if((a1+a2+a3) == x)
                    cout<<a1<<" "<<a2<<" "<<a3<<endl;
            }
        }
    }

}



int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int size = 7;
	int x = 12;
	FindTriplet(arr,size,x);
}
