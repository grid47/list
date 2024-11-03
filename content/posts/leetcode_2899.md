
+++
authors = ["Crafted by Me"]
title = "Leetcode 2899: Last Visited Integers"
date = "2016-11-25"
description = "In-depth solution and explanation for Leetcode 2899: Last Visited Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-visited-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>v;
        vector<int>ans;
        int count=0;
        for(int i=0;i<words.size();i++){
            if(words[i]=="prev"){
                count++;
                if(count>v.size()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(v[v.size()-count]);
                }
            }
            else{
                count=0;
                v.push_back(stoi(words[i]));
            }
        }
        return ans;
    }
};
{{< /highlight >}}


---


"| 2900: Longest Unequal Adjacent Groups Subsequence I |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

