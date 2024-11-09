
+++
authors = ["grid47"]
title = "Leetcode 2904: Shortest and Lexicographically Smallest Beautiful String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2904: Shortest and Lexicographically Smallest Beautiful String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        string ans = "";
        int j = 0, cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') cnt++;

            while( j < n && cnt == k )
            {
                string tmp = s.substr(j, i - j + 1);

                if(ans.size()==0 || tmp.size() < ans.size()) ans = tmp;
                else if(tmp.size() == ans.size()) ans = min(ans, tmp);

                if(s[j] == '1') cnt--;

                j++;
            }
        }

        return ans;        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2904.md" >}}
---
{{< youtube FhAuoztsceo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2905: Find Indices With Index and Value Difference II](https://grid47.xyz/posts/leetcode-2905-find-indices-with-index-and-value-difference-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
