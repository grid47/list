
+++
authors = ["grid47"]
title = "Leetcode 1773: Count Items Matching a Rule"
date = "2024-05-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1773: Count Items Matching a Rule in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-items-matching-a-rule/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int i;
        if(ruleKey=="type")i=0;
        if(ruleKey=="color")i=1;
        if(ruleKey=="name")i=2;
        
        int ans=0;
        for(int j=0;j<items.size();j++){
            if(items[j][i]==ruleValue)ans++;
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1773.md" >}}
---
{{< youtube FL3vJlSmq7w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1774: Closest Dessert Cost](https://grid47.xyz/leetcode/solution-1774-closest-dessert-cost/) |
| --- |
