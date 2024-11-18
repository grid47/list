
+++
authors = ["grid47"]
title = "Leetcode 946: Validate Stack Sequences"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 946: Validate Stack Sequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "YF5ZWSWvMT0"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/validate-stack-sequences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 1, j = 0;
        stk.push(pushed[0]);
        int n = pushed.size();
        while(i < n) {
            while(j < n && !stk.empty() && stk.top() == popped[j]) {
                j++;
                stk.pop();
            }
            stk.push(pushed[i++]);
        }
        while(j < n && !stk.empty() && stk.top() == popped[j]) {
            j++;
            stk.pop();
        }        
        
        return stk.empty();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/946.md" >}}
---
{{< youtube YF5ZWSWvMT0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #947: Most Stones Removed with Same Row or Column](https://grid47.xyz/leetcode/solution-947-most-stones-removed-with-same-row-or-column/) |
| --- |
