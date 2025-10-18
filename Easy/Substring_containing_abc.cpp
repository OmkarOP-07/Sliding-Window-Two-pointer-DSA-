#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> hash(3,-1);
        int n = s.size();
        int ans = 0;
        int ind = 0;
        for (int ind = 0; ind < n; ind++)
        {
             hash[s[ind]-'a'] = ind;
            if (hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
                ans += min({hash[0], hash[1], hash[2]});              
            }
        }
        return ans;
    }
};

int main()
{
    Solution sh;
    string s = "abcabc";
   cout<<sh.numberOfSubstrings(s);
  // cout<<s[2]-97;
 return 0;
}