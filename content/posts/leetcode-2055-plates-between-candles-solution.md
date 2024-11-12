
+++
authors = ["grid47"]
title = "Leetcode 2055: Plates Between Candles"
date = "2024-04-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2055: Plates Between Candles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Binary Search","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/plates-between-candles/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n = s.length();
        vector<int> left(n, 0), right(n, 0), count(n, 0), ans(q.size(), 0);
        int node = -1;
        int cnt  = 0;
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '|') {

                node = i;
                cnt++;
            }

            left[i]  = node;
            count[i] = cnt;

        }
        
        node = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '|'){
                node = i;
            }
            right[i] = node;
            
        }
        
        int idx = 0;
        for(vector<int> qr : q) {



            int r = left[qr[1]];
            int l = right[qr[0]];
           // int c = count[r] - count[l] + 1;
            
            if (r == -1 || l == -1 || r - l <= 1) {

                ans[idx] = 0;

            } else {
int c = count[r] - count[l] +1;
     ans[idx] = r - l + 1 - c;

            }
            
            idx++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2055.md" >}}
---
{{< youtube -1IsQyTM6Lg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2058: Find the Minimum and Maximum Number of Nodes Between Critical Points](https://grid47.xyz/posts/leetcode-2058-find-the-minimum-and-maximum-number-of-nodes-between-critical-points-solution/) |
| --- |
