
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 744: Find Smallest Letter Greater Than Target"
date = "2022-10-16"
description = "Solution to Leetcode 744"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for(int i = 0; i < letters.size(); i++) {
            if(letters[i] > target) {
                ans = letters[i];
                break;
            }
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

