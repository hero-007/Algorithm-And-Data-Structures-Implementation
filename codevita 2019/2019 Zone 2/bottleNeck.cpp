#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long 

class Bottle{
    public:
        ull radius;
        bool isSelected;
    
};

bool f(Bottle b1,Bottle b2)
{
    if(b1.radius < b2.radius)
        return true;
    return false;
}

int main()
{
    ull n;
    int cb = 0;
    cin>>n;
    Bottle bottle[n];
    for(ull i=0;i<n;i++)
    {
        cin>>bottle[i].radius;
        bottle[i].isSelected = false;
    }
    
    sort(bottle,bottle+n,f);
    
    for(ull i=0;i<n;i++)
    {
        ull curr_radius = bottle[i].radius;
        if(bottle[i].isSelected)
            continue;
        else
        {
            for(ull j=i+1;j<n;j++)
            {
                ull my_r = bottle[j].radius;
                bool status = bottle[j].isSelected;
                if(my_r > curr_radius && status == false)
                {
                    curr_radius = my_r;
                    bottle[j].isSelected = true;
                }
            }
            
            cb +=1;
            bottle[i].isSelected = true;
        }
    }
    cout<<cb;
    return 0;
}
