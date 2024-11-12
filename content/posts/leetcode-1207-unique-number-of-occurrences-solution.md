
+++
authors = ["grid47"]
title = "Leetcode 1207: Unique Number of Occurrences"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1207: Unique Number of Occurrences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-number-of-occurrences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i = 0;
        sort(arr.begin(),arr.end());
        vector<int> ans;
        while (i < arr.size()){
            int count = 1;
            for (int j = i+1; j< arr.size(); j++){
                if (arr[i] == arr[j])
                    count++;
            }
            ans.push_back(count);
            i = i + count;
        }
        sort(ans.begin(),ans.end());
        for (int i = 0; i < ans.size() - 1; i++){
            if (ans[i] == ans [i+1])
                return false;
        }
        return true;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1207.md" >}}
---
{{< youtube _NYimlZY1PE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1208: Get Equal Substrings Within Budget](https://grid47.xyz/posts/leetcode-1208-get-equal-substrings-within-budget-solution/) |
| --- |
