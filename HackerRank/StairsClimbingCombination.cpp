/*
Davis has a number of staircases in his house and he likes to climb each staircase 1, 2, or 3 steps at a time. Being a very precocious child, he wonders how many ways there are to reach the top of the staircase.

Given the respective heights for each of the  staircases in his house, find and print the number of ways he can climb each staircase, module 10^9 + 7  on a new line.

For example, there is 1 staircase in the house that is 3 steps high. Davis can step on the following sequences of steps:

1 1 1 1 1
1 1 1 2
1 1 2 1 
1 2 1 1
2 1 1 1
1 2 2
2 2 1
2 1 2
1 1 3
1 3 1
3 1 1
2 3
3 2

Answer = 13

*/

#include<iostream>
#define mod 10000000007
using namespace std;

int stepPerms(int n) {
    if (n < 0)
        return 0;
    else if (n == 0 || n == 1)
        return 1;
    else if (n == 3)
        return 4;
    else if (n == 2)
        return 2;
        
    else{
        int count = 0;
        count = stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3);

        if (count >= mod)
            return count%mod;
        else
            return count;
    }
}

int main()
{
	int s;
	printf("Enter the number of stairs : ");
	scanf("%d",&s);
	
	int number_of_ways = stepPerms(s);
	printf("Total number of ways = %d\n",number_of_ways);
	return 0;
}
