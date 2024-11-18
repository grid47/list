
+++
authors = ["grid47"]
title = "Leetcode 1441: Build an Array With Stack Operations"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1441: Build an Array With Stack Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "uK6JvnLUcck"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/build-an-array-with-stack-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int currElem=1;
        for(int i=0;i<target.size();i++){
            while(currElem!=target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                currElem++;
            }
            ans.push_back("Push");
            currElem++;
        }
        return ans;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1441.md" >}}
---
{{< youtube uK6JvnLUcck >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1442: Count Triplets That Can Form Two Arrays of Equal XOR](https://grid47.xyz/leetcode/solution-1442-count-triplets-that-can-form-two-arrays-of-equal-xor/) |
| --- |
