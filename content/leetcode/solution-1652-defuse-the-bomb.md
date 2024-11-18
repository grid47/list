
+++
authors = ["grid47"]
title = "Leetcode 1652: Defuse the Bomb"
date = "2024-05-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1652: Defuse the Bomb in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "r81OUfKmGtM"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/defuse-the-bomb/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        vector<int> ans(n, 0);
        
        if(k == 0) return ans;
        
        int sum = 0;
        if(k > 0) {
            for(int i = 1; i < k + 1; i++)
                sum += code[i];
            ans[0] = sum;
            for(int i = 1; i < n; i++) {
                sum += code[(i + k) % n];
                sum -= code[i];
                ans[i] = sum;
            }
            return ans;
        }

        for(int i = 0; i < abs(k); i++)
            sum += code[n - 1 - i];
        ans[0] = sum;
        for(int i = 1; i < n; i++) {
            sum += code[i - 1];
            sum -= code[(i - 1 - abs(k) + n) % n];
            ans[i] = sum;
        }
        return ans;        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1652.md" >}}
---
{{< youtube r81OUfKmGtM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1653: Minimum Deletions to Make String Balanced](https://grid47.xyz/leetcode/solution-1653-minimum-deletions-to-make-string-balanced/) |
| --- |
