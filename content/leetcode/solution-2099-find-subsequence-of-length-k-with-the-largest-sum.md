
+++
authors = ["grid47"]
title = "Leetcode 2099: Find Subsequence of Length K With the Largest Sum"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2099: Find Subsequence of Length K With the Largest Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QXvaOym_Awk"
youtube_upload_date="2021-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QXvaOym_Awk/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> v(nums.begin(), nums.end());
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());
        int cnt = count(v.begin(), v.begin() + k, v[k - 1]);
        
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
            if((nums[i] > v[k - 1]) ||
               (nums[i] == v[k - 1] && (cnt-- > 0)))
                res.push_back(nums[i]);
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find a subsequence of length `k` from an integer array `nums` that has the highest possible sum. A subsequence is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements. The output should maintain the relative order of the elements in `nums`.

### Approach

To solve this problem efficiently, we can leverage the following approach:

1. **Clone and Partially Sort the Array**: To find the `k` largest elements, we start by creating a copy of the `nums` array. This allows us to work with the values without modifying the original array’s structure.

2. **Use `nth_element` for Efficient Partial Sorting**: We use `nth_element` on the copied array to ensure that the `k` largest elements are positioned in the first `k` places, sorted in descending order. The function `nth_element` achieves this with average-case O(n) complexity. This helps us quickly find the k largest elements without fully sorting the array, which would take O(n log n) time.

3. **Handle Duplicates Carefully**: The `nth_element` function sorts the `k` largest elements but may include duplicate values around the boundary between the k-th and (k+1)-th elements. We handle this by counting the number of times the k-th largest value appears within the selected range.

4. **Collect the Elements in Original Order**: After identifying the `k` largest values, we iterate through the original array to select elements for the final result. For each element in `nums`:
   - If it is larger than the k-th largest value in our partial array, it is included in the result.
   - If it equals the k-th largest value and the count has not been fully used, we also include it.

5. **Return the Result**: The result array is built in the same order as `nums`, containing the `k` largest elements with maximum sum and correct relative order.

This approach is optimal for efficiently finding and arranging the desired subsequence while maintaining the necessary order.

### Code Breakdown (Step by Step)

Let’s walk through the code to see how each part works in detail.

1. **Clone and Partially Sort the Array**:
   ```cpp
   vector<int> v(nums.begin(), nums.end());
   nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());
   ```
   - Here, we create a copy of `nums` called `v` to hold the elements that we want to partially sort.
   - Using `nth_element`, we position the `k` largest elements at the beginning of `v`, with `v[k - 1]` representing the k-th largest value. The `greater<int>()` comparator ensures that the elements are arranged in descending order for the first `k` elements.

2. **Count Occurrences of the k-th Largest Value**:
   ```cpp
   int cnt = count(v.begin(), v.begin() + k, v[k - 1]);
   ```
   - Here, we count how many times the k-th largest value (`v[k - 1]`) appears in the first `k` elements of `v`. This is necessary to manage duplicates correctly when we later select elements from `nums`.

3. **Collect Elements in the Original Order**:
   ```cpp
   vector<int> res;
   for(int i = 0; i < nums.size(); i++)
       if((nums[i] > v[k - 1]) || (nums[i] == v[k - 1] && (cnt-- > 0)))
           res.push_back(nums[i]);
   ```
   - We initialize an empty vector `res` to store the final result.
   - We iterate over `nums`, checking each element to see if it should be included in `res`:
     - If `nums[i]` is greater than the k-th largest value, it is included in `res`.
     - If `nums[i]` equals the k-th largest value, we include it only if our `cnt` variable indicates that we still need this value (by checking if `cnt-- > 0`).

4. **Return the Result**:
   ```cpp
   return res;
   ```
   - After collecting the required elements in the correct order, we return `res`, which now contains the `k` largest elements with maximum sum from `nums`, maintaining their original order.

### Complexity

- **Time Complexity**: The algorithm has an average time complexity of O(n), where `n` is the number of elements in `nums`. This is due to the `nth_element` function, which operates in O(n) on average. The subsequent loop to collect the result has O(n) complexity as well.
- **Space Complexity**: The algorithm uses O(n) additional space, as we create a copy of `nums` and store the result in `res`.

### Conclusion

This solution leverages efficient sorting techniques and a careful selection process to find a subsequence with maximum sum in optimal time. The use of `nth_element` allows us to quickly obtain the `k` largest elements without fully sorting the array, and the counting mechanism ensures that duplicates are handled accurately. This approach highlights the importance of balancing efficiency and correctness in algorithm design, especially in competitive programming and interview settings where both optimal time complexity and precise output are essential.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/)

---
{{< youtube QXvaOym_Awk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
