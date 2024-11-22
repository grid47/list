
+++
authors = ["grid47"]
title = "Leetcode 2733: Neither Minimum nor Maximum"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2733: Neither Minimum nor Maximum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "n6Wg_vntUAA"
youtube_upload_date="2023-06-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/n6Wg_vntUAA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findNonMinOrMax(vector<int>& A) {
        if (A.size() < 3)
            return -1;
        int mx = max(A[0], max(A[1], A[2])), mn = min(A[0], min(A[1], A[2]));
        for (int i = 0; i < 3; ++i)
            if (mn < A[i] && A[i] < mx)
                return A[i];
        return -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find an element in an array that is neither the minimum nor the maximum. If such an element exists, return it; otherwise, return -1. However, there is a constraint that the size of the array is at least 3. If the size of the array is less than 3, the solution must return -1 as it's impossible to find a middle element.

The challenge becomes simpler when we focus on the first three elements of the array because in any array of at least 3 elements, if a non-minimum or non-maximum element exists, it must be one of the first three elements. This insight helps in optimizing the problem.

### Approach

To solve the problem efficiently, we can break it down into the following steps:

1. **Initial Check for Size**: If the array has fewer than 3 elements, return -1 right away because we cannot have a middle element to compare.
  
2. **Find the Maximum and Minimum of the First Three Elements**: Since we are interested in finding an element that is neither the maximum nor the minimum, the first logical step is to examine the first three elements of the array. In any array of size 3 or more, the answer (if it exists) must be one of the first three elements. Therefore, we calculate the minimum and maximum of the first three elements to narrow down our search.

3. **Check the Middle Element**: After identifying the minimum and maximum of the first three elements, iterate through these three elements and check if any of them lie between the minimum and maximum (i.e., they are not the minimum or maximum). This element will be the one that is neither the smallest nor the largest.

4. **Return the Result**: If an element is found that is neither the minimum nor the maximum, return that element. If no such element exists, return -1.

### Code Breakdown (Step by Step)

Let’s break the code into its key steps to understand the logic more clearly.

#### Step 1: Initial Size Check

```cpp
if (A.size() < 3)
    return -1;
```

- The first check in the code is to determine whether the size of the array is less than 3. If so, there is no way to find a middle element, as an array of less than 3 elements cannot have both a minimum and a maximum and still leave room for a non-minimum, non-maximum element. Hence, if the size is less than 3, the function returns -1 immediately.

#### Step 2: Find Maximum and Minimum of the First Three Elements

```cpp
int mx = max(A[0], max(A[1], A[2])), mn = min(A[0], min(A[1], A[2]));
```

- Here, we compute the maximum and minimum of the first three elements in the array. The reason we focus on just the first three elements is based on the realization that in any array of size 3 or greater, the element that is neither the minimum nor the maximum will be one of the first three elements. 

- We use the `max` and `min` functions to calculate the largest (`mx`) and smallest (`mn`) values among the first three elements.

#### Step 3: Iterate Through the First Three Elements to Find the Middle Element

```cpp
for (int i = 0; i < 3; ++i)
    if (mn < A[i] && A[i] < mx)
        return A[i];
```

- In this loop, we check each of the first three elements (`A[0]`, `A[1]`, `A[2]`). If an element is strictly greater than the minimum and strictly less than the maximum (i.e., it lies between the two), we return it immediately as the result.
  
- The condition `mn < A[i] && A[i] < mx` checks if the element is not the smallest or the largest, which means it is neither the minimum nor the maximum in the set of the first three elements. If such an element exists, we return it right away.

#### Step 4: Return -1 If No Valid Element is Found

```cpp
return -1;
```

- If none of the first three elements satisfy the condition (i.e., they are either the minimum or the maximum), we return -1, indicating that there is no non-minimum or non-maximum element in the first three elements.

### Complexity Analysis

#### Time Complexity

- **Initial Size Check**: The first step, checking whether the array size is less than 3, is done in constant time, \(O(1)\).
  
- **Finding Maximum and Minimum**: The calculation of the maximum and minimum of the first three elements also takes constant time, \(O(1)\), because we only need to compare three values.

- **Iteration Through First Three Elements**: The loop that checks each of the first three elements also runs in constant time, \(O(1)\).

Thus, the overall time complexity is \(O(1)\), which means that the function operates in constant time regardless of the size of the input array.

#### Space Complexity

- The space complexity is \(O(1)\) because we are only using a few variables (`mx`, `mn`, and the loop variable `i`) to store intermediate values. No extra space is used that grows with the size of the input array.

### Conclusion

The solution is optimal and runs in constant time, \(O(1)\), due to the use of simple comparisons and direct access to the first three elements of the array. It efficiently solves the problem by only focusing on the first three elements, where any element that is neither the minimum nor the maximum must exist. The code is easy to understand, concise, and works in constant time, making it suitable for large arrays as well. This is a perfect example of how recognizing problem constraints can lead to an efficient solution.

[`Link to LeetCode Lab`](https://leetcode.com/problems/neither-minimum-nor-maximum/description/)

---
{{< youtube n6Wg_vntUAA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
