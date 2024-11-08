
+++
authors = ["grid47"]
title = "Leetcode 2055: Plates Between Candles"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2058: Find the Minimum and Maximum Number of Nodes Between Critical Points](https://grid47.xyz/posts/leetcode_2058) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
