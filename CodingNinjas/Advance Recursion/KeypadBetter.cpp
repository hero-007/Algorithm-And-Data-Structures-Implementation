#include <bits/stdc++.h>
using namespace std;

string getStringCombination(int t)
{
	if(t == 2)
		return "abc";
	else if(t==3)
		return "def";
	else if(t==4)
		return "ghi";
	else if(t==5)
		return "jkl";
	else if(t==6)
		return "mno";
	else if(t==7)
		return "pqrs";
	else if(t==8)
		return "tuv";
	else if(t==9)
		return "wxyz";
	else
		return "";
}

void printAllCombinations(int num,string output)
{
    if(num == 0)
    {
        cout<<output<<endl;
        return;
    }
    
    int d = num%10;
    string sk = getStringCombination(d);
    int l = sk.length();
    int n_num = num/10;
    
    for(int i=0;i<l;i++)
    {
        char ch = sk[i];
        string n_output = ch+output;
        
        printAllCombinations(n_num,n_output);
    }
}
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    printAllCombinations(num,"");
}

int main(){
	
	cout<<"Enter the number : ";
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}


