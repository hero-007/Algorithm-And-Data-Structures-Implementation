#include<bits/stdc++.h>

using namespace std;

void longFactorials(int n) {
    int *arr = new int[201];
    for(int i=0;i<=200;i++)
        arr[i] = 0;

    if(n == 0)
    {
        cout<<0<<endl;
        return;
    }
    else
    {
        arr[200] = 1;
        for(int j=2;j<=n;j++)
        {
            int num = j;
            int carry = 0;
            for(int k=200;k>=0;k--)
            {
                int r = (arr[k]*num)+carry;
                int d = r%10;
                arr[k] = d;
                carry = r/10;
            }
        }

        // Now Print the result
        int flag = -1;
        for(int i=0;i<=200;i++)
        {
            if(arr[i] == 0 && flag == -1)
                continue;
            
            flag = 1;
            cout<<arr[i];
        }
        cout<<endl;
    }

}


int main()
{
    int n;
    cin>>n;
    longFactorials(n);
    return 0;
}