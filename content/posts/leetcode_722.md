
+++
authors = ["Crafted by Me"]
title = "Leetcode 722: Remove Comments"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 722: Remove Comments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-comments/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool is_mul = false;
        string res = "";
        for(int i = 0; i < source.size(); i++) {
            string str = source[i];
            res = is_mul? res:"";
            for(int j = 0; j < str.size() ; j++) {
                if(!is_mul) {
                    if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '/') {
                        break;
                    } else if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '*') {
                        is_mul = true;
                        j++;
                    } else {
                        res += str[j];
                    }
                } else {
                    if(j < str.size() - 1 && str[j] == '*' && str[j + 1] == '/') {
                        is_mul = false;
                        j++;
                    }
                }
            }

            if(!is_mul && res != "") ans.push_back(res);
        }
        return ans;
    }
};

//
/*
*/
/* */
// */ --- //
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/722.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #723: Candy Crush](https://grid47.xyz/posts/leetcode_723) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

