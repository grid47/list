
+++
authors = ["Crafted by Me"]
title = "Leetcode 2038: Remove Colored Pieces if Both Neighbors are the Same Color"
date = "2019-04-05"
description = "In-depth solution and explanation for Leetcode 2038: Remove Colored Pieces if Both Neighbors are the Same Color in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/)

---

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


---
{{< youtube 03zIcb12PKo >}}

"| 2039: The Time When the Network Becomes Idle |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

