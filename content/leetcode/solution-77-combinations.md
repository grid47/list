
+++
authors = ["grid47"]
title = "Leetcode 77: Combinations"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 77: Combinations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/77.webp"
youtube = "q0s6m7AiM7o"
youtube_upload_date="2021-08-31"
youtube_thumbnail="https://i.ytimg.com/vi/q0s6m7AiM7o/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/combinations/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/77.webp" 
    alt="A glowing, radiant combination of elements gently shifting together."
    caption="Solution to LeetCode 77: Combinations Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        vector<vector<int>> ans;
        vector<int> tmp;
        
            bt(ans, 1, k, tmp);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, int i, int k, vector<int> &tmp) {
        if(tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if(i == n + 1) return;
        
        for(int j = i; j <= n; j++) {
            tmp.push_back(j);
            bt(ans, j + 1, k, tmp);
            tmp.pop_back();
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/77.md" >}}
---
{{< youtube q0s6m7AiM7o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #78: Subsets](https://grid47.xyz/leetcode/solution-78-subsets/) |
| --- |