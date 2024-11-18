
+++
authors = ["grid47"]
title = "Leetcode 1447: Simplified Fractions"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1447: Simplified Fractions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xAPYdvSkcF8"
youtube_upload_date="2020-05-17"
youtube_thumbnail="https://i.ytimg.com/vi/xAPYdvSkcF8/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGUgZSgVMA8=&rs=AOn4CLA8kfJhe38vkPWigQhNMfXCO873lw"
+++



[`Problem Link`](https://leetcode.com/problems/simplified-fractions/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if(n == 1) return {};
        vector<string> res;
        queue<tuple<int, int, int, int>> q;
        q.emplace(0, 1, 1, 1);
        while(!q.empty()) {
            auto [num1, den1, num2, den2] = q.front();
            q.pop();
            int num = num1 + num2;
            int den = den1 + den2;
            res.push_back(to_string(num) + "/" + to_string(den));
            if(den + den1 <= n) q.emplace(num1, den1, num, den);
            if(den + den2 <= n) q.emplace(num, den, num2, den2);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1447.md" >}}
---
{{< youtube xAPYdvSkcF8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1448: Count Good Nodes in Binary Tree](https://grid47.xyz/leetcode/solution-1448-count-good-nodes-in-binary-tree/) |
| --- |
