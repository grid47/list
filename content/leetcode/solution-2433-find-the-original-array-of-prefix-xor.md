
+++
authors = ["grid47"]
title = "Leetcode 2433: Find The Original Array of Prefix Xor"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2433: Find The Original Array of Prefix Xor in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "idcT-p_DDrI"
youtube_upload_date="2023-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/idcT-p_DDrI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.size());
        res[0] = pref[0];
        for(int i = 1; i < pref.size(); i++)
            res[i] = pref[i] ^ pref[i - 1];
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array `pref` of integers where `pref[i]` is the cumulative XOR (exclusive OR) of elements from `arr[0]` to `arr[i]` (inclusive), your task is to recover the original array `arr` from the given `pref` array. Specifically, we are tasked with finding the array `arr` such that:

- `arr[0] = pref[0]`
- `arr[1] = pref[1] ^ pref[0]`
- `arr[2] = pref[2] ^ pref[1]`
- ...
- `arr[i] = pref[i] ^ pref[i-1]`
  
The XOR operation is used to extract the values in `arr` from the cumulative `pref` array.

### Approach

To solve this problem efficiently, we need to understand the properties of the XOR operation. XOR (exclusive OR) is a bitwise operation that has some important properties:
1. **Identity**: For any integer `a`, `a ^ 0 = a`.
2. **Self-inverse**: For any integer `a`, `a ^ a = 0`.
3. **Commutative**: The order of XOR does not matter, i.e., `a ^ b = b ^ a`.
4. **Associative**: XOR can be grouped in any way, i.e., `a ^ (b ^ c) = (a ^ b) ^ c`.

The problem provides us with the cumulative XOR values in the `pref` array, and we need to deduce the individual elements of the original array `arr`. Specifically, we can use the following relationship:

- `arr[0] = pref[0]`
- `arr[i] = pref[i] ^ pref[i-1]` for all `i > 0`.

This relationship works because XOR is self-inverse. For example, if we know the cumulative XOR up to index `i`, we can get the value of `arr[i]` by "undoing" the cumulative XOR of all previous elements using the XOR operation. The cumulative XOR value at index `i` (`pref[i]`) is the XOR of all the elements up to that index. Therefore, by XORing `pref[i]` with `pref[i-1]`, we effectively isolate the value of `arr[i]`.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the result array
```cpp
vector<int> res(pref.size());
```
- We initialize a vector `res` with the same size as the `pref` array. This will store the resulting array `arr` that we are going to compute.

#### Step 2: Assign the first element
```cpp
res[0] = pref[0];
```
- The first element of the result array `arr[0]` is simply equal to the first element of the `pref` array, because there is no previous element to XOR with.

#### Step 3: Calculate subsequent elements using XOR
```cpp
for(int i = 1; i < pref.size(); i++)
    res[i] = pref[i] ^ pref[i - 1];
```
- For each subsequent element (from index 1 onwards), we use the XOR of the current value in `pref` and the previous value in `pref` to compute the corresponding element in `arr`. This works because of the XOR properties described earlier, specifically the self-inverse property, which allows us to "undo" the cumulative XOR up to the previous index and isolate the current value.

#### Step 4: Return the result array
```cpp
return res;
```
- After iterating through all elements of the `pref` array and computing the corresponding values of `arr`, we return the result array `res`.

### Complexity

#### Time Complexity:
The time complexity of this solution is **O(n)**, where `n` is the size of the `pref` array. This is because we only need a single pass through the array to compute the values of `arr`, and each operation within the loop (XOR and assignment) takes constant time.

#### Space Complexity:
The space complexity is **O(n)**, where `n` is the size of the `pref` array. This is because we use an additional array `res` of size `n` to store the result.

### Conclusion

This solution efficiently recovers the original array `arr` from the cumulative XOR array `pref` by exploiting the properties of the XOR operation. The time complexity of **O(n)** and space complexity of **O(n)** make this approach suitable for large input sizes. By understanding how the XOR operation works and using its properties, we can easily reverse the cumulative XOR operation and recover the original array. The problem can be solved in linear time, making it an optimal solution for this task.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/)

---
{{< youtube idcT-p_DDrI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
