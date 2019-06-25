/* C++ program to print a given number in words. 
The program handles till 9 digits numbers and 
can be easily extended to 20 digit number */
#include <iostream> 
using namespace std; 


string one[] = { "", "One ", "Two ", "Three ", "Four ", 
				"Five ", "Six ", "Seven ", "Eight ", 
				"Nine ", "Ten ", "Eleven ", "Twelve ", 
				"Thirteen ", "Fourteen ", "Fifteen ", 
				"Sixteen ", "Seventeen ", "Eighteen ", 
				"Nineteen "
			}; 


string ten[] = { "", "", "Twenty ", "Thirty ", "Forty ", 
				"Fifty ", "Sixty ", "Seventy ", "Eighty ", 
				"Ninety "
			}; 

// n is 1- or 2-digit number 
string numToWords(int n, string s) 
{ 
	string str = ""; 
	// if n is more than 19, divide it 
	if (n > 19) 
		str += ten[n / 10] + one[n % 10]; 
	else
		str += one[n]; 

	// if n is non-zero 
	if (n) 
		str += s; 

	return str; 
} 

 
string convertToWords(long n) 
{ 
	
	string out; 

	
	out += numToWords((n / 10000000), "Crore "); 

	
	out += numToWords(((n / 100000) % 100), "Lakh "); 

	
	out += numToWords(((n / 1000) % 100), "Thousand "); 

	
	out += numToWords(((n / 100) % 10), "Hundred "); 


	
	out += numToWords((n % 100), ""); 

	return out; 
} 

// Driver code 
int main() 
{ 
	// long handles upto 9 digit no 
	// change to unsigned long long int to 
	// handle more digit number 
	long n = 1729; 

	// convert given number in words 
	cout << convertToWords(n) << endl; 

	return 0; 
} 

