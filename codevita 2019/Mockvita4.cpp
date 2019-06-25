//g++  5.4.0
//#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define X first
#define Y second
#define setZero(array) memset((array), 0, sizeof (array))
#define setOne(array) memset((array), 1, sizeof (array))
#define setTrue(array) memset((array), true, sizeof (array))
#define setFalse(array) memset((array), false, sizeof (array))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
using namespace std;
signed main(){
    _
    int i, j, k, res, n, mx_profit=0, crr_profit;
    int profit[4][4];
    int price[4], age[39], combo[4] = {0, 1, 2, 3};
    string names[4];
    char grade_i;
    pair<int, int> movie[4];
    
    pair<int, int> time[] = {
        {3, 20},
        {21, 40},
        {41, 49},
        {50, 70}
    };
    
    pair<int, int> grade[] = {
        {24, 50},
        {15, 25},
        {3, 18},
        {45, 70}
    };
    
    cin >> names[0] >> names[1] >> names[2] >> names[3];
    
    for(i=0; i<4; ++i){
        cin >> grade_i;
        movie[i] = grade[grade_i - 'A'];
    }
    
    for(i=0; i<4; ++i){
        cin >> price[i];
    }
    
    cin >> n; //n = number of audiance
    
    for(i=0; i<n; ++i){
        cin >> age[i];
    }
    
    for(i=0; i<4; ++i){
        for(j=0; j<4; ++j){
            for(res = 0, k=0; k<n; ++k){
                if(
                    movie[i].X <= age[k] and
                    movie[i].Y >= age[k] and
                    !(time[j].X <= age[k]  and
                    time[j].Y >= age[k])
                ){
                    ++res;
                }
            }
            profit[i][j] = res * price[i];
        }cout << endl;
    }
    
    do{
        //cout << combo[0] << combo[1] << combo[2] << combo[3] << endl; 
        crr_profit = profit[combo[0]][0] +
                     profit[combo[1]][1] +
                     profit[combo[2]][2] +
                     profit[combo[3]][3] ;
        
        mx_profit = max(mx_profit, crr_profit);
    }while(next_permutation(combo, combo+4));
    
    sort(combo, combo + 4);
    
    do{
        crr_profit = profit[combo[0]][0] +
                     profit[combo[1]][1] +
                     profit[combo[2]][2] +
                     profit[combo[3]][3] ;
        
        if(crr_profit == mx_profit){
            cout << names[combo[0]] << " "
                << names[combo[1]] << " "
                << names[combo[2]] << " "
                << names[combo[3]] << endl;
        }
    }while(next_permutation(combo, combo+4));
    
    cout << "Maximum Profit: " << mx_profit;
    
    return 0;
}

