#include<bits/stdc++.h>
using namespace std;

void merge_2(int *arr,int st,int ed)
{
	int leng = ed-st+1;
	int mid = (st+ed)/2;
	
	int *temp = new int[leng];
	
	int i=st,j=mid+1,itr=0;
	while(i <= mid && j <= ed)
	{
		if(arr[i] <= arr[j])
		{
			temp[itr] = arr[i];
			i++;
		}
		else
		{
			temp[itr] = arr[j];
			j++;
		}
		itr++;
	}
	
	while(i <= mid){
		temp[itr]=arr[i];
		itr++;
		i++;
	}
	while(j <= ed){
		temp[itr]=arr[j];
		itr++;
		j++;
	}
	int mtr = 0;
	for(int k = st;k<=ed;k++)
	{
		arr[k] = temp[mtr];
		mtr++;
	}
	
	delete []temp;
}

void merge(int *arr, int start_index, int mid_index, int end_index)
{
	int left_size = mid_index-start_index+1;
	int right_size = end_index-mid_index;
	
	int *left = new int[left_size+1];
	int *right = new int[right_size+1];
	
	left[left_size] = INT_MAX;
	right[right_size] = INT_MAX;
	
	for(int i=0;i<left_size;i++)
		left[i] = arr[start_index+i];
		
	for(int i=0;i<right_size;i++)
		right[i] = arr[mid_index+i+1];
		
	
	int left_ptr = 0, right_ptr = 0, itr = start_index;
	while(left_ptr < left_size && right_ptr < right_size)
	{
		if(left[left_ptr] < right[right_ptr])
		{
			arr[itr] = left[left_ptr];
			itr++;
			left_ptr++;
		}
		else{
			arr[itr] = right[right_ptr];
			itr++;
			right_ptr++;
		}
	}
	
	// Copy the remaining elements if there are any 
	while (left_ptr < left_size)
	{
		arr[itr] = left[left_ptr];
		left_ptr++;
		itr++;
	}
	
	while (right_ptr < right_size)
	{
		arr[itr] = right[right_ptr];
		right_ptr++;
		itr++;
	}
	
	delete left;
	delete right;
}

void merge_sort(int *arr, int start_index, int end_index)
{
	if(start_index < end_index)
	{
		int mid_index = (start_index + end_index)/2;
		
		merge_sort(arr,start_index,mid_index);
		merge_sort(arr,mid_index+1,end_index);
		merge_2(arr,start_index,end_index);
	}
}

int main()
{
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;
	
	int *arr = new int[n];
	
	cout<<"Enter the array elements below : "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	merge_sort(arr,0,n-1);
	
	cout<<"\nSorted array : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}
