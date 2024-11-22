
+++
authors = ["grid47"]
title = "Leetcode 2717: Semi-Ordered Permutation"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2717: Semi-Ordered Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "u4bKt4MBHUU"
youtube_upload_date="2023-06-04"
youtube_thumbnail="https://i.ytimg.com/vi/u4bKt4MBHUU/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int semiOrderedPermutation(vector<int>& A) {
        int n = A.size(), 
        i = find(A.begin(), A.end(), 1) - A.begin(), 
        j = find(A.begin(), A.end(), n) - A.begin();
        return i + n - 1 - j - (i > j);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks for the number of moves required to transform a given permutation into a semi-ordered permutation. A **semi-ordered permutation** is a permutation where the smallest element `1` is at the beginning and the largest element `n` is at the end of the sequence. The goal is to determine how many moves are necessary to make the permutation semi-ordered, given that you can only move elements around (swap them) to achieve this order.

### Approach

The key observation here is that we need to find the positions of the smallest element (1) and the largest element (n) in the array, and then figure out how much effort is required to move them into the correct positions: 1 should be at the beginning (index 0), and n should be at the end (index `n-1`). The number of moves is influenced by the relative order of these two elements in the original array. Specifically:

1. We need to find the positions of `1` and `n`.
2. We calculate how far `1` is from the start of the array, and how far `n` is from the end of the array.
3. We account for the case when `1` is to the right of `n` in the original array, because in such cases, moving `1` to the start and `n` to the end causes an overlap of the two elements, which reduces the total number of required moves.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables and Find Positions of 1 and n
```cpp
int n = A.size(),
    i = find(A.begin(), A.end(), 1) - A.begin(),
    j = find(A.begin(), A.end(), n) - A.begin();
```
- `n = A.size()`: This retrieves the size of the array, which is the total number of elements in the permutation.
- `i = find(A.begin(), A.end(), 1) - A.begin()`: This line finds the position of `1` in the array. `find` returns an iterator to the first occurrence of `1`, and `- A.begin()` converts the iterator to the index of `1`.
- `j = find(A.begin(), A.end(), n) - A.begin()`: Similarly, this finds the position of `n` in the array.

#### Step 2: Calculate the Number of Moves
```cpp
return i + n - 1 - j - (i > j);
```
- `i + n - 1 - j`: This computes the total number of moves required to bring `1` to the front and `n` to the end, assuming that `i` is the position of `1` and `j` is the position of `n`.
  - `i` represents how far `1` is from the front of the array.
  - `n - 1 - j` represents how far `n` is from the end of the array.
  - Adding these two gives us the total number of moves required if there were no overlap between `1` and `n`.
- `(i > j)`: If `1` is found after `n` (i.e., `i > j`), we subtract 1 from the total moves because the positions of `1` and `n` will overlap once we move `1` to the front and `n` to the back. This overlap reduces the number of moves by one.

### Complexity

#### Time Complexity
- **O(n)**: The time complexity of this solution is **O(n)**, where `n` is the size of the array. The `find` operation to locate the positions of `1` and `n` takes linear time, and since we only traverse the array once to find the positions, the overall time complexity is linear.

#### Space Complexity
- **O(1)**: The space complexity is **O(1)**, because we are only using a constant amount of extra space (just a few integer variables to store the positions of `1` and `n`, and the size of the array).

### Conclusion

The solution efficiently computes the number of moves required to convert a permutation into a semi-ordered permutation, where the smallest element `1` is at the front and the largest element `n` is at the end. The approach works in linear time by simply finding the positions of `1` and `n` and calculating the number of moves based on their relative positions. This is an optimal solution with a time complexity of **O(n)** and space complexity of **O(1)**.

[`Link to LeetCode Lab`](https://leetcode.com/problems/semi-ordered-permutation/description/)

---
{{< youtube u4bKt4MBHUU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
