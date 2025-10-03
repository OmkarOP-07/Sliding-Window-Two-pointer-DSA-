#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int maxLen = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int zeros = 0;
//             for (int j = i; j < nums.size(); j++)
//             {
//                 if(nums[j] == 0) zeros++;
//                 if(zeros<= k){
//                     int len = j - i + 1;
//                     maxLen = max(maxLen, len);
//                 }
//                 else {
//                     break;
//                 }
//             }    
//         }
//         return maxLen;
//     }
// };

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int n = nums.size();
        int l = 0;
        int r = 0; int zeros = 0;
        while (r < n)
        {
            if(nums[r] == 0){
                zeros++;
            }
            while (zeros > k) 
            {
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            if(zeros <= k){
                int len = r-l+1;
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};
int main()
{
    Solution sh;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<sh.longestOnes(nums, k);
 return 0;
}