#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// O(N)+ O(N)
int FruitsIntoBasket(vector<int> arr, int k)
{
    int maxLen = 0;
    int l = 0;
    int r = 0;
    unordered_map<int, int> mpp;
    while (r < arr.size())
    {
        mpp[arr[r]]++;
        if (mpp.size() > k)
        {
            while (mpp.size() > k)
            {
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        if (mpp.size() <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}

// O(N)
int FruitsIntoBasketOptimal(vector<int> arr, int k)
{
    int maxLen = 0;
    int l = 0;
    int r = 0;
    unordered_map<int, int> mpp;
    while (r < arr.size())
    {
        mpp[arr[r]]++;
        if(mpp.size() > k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) 
                mpp.erase(arr[l]);
            l++;
        }
        if(mpp.size() <= k){
            maxLen = max(maxLen, r-l+1);
        }

        r++;
    }
    return maxLen;
}
int main()
{
    vector<int> arr = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << FruitsIntoBasketOptimal(arr, 2);
    return 0;
}