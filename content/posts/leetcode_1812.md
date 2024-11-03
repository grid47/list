
+++
authors = ["Crafted by Me"]
title = "Leetcode 1812: Determine Color of a Chessboard Square"
date = "2019-11-17"
description = "In-depth solution and explanation for Leetcode 1812: Determine Color of a Chessboard Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-color-of-a-chessboard-square/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool squareIsWhite(string cord) {
        int x = cord[0] - 'a' + 1;
        x += cord[1] - '0';
        return x % 2;
    }
};
{{< /highlight >}}


---


"| 1813: Sentence Similarity III |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

