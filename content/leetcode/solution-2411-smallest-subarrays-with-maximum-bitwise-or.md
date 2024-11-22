
+++
authors = ["grid47"]
title = "Leetcode 2411: Smallest Subarrays With Maximum Bitwise OR"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2411: Smallest Subarrays With Maximum Bitwise OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Bit Manipulation","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0xR5bFyo2QA"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0xR5bFyo2QA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n, 1), last(30, 0);
        
        
        for(int i = n - 1; i >= 0; i--) {
            
            
            for(int j = 0; j < 30; j++) {
                
                if(nums[i] & (1 << j)) {
                    last[j] = i;
                }
                
                ans[i] = max(ans[i], last[j] - i + 1);
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array `nums` of size `n`, the task is to find the smallest subarray that contains all the bits of each element of the array. For each element `nums[i]`, we need to find the length of the smallest subarray that contains all the set bits of `nums[i]`. The challenge is to solve this efficiently.

### Approach

The problem requires us to find the smallest subarray for each element of the array such that the subarray contains all the bits that are set in the binary representation of the number. To solve this problem efficiently, we can use bitwise operations combined with a dynamic programming approach.

Here's the breakdown of the approach:

1. **Bitwise Operations**:
    - Each integer can be represented as a sequence of bits (0s and 1s). The idea is to track the position of the most recent occurrence of each bit (from the least significant bit to the most significant bit) as we process the array from right to left.
    - The challenge is to keep track of the smallest subarray that contains all the set bits of each number. We can do this by checking the most recent occurrences of the bits for each number.

2. **Tracking the Last Occurrence of Each Bit**:
    - We maintain an array `last` of size 30, which tracks the most recent index where each bit (from the 0th to the 29th bit) was set.
    - For each number `nums[i]`, we check the positions of all bits that are set in the number and update the `last` array accordingly.

3. **Dynamic Programming Approach**:
    - The idea is to iteratively compute the smallest subarray for each index `i` by considering all the set bits in `nums[i]` and the last seen positions of those bits.
    - For each bit in the current number, we compute the distance between the current index `i` and the last seen position of that bit. The answer for `nums[i]` will be the maximum of these distances plus one (since we want the length of the subarray).

4. **Final Answer**:
    - For each index `i`, the length of the smallest subarray that contains all the set bits of `nums[i]` is stored in the `ans` array. Finally, we return the `ans` array as the result.

### Code Breakdown (Step by Step)

#### 1. Initialization

```cpp
int n = nums.size();
vector<int> ans(n, 1), last(30, 0);
```

- `n` stores the size of the input array `nums`.
- `ans` is a vector that will store the answer for each index. Initially, we assume that the smallest subarray for each element is of length 1.
- `last` is a vector of size 30 (as we are dealing with integers with up to 30 bits) to store the last seen index for each bit.

#### 2. Loop Over the Array from Right to Left

```cpp
for(int i = n - 1; i >= 0; i--) {
    for(int j = 0; j < 30; j++) {
```

- We loop over the array from right to left (starting from the last index). This allows us to efficiently compute the smallest subarray that contains all the set bits for each element.
- For each element `nums[i]`, we need to check each of the 30 possible bits (0 through 29).

#### 3. Update the `last` Array for Each Bit

```cpp
if(nums[i] & (1 << j)) {
    last[j] = i;
}
```

- `nums[i] & (1 << j)` checks whether the `j`-th bit of `nums[i]` is set (1). If it is set, we update the `last` array to store the current index `i` as the most recent index where this bit was set.

#### 4. Compute the Length of the Smallest Subarray

```cpp
ans[i] = max(ans[i], last[j] - i + 1);
```

- After updating the `last` array for the current bit, we compute the length of the smallest subarray for `nums[i]`. For each bit `j`, the smallest subarray that contains this bit will have a length equal to `last[j] - i + 1` (the distance between the current index `i` and the last seen index of this bit).
- We take the maximum of all such distances to ensure that the subarray contains all the bits.

#### 5. Return the Result

```cpp
return ans;
```

- Once the loop finishes, the `ans` array will contain the smallest subarray lengths for each element in the input array. We return the `ans` array as the result.

### Complexity

#### Time Complexity:

- We loop over each element of the input array `nums`, and for each element, we check each of the 30 bits. Hence, the total time complexity is:
  
  \[
  O(n \times 30) = O(n)
  \]
  
  where `n` is the size of the array `nums`. Since the number of bits is constant (30), it does not affect the overall time complexity.

#### Space Complexity:

- The space complexity is determined by the two arrays:
  - `ans`: This array stores the smallest subarray lengths for each element, which takes \(O(n)\) space.
  - `last`: This array stores the last seen index for each of the 30 bits, which takes \(O(30) = O(1)\) space.
  
Thus, the space complexity is:

\[
O(n)
\]

### Conclusion

The solution efficiently computes the smallest subarray that contains all the set bits of each element in the array by leveraging bitwise operations and dynamic programming. The time complexity of \(O(n)\) and space complexity of \(O(n)\) make this approach suitable for large input sizes. By processing the array from right to left and tracking the most recent occurrences of each bit, we can ensure that the smallest subarray is computed efficiently for each element.

[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/)

---
{{< youtube 0xR5bFyo2QA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
