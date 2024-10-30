
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2023: Number of Pairs of Strings With Concatenation Equal to Target"
date = "2019-04-18"
description = "Solution to Leetcode 2023"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> freq;
        for(auto num : nums) if(num.size() < target.size()) freq[num]++;

        int res = 0;
        for(auto [s, frq]: freq) {
            if(target.find(s) == 0) {
                if(s + s == target) 
                res += frq * (frq - 1);
                else
                res  += frq * freq[target.substr(s.size())];
            }
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

