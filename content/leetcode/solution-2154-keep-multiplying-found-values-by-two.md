
+++
authors = ["grid47"]
title = "Leetcode 2154: Keep Multiplying Found Values by Two"
date = "2024-04-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2154: Keep Multiplying Found Values by Two in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "b-6Wf-ZShQQ"
youtube_upload_date="2022-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b-6Wf-ZShQQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int findFinalValue(vector<int>& nums, int o) {
        int h[1001]={};
        for(auto i:nums) h[i]++;
		
        while(o<=1000 && h[o])
            o*=2;
        
        return o;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the "final value" of a given integer `o` after repeatedly multiplying it by 2 if it exists in the array `nums`. Given an integer `o` and a list of integers `nums`, the process continues as long as the current value of `o` exists in `nums`. The function returns the final value of `o` after it no longer exists in `nums`.

### Approach

The approach leverages an array `h` to store the count of elements in `nums`. Using this frequency array, we can quickly check if the current value of `o` exists in `nums` by simply checking if `h[o]` is non-zero. If it exists, we multiply `o` by 2 and continue the process. If `o` is greater than 1000 or `h[o]` is zero, the loop terminates, and the function returns `o`.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
  int findFinalValue(vector<int>& nums, int o) {
        int h[1001]={};          // Step 1: Initialize an array `h` with 1001 elements set to 0
        for(auto i : nums)       // Step 2: Populate `h` with elements from `nums`
            h[i]++;
        
        while(o <= 1000 && h[o]) // Step 3: Repeat while `o` is within bounds and exists in `nums`
            o *= 2;              // Step 4: Multiply `o` by 2 if it exists in `nums`
        
        return o;                // Step 5: Return the final value of `o`
    }
};
```

#### Step-by-Step Breakdown

1. **Frequency Array Initialization**:
   ```cpp
   int h[1001]={};
   ```
   An array `h` of size 1001 is created with all elements initialized to 0. Each index in `h` represents an integer value from 0 to 1000, so any element in `nums` (bounded by 1000) can be easily accessed in constant time.

2. **Populating the Frequency Array**:
   ```cpp
   for(auto i : nums) h[i]++;
   ```
   For each element `i` in `nums`, we increment the corresponding index in `h`, marking its presence in the array `nums`.

3. **Loop to Adjust the Value of `o`**:
   ```cpp
   while(o <= 1000 && h[o])
       o *= 2;
   ```
   This loop continues as long as `o` is within the bounds (less than or equal to 1000) and `o` is found in `nums`. If `h[o]` is non-zero, this means `o` exists in `nums`, so we multiply `o` by 2. The loop exits when either `o` is not found in `nums` or `o` exceeds 1000.

4. **Returning the Final Value of `o`**:
   ```cpp
   return o;
   ```
   After the loop finishes, `o` no longer exists in `nums` or has exceeded 1000, so we return `o`.

### Complexity Analysis

#### Time Complexity
- Constructing the frequency array `h` from `nums` takes **O(n)** time, where `n` is the number of elements in `nums`.
- The while loop may potentially iterate at most **log(n)** times since we double `o` each time.

Thus, the overall time complexity is **O(n)**, which is efficient.

#### Space Complexity
- The space complexity is **O(1)** as `h` is a fixed-size array (1001 elements) and does not depend on the input size `n`.

### Conclusion

This solution provides an efficient way to compute the "final value" by checking for each existence of `o` using constant-time lookups in the frequency array. This results in a linear time solution with minimal space usage, which makes it optimal for large arrays with elements bounded by 1000. The solution also ensures that `o` is doubled efficiently until it reaches a value not present in `nums`. This approach balances both time and space complexity, achieving high performance with simplicity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/)

---
{{< youtube b-6Wf-ZShQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
