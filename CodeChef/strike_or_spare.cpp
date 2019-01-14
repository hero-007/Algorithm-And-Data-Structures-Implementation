#include<iostream>
#include<cmath>

using namespace std;

int count_digits(int a){
	int d = 0;
	while (a>0){
		d++;
		a=a/10;
	}
	return d;
}

int gcd(int a,int b){
	if (b == 0 )
		 return a;
	else
		return gcd(b,a%b);
		 
}

int main(){
	int t;
	cin>>t;
	while (t>0){
		t--;
		int n;
		cin>>n;
		int d = count_digits(n);
		if (d%2){
			// This block will be executed if number of digits are odd
			int m = (d-1)/2;
			int p = int(pow(10,m+1));
			int q = int(pow(10,d));
			/**int gd = gcd(q,p);
			p = p/gd;
			q = q/gd;**/
			cout<<p<<" "<<q<<endl;
		}
		else{
			// This block will be executed if number of digits are even
			int m = d/2;
			int p = int(pow(10,m));
			int q = int(pow(10,d));
			/**int gd = gcd(q,p);
			p = p/gd;
			q = q/gd;**/
			cout<<p<<" "<<q<<endl;
		}
		
	}
	
	return 0;
}
