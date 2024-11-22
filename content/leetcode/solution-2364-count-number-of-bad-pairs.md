
+++
authors = ["grid47"]
title = "Leetcode 2364: Count Number of Bad Pairs"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2364: Count Number of Bad Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "alyDgY0FCiA"
youtube_upload_date="2022-08-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/alyDgY0FCiA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countBadPairs(vector<int>& nums, long cnt = 0) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
            cnt += i - mp[i - nums[i]]++;
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to count the number of "bad pairs" in an array of integers. A pair `(i, j)` is defined as bad if it satisfies two conditions:
- `j > i` (i.e., the second index `j` is greater than the first index `i`).
- `j - i` is **not** equal to `nums[j] - nums[i]` (the difference between the indices should not match the difference between the values at those indices).

In simpler terms, we need to count how many pairs of indices do not have the same difference between their indices and the difference between their corresponding values. The task requires an efficient way to calculate these bad pairs in a given list of integers.

### Approach

To solve this problem efficiently, a brute-force solution would involve checking each pair `(i, j)` for all pairs of indices in the array, which would be computationally expensive with a time complexity of `O(n^2)`. Instead, an optimized solution uses a **hash map** (or unordered map) to track differences between index `i` and the value `nums[i]` efficiently. By recognizing that a good pair `(i, j)` satisfies the condition `i - nums[i] = j - nums[j]`, we can reduce the problem to tracking these differences and counting how many times each difference has appeared before. 

1. **Key Observation:**
   - For each index `i`, the difference `i - nums[i]` can be used as a key to identify whether a pair `(i, j)` is "good" or "bad." If `i - nums[i]` has appeared before at a previous index, it means the pair involving the current index and the previous index is a "good pair."
   
2. **Using a Hash Map:**
   - We use a hash map to store how many times each difference `i - nums[i]` has appeared before. By doing so, we can quickly calculate how many good pairs exist for a given index `i`, and thus determine the number of bad pairs.

3. **Counting Bad Pairs:**
   - The total number of pairs `(i, j)` for which `j > i` is `n(n-1)/2` where `n` is the length of the array.
   - The number of good pairs is determined by counting how many times the difference `i - nums[i]` has appeared before. The bad pairs can be obtained by subtracting the count of good pairs from the total number of pairs.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
long long countBadPairs(vector<int>& nums, long cnt = 0) {
    unordered_map<int, int> mp;
```

- We define the function `countBadPairs` which accepts a vector `nums` representing the array and an optional variable `cnt` (initialized to `0`) to store the count of bad pairs.
- We also initialize an unordered map `mp` that will be used to store the difference `i - nums[i]` as the key and its frequency as the value. This helps in tracking the number of times a certain difference has occurred before.

#### Step 2: Iterate Through the Array

```cpp
for(int i = 0; i < nums.size(); i++) {
    cnt += i - mp[i - nums[i]]++;
}
```

- The loop runs through each element in the `nums` array by index `i`.
- The expression `i - nums[i]` is calculated, which is the difference between the index `i` and the value at that index `nums[i]`. This difference is used as a key in the unordered map `mp`.
- `mp[i - nums[i]]` is the number of times this difference has occurred before. We add this number to `cnt` because these are the "good pairs" (i.e., the pairs that satisfy the condition `i - nums[i] = j - nums[j]`).
- We then increment the count of this difference in the map (`mp[i - nums[i]]++`). This ensures that we keep track of how many times this difference has occurred for future indices.

#### Step 3: Return the Result

```cpp
return cnt;
```

- After processing all the elements in the array, the variable `cnt` contains the total number of bad pairs.
- We return `cnt` as the result, which represents the number of bad pairs in the array.

### Complexity

#### Time Complexity:
- The algorithm iterates through the array `nums` exactly once, performing constant-time operations (such as updating the hash map and performing arithmetic) for each element. 
- The operations for inserting and retrieving values from an unordered map (`mp`) are, on average, O(1). 
- Therefore, the time complexity is `O(n)`, where `n` is the length of the array `nums`.

#### Space Complexity:
- The space complexity is dominated by the hash map `mp`, which stores the differences `i - nums[i]` and their frequencies. In the worst case, the number of unique differences could be equal to the length of the array `n`, leading to a space complexity of `O(n)`.

### Conclusion

This solution efficiently counts the number of bad pairs in an array by leveraging a hash map to track the frequency of differences between the index `i` and the value `nums[i]`. By counting good pairs and subtracting them from the total number of pairs, we can compute the number of bad pairs efficiently. This approach has a linear time complexity `O(n)` and is much more efficient than a brute-force solution. 

The space complexity is also `O(n)` due to the hash map, which stores the differences. This solution is well-suited for handling larger arrays, providing an optimal solution with respect to both time and space.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-bad-pairs/description/)

---
{{< youtube alyDgY0FCiA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
