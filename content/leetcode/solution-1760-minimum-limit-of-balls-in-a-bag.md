
+++
authors = ["grid47"]
title = "Leetcode 1760: Minimum Limit of Balls in a Bag"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1760: Minimum Limit of Balls in a Bag in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "znZ4wT1L8Y0"
youtube_upload_date="2021-02-14"
youtube_thumbnail="https://i.ytimg.com/vi/znZ4wT1L8Y0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSize(vector<int>& nums, int mxOps) {
        
        int l = 1, r = *max_element(nums.begin(), nums.end());
        // int total_bags = n + 2 * mxOps - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(int a: nums)
                cnt += (a - 1) / mid;
            if(cnt <= mxOps)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine the minimum size of the largest bag that can be achieved by performing a limited number of operations on an array of integers. The array `nums` represents the sizes of bags, and `mxOps` is the maximum number of operations allowed. The goal is to minimize the maximum size of the bags after performing the operations. 

Each operation allows us to decrease the size of a bag by any integer amount. Thus, with a given number of operations, we want to find out what the smallest possible size of the largest bag can be, ensuring that we can achieve this size with the allowed operations.

### Approach

The solution uses a binary search algorithm to efficiently find the minimum size of the largest bag. The idea is to search for the smallest possible size `mid` for which we can achieve that size while performing no more than `mxOps` operations.

1. **Binary Search Setup**:
   - The search range is set between `1` and the maximum value found in `nums`.
   - We continuously narrow down the search space based on the number of operations required to achieve the `mid` size.

2. **Operation Counting**:
   - For each candidate size `mid`, we calculate how many operations are needed to ensure that all bags are less than or equal to `mid`.
   - If the total operations needed to reduce all bags is within the allowed `mxOps`, then `mid` is a feasible size, and we continue searching for a potentially smaller size. If it exceeds `mxOps`, we need to search for a larger size.

3. **Termination**:
   - The search continues until the lower and upper bounds converge, at which point the minimum size of the largest bag that can be achieved with the allowed operations is found.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the `minimumSize` function:

1. **Class Definition**: The method is defined within the class `Solution`.

   ```cpp
   class Solution {
   ```

2. **Public Method**: The `minimumSize` method takes two parameters: a vector of integers `nums` and an integer `mxOps`.

   ```cpp
   public:
       int minimumSize(vector<int>& nums, int mxOps) {
   ```

3. **Initialization**: 
   - The lower bound `l` is initialized to `1`.
   - The upper bound `r` is initialized to the maximum element in `nums`.

   ```cpp
   int l = 1, r = *max_element(nums.begin(), nums.end());
   ```

4. **Binary Search Loop**: A `while` loop continues until `l` is less than `r`.

   ```cpp
   while(l < r) {
   ```

5. **Calculate Midpoint**: Inside the loop, calculate the midpoint `mid` as the average of `l` and `r`.

   ```cpp
   int mid = l + (r - l) / 2;
   ```

6. **Count Operations**: Initialize a counter `cnt` to zero. For each bag size `a` in `nums`, calculate how many operations would be required to reduce that bag size to `mid` or less. This is done using the formula `(a - 1) / mid`, which gives the number of full `mid` sizes that can fit into `a`.

   ```cpp
   int cnt = 0;
   for(int a: nums)
       cnt += (a - 1) / mid;
   ```

7. **Adjust Search Bounds**:
   - If the total operations `cnt` is less than or equal to `mxOps`, it means we can afford to make `mid` the maximum size, so we try to find a smaller possible size by setting `r = mid`.
   - Otherwise, we need a larger size, so we set `l = mid + 1`.

   ```cpp
   if(cnt <= mxOps)
       r = mid;
   else
       l = mid + 1;
   ```

8. **Return Result**: When the loop terminates, `l` will point to the smallest maximum size that can be achieved with the allowed operations, which is returned as the result.

   ```cpp
   return l;
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n \log m)\), where \(n\) is the number of elements in `nums` and \(m\) is the maximum element in `nums`. The logarithmic factor arises from the binary search over the range of possible sizes, while the linear scan through `nums` for counting operations contributes to the \(n\) factor.

- **Space Complexity**: The space complexity is \(O(1)\) as no additional data structures that grow with input size are used.

### Conclusion

The `minimumSize` function effectively finds the minimum possible size of the largest bag after performing a limited number of operations on an array of integers. By employing a binary search strategy, the solution efficiently narrows down the feasible sizes based on the required operations for each potential size. This approach demonstrates an effective method for solving optimization problems involving constraints and searching for optimal values within a defined range.

The clear structure of the code and the logical flow of the binary search make it an elegant solution to the problem, ensuring both correctness and efficiency. This algorithmic technique can be applied to a variety of problems that require optimizing a variable under certain constraints, showcasing its versatility and utility in algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/)

---
{{< youtube znZ4wT1L8Y0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
