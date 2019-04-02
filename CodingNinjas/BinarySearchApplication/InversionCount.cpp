#include<bits/stdc++.h>
using namespace std;



int getMergeCount(int *arr,int st_index,int mid_index,int ed_index)
{
	int left_size = mid_index-st_index+1;
	int right_size = ed_index-mid_index;
	
	int left_arr[left_size+1];
	int right_arr[right_size+1];
	
	left_arr[left_size] = INT_MAX;
	right_arr[right_size] = INT_MAX;
	
	// filling the elements in left_arr and right_arr
	for(int i=0;i<left_size;i++)
		left_arr[i] = arr[st_index+i];
		
	for(int j=0;j<right_size;j++)
		right_arr[j] = arr[mid_index+j+1];
		
	// Now merge these two arrays and count the number of inversions possible
	int left_ptr = 0,right_ptr = 0,itr = st_index;
	int number_of_inversions = 0;
	
	while((left_ptr < left_size) && (right_ptr < right_size))
	{
		if(left_arr[left_ptr] > right_arr[right_ptr])
		{
			int left_len = left_size-left_ptr;
			number_of_inversions += left_len;
			arr[itr] = right_arr[right_ptr];
			right_ptr++;
			itr++;
		}
		else
		{
			arr[itr] = left_arr[left_ptr];
			left_ptr++;
			itr++;
		}
	}
	
	// Copy the remaining elements to arr
	while(left_ptr < left_size)
	{
		arr[itr] = left_arr[left_ptr];
		itr++;
		left_ptr++;
	}
	
	while(right_ptr < right_size)
	{
		arr[itr] = right_arr[right_ptr];
		itr++;
		right_ptr++;
	}
	
	return number_of_inversions;
}

int getInversionCount(int *arr,int st_index,int ed_index)
{
	if (st_index == ed_index)
		return 0;
		
	if(st_index < ed_index)
	{
		int mid_index = (st_index+ed_index)/2;
		
		int left_count = getInversionCount(arr,st_index,mid_index);
		int right_count = getInversionCount(arr,mid_index+1,ed_index);
		int merge_count = getMergeCount(arr,st_index,mid_index,ed_index);
		
		return (left_count+right_count+merge_count);
	}
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int num_inversions = getInversionCount(arr,0,n-1);
	cout<<num_inversions<<endl;
}
