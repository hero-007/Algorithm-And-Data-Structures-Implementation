#include<bits/stdc++.h>
using namespace std;

int min(int a, int b) 
{ 
    return (a < b) ? a : b; 
} 

int binomialCoeff(int n, int k) 
{ 
    int C[n + 1][k + 1]; 
    int i, j; 
  
    // Caculate value of Binomial Coefficient 
    // in bottom up manner 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            // Base Cases 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            // Calculate value using previously 
            // stored values 
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 

int main() 
{ 
	int res = 1;
    int x,s,y,m,z,c;
    char ch1,ch2;
    char chk;
    
    cin>>x>>s>>y>>m>>z>>c;
    cin>>ch1>>ch2;
    cin>>chk;
    
    int t1 = 0,t2 = 0,t3 = 0;
    t1 = binomialCoeff(x,s);
    t2 = binomialCoeff(y,m);
    t3 = binomialCoeff(z,c);
    
    res = res * t1 * t2 * t3;
    
    vector< pair<int,int> >ques;
    ques.push_back(make_pair(x,s));
    ques.push_back(make_pair(y,m));
    ques.push_back(make_pair(z,c));
    
    int g1 = -1,g2 = -1,g3 = -1;
    int tempx = (int)(ch1-'A')+1;
    int tempy = (int)(ch2-'A')+1;
    int tempz = (int)(chk-'A')+1;
    
    // find the grup of ch1
    if(tempx <= x)
    	g1 = 0;
    else if(tempx <= (x+y))
    	g1 = 1;
    else	
    	g1 = 2;
    
    // find the group of ch2
	if(tempy <= x)
    	g2 = 0;
    else if(tempy <= (x+y))
    	g2 = 1;
    else	
    	g2 = 2;
	
	// find the group of chk
	if(tempz <= x)
    	g3 = 0;
    else if(tempz <= (x+y))
    	g3 = 1;
    else	
    	g3 = 2;	
    
    
    // find the result 
    
    int result = 0;
    
    // remove chk from its grup
    ques[g3].first = ques[g3].first - 1;
    
    // select the first and reject second 
    int temp1 = 1;
    ques[g1].first = ques[g1].first - 1;
    ques[g1].second = ques[g1].second -1;
    ques[g2].first = ques[g2].first -1;
    
    for(int i=0;i<3;i++)
    {
    	int a = ques[i].first;
    	int b = ques[i].second;
    	
    	if(a < b)
    	{
    		temp1 = 0;
    		break;
		}
		
		temp1 = temp1 * binomialCoeff(a,b); 
	}
	
	// change to original state 
	ques[g1].first = ques[g1].first + 1;
    ques[g1].second = ques[g1].second + 1;
    ques[g2].first = ques[g2].first + 1;
    
	// select second and reject first one
	 int temp2 = 1;
	ques[g2].first = ques[g2].first - 1;
    ques[g2].second = ques[g2].second -1;
    ques[g1].first = ques[g1].first -1;
    
    for(int i=0;i<3;i++)
    {
    	int a = ques[i].first;
    	int b = ques[i].second;
    	
    	if(a < b)
    	{
    		temp2 = 0;
    		break;
		}
		temp2 = temp2 * binomialCoeff(a,b); 
	}
	
	// change to original state
	ques[g2].first = ques[g1].first + 1;
    ques[g2].second = ques[g1].second + 1;
    ques[g1].first = ques[g2].first + 1;
	
	// reject both 
	int temp3 = 1;
	ques[g1].first = ques[g1].first -1;
	ques[g2].first = ques[g2].first -1;
	
	for(int i=0;i<3;i++)
    {
    	int a = ques[i].first;
    	int b = ques[i].second;
    	
    	if(a < b)
    	{
    		temp3 = 0;
    		break;
		}
		
		temp3 = temp3 * binomialCoeff(a,b); 
	}
	
	result = temp1 + temp2 + temp3 + 1;
	cout<<res<<"\n";
	cout<<result;
} 
