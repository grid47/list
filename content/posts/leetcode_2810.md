
+++
authors = ["Crafted by Me"]
title = "Leetcode 2810: Faulty Keyboard"
date = "2017-02-22"
description = "In-depth solution and explanation for Leetcode 2810: Faulty Keyboard in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/faulty-keyboard/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string finalString(string s) {
        string res = "";
        for(auto c : s){
            if(c == 'i'){
                if(res.size()){
                    reverse(res.begin(), res.end());
                }
                
            }else
             res+=c;
        }
        return res;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2811: Check if it is Possible to Split Array](https://grid47.xyz/posts/leetcode_2811) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

