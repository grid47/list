
+++
authors = ["Crafted by Me"]
title = "Leetcode 1441: Build an Array With Stack Operations"
date = "2019-11-22"
description = "Solution to Leetcode 1441"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/build-an-array-with-stack-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int currElem=1;
        for(int i=0;i<target.size();i++){
            while(currElem!=target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                currElem++;
            }
            ans.push_back("Push");
            currElem++;
        }
        return ans;        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

