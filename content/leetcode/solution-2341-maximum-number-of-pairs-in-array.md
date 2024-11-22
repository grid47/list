
+++
authors = ["grid47"]
title = "Leetcode 2341: Maximum Number of Pairs in Array"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2341: Maximum Number of Pairs in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "9KeeDZ6tcy4"
youtube_upload_date="2022-07-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/9KeeDZ6tcy4/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  // even counter
  vector<int> numberOfPairs(vector<int>& nums) {
      int cnt[101] = {}, pairs = 0;
      for (int n : nums)
          pairs += ++cnt[n] % 2 == 0 ? 1 : 0;
      return { pairs, (int)nums.size() - pairs * 2 };
  }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires determining how many pairs of identical elements can be formed from an array of integers, and how many elements remain unpaired. The goal is to return two values:
1. **The number of pairs**: A pair is defined as two identical elements.
2. **The number of leftover elements**: These are the elements that cannot form a pair.

### Approach

To solve the problem efficiently, we use the following steps:
1. **Count the Occurrences of Each Element**: We need to keep track of how many times each element appears in the input array.
2. **Pairing Process**: As we count the occurrences of elements, we can form pairs. Specifically, for each element that appears an even number of times, we can form pairs, while the remainder will be left as unpaired elements.
3. **Remaining Elements**: For elements that appear an odd number of times, one element will remain unpaired after forming as many pairs as possible.

We will use a fixed-size array `cnt` where each index represents a possible value in the range [0, 100] (since the problem statement assumes the elements of `nums` lie in this range).

### Code Breakdown (Step by Step)

#### 1. **Initialization**
```cpp
int cnt[101] = {}, pairs = 0;
```
- **`cnt[101]`:** This array is used to store the count of each integer in the input array. Since the elements of `nums` are guaranteed to be between 0 and 100, an array of size 101 (for indices 0 to 100) is enough to track the frequency of each number.
- **`pairs`:** This variable keeps track of the total number of pairs formed. Initially, it's set to 0.

#### 2. **Counting Occurrences and Forming Pairs**
```cpp
for (int n : nums)
    pairs += ++cnt[n] % 2 == 0 ? 1 : 0;
```
- **`for (int n : nums)`:** This loop iterates over each number `n` in the input array `nums`.
- **`++cnt[n]`:** We increment the count for the number `n` in the array `cnt`. This increases the count for the number `n` by 1.
- **`% 2 == 0 ? 1 : 0`:** After updating the count of `n`, we check if the new count is even. If it is even, it means we have successfully formed a pair (since two identical elements form a pair). If the count becomes even, we increment the `pairs` counter by 1.
- **`pairs += ...`:** This adds 1 to the `pairs` counter whenever a pair is formed.

#### 3. **Return the Result**
```cpp
return { pairs, (int)nums.size() - pairs * 2 };
```
- **`pairs`:** This value is the number of pairs formed, which has been counted in the previous step.
- **`(int)nums.size() - pairs * 2`:** The total number of leftover elements is calculated as the total number of elements in the input array (`nums.size()`) minus twice the number of pairs (`pairs * 2`). Since each pair consists of two elements, multiplying `pairs` by 2 gives the total number of elements used in pairs. The difference gives the number of leftover unpaired elements.

The result is returned as a vector containing two elements:
1. The first element is the number of pairs.
2. The second element is the number of leftover unpaired elements.

### Complexity

#### Time Complexity:
- **O(n):** The algorithm processes each element of the input array `nums` once. For each element, it performs a constant-time operation of updating the count and checking if a pair is formed. Therefore, the time complexity is linear in terms of the size of the input array.

#### Space Complexity:
- **O(1):** The space used by the solution is constant because the size of the `cnt` array is fixed at 101, regardless of the size of the input array. The space used does not depend on the input size, so the space complexity is constant.

### Conclusion

This solution efficiently solves the problem of counting pairs and leftover elements in an array. By using a counting array (`cnt`) to track the occurrences of each element, we can easily calculate the number of pairs and unpaired elements in a single pass through the input array. This approach works in linear time O(n), making it very efficient for large input sizes. The solution also uses constant space O(1), which is optimal for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-pairs-in-array/description/)

---
{{< youtube 9KeeDZ6tcy4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
