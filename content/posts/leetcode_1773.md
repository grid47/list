
+++
authors = ["Crafted by Me"]
title = "Leetcode 1773: Count Items Matching a Rule"
date = "2019-12-26"
description = "In-depth solution and explanation for Leetcode 1773: Count Items Matching a Rule in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| Next : [LeetCode #1774: Closest Dessert Cost](https://grid47.xyz/posts/leetcode_1774) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

