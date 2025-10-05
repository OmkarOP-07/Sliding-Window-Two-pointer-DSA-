#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int maxf = 0;
            vector<int> hash(26, 0);
            for (int j = i; j < s.size(); j++)
            {
                hash[s[j] - 'A']++;
                maxf = max(maxf, hash[s[j] - 'A']);
                int changes = (j - i + 1) - maxf;
                if (changes <= k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxLen;
    }
    int characterReplacementOptimal(string s, int k)
    {
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int n = s.size();
        vector<int> hash(26, 0);
        int maxf = 0;
        while (r < n)
        {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            if ((r - l + 1) - maxf > k)
            {
                hash[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};

int main()
{
    Solution sh;
    string s = "AABABBA";
    cout << sh.characterReplacementOptimal(s, 1);
    return 0;
}