#include <bits/stdc++.h>

using namespace std;

int main()
{
	short int t;
	cin>>t;
	while (t>0){
		t--;
		int n,spam=0,non_spam=0;
		signed int maxx,minx,w,b;
		cin>>n>>minx>>maxx; 		// n,minx,maxx
		int arr[n][2];
		
		for (int j=0;j<n;j++){
			cin>>w>>b;
			arr[j][0]=w;
			arr[j][1]=b;
		}
		
		for (int i=minx;i<=maxx;i++){
			int y = i%2;
			
			int l = (arr[0][0]*y+arr[0][1])%2;
			
			/**for (int k=0;k<n;k++){
				y = (arr[k][0]*y+arr[k][1])%2;
			}**/
			
			if (l)
				spam++;
			else
				non_spam++;
		}
		cout<<non_spam<<" "<<spam<<endl;
	}
	return 0;
}
