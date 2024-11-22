
+++
authors = ["grid47"]
title = "Leetcode 2670: Find the Distinct Difference Array"
date = "2024-02-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2670: Find the Distinct Difference Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ikDNBcVaq6Y"
youtube_upload_date="2023-05-07"
youtube_thumbnail="https://i.ytimg.com/vi/ikDNBcVaq6Y/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        map<int, int> l, r;
        for(int i = 0; i < n; i++) {
            r[nums[i]]++;
        }

        for(int i = 0; i < n; i++) {
            r[nums[i]]--;
            if(r[nums[i]] == 0) r.erase(nums[i]);
            l[nums[i]]++;
            ans[i] = l.size() - r.size();
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to compute the distinct difference array for a given array `nums`. For each index `i` in the array, we need to calculate the difference between the number of distinct elements in the left subarray (`nums[0]` to `nums[i]`) and the number of distinct elements in the right subarray (`nums[i+1]` to `nums[n-1]`). The result should be an array of the same length as the input array, where each element represents this distinct difference for the corresponding index.

### Approach

To solve this problem efficiently, we can make use of two hash maps to track the distinct elements on the left side (`l`) and right side (`r`) of the current index as we iterate over the array.

1. **Initial Setup**:
   - Use two hash maps `l` and `r` to store the frequencies of elements on the left and right sides of the current index.
   - Initially, `r` contains all elements of the array, and `l` is empty.

2. **Iterate Over the Array**:
   - For each index `i`:
     - Move the element `nums[i]` from `r` (right side) to `l` (left side).
     - Update the distinct element count on both sides.
     - Calculate the distinct difference as the difference between the sizes of the two sets (`l.size()` and `r.size()`).

3. **Efficiency**:
   - By using hash maps (`l` and `r`), we can efficiently track the distinct elements on both sides of each index.
   - The key observation is that we can update these sets incrementally as we move through the array, rather than recalculating distinct counts for each subarray from scratch.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
vector<int> distinctDifferenceArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    map<int, int> l, r;
```

- **Line 1**: We define the function `distinctDifferenceArray` that takes the input vector `nums` as its parameter.
- **Line 2**: We retrieve the size of the input array `nums` and store it in the variable `n`.
- **Line 3**: We initialize an output vector `ans` of size `n`, initialized to 0. This will store the final result.
- **Line 4**: Two maps, `l` and `r`, are defined to keep track of the frequency of elements on the left and right sides of the current index.

#### Step 2: Populate the Right Map

```cpp
for(int i = 0; i < n; i++) {
    r[nums[i]]++;
}
```

- **Lines 5-6**: We iterate over the input array `nums` and populate the `r` map. The key of `r` is the element in `nums`, and the value is the count of how many times that element appears in the array. After this loop, `r` contains the frequency of each element in the entire array, representing the right subarray.

#### Step 3: Compute the Distinct Difference for Each Index

```cpp
for(int i = 0; i < n; i++) {
    r[nums[i]]--;
    if(r[nums[i]] == 0) r.erase(nums[i]);
    l[nums[i]]++;
    ans[i] = l.size() - r.size();
}
```

- **Lines 7-9**: We now iterate over each index `i` in the array `nums`:
  - `r[nums[i]]--`: We decrement the frequency of `nums[i]` in the `r` map. This is because we are now moving this element from the right subarray to the left subarray.
  - `if(r[nums[i]] == 0) r.erase(nums[i]);`: If the frequency of `nums[i]` in `r` becomes zero, we remove it from the map. This ensures that `r` only contains the elements that are still present on the right side.
  - `l[nums[i]]++`: We increment the frequency of `nums[i]` in the `l` map, indicating that the element has moved to the left subarray.
  - `ans[i] = l.size() - r.size();`: The distinct difference for index `i` is computed as the difference between the sizes of the two maps (`l.size()` and `r.size()`). The size of `l` gives the number of distinct elements on the left, and the size of `r` gives the number of distinct elements on the right.

#### Step 4: Return the Result

```cpp
return ans;
```

- **Line 10**: After processing all the elements in `nums`, we return the `ans` array, which contains the distinct difference for each index.

### Complexity

#### Time Complexity:
- The time complexity is dominated by the two loops:
  - The first loop, where we populate the `r` map, takes **O(n)** time, where `n` is the size of the input array.
  - The second loop, where we compute the distinct difference for each index, also takes **O(n)** time.
  - Each operation on a map (insertion, deletion, and lookup) takes **O(log n)** time, but since each element is processed once, the overall time complexity remains **O(n log n)**.

#### Space Complexity:
- The space complexity is **O(n)** because we use two maps (`l` and `r`) to store the frequencies of elements. In the worst case, both maps could contain all the elements in the array, requiring space proportional to `n`.

### Conclusion

This solution efficiently computes the distinct difference array for the given array `nums`. By maintaining two maps (`l` for the left side and `r` for the right side), we can update the distinct counts as we iterate over the array, which allows us to avoid recomputing the distinct elements from scratch for each index. The time complexity of **O(n log n)** makes this solution feasible for large arrays, and the space complexity of **O(n)** ensures that it uses memory efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-distinct-difference-array/description/)

---
{{< youtube ikDNBcVaq6Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
