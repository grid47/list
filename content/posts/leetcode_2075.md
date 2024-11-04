
+++
authors = ["Crafted by Me"]
title = "Leetcode 2075: Decode the Slanted Ciphertext"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2075: Decode the Slanted Ciphertext in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-the-slanted-ciphertext/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string decodeCiphertext(string et, int rows) {
        cout << et.size() << " " << rows;
        string res = "";
        int col = et.size() / rows;
        int idx = 0;
        string space = "";
        // cout << col << " " << rows << " ";
        while(idx < col - rows + 2) {
            for(int i = 0; i < rows && idx + i + i * col < et.size(); i++) {
                if(et[idx + i + i * col] == ' ')
                    space += ' ';
                else {
                    res += (space + et[idx + i + i * col]);                    
                    space = "";
                }

            }
            idx++;
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube vFxVjspTM-0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2076: Process Restricted Friend Requests](https://grid47.xyz/posts/leetcode_2076) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

