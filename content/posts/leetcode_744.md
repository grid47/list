
+++
authors = ["Yasir"]
title = "Leetcode 744: Find Smallest Letter Greater Than Target"
date = "2022-10-15"
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

{{< highlight html >}}
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

