
+++
authors = ["grid47"]
title = "Leetcode 1673: Find the Most Competitive Subsequence"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1673: Find the Most Competitive Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GBJFxSD3B_s"
youtube_upload_date="2021-02-22"
youtube_thumbnail="https://i.ytimg.com/vi/GBJFxSD3B_s/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        vector<int> stk;
        for(int i = 0; i < nums.size(); i++) {

            while (!stk.empty()          &&
                 stk.back() > nums[i] &&
                (stk.size() + nums.size() - (i + 1)) >= k )
                stk.pop_back();

            if(stk.size() < k)
                stk.push_back(nums[i]);

        }
        
        return stk;
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine the most competitive subsequence of a given length \( k \) from an array of integers \( nums \). A subsequence is considered more competitive if it appears in the order of elements in the original array while being lexicographically smaller than any other subsequence of the same length. The goal is to return a subsequence of size \( k \) that meets these criteria.

### Approach

To solve this problem efficiently, we can use a greedy algorithm with a stack to maintain the most competitive subsequence. The core idea is to iteratively add elements from the array \( nums \) to the stack while ensuring that we maintain the required length \( k \) and the lexicographical order. Here’s a step-by-step outline of the approach:

1. **Stack Usage**: We use a stack (`stk`) to build our subsequence. The stack helps us maintain the order and allow easy removal of elements that would lead to a less competitive subsequence.
  
2. **Iterate through `nums`**: We go through each element of the `nums` array, deciding whether to include it in the stack or to discard some elements already in the stack.

3. **Pop Conditions**:
   - We will pop elements from the stack while the current element (`nums[i]`) is smaller than the top of the stack (`stk.back()`). This ensures we keep smaller elements at the top.
   - We also need to ensure that after popping, we can still achieve a subsequence of length \( k \) with the remaining elements. This is checked using the condition:
     \[
     \text{(size of stk)} + \text{(remaining elements in nums)} - \text{(current index + 1)} \geq k
     \]
   This condition ensures that even after popping elements, we have enough remaining elements to fill up to \( k \).

4. **Push Current Element**: If the size of the stack is less than \( k \), we push the current element onto the stack.

5. **Return the Stack**: Finally, we return the stack as the most competitive subsequence of length \( k \).

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
```
- **Class and Method Definition**: We define a class `Solution` and declare the public method `mostCompetitive`, which takes a vector of integers `nums` and an integer `k`.

```cpp
        vector<int> stk;
```
- **Stack Initialization**: We initialize a vector `stk` to use as our stack for building the subsequence.

```cpp
        for(int i = 0; i < nums.size(); i++) {
```
- **Iterate Through `nums`**: We start a loop to iterate through each element in `nums`.

```cpp
            while (!stk.empty() &&
                 stk.back() > nums[i] &&
                (stk.size() + nums.size() - (i + 1)) >= k )
                stk.pop_back();
```
- **Pop Condition**: This while loop checks if the top element of the stack is greater than the current element (`nums[i]`). If it is, we pop the stack while also ensuring we can still form a valid subsequence of length \( k \).

```cpp
            if(stk.size() < k)
                stk.push_back(nums[i]);
```
- **Push Condition**: If the size of the stack is less than \( k \), we push the current number onto the stack.

```cpp
        return stk;
```
- **Return the Result**: Finally, we return the stack containing the most competitive subsequence.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \( O(n) \), where \( n \) is the number of elements in `nums`. Each element is pushed and popped from the stack at most once.

- **Space Complexity**: The space complexity is \( O(k) \) for the stack, which holds the result of length \( k \).

### Conclusion

The provided solution efficiently finds the most competitive subsequence of length \( k \) from the given array using a greedy approach with a stack. This algorithm ensures that we maintain the desired order and competitiveness of the subsequence through careful element management.

**Key Insights**:
1. **Greedy Approach**: The greedy nature of the algorithm allows for quick decisions on which elements to keep in the stack.
2. **Stack Utilization**: The stack not only helps manage the current subsequence but also simplifies the logic of maintaining the lexicographical order.
3. **Efficiency**: The algorithm's linear time complexity makes it suitable for large inputs, ensuring performance is not compromised.

Overall, this solution is a good example of applying a stack data structure to maintain order and achieve optimal results in competitive subsequence problems. The clarity and conciseness of the implementation contribute to its effectiveness.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-most-competitive-subsequence/description/)

---
{{< youtube GBJFxSD3B_s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
