
+++
authors = ["grid47"]
title = "Leetcode 528: Random Pick with Weight"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 528: Random Pick with Weight in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Prefix Sum","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/528.webp"
youtube = "oYjDXfo-mt0"
youtube_upload_date="2020-05-22"
youtube_thumbnail="https://i.ytimg.com/vi/oYjDXfo-mt0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/528.webp" 
    alt="A series of objects with different weights, each object softly glowing based on its probability of being picked."
    caption="Solution to LeetCode 528: Random Pick with Weight Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> wc;
    public:
    Solution(vector<int>& w) {
        int n = w.size();
        for(int i = 1; i < n; i++)
            w[i] += w[i - 1];
        wc = w;
    }
    
    int pickIndex() {
        
        int x = rand() % wc.back()+1;//[(wc.size() - 1)];        
        int l = 0, r = wc.size() - 1;
    
        while(l < r) {

            int mid = l + (r - l) / 2;            
            if(wc[mid] == x) return mid;

            if(wc[mid] < x) l = mid + 1;
            else            r = mid;
        
        }
        
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
{{< /highlight >}}
---

### Problem Statement

The task is to create a solution where each index of an input array `w` is chosen with a probability proportional to the value at that index. This requires building a mechanism to select indices according to weighted probabilities. Given an array of positive integers, we need a way to initialize a data structure that, when calling `pickIndex`, returns an index based on these weights.

### Approach

1. **Prefix Sum Array**:
   - First, transform the input weights array `w` into a prefix sum array. In the prefix sum array, each element at index `i` will contain the sum of all weights from the start up to index `i`.
   - This transformation allows each index in the prefix sum array to represent cumulative probability bounds for selection.

2. **Random Selection Using Binary Search**:
   - To pick an index with the appropriate weight, generate a random integer `x` within the range `[1, wc.back()]` where `wc.back()` represents the total sum of weights.
   - Using binary search, locate the smallest index in the prefix sum array `wc` where `wc[i] >= x`. This index `i` represents the randomly selected index based on the weight.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Prefix Sum Array

```cpp
Solution(vector<int>& w) {
    int n = w.size();
    for(int i = 1; i < n; i++)
        w[i] += w[i - 1];
    wc = w;
}
```

- This constructor takes an input weight array `w` and modifies it to be a prefix sum array.
- By iterating from the second element, we update each element to hold the cumulative sum up to that point. This helps in determining probability boundaries, making it efficient to select indices in proportion to their weights.

#### Step 2: Generate a Random Index Based on Weights

```cpp
int pickIndex() {
    int x = rand() % wc.back() + 1;
    int l = 0, r = wc.size() - 1;
    
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(wc[mid] == x) return mid;
        if(wc[mid] < x) l = mid + 1;
        else            r = mid;
    }
    return l;
}
```

- **Generate Random Number**: `rand() % wc.back() + 1` produces a random number between `1` and the sum of all weights (`wc.back()`).
- **Binary Search for Index**: Using binary search, we find the first index in `wc` where the value is greater than or equal to `x`.
   - If `wc[mid]` equals `x`, `mid` is returned immediately.
   - Otherwise, the search continues, adjusting `l` or `r` to find the smallest `mid` where `wc[mid]` is greater than or equal to `x`.

#### Example:
Suppose `w = [1, 3, 2]`. After constructing `wc`, it becomes `[1, 4, 6]`. A random value `x` within the range `[1, 6]` will land in intervals corresponding to the weights in `w`:
- If `x` is in `[1, 1]`, index `0` is selected.
- If `x` is in `[2, 4]`, index `1` is selected.
- If `x` is in `[5, 6]`, index `2` is selected.

### Complexity

- **Time Complexity**:
   - **Constructor**: Building the prefix sum array has a time complexity of `O(n)`, where `n` is the size of `w`.
   - **pickIndex**: Each call to `pickIndex` involves a binary search, which has a time complexity of `O(log n)`.
- **Space Complexity**:
   - **Constructor**: The constructor requires `O(n)` space to store the prefix sum array `wc`.

### Conclusion

This approach is efficient and effective for solving the weighted random index selection problem:
- The prefix sum array allows proportional selection by creating probability intervals.
- Binary search provides a fast way to locate the correct index based on a random value, ensuring that each index is selected in proportion to its weight.
  
This solution is optimal in both time and space for handling random weighted selections efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/random-pick-with-weight/description/)

---
{{< youtube oYjDXfo-mt0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
