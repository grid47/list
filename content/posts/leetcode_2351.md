
+++
authors = ["Crafted by Me"]
title = "Leetcode 2351: First Letter to Appear Twice"
date = "2018-05-27"
description = "In-depth solution and explanation for Leetcode 2351: First Letter to Appear Twice in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-letter-to-appear-twice/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> v(26);
        for(char c:s){
            v[c-'a']++;
            if(v[c-'a']>1)return c;
        }
        return 'a';
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2352: Equal Row and Column Pairs](https://grid47.xyz/posts/leetcode_2352) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

