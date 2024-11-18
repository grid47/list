
+++
authors = ["grid47"]
title = "Leetcode 2553: Separate the Digits in an Array"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2553: Separate the Digits in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "wr1TK3mDUVY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/separate-the-digits-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        
        for(auto x: nums) {
            vector<int> tmp;
            while(x) {
                tmp.push_back(x % 10);
                x /= 10;
            }
            while(!tmp.empty()) {
                ans.push_back(tmp.back());
                tmp.pop_back();
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2553.md" >}}
---
{{< youtube wr1TK3mDUVY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2554: Maximum Number of Integers to Choose From a Range I](https://grid47.xyz/leetcode/solution-2554-maximum-number-of-integers-to-choose-from-a-range-i/) |
| --- |
