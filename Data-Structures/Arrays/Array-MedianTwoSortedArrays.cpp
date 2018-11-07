//============================================================================
// Name        : Array-MedianTwoSortedArrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

double MedianArray(vector<int>& a)
{
    int mid = (a.size())%2 ? a.size()/2 : a.size()/2 - 1;
    double output = a[mid];
    if(a.size()%2)
    {
        output = (output + a[mid+1])/2;
    }
    return output;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    double output = 0;
    int size1 = nums1.size(), size2 = nums2.size();

    if(!size1 && !size2)
        return output;

    if(!size1)
        return MedianArray(nums2);
    if(!size2)
        return MedianArray(nums1);

    int mid = (size1+size2)/2;
    mid = (size1+size2)%2 ? mid : mid - 1;

    while(i+j<mid+1 && j<size2 && i<size1)
    {
        if(i+j == mid)
            break;
        else if(nums1[i]<nums2[j])
        {
            i++;
        }
        else if(nums1[i] == nums2[j] && j<size2-1 && nums2[j+1]!=nums1[i])
        {
            i++;
        }
        else
            j++;
    }
    while(i+j<mid+1)//rest of larger array
    {
        if(i == size1) j++;
        else if(j == size2) i++;
    }
    if((size1+size2)%2==0)
        output = ((double)nums1[i] + (double)nums2[j])/2.0;
    else
        output = nums1[i]<nums2[j]?nums1[i]:nums2[j];
    return output;
}
//Working solution[Recursive]
int kthElement(vector<int>& nums1, vector<int>& nums2, int k, int s1, int s2)
{
	if(s1>=nums1.size())
		return nums2[s2+k-1];

	if(s2>=nums2.size())
			return nums1[s1+k-1];

	if(k == 1)
		return min(nums1[s1], nums2[s2]);
	int m1 = s1 + k/2 - 1;
	int m2 = s2 + k/2 - 1;

	int mid1 = m1<nums1.size()?nums1[m1]:INT_MAX;
	int mid2 = m2<nums2.size()?nums2[m2]:INT_MAX;

	if(mid1<mid2)
		return kthElement(nums1, nums2, k-k/2, mid1+1, s2);
	else
		return kthElement(nums1, nums2, k-k/2, s1, mid2+1);
}

double findMedianSortedArraysII(vector<int>& nums1, vector<int>& nums2){
	int total = nums1.size() + nums2.size();
	if(total%2 == 1)
		return (double)kthElement(nums1, nums2, total/2 + 1, 0, 0);
	else
		return (double)(kthElement(nums1, nums2, total/2, 0, 0) +
				kthElement(nums1, nums2, total/2 + 1, 0, 0)/2);
}
//Better way [Iterative]
double findMedianSortedArraysIII(vector<int>& nums1, vector<int>& nums2){
	int size1 = nums1.size();
	int size2 = nums2.size();
	if(size1>size2)
		return findMedianSortedArraysIII(nums2, nums1);
	int total = size1+size2+1;
	int start = 0;
	int end = size1;
	int partition1 = (start + end) /2;
	int partition2 = total/2 - partition1;
	while(start<=end)
	{
		int leftpart1 = partition1==0 ? INT_MIN : nums1[partition1-1];
		int leftpart2 = partition2==0 ? INT_MIN : nums2[partition2-1];
		int rightpart1 = partition1 == size1? INT_MAX : nums1[partition1];
		int rightpart2 = partition2 == size2? INT_MAX : nums2[partition2];

		if(leftpart1<=rightpart2 &&
			leftpart2<=rightpart2)
			break;
		else if(rightpart1>leftpart2)
			end = partition1-1;

		else if (rightpart2<leftpart1)
			start = partition1+1;

		partition1 = (end + partition1)/2;
		partition2 = total/2 -  partition1;
	}
	if(total%2 == 0)
		return (double)max(nums1[partition1-1], nums2[partition2-1]);
	else
		return (double)(max(nums1[partition1-1], nums2[partition2-1])
				+ min(nums1[partition1], nums2[partition2]))/2;

}

//Solution II
double findMedianSortedArraysIIII(vector<int>& nums1, vector<int>& nums2) {
	int size1 = nums1.size();
	int size2 = nums2.size();
	if(size1>size2)
		return findMedianSortedArraysIIII(nums2, nums1);

	int total = size1 + size2 + 1;
	int start = 0;
	int end = size1;

	while(start<=end)
	{

		int partition1 = (end+start)/2;
		int partition2 = (total)/2-partition1;

		if(partition1<end && nums2[partition2-1]>nums1[partition1])
			start = partition1+1;
		else if(partition1>start && nums1[partition1-1]>nums2[partition2] )
			end = partition1-1;
		else
		{
			int maxleft = 0;
			if(partition1 == 0)
				maxleft = nums2[partition2-1];
			else if(partition2 == 0)
				maxleft = nums1[partition1-1];
			else
				maxleft = (double)max(nums1[partition1-1], nums2[partition2-1]);
			if(total%2 == 0)
				return maxleft;

			int maxright = 0;
			if(partition1 == 0)
				maxright = nums2[partition2];
			else if(partition2 == 0)
				maxright = nums1[partition1];
			else
				maxright = (double)max(nums1[partition1], nums2[partition2]);
			return (double)(maxleft + maxright)/2;
		}
	}
	return 0.0;
}

int main() {
	vector<int> a = {1,2};
	vector<int> b = {3};
	cout<<findMedianSortedArraysIIII(a, b);
	return 0;
}
