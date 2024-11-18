
+++
authors = ["grid47"]
title = "Leetcode 2899: Last Visited Integers"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2899: Last Visited Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-visited-integers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>v;
        vector<int>ans;
        int count=0;
        for(int i=0;i<words.size();i++){
            if(words[i]=="prev"){
                count++;
                if(count>v.size()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(v[v.size()-count]);
                }
            }
            else{
                count=0;
                v.push_back(stoi(words[i]));
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2899.md" >}}
---
{{< youtube vWwJsOGGKu8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2900: Longest Unequal Adjacent Groups Subsequence I](https://grid47.xyz/leetcode/solution-2900-longest-unequal-adjacent-groups-subsequence-i/) |
| --- |
