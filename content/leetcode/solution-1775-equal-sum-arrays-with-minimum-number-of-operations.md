
+++
authors = ["grid47"]
title = "Leetcode 1775: Equal Sum Arrays With Minimum Number of Operations"
date = "2024-05-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1775: Equal Sum Arrays With Minimum Number of Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "n-BwszD77og"
youtube_upload_date="2021-02-28"
youtube_thumbnail="https://i.ytimg.com/vi/n-BwszD77og/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays, nums1 and nums2, with integers between 1 and 6. The lengths of the two arrays can differ. In one operation, you can change any element in either array to any value between 1 and 6. The task is to find the minimum number of operations required to make the sums of the two arrays equal. If it is not possible to make the sums equal, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays nums1 and nums2 of integers between 1 and 6. You can perform any number of operations where you change an element's value in either array.
- **Example:** `nums1 = [2, 3, 4, 5, 6], nums2 = [1, 2, 2, 3]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 10^5
	- 1 <= nums1[i], nums2[i] <= 6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to make the sums of nums1 and nums2 equal, or return -1 if it is not possible.
- **Example:** `Input: nums1 = [2, 3, 4, 5, 6], nums2 = [1, 2, 2, 3], Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To equalize the sum of nums1 and nums2 with the minimum number of operations by changing elements within the allowed range (1 to 6).

- 1. Calculate the sum of both nums1 and nums2.
- 2. If the sums are already equal, return 0.
- 3. If it is not possible to equalize the sums by the allowed changes, return -1.
- 4. Otherwise, iterate through the arrays and apply changes to the elements of nums1 or nums2 to balance the sums with the fewest changes.
{{< dots >}}
### Problem Assumptions ✅
- You can modify any element in either array within the allowed range (1 to 6).
- You are allowed to increase or decrease elements to any value between 1 and 6.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums1 = [2, 3, 4, 5, 6], nums2 = [1, 2, 2, 3]`  \
  **Explanation:** By changing nums2[0] to 6 and nums2[1] to 6, we make the sums of nums1 and nums2 equal (both sums are 20), so the answer is 2 operations.

- **Input:** `Input: nums1 = [1, 1, 1, 1], nums2 = [6, 6]`  \
  **Explanation:** It is not possible to make the sums of nums1 and nums2 equal because nums1's sum cannot be reduced and nums2's sum cannot be increased sufficiently.

{{< dots >}}
## Approach 🚀
The approach is to iteratively compare the sums of nums1 and nums2 and apply changes to the elements that will bring the sums closer to each other, while tracking the number of changes made.

### Initial Thoughts 💭
- If one array's sum is greater than the other, we need to decrease the larger sum or increase the smaller sum.
- If the difference between the sums is too large to be adjusted with valid operations, return -1.
- We need to carefully balance the sums by considering the potential effect of changing each element by up to 5 (from 1 to 6).
{{< dots >}}
### Edge Cases 🌐
- Ensure that neither array is empty.
- The solution should handle large arrays efficiently, up to the limit of 10^5 elements.
- Consider cases where the difference between the sums is too large to be fixed, such as when one sum is much larger than the other.
- Respect the constraint that the elements of nums1 and nums2 must be between 1 and 6.
{{< dots >}}
## Code 💻
```cpp
int minOperations(vector<int>& nums1, vector<int>& nums2) {
    if( nums1.size() > 6*nums2.size() || 
        nums2.size() > 6*nums1.size())
        return -1;
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

    if(sum1 > sum2) return minOperations(nums2, nums1);

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = nums2.size() - 1, ops = 0;
    while(sum2 > sum1) {

        if(j < 0 || i < nums1.size() && 6 - nums1[i] > nums2[j] - 1) {
            sum1 += 6 - nums1[i++];
        } else {
            sum2 -= nums2[j--] - 1;
        }

        ++ops;
    }
    return ops;
}
```

This function calculates the minimum number of operations needed to make the sum of the first list (`nums1`) greater than or equal to the sum of the second list (`nums2`). It performs operations where elements of the list `nums1` are incremented to 6, or elements of `nums2` are decremented by 1, until the sum of `nums1` is no less than the sum of `nums2`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minOperations(vector<int>& nums1, vector<int>& nums2) {
	```
	Define the function `minOperations` that takes two integer vectors `nums1` and `nums2` and returns the minimum number of operations required to balance their sums.

2. **Condition Check**
	```cpp
	    if( nums1.size() > 6*nums2.size() || 
	```
	Check if the size of `nums1` is more than six times the size of `nums2`, or if `nums2` is more than six times the size of `nums1`. If so, return -1 as no solution is possible.

3. **Condition Check**
	```cpp
	        nums2.size() > 6*nums1.size())
	```
	Continuing the condition check to ensure the size constraints are met. If the sizes don't meet the criteria, return -1.

4. **Return Statement**
	```cpp
	        return -1;
	```
	If the size condition is not met, return `-1`, indicating it's not possible to balance the sums.

5. **Sum Calculation**
	```cpp
	    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
	```
	Calculate the sum of all elements in `nums1` using the `accumulate` function.

6. **Sum Calculation**
	```cpp
	    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
	```
	Calculate the sum of all elements in `nums2` using the `accumulate` function.

7. **Recursive Call**
	```cpp
	    if(sum1 > sum2) return minOperations(nums2, nums1);
	```
	If the sum of `nums1` is greater than `nums2`, call the function recursively with the lists swapped to ensure `nums1` is the smaller list.

8. **Sorting**
	```cpp
	    sort(nums1.begin(), nums1.end());
	```
	Sort `nums1` in ascending order to facilitate the smallest possible operations.

9. **Sorting**
	```cpp
	    sort(nums2.begin(), nums2.end());
	```
	Sort `nums2` in ascending order to facilitate the largest possible operations.

10. **Variable Initialization**
	```cpp
	    int i = 0, j = nums2.size() - 1, ops = 0;
	```
	Initialize indices `i` for `nums1`, `j` for `nums2`, and a variable `ops` to keep track of the number of operations.

11. **While Loop**
	```cpp
	    while(sum2 > sum1) {
	```
	Start a `while` loop that runs until `sum1` is greater than or equal to `sum2`.

12. **Condition Check**
	```cpp
	        if(j < 0 || i < nums1.size() && 6 - nums1[i] > nums2[j] - 1) {
	```
	Check if `j` is out of bounds or if the next operation on `nums1[i]` would be more beneficial than decrementing `nums2[j]`.

13. **Update Sum1**
	```cpp
	            sum1 += 6 - nums1[i++];
	```
	If the operation on `nums1[i]` is more beneficial, increment `sum1` by the difference between 6 and the current value of `nums1[i]`, then increment `i`.

14. **Else Condition**
	```cpp
	        } else {
	```
	If the condition above is false, proceed to decrement `nums2[j]` instead.

15. **Update Sum2**
	```cpp
	            sum2 -= nums2[j--] - 1;
	```
	Decrement `sum2` by `nums2[j] - 1`, then decrement `j`.

16. **Operation Count**
	```cpp
	        ++ops;
	```
	Increment the `ops` variable to count the operation performed.

17. **Return Statement**
	```cpp
	    return ops;
	```
	Return the total number of operations required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The dominant operation is sorting the arrays.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space complexity is O(n) due to the space required for sorting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/description/)

---
{{< youtube n-BwszD77og >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
