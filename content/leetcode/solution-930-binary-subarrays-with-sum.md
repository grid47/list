
+++
authors = ["grid47"]
title = "Leetcode 930: Binary Subarrays With Sum"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 930: Binary Subarrays With Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "j4JDr4-jvo4"
youtube_upload_date="2024-03-14"
youtube_thumbnail="https://i.ytimg.com/vi/j4JDr4-jvo4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal -1);
    }
    
    int atmost(vector<int> &nums, int s) {
        if(s < 0) return 0;
        int res = 0, j = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            s -= nums[i];
            while(s < 0) s += nums[j++];
            res += (i - j + 1);
        }
        return res;
    }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the number of contiguous subarrays within a binary array (i.e., an array of 0s and 1s) that have a specific sum of `goal`. The binary array is represented by an array `nums` of integers, and the target sum is given by the integer `goal`. A subarray is a contiguous portion of the array, and we need to return the total number of subarrays whose sum equals `goal`.

### Approach

The key insight in solving this problem efficiently lies in using the concept of **at most sum subarrays**. Rather than directly counting subarrays that sum to exactly `goal`, we can count all subarrays whose sum is **at most `goal`** and use this count to compute the answer for subarrays with an exact sum of `goal`.

The approach is based on the **two-pointer** or **sliding window** technique, which helps in efficiently counting the number of subarrays whose sum is at most a given value. The idea is to break the problem down into two simpler subproblems:

1. **At Most `goal` Subarrays**: Count the number of subarrays whose sum is at most `goal`.
2. **At Most `goal - 1` Subarrays**: Count the number of subarrays whose sum is at most `goal - 1`.

The difference between these two counts will give us the number of subarrays whose sum is exactly `goal`, because:

- Subarrays with a sum at most `goal` are all subarrays where the sum can be any value from 0 to `goal`.
- Subarrays with a sum at most `goal - 1` are all subarrays where the sum can be any value from 0 to `goal - 1`.

The number of subarrays whose sum is exactly `goal` is the difference between the two, i.e.,

\[
\text{{numSubarraysWithSum}} = \text{{atmost}}(\text{{nums}}, \text{{goal}}) - \text{{atmost}}(\text{{nums}}, \text{{goal}} - 1)
\]

By using this approach, we avoid the need to generate all possible subarrays, which would be inefficient for larger arrays.

### Code Breakdown (Step by Step)

1. **`numSubarraysWithSum` Function**:
   This function calculates the number of subarrays whose sum is exactly equal to the `goal`. It calls the `atmost` function twice to get the counts for sums at most `goal` and at most `goal - 1` and computes their difference.

   ```cpp
   int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atmost(nums, goal) - atmost(nums, goal - 1);
   }
   ```

2. **`atmost` Function**:
   This function calculates the number of subarrays whose sum is at most a given value `s`. The function uses a sliding window (or two-pointer approach) to keep track of the current subarray sum as it iterates through the array. When the sum exceeds `s`, it shrinks the window from the left by incrementing the pointer `j`.

   ```cpp
   int atmost(vector<int> &nums, int s) {
       if(s < 0) return 0;  // If the sum `s` is negative, no subarray can have a negative sum
       int res = 0, j = 0;  // `res` will store the result, and `j` is the left pointer
       
       // Iterate through the array with the right pointer `i`
       for(int i = 0; i < nums.size(); i++) {
           s -= nums[i];  // Subtract the current element from the sum
           
           // Shrink the window from the left until the sum is <= s
           while(s < 0) s += nums[j++];
           
           // Add the number of valid subarrays ending at index `i`
           res += (i - j + 1);
       }
       return res;
   }
   ```

   The key points of this function:
   - It keeps track of the sum of the current subarray (from `j` to `i`).
   - If the sum exceeds `s`, it moves the left pointer `j` rightward to reduce the sum back to `s` or below.
   - The number of subarrays ending at index `i` that have a sum at most `s` is `i - j + 1`, as it counts all subarrays between indices `j` and `i` (inclusive).
   - It returns the total number of valid subarrays.

3. **Time Complexity**:
   - The `atmost` function uses a sliding window approach. Each index of the array is processed at most twice (once when it is added to the window and once when it is removed), making the time complexity of the `atmost` function **O(n)**, where `n` is the size of the input array.
   - The `numSubarraysWithSum` function calls `atmost` twice, so the overall time complexity is still **O(n)**.

4. **Space Complexity**:
   - The space complexity is **O(1)** because the algorithm only uses a constant amount of extra space for variables like `res`, `j`, and `s`.

### Complexity

- **Time Complexity**: **O(n)** where `n` is the number of elements in the input array `nums`. This is because we only pass through the array a constant number of times (using the sliding window technique).
- **Space Complexity**: **O(1)**, as we are using only a fixed amount of extra space for our computations, regardless of the input size.

### Conclusion

The solution to the problem uses the sliding window technique to efficiently count the number of subarrays with a sum at most a given value. By using the difference between the number of subarrays with sum at most `goal` and `goal - 1`, we efficiently count the number of subarrays whose sum is exactly equal to `goal`. This approach avoids the need for generating all subarrays, making it scalable for large inputs.

This method offers an optimal solution with linear time complexity, making it a great choice for problems involving subarray sums in a binary array. The use of the sliding window technique ensures that the solution is both efficient and easy to understand.

[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-subarrays-with-sum/description/)

---
{{< youtube j4JDr4-jvo4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
