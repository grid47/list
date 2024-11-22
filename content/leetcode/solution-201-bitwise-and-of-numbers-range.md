
+++
authors = ["grid47"]
title = "Leetcode 201: Bitwise AND of Numbers Range"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 201: Bitwise AND of Numbers Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/201.webp"
youtube = "vZkutwUrPgE"
youtube_upload_date="2020-04-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/vZkutwUrPgE/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/201.webp" 
    alt="A series of overlapping circles, each representing a number, with a soft intersection of glowing bits in the middle."
    caption="Solution to LeetCode 201: Bitwise AND of Numbers Range Problem"
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
    int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    
    while(right != left)
    {
        right >>= 1 ;
        left  >>= 1;
        shift++;
    }
    
    return right << shift;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

We’re tasked with calculating the **bitwise AND** of all the numbers between `left` and `right`, inclusive. Given two integers `left` and `right`, the goal is to compute the result of applying the **bitwise AND** operation to all the numbers in the range.

For example:
- **Input:** `left = 5`, `right = 7`
- **Output:** `4`

**Explanation:**
- The numbers in the range from 5 to 7 are: `5, 6, 7`.
- The **bitwise AND** of these numbers: `5 & 6 & 7 = 4`.

---

### 🧠 Approach

The **bitwise AND** operation works by comparing each bit of the numbers. A `1` in the result is set only if all corresponding bits of the numbers being compared are `1`. For a large range of numbers, iterating over each one could be inefficient.

But, don’t worry! We can optimize our approach based on a few key observations:

#### 1. **Identifying the Common Prefix**:
The bitwise AND result for all numbers between `left` and `right` depends only on the **common binary prefix** of `left` and `right`. If we keep shifting both numbers to the right, the differing bits will gradually disappear. Once they’re equal, we’ve found the common prefix.

#### 2. **Bitwise Shifting**:
By repeatedly shifting `left` and `right` to the right (dividing by 2), we move toward making them equal. The number of shifts required to make them equal tells us the position of the common prefix. After that, we just shift `right` back to the left to restore the prefix.

This clever trick means we don’t need to check each number in the range, making our solution super efficient!

---

### 🔨 Step-by-Step Code Breakdown

Let’s walk through how to implement this approach:

#### Step 1: Initialize the Shift Counter
```cpp
int shift = 0;
```
- We initialize a variable `shift` to 0. This will track how many times we need to shift `left` and `right` to the right until they become equal.

#### Step 2: Right Shift Until `left` and `right` are Equal
```cpp
while(right != left)
{
    right >>= 1;
    left >>= 1;
    shift++;
}
```
- The `while` loop continues until `left` and `right` are equal.
- Each iteration shifts both `left` and `right` to the right by 1. Think of this as cutting each number in half and moving its bits one position to the right.
- We increment the `shift` counter as we keep shifting.
- Once `left` and `right` become equal, they now share the same common prefix in their binary representation.

#### Step 3: Shift Back to the Left
```cpp
return right << shift;
```
- After the loop, both `left` and `right` are equal, and we now shift `right` back to the left by the number of shifts we counted. This restores the common binary prefix to its original position.
- The result of this operation is the **bitwise AND** of all numbers between `left` and `right`.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **O(log(max(left, right))):** The `while` loop runs while `left` and `right` are not equal. In each iteration, both numbers are halved (right-shifted). The number of iterations needed is proportional to the number of bits in the larger of the two numbers. Since the number of bits is roughly `log(x)`, where `x` is the larger number, the time complexity is O(log(max(left, right))).

#### Space Complexity:
- **O(1):** We only use a constant amount of extra space for `shift`, `left`, and `right`. No additional data structures are required, so the space complexity is constant.

---

### 🏁 Conclusion

This solution is a game-changer! By using bitwise operations and focusing on the **common binary prefix** of `left` and `right`, we avoid the need to iterate through every number in the range. This makes the approach super efficient, especially for large ranges.

#### Key Takeaways:
1. **Efficiency:** The algorithm runs in O(log(max(left, right))) time, making it perfect for large values of `left` and `right`.
2. **Space Optimization:** With O(1) space complexity, it’s optimal for environments where memory is limited.
3. **Bitwise Power:** Shifting bits around allows us to achieve the desired result in a neat, optimized way.

This solution is **elegant** and **efficient**, showing that sometimes the best way to solve a problem is with a little clever thinking. Keep up the great work! 👏

[`Link to LeetCode Lab`](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)

---
{{< youtube vZkutwUrPgE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
