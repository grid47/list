
+++
authors = ["grid47"]
title = "Leetcode 2353: Design a Food Rating System"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2353: Design a Food Rating System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-a-food-rating-system/description/)

---
**Code:**

{{< highlight cpp >}}
class FoodRatings {
    unordered_map<string, set<pair<int, string>>> cus_itm;
    unordered_map<string, string> fd_cus;
    unordered_map<string, int> fd_rat;
public:
    FoodRatings(vector<string>& fd, vector<string>& cus, vector<int>& rat) {
        int n = fd.size();
        for(int i = 0; i < n; i++) {
            cus_itm[cus[i]].insert(pair(-rat[i], fd[i]));
            fd_cus[fd[i]] = cus[i];
            fd_rat[fd[i]] = rat[i];
        }
    }
    
    void changeRating(string fd, int rat) {
        string cus = fd_cus[fd];
        int r = fd_rat[fd];
        cus_itm[cus].erase({-r, fd});
        cus_itm[cus].insert({-rat, fd});
        fd_rat[fd] = rat;
 
    }
    
    string highestRated(string cus) {
        return begin(cus_itm[cus])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2353.md" >}}
---
{{< youtube Ikp8SgbgbEo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2357: Make Array Zero by Subtracting Equal Amounts](https://grid47.xyz/posts/leetcode-2357-make-array-zero-by-subtracting-equal-amounts-solution/) |
| --- |
