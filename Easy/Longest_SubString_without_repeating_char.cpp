#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int maxLen = 0;
//         for (int i = 0; i < s.length(); i++)
//         {
//             int hash[255] = {0};
//             for (int j = i; j < s.length(); j++)
//             {
//                 if(hash[s[j]] == 1) break;
//                 hash[s[j]] = 1;
//                 maxLen = max(maxLen, (j - i + 1));
//             }
//         }
//         return maxLen;
//     }
// };
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.length() == 1) return 1;
        int maxLen = 0; int n = s.length();
        vector<int> hash(255, -1);
        int l = 0; int r = 0;
        while(r<n){
            if(hash[s[r]] != -1){  //char is in the map
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
int main()
{
    Solution sh;
    cout << sh.lengthOfLongestSubstring("au");
    return 0;
}