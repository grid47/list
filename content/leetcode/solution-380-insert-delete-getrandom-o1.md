
+++
authors = ["grid47"]
title = "Leetcode 380: Insert Delete GetRandom O(1)"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 380: Insert Delete GetRandom O(1) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Design","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/380.webp"
youtube = "j4KwhBziOpg"
youtube_upload_date="2022-03-16"
youtube_thumbnail="https://i.ytimg.com/vi/j4KwhBziOpg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/insert-delete-getrandom-o1/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/380.webp" 
    alt="A sequence of elements being added or deleted, with each random selection softly highlighted."
    caption="Solution to LeetCode 380: Insert Delete GetRandom O(1) Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class RandomizedSet {
private:
    vector<int> a;
    unordered_map<int,int> m;
public:
    RandomizedSet() {
    }
    bool insert(int val) {
        if(m.find(val)!=m.end())
            return false;
        else{
            a.push_back(val);
            m[val]=a.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end())
            return false;
        else{
            int last=a.back(); 
            a[m[val]]=a.back();
            a.pop_back();
            m[last]=m[val];   
            m.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/380.md" >}}
---
{{< youtube j4KwhBziOpg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #382: Linked List Random Node](https://grid47.xyz/leetcode/solution-382-linked-list-random-node/) |
| --- |
