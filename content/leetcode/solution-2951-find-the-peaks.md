
+++
authors = ["grid47"]
title = "Leetcode 2951: Find the Peaks"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2951: Find the Peaks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "zatlKoGhxCQ"
youtube_upload_date="2023-12-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/zatlKoGhxCQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        vector<int> res;
        for(int i = 1; i < nums.size() - 1; i++) {
            if((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
                res.push_back(i);            
        }

        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement:
The problem requires finding the indices of the "peaks" in an array. A peak is defined as an element in the array that is strictly greater than both its left and right neighbors. The goal is to return a list of indices where the peaks occur in the given array `nums`.

### Approach:
To solve this problem efficiently, we need to iterate through the array and identify positions where an element is greater than both its adjacent elements. We can solve this problem in a single pass through the array, starting from the second element and ending at the second-to-last element. This ensures that we don’t go out of bounds when checking neighboring elements.

#### Step-by-Step Approach:

1. **Initial Setup**: We initialize an empty vector `res` to store the indices of the peaks.

2. **Iterate through the Array**: We start from the second element and continue until the second-to-last element. This is because a peak must have both a left and a right neighbor to compare against, so the first and last elements cannot be peaks.

3. **Check for Peaks**: For each element `nums[i]`, we check if it is greater than both its left neighbor (`nums[i - 1]`) and its right neighbor (`nums[i + 1]`). If this condition is satisfied, it means that `nums[i]` is a peak, and we add the index `i` to the result vector `res`.

4. **Return the Result**: Once we finish iterating through the array, we return the vector `res` containing the indices of all the peaks.

### Code Breakdown:

#### 1. **Initialization of Result Vector**:
At the beginning of the function, we create an empty vector `res` to store the indices of the peaks.
```cpp
vector<int> res;
```
This will hold the result that will be returned at the end of the function.

#### 2. **Loop through the Array**:
We iterate over the array starting from the second element (`i = 1`) and ending at the second-to-last element (`nums.size() - 1`).
```cpp
for(int i = 1; i < nums.size() - 1; i++) {
```
This ensures that we check each element's left and right neighbors.

#### 3. **Check for Peak**:
Inside the loop, we check if the current element `nums[i]` is greater than both its left neighbor `nums[i - 1]` and its right neighbor `nums[i + 1]`.
```cpp
if((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
```
If this condition is true, it means that `nums[i]` is a peak.

#### 4. **Add the Peak Index**:
If the current element is a peak, we push the index `i` into the result vector `res`.
```cpp
res.push_back(i);
```

#### 5. **Return the Result**:
After the loop ends, we return the vector `res` that contains the indices of all the peaks found in the array.
```cpp
return res;
```

### Complexity:

#### Time Complexity:
The time complexity of this solution is **O(n)**, where `n` is the size of the input array `nums`. This is because we iterate through the array once, checking each element and its neighbors. The number of comparisons made for each element is constant, and we perform these comparisons only once per element.

- Iterating through the array takes **O(n)** time.
- Checking each element and its neighbors is done in constant time, so the total complexity is **O(n)**.

#### Space Complexity:
The space complexity of this solution is **O(1)** if we exclude the space used for the output. The only extra space we use is the `res` vector, which stores the indices of the peaks. Since we only store indices and the maximum number of peaks will be at most `n - 2` (because the first and last elements cannot be peaks), the space used by `res` is proportional to the number of peaks, which is at most `O(n)` in the worst case.

Thus, the space complexity is **O(n)** due to the storage of the result vector. If we exclude this output storage, the space complexity is **O(1)**.

### Conclusion:
This solution efficiently finds the indices of the peaks in the given array `nums` in linear time. It only requires a single pass through the array and performs a constant number of operations for each element. The space complexity is also minimal, only requiring space for the output vector, making this approach both time and space efficient. This method is well-suited for large arrays where we need to quickly identify the peaks without unnecessary computations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-peaks/description/)

---
{{< youtube zatlKoGhxCQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
