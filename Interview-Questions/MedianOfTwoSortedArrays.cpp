/**
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * Example 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> finallist;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                finallist.push_back(nums1[i++]);
            } else {
                finallist.push_back(nums2[j++]);
            }
        }
        while (i < nums1.size()) {
            finallist.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            finallist.push_back(nums2[j++]);
        }
        
        int mid = finallist.size()/2;
        bool twoEl = finallist.size()%2 == 0;
        if (twoEl) {
            return double(finallist[mid-1] + finallist[mid]) / 2;
        } else {
            return finallist[mid];
        }
    }
};
