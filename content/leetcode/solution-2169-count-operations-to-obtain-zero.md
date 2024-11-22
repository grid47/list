
+++
authors = ["grid47"]
title = "Leetcode 2169: Count Operations to Obtain Zero"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2169: Count Operations to Obtain Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "yPqe3KshvVo"
youtube_upload_date="2022-02-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yPqe3KshvVo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 > 0 && num2 > 0) {
            if(num1 > num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            ans++;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem is to find the number of operations needed to reduce two given positive integers, `num1` and `num2`, to zero using a specific operation. The operation allows repeatedly subtracting the smaller number from the larger one until at least one of the numbers becomes zero. The task is to return the total count of these operations.

### Approach
The approach leverages a simple iterative process:
- Continue as long as both `num1` and `num2` are greater than zero.
- In each iteration, check which number is larger:
  - Subtract the smaller number from the larger one.
  - Increment the operation count (`ans`).
- The loop stops when one of the numbers becomes zero, at which point the total count of operations is returned.

### Code Breakdown (Step by Step)
1. **Initialization**:
   - An integer `ans` is initialized to `0` to keep track of the number of operations performed.

2. **While Loop**:
   - The condition `while(num1 > 0 && num2 > 0)` ensures that the loop continues until at least one of the numbers becomes zero.
   
3. **Conditional Check**:
   - Inside the loop, a check is made:
     - If `num1 > num2`, subtract `num2` from `num1`.
     - Otherwise, subtract `num1` from `num2`.
   - This step effectively reduces the larger of the two numbers by the smaller one.
   
4. **Increment Operation Counter**:
   - After each subtraction operation, increment `ans` to count the operation.

5. **Return Statement**:
   - Once the loop terminates, the function returns `ans`, which holds the total number of operations.

### Complexity
- **Time Complexity**: The time complexity of this approach is O(max(num1, num2)), as the number of operations depends on the size of the input values. The loop iterates as long as the larger number can be reduced by the smaller one.
- **Space Complexity**: The space complexity is O(1) since no additional space is used other than a few variables for tracking the operation count and performing calculations.

### Conclusion
This solution is an efficient way to count the number of operations required to make two positive integers zero through iterative subtraction. It highlights the simplicity of a greedy approach that ensures each step moves towards the goal by removing the smaller value from the larger one. The problem is effectively reduced using basic arithmetic and logical conditions, achieving an optimal solution for scenarios where both numbers can be manipulated through iterative subtraction.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-operations-to-obtain-zero/description/)

---
{{< youtube yPqe3KshvVo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
