
+++
authors = ["grid47"]
title = "Leetcode 2333: Minimum Sum of Squared Difference"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2333: Minimum Sum of Squared Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wp8lV0aP6aU"
youtube_upload_date="2022-07-09"
youtube_thumbnail="https://i.ytimg.com/vi/wp8lV0aP6aU/maxresdefault.jpg"
comments = true
+++



---
You are given two integer arrays, nums1 and nums2, each of length n. You are also given two integers k1 and k2. Modify any element of nums1 or nums2 at most k1 or k2 times, respectively, to minimize the sum of squared differences between the two arrays.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two integer arrays nums1 and nums2 of length n, and two integers k1 and k2.
- **Example:** `nums1 = [10, 20, 30], nums2 = [1, 15, 35], k1 = 2, k2 = 3`
- **Constraints:**
	- 1 <= n <= 10^5
	- 0 <= nums1[i], nums2[i] <= 10^5
	- 0 <= k1, k2 <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible sum of squared differences after modifying the elements of nums1 and nums2 as described.
- **Example:** `50`
- **Constraints:**
	- The result must be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Minimize the sum of squared differences by adjusting elements of nums1 and nums2 under given constraints.

- Calculate the initial squared differences between nums1 and nums2.
- Determine the amount of adjustment possible based on k1 and k2 for each element.
- Apply the adjustments in a way that minimizes the overall squared difference.
{{< dots >}}
### Problem Assumptions ✅
- You are allowed to modify the elements of nums1 and nums2 within the provided limits of k1 and k2.
- The arrays nums1 and nums2 can be modified independently.
{{< dots >}}
## Examples 🧩
- **Input:** `nums1 = [5, 12, 8], nums2 = [3, 9, 5], k1 = 1, k2 = 2`  \
  **Explanation:** By adjusting nums1[0] by +1 and nums2[2] by -2, the minimum sum of squared differences is achieved.

{{< dots >}}
## Approach 🚀
To minimize the sum of squared differences, adjust the elements of nums1 and nums2 intelligently using k1 and k2 to reduce the largest differences first.

### Initial Thoughts 💭
- The sum of squared differences is sensitive to large differences between corresponding elements.
- The optimal approach involves reducing these differences while respecting the available modification limits.
- Start by computing the initial sum of squared differences.
- Determine which elements can be adjusted most effectively with the given k1 and k2 values.
{{< dots >}}
### Edge Cases 🌐
- If nums1 and nums2 are empty, the result should be 0.
- For very large inputs, the solution should handle the constraints efficiently.
- If k1 or k2 is 0, no modifications can be made, and the sum of squared differences remains unchanged.
- Handle cases where the elements in nums1 and nums2 are already very close.
{{< dots >}}
## Code 💻
```cpp
long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

    int n = nums1.size();
    vector<long long> diff(n, 0);
    for(int i = 0; i < n; i++)
    diff[i] = abs(nums1[i] - nums2[i]);

    long long m = *max_element(diff.begin(), diff.end());
    int k = k1 + k2;

    vector<long long> bck(m + 1, 0);
    for(int i = 0; i < n; i++)
        bck[diff[i]]++;

    for(int i = m; i > 0; i--)
        if (bck[i] > 0) {
            long long num     = min(bck[i], (long long) k);
            bck[i]     -= num;
            bck[i - 1] += num;
            k -= num;
            if (k == 0) break;
        }

    long long res = 0;
    for(long long i = 0; i < m + 1; i++)
     res += bck[i] * (i * i);

    return res;
}
```

This function calculates the minimum sum of squared differences between two lists `nums1` and `nums2` after performing up to `k1` and `k2` operations to adjust the values of the lists. It uses a greedy approach with a counting strategy to minimize the difference.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
	```
	Declares the function `minSumSquareDiff` that calculates the minimum sum of squared differences between two integer arrays after adjusting their values using up to `k1` and `k2` operations.

2. **Array Size Calculation**
	```cpp
	    int n = nums1.size();
	```
	Calculates the size of the input arrays `nums1` and `nums2`, storing it in variable `n`.

3. **Difference Array Initialization**
	```cpp
	    vector<long long> diff(n, 0);
	```
	Initializes an array `diff` to store the absolute differences between the elements of `nums1` and `nums2`.

4. **Loop Through Arrays**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loops through the arrays `nums1` and `nums2` to calculate the absolute differences.

5. **Calculate Differences**
	```cpp
	    diff[i] = abs(nums1[i] - nums2[i]);
	```
	Calculates the absolute difference between corresponding elements in `nums1` and `nums2` and stores it in the `diff` array.

6. **Find Maximum Difference**
	```cpp
	    long long m = *max_element(diff.begin(), diff.end());
	```
	Finds the maximum difference in the `diff` array to determine the range of possible values for adjustments.

7. **Total Operations Calculation**
	```cpp
	    int k = k1 + k2;
	```
	Calculates the total number of operations (`k1` and `k2`) available to adjust the values.

8. **Count Occurrences of Differences**
	```cpp
	    vector<long long> bck(m + 1, 0);
	```
	Initializes a backup array `bck` to store the count of each difference value.

9. **Loop Through Differences**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loops through the `diff` array to count the occurrences of each difference value.

10. **Update Count Array**
	```cpp
	        bck[diff[i]]++;
	```
	Increments the count of the current difference in the backup array `bck`.

11. **Loop Through Differences in Reverse**
	```cpp
	    for(int i = m; i > 0; i--)
	```
	Starts a loop from the maximum difference down to 1 to try and minimize the differences with available operations.

12. **Check if Adjustments are Possible**
	```cpp
	        if (bck[i] > 0) {
	```
	Checks if there are any occurrences of the current difference `i` that can be adjusted.

13. **Calculate Number of Adjustments**
	```cpp
	            long long num     = min(bck[i], (long long) k);
	```
	Calculates the number of adjustments that can be made for the current difference, based on the available operations.

14. **Update Count Array After Adjustments**
	```cpp
	            bck[i]     -= num;
	```
	Decreases the count of the current difference by the number of adjustments made.

15. **Update Lower Difference Count**
	```cpp
	            bck[i - 1] += num;
	```
	Increases the count of the next lower difference by the number of adjustments made.

16. **Update Remaining Operations**
	```cpp
	            k -= num;
	```
	Reduces the remaining number of operations by the number of adjustments made.

17. **Check if Operations Are Exhausted**
	```cpp
	            if (k == 0) break;
	```
	Checks if all available operations have been used, and if so, breaks out of the loop.

18. **Initialize Result**
	```cpp
	    long long res = 0;
	```
	Initializes the result variable `res` to store the final sum of squared differences.

19. **Sum of Squared Differences**
	```cpp
	    for(long long i = 0; i < m + 1; i++)
	```
	Loops through the `bck` array to calculate the sum of squared differences.

20. **Accumulate Squared Differences**
	```cpp
	     res += bck[i] * (i * i);
	```
	Accumulates the sum of squared differences using the counts from the `bck` array.

21. **Return Result**
	```cpp
	    return res;
	```
	Returns the final result, which is the minimum sum of squared differences after the adjustments.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) for sorting and calculating differences.
- **Average Case:** O(n log n) for sorting and updating the elements.
- **Worst Case:** O(n log n) due to sorting, which is the most time-consuming operation.

The complexity is dominated by the sorting step.

### Space Complexity 💾
- **Best Case:** O(n) for storing differences and counts.
- **Worst Case:** O(n) for storing differences and counts.

Space complexity is linear in terms of the number of elements in nums1 and nums2.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-sum-of-squared-difference/description/)

---
{{< youtube wp8lV0aP6aU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
