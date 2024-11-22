
+++
authors = ["grid47"]
title = "Leetcode 2784: Check if Array is Good"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2784: Check if Array is Good in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "le-u0OA8HMM"
youtube_upload_date="2023-07-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/le-u0OA8HMM/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int cnt[201] = {}, n = nums.size() - 1;
        for (auto num : nums)
            ++cnt[num];
        return all_of(begin(cnt) + 1, begin(cnt) + n, [](int c){ return c == 1; }) && cnt[n] == 2;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine whether a given array `nums` is "good". An array is considered good if:
1. All the elements in the array, except for the last one, appear exactly once.
2. The last element in the array must appear exactly twice.

Your task is to implement a function that checks if the array satisfies these conditions.

### Approach

To solve the problem, we need to verify two main conditions for the array:
- All elements, except the last one, must appear exactly once.
- The last element must appear exactly twice.

### Steps to Solve:

1. **Count the occurrences of elements**:
   - First, we need to count how many times each element appears in the array. This can be efficiently done using a frequency counter (a simple array or map).
   
2. **Check the conditions**:
   - We then check that each element in the array (except the last one) appears exactly once.
   - Finally, we ensure that the last element appears exactly twice.

### Code Breakdown

#### Step 1: Frequency Count Array
```cpp
int cnt[201] = {};
```
- **`cnt[201]`**: An array `cnt` is used to store the frequency of each element in the array `nums`. Since the problem states that the elements in the array are between 1 and `n` (where `n` is the size of the array minus 1), the size of the array `cnt` is set to 201 to accommodate all possible values.

#### Step 2: Counting Element Frequencies
```cpp
for (auto num : nums)
    ++cnt[num];
```
- We loop through each element in the input array `nums` and increment its corresponding count in the `cnt` array. For each element `num`, we increment `cnt[num]` by 1. This gives us the frequency of each element in the array.

#### Step 3: Checking the Conditions
```cpp
return all_of(begin(cnt) + 1, begin(cnt) + n, [](int c){ return c == 1; }) && cnt[n] == 2;
```
- **`all_of(begin(cnt) + 1, begin(cnt) + n, [](int c){ return c == 1; })`**:
    - This uses the `all_of` function to check if all elements in the `cnt` array (from index `1` to `n-1`) have a count of exactly `1`. These represent the elements that must appear exactly once in the array (except for the last one).
    - The condition `c == 1` ensures that the count for each element is 1.
    - The range `begin(cnt) + 1` to `begin(cnt) + n` skips the first index (`cnt[0]`) as it is not part of the element values.
  
- **`cnt[n] == 2`**:
    - This checks that the last element of the array `nums` (which is indexed at `n` in the array) appears exactly twice. The last element is treated specially, so we directly check if its count is `2`.

- The `&&` operator combines these two conditions, so the function returns `true` only if both conditions are satisfied:
    1. All elements, except for the last one, appear exactly once.
    2. The last element appears exactly twice.

#### Step 4: Returning the Result
The result of the `all_of` check and the check for the last element's count is returned directly as a boolean value.

### Complexity

#### Time Complexity:
- **O(n)**: The time complexity is linear because we iterate through the array `nums` once to count the frequency of elements, and we check the conditions using the `all_of` function, which operates in linear time with respect to the size of the `cnt` array (which is a fixed size of 201). Therefore, the overall time complexity is **O(n)**, where `n` is the size of the input array `nums`.

#### Space Complexity:
- **O(1)**: The space complexity is constant because we use an array `cnt` of size 201, which is independent of the size of the input array. The size of this array is fixed and does not grow with the input size, so the space complexity is constant **O(1)**.

### Conclusion

This approach provides an efficient solution to the problem by leveraging a frequency counter to ensure that the array meets the specified conditions for being "good". The algorithm operates in linear time, **O(n)**, where `n` is the size of the input array, and uses constant space, **O(1)**, to store the frequency counts. This makes it a highly efficient solution suitable for large arrays.

By using a simple frequency count array and performing checks on the elements of the array, the solution is both easy to understand and implement. The use of the `all_of` function makes the code more concise and readable, improving the clarity of the solution.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-array-is-good/description/)

---
{{< youtube le-u0OA8HMM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
