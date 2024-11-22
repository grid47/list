
+++
authors = ["grid47"]
title = "Leetcode 713: Subarray Product Less Than K"
date = "2024-08-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 713: Subarray Product Less Than K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/713.webp"
youtube = "Cg6_nF7YIks"
youtube_upload_date="2024-03-27"
youtube_thumbnail="https://i.ytimg.com/vi/Cg6_nF7YIks/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/713.webp" 
    alt="An array of numbers where subarrays with products less than K are highlighted and softly glowing."
    caption="Solution to LeetCode 713: Subarray Product Less Than K Problem"
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        long long prod = 1;
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            
            while(prod >= k && j <= i) {
                prod /= nums[j++];
            }
            
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem asks us to find the number of contiguous subarrays in a given array `nums` such that the product of the elements in each subarray is less than a given value `k`. Specifically, the task is to calculate how many contiguous subarrays have a product that is less than `k`.

### Approach
This problem can be solved using the **sliding window** technique, which efficiently handles situations where we need to examine consecutive elements of an array. By maintaining a window of elements whose product is less than `k`, we can find all the valid subarrays without needing to check each possible subarray individually, which would be inefficient.

The core idea of the sliding window technique in this case is to extend the window by including more elements from the array, while keeping track of the product of the elements in that window. If the product exceeds or equals `k`, we shrink the window from the left until the product is less than `k` again.

### Code Breakdown (Step by Step)
Let's break down the solution step by step:

1. **Initialization**:
   - `prod = 1`: This variable holds the product of the elements in the current window.
   - `res = 0`: This variable counts the number of valid subarrays.
   - `j = 0`: This is the left boundary of the sliding window.

2. **Loop Over Array Elements**:
   - The outer loop iterates over each element `i` in the array `nums`:
     ```cpp
     for(int i = 0; i < nums.size(); i++) {
     ```

3. **Extend the Window**:
   - For each element `nums[i]`, the product is updated by multiplying it with `prod`:
     ```cpp
     prod *= nums[i];
     ```

4. **Shrink the Window (If Necessary)**:
   - If the product of the elements in the current window becomes greater than or equal to `k`, we move the left boundary `j` to the right, effectively removing elements from the window to reduce the product:
     ```cpp
     while(prod >= k && j <= i) {
         prod /= nums[j++];
     }
     ```
   - This ensures that the product of the elements in the window is always less than `k`.

5. **Count Valid Subarrays**:
   - After adjusting the window, the number of subarrays ending at index `i` with a product less than `k` is given by `i - j + 1`. This is because for each valid `i`, there are `i - j + 1` valid subarrays that can be formed by the elements in the range `[j, i]`:
     ```cpp
     res += (i - j + 1);
     ```

6. **Return the Result**:
   - Finally, the total count of valid subarrays is returned:
     ```cpp
     return res;
     ```

### Complexity Analysis

- **Time Complexity**:
  - The time complexity of this approach is **O(n)**, where `n` is the size of the array `nums`. This is because each element is added and removed from the product at most once. The two pointers `i` and `j` each move through the array once, and no element is processed more than twice.

- **Space Complexity**:
  - The space complexity is **O(1)**, since we only use a constant amount of extra space for variables like `prod`, `res`, and `j`. The space used does not depend on the size of the input array.

### Conclusion
This solution efficiently counts the number of contiguous subarrays whose product is less than a given value `k` using a sliding window approach. By iterating over the array once, adjusting the window as needed, and counting valid subarrays on the go, the algorithm achieves optimal time complexity. This is a perfect example of how the sliding window technique can be leveraged to solve problems involving subarrays or sub-sequences in linear time.

By implementing this solution, we achieve an efficient algorithm for a problem that might otherwise seem to require brute force, ensuring that we can handle large input arrays in a time-efficient manner.

This approach, due to its linear time complexity, is well-suited for handling large datasets and real-time applications where performance is critical. The technique of adjusting the window dynamically ensures that we only process the necessary elements, avoiding redundant calculations and optimizing the overall process.

In summary, this code offers a clean, efficient, and scalable solution to the problem, demonstrating the power of the sliding window technique in solving subarray problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/subarray-product-less-than-k/description/)

---
{{< youtube Cg6_nF7YIks >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
