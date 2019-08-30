#include <iostream> 
using namespace std; 
int leftTerm, rightTerm;
void printLeft(int i,int &leftTerm)
{
    for (int j = 1; j <= i; j++) { 
			cout << leftTerm;
			leftTerm+=10; 
	} 
}
void printRight(int i,int &rightTerm)
{
    for (int j = 1; j < i; j++) { 
			cout << rightTerm;
			rightTerm+=10; 
	}
}

int main() 
{ 

	int value;
    cin>>value;
	
	int i, j; 
	leftTerm = 10;
	rightTerm = value * value + 1; 
    rightTerm = rightTerm * 10;

	for (i = value; i > 0; i--) {
		for (int star = value; star > i; star--) 
			cout <<"**";

        printLeft(i,leftTerm);

        printRight(i,rightTerm);

        cout<<rightTerm/10;
	    
		rightTerm = rightTerm - ( (i - 1) * 2 ) * 10;
		cout << endl; 
	} 
}
