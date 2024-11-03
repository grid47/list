
+++
authors = ["Crafted by Me"]
title = "Leetcode 2055: Plates Between Candles"
date = "2019-03-19"
description = "In-depth solution and explanation for Leetcode 2055: Plates Between Candles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2056: Number of Valid Move Combinations On Chessboard](https://grid47.xyz/posts/leetcode_2056) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

