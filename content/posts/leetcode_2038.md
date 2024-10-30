
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2038: Remove Colored Pieces if Both Neighbors are the Same Color"
date = "2019-04-03"
description = "Solution to Leetcode 2038"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/)

---
{{< youtube 03zIcb12PKo >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        for(int i = 1; i < colors.size() - 1; i++) {
            if(colors[i - 1] == colors[i] && colors[i] == colors[i+1]) {
                if(colors[i] == 'A') a++;
                else b++;
            }
        }
        return a > b;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

