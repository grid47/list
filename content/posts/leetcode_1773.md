
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1773: Count Items Matching a Rule"
date = "2019-12-24"
description = "Solution to Leetcode 1773"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-items-matching-a-rule/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

