
+++
authors = ["grid47"]
title = "Leetcode 2640: Find the Score of All Prefixes of an Array"
date = "2024-02-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2640: Find the Score of All Prefixes of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xp413jTlTNk"
youtube_upload_date="2023-04-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Xp413jTlTNk/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int mx = nums[0];
        long long sum = 0;
        int n = nums.size();
        vector<long long> ans(n, 0);
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            int scr = nums[i] + mx;
            ans[i] = i == 0? scr: ans[i - 1] + scr;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to calculate the prefix scores for a given array `nums`. The prefix score at index `i` is defined as the sum of all elements from index `0` to `i`, where each element in the range contributes the sum of the element and the maximum value from index `0` to `i`. We need to return a vector where each element represents the prefix score at the corresponding index.

### Approach

To solve the problem efficiently, the approach leverages a running maximum for the elements from the start up to the current index and calculates the prefix scores progressively as we traverse through the array. Here's the breakdown of the approach:

1. **Initialize the Required Variables**:
   - We start by initializing `mx`, which keeps track of the maximum element encountered so far. This helps us compute the score for each element.
   - `sum` keeps a running total of the prefix scores.
   - An array `ans` of the same size as `nums` is used to store the prefix scores for each index.

2. **Iterate Over the Array**:
   - For each element `nums[i]`, we update `mx` to be the maximum between the current `mx` and `nums[i]`. This ensures that `mx` always holds the largest number seen up to the current index.
   
   - For each element `nums[i]`, calculate the score `scr` as `nums[i] + mx`. This represents the contribution of the current element and the maximum value encountered up to that point.
   
   - The prefix score at index `i` is the sum of the current score and the prefix score at the previous index, except for the first index where it is just the score at that index.

3. **Return the Result**:
   - After iterating through the entire array, the `ans` vector contains the prefix scores for all indices, which is then returned.

### Code Breakdown (Step by Step)

#### 1. **Initialization of Variables**

We first initialize the necessary variables:

- `mx`: This variable stores the maximum element encountered so far. It is initialized to `nums[0]`, the first element of the array, because the first element will be the maximum for the first index.
- `sum`: This variable is used to accumulate the scores as we calculate the prefix scores, although it’s not directly used here.
- `ans`: This vector holds the final result, initialized to store `n` values, each set to zero initially.

```cpp
int mx = nums[0];  // Initialize max to the first element
long long sum = 0;  // Initialize sum to 0 (not directly used)
int n = nums.size();  // Size of the input array
vector<long long> ans(n, 0);  // Initialize result vector to store prefix scores
```

#### 2. **Iterate Over the Array**

Next, we loop through each element in the array `nums`:

- **Updating the maximum**: For each element, we update `mx` to the larger of the current `mx` and the current element `nums[i]`.
- **Calculating the score**: We calculate the score for the current element as the sum of the element and the current `mx`. This is the contribution of `nums[i]` to the prefix score.
- **Storing the prefix score**: For the first element (`i == 0`), the prefix score is just the score of the current element. For subsequent elements, the prefix score is the cumulative sum of scores up to the previous element plus the score of the current element.

```cpp
for(int i = 0; i < n; i++) {
    mx = max(mx, nums[i]);  // Update max value encountered so far
    int scr = nums[i] + mx;  // Calculate score for the current element
    ans[i] = i == 0 ? scr : ans[i - 1] + scr;  // Compute prefix score
}
```

#### 3. **Return the Result**

Once the loop finishes, the `ans` vector contains the prefix scores for all indices. We then return the vector.

```cpp
return ans;
```

### Complexity

#### Time Complexity:
- **Looping through the array**: The solution involves a single loop over the array `nums`, iterating `n` times (where `n` is the size of the input array).
- **Each iteration** performs constant-time operations such as calculating the maximum and the score for the current element.

Thus, the overall time complexity is \(O(n)\), where \(n\) is the number of elements in the input array.

#### Space Complexity:
- We use a vector `ans` of size `n` to store the prefix scores, so the space complexity is \(O(n)\).
- Other variables like `mx`, `sum`, and `scr` use constant space, so they do not affect the space complexity.

Thus, the overall space complexity is \(O(n)\), where \(n\) is the number of elements in the input array.

### Conclusion

This solution efficiently computes the prefix scores by maintaining a running maximum of the elements and progressively calculating the scores. By using a single loop to process the array and updating the prefix scores on-the-fly, the approach ensures an optimal \(O(n)\) time complexity, making it suitable for large input arrays. The space complexity is also linear, as we only store the result vector and a few auxiliary variables. This method is both time-efficient and space-efficient for the problem at hand.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/)

---
{{< youtube Xp413jTlTNk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
