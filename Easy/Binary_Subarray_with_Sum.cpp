#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int funct(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int r = 0; int l = 0;
        int n = nums.size(); int sum = 0;
        int count = 0;
        while(r < n)
        {
            sum = sum + nums[r];
            while (sum > goal)
            {
                sum = sum - nums[l];
                l = l + 1;
            }
            count = count + (r - l + 1);

            r = r + 1;
        }
        return count;
    }
    
    int numSubarraysWithSum(vector<int> nums, int goal)
    {
        return funct(nums, goal) - funct(nums, goal - 1);
    }
};

int main()
{
    Solution sh;
    vector<int> arr = {1, 0, 1, 0, 1};
    cout << sh.numSubarraysWithSum(arr, 2);
    return 0;
}