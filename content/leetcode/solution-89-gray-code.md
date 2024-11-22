
+++
authors = ["grid47"]
title = "Leetcode 89: Gray Code"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 89: Gray Code in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/89.webp"
youtube = "k5UYQtKXJGo"
youtube_upload_date="2022-02-06"
youtube_thumbnail="https://i.ytimg.com/vi/k5UYQtKXJGo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/89.webp" 
    alt="A peaceful, spiraling Gray code sequence glowing softly as it shifts from one value to the next."
    caption="Solution to LeetCode 89: Gray Code Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};

        for (int idx = 0; idx < n; idx++) {
            int sz = res.size();
            for (int jdx = sz - 1; jdx >= 0; jdx--)
                res.push_back(res[jdx] | (1 << idx));
        }

        return res;        
    }
};
{{< /highlight >}}
---

### 📝 **Gray Code Sequence Problem**

Given an integer `n`, the task is to generate the Gray Code sequence for `n` bits. In this sequence, each number differs from the previous one by exactly one bit.

#### Example:
- For `n = 2`, the Gray Code sequence is: `[0, 1, 3, 2]`
- For `n = 3`, the Gray Code sequence is: `[0, 1, 3, 2, 6, 7, 5, 4]`

### 🔍 **Approach**

To generate the Gray Code sequence efficiently, we use an **iterative approach**. The key observation is:
- The Gray Code for `n` bits can be derived by reflecting the Gray Code for `n-1` bits and prefixing the original values with `0` and the reflected values with `1`.

#### Step-by-Step Process:
1. **Base Case**: For `n = 0`, the Gray Code sequence is simply `[0]`.
2. **Iterative Generation**:
   - For each bit position from `1` to `n`, reflect the previous sequence, prefix the original numbers with `0`, and the reflected numbers with `1`.
   - This step effectively builds the sequence incrementally, adding one bit at a time.

### 🧑‍💻 **Code Breakdown**

#### Step 1: Initialize the Result

```cpp
vector<int> res = {0};
```
We start with the base case where the Gray Code sequence for `0` bits is just `[0]`.

#### Step 2: Iterating Over the Bit Positions

```cpp
for (int idx = 0; idx < n; idx++) {
```
We loop through each bit position (from `0` to `n-1`). For each iteration, the sequence is updated to include Gray Code for the current number of bits.

#### Step 3: Reflecting the Sequence

```cpp
int sz = res.size();
for (int jdx = sz - 1; jdx >= 0; jdx--)
    res.push_back(res[jdx] | (1 << idx));
```

- The `sz = res.size()` stores the current size of the sequence.
- The inner loop processes the sequence in reverse order. For each element in the current sequence, we add a new value by setting the `idx`-th bit to `1` using the bitwise OR operation `res[jdx] | (1 << idx)`. This step mirrors the sequence and adds the new bit to the reflected part.

#### Step 4: Return the Final Result

```cpp
return res;
```
After processing all bit positions, the sequence `res` contains the Gray Code sequence for `n` bits, which is returned.

### ⏱ **Complexity Analysis**

#### Time Complexity:
The time complexity is **O(2^n)** because:
- The size of the Gray Code sequence for `n` bits is `2^n`.
- Each iteration of the outer loop processes the sequence by reflecting it and adding `1` to each value, so the total number of operations is proportional to the size of the sequence.

Thus, the time complexity is **O(2^n)**.

#### Space Complexity:
The space complexity is also **O(2^n)**, as we store the Gray Code sequence in a vector of size `2^n`.

### 🎯 **Conclusion**

This solution generates the Gray Code sequence for `n` bits using an iterative approach. By reflecting the sequence and adjusting each number by adding one bit at a time, the algorithm constructs the sequence efficiently. With both time and space complexities of **O(2^n)**, this approach is optimal for generating the Gray Code sequence, especially for larger values of `n`.

---

#### 🌟 **Final Thoughts**:
This solution is highly efficient and can be used to generate Gray Code sequences for a wide range of inputs. Keep practicing these types of problems to further enhance your understanding of bit manipulation and iterative algorithms!

[`Link to LeetCode Lab`](https://leetcode.com/problems/gray-code/description/)

---
{{< youtube k5UYQtKXJGo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
