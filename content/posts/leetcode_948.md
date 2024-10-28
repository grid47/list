
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 948: Bag of Tokens"
date = "2022-03-26"
description = "Solution to Leetcode 948"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bag-of-tokens/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0, pts = 0, i = 0, j = tokens.size() - 1;
        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i++];
                res = max(res, ++pts);
            } else if(pts > 0) {
                power += tokens[j--];
                pts--;
            } else break;
        }
        
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

