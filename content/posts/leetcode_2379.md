
+++
authors = ["Crafted by Me"]
title = "Leetcode 2379: Minimum Recolors to Get K Consecutive Black Blocks"
date = "2018-04-28"
description = "Solution to Leetcode 2379"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
int minimumRecolors(string blocks, int k) {
    int b = 0, mb = 0;
    for (int i = 0; i < blocks.size(); ++i) {
        b += blocks[i] == 'B';
        if (i >= k)
            b -= blocks[i - k] == 'B';
        mb = max(b, mb);
    }
    return k - mb;
}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

