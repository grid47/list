
+++
authors = ["grid47"]
title = "Leetcode 645: Set Mismatch"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 645: Set Mismatch in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/645.webp"
youtube = "d-ulaeRBA64"
youtube_upload_date="2024-01-22"
youtube_thumbnail="https://i.ytimg.com/vi/d-ulaeRBA64/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/645.webp" 
    alt="Two sets where the mismatch is found and highlighted, with each mismatched element glowing softly."
    caption="Solution to LeetCode 645: Set Mismatch Problem"
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
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        for(int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            ans[1] ^= (i+1) ^ val;
            if (nums[val-1] < 0) ans[0] = val;
            else nums[val-1] = -nums[val-1];
        }
        ans[1] ^= ans[0];
        return ans;        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to identify the two numbers in an array that contain duplicates and a missing number. The array consists of `n` numbers, where each number is between `1` and `n` inclusive, but one number appears twice and one number is missing. Our goal is to return a vector containing two integers:
1. The number that appears twice.
2. The number that is missing.

For example, given an array `[1, 2, 2, 4]`, the output should be `[2, 3]` because `2` appears twice and `3` is missing.

### Approach

To solve this problem efficiently, we can use a technique that leverages **XOR** and modifies the array in place. The key idea is that:
- We can XOR all the indices and values in the array to identify the difference between the missing and duplicate numbers.
- We can also track the duplicate by marking the elements in the array to help pinpoint which number is missing.

Here’s a step-by-step breakdown of how the solution works:
1. **XOR operation**: XORing a number with itself results in `0`. Thus, by XORing all the values and indices of the array, we can eliminate matching pairs. This allows us to isolate the difference between the duplicate and the missing number.
2. **Tracking duplicate**: To find the duplicate number, we modify the array during iteration, marking the elements as negative when they are visited. If we encounter a negative number during the iteration, we know that number is the duplicate.
3. **Finding the missing number**: The XOR result of all numbers gives us a combination of the duplicate and missing number. By XORing the result with the duplicate number, we isolate the missing number.

### Code Breakdown (Step by Step)

Let’s now break down the solution code line by line to understand how it works:

#### 1. **Function Signature**:
```cpp
vector<int> findErrorNums(vector<int>& nums) {
    vector<int> ans(2, 0);
```
- The function `findErrorNums` accepts a reference to a vector `nums` of size `n`. It returns a vector of size `2` to store the duplicate number and the missing number.
- We initialize the answer vector `ans` with two `0`s, where `ans[0]` will store the duplicate number and `ans[1]` will store the missing number.

#### 2. **Iterating through the array**:
```cpp
for(int i = 0; i < nums.size(); i++) {
    int val = abs(nums[i]);
    ans[1] ^= (i+1) ^ val;
```
- We loop through each element of the `nums` array.
- For each element, we use `abs(nums[i])` to work with the positive version of the number because, during iteration, some elements might have been marked as negative.
- We XOR the current index `(i+1)` and the absolute value of the current number `val`. This helps accumulate the difference between the duplicate and missing numbers.

#### 3. **Marking visited numbers**:
```cpp
if (nums[val-1] < 0) ans[0] = val;
else nums[val-1] = -nums[val-1];
```
- If the element at index `val-1` in `nums` is already negative, it means that the number `val` has been encountered before and is the duplicate. In that case, we assign `val` to `ans[0]`, marking it as the duplicate number.
- If the element at index `val-1` is positive, we mark it as visited by setting `nums[val-1]` to its negative value. This helps track which numbers have been seen already.

#### 4. **Final XOR to get the missing number**:
```cpp
ans[1] ^= ans[0];
```
- After the loop completes, `ans[1]` holds the XOR result of all the indices and values, including both the duplicate and the missing number. By XORing it with `ans[0]` (the duplicate number), we isolate the missing number.

#### 5. **Return the result**:
```cpp
return ans;
```
- Finally, we return the `ans` vector, which contains the duplicate and missing numbers.

### Complexity

#### Time Complexity:
- The solution iterates over the array once, performing constant-time operations during each iteration (XOR, absolute value check, array modification). Thus, the time complexity is `O(n)`, where `n` is the number of elements in the input array.

#### Space Complexity:
- The space complexity is `O(1)` since we are using only a constant amount of extra space (the answer vector of size 2). The solution modifies the input array in place, so no additional space is required for storing intermediate results.

### Conclusion

This solution provides an efficient way to solve the problem of finding the duplicate and missing numbers in an array using XOR and in-place modifications. By leveraging the properties of XOR, we can reduce the space complexity to constant space and achieve a linear time complexity solution. This makes it an optimal approach for large input arrays.

The steps outlined above efficiently identify the duplicate and missing numbers without needing extra space for auxiliary arrays or data structures, making this solution both time and space-efficient. The solution is also highly scalable, working for any input size that fits within the problem's constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/set-mismatch/description/)

---
{{< youtube d-ulaeRBA64 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
