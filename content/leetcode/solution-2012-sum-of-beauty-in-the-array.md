
+++
authors = ["grid47"]
title = "Leetcode 2012: Sum of Beauty in the Array"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2012: Sum of Beauty in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pOb_fN_-rzo"
youtube_upload_date="2021-09-19"
youtube_thumbnail="https://i.ytimg.com/vi/pOb_fN_-rzo/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array 'nums'. For each index i (1 <= i <= nums.length - 2), calculate the beauty of nums[i] based on the following conditions:

- The beauty of nums[i] is 2 if for all indices j before i and for all indices k after i, nums[j] < nums[i] < nums[k].
- The beauty of nums[i] is 1 if nums[i-1] < nums[i] < nums[i+1] but the previous condition is not met.
- The beauty of nums[i] is 0 if neither of the above conditions holds.

Return the sum of beauty values for all nums[i] where 1 <= i <= nums.length - 2.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of integers, nums, representing the array.
- **Example:** `nums = [1, 5, 3, 6, 2]`
- **Constraints:**
	- 3 <= nums.length <= 100000
	- 1 <= nums[i] <= 100000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.
- **Example:** `Output: 3`
- **Constraints:**
	- The result will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently calculate the sum of beauties for all indices i where 1 <= i <= nums.length - 2.

- Precompute the 'left' and 'right' arrays that hold the smallest and largest values for each index i respectively.
- Iterate over the array and calculate the beauty for each index based on the given conditions.
- Sum the beauties and return the total.
{{< dots >}}
### Problem Assumptions ✅
- You are assuming the array has at least 3 elements.
- There will be no invalid indices; the index range for beauty calculation is between 1 and nums.length - 2.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: nums = [1, 5, 3, 6, 2]`  \
  **Explanation:** For each index i in the range 1 <= i <= 3: The beauty of nums[1] is 2 (because nums[0] < nums[1] < nums[2], nums[3], nums[4]). The beauty of nums[2] is 1 (because nums[1] < nums[2] < nums[3] but doesn't meet the first condition). The beauty of nums[3] is 0 (it doesn't satisfy any condition). Sum = 2 + 1 + 0 = 3.

- **Input:** `Example 2: Input: nums = [4, 2, 7]`  \
  **Explanation:** For each index i in the range 1 <= i <= 1: The beauty of nums[1] is 1 (because nums[0] < nums[1] < nums[2] but doesn't meet the first condition). Sum = 1.

- **Input:** `Example 3: Input: nums = [10, 5, 2]`  \
  **Explanation:** For each index i in the range 1 <= i <= 1: The beauty of nums[1] is 0 (it doesn't satisfy any condition). Sum = 0.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to identify the beauty conditions for each index i and efficiently compute the beauty values using a sliding window approach.

### Initial Thoughts 💭
- The conditions involve comparing nums[i] with both its neighbors and all previous and future elements.
- The sliding window approach can help precompute left and right bounds efficiently.
- We can optimize the calculation by precomputing two arrays, 'left' and 'right', to store the necessary values for each index, thus avoiding nested loops.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty due to the constraint of nums.length being at least 3.
- For large arrays with up to 100,000 elements, we ensure the algorithm runs efficiently in O(n) time.
- When all elements are the same, the beauty of all indices will be 0.
- Ensure that the input array follows the constraint of having at least 3 elements.
{{< dots >}}
## Code 💻
```cpp
int sumOfBeauties(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int,int>> left(n), right(n);

    left[0] = make_pair(nums[0], 0);
    for(int i = 1; i < n; i++)
        if(nums[i] >= left[i - 1].first) {
            left[i] = make_pair(nums[i], i);
        } else left[i] = left[i - 1];
    
    right[n-1] = make_pair(nums[n - 1], n - 1);
    for(int i = n - 2; i >= 0; i--)
        if(nums[i] <= right[i + 1].first) {
            right[i] = make_pair(nums[i], i);
        } else right[i] = right[i + 1];
    
    int sum = 0;
    for(int i = 1; i < n - 1; i++) {
        if(left[i - 1].first < nums[i] && right[i + 1].first > nums[i])
            sum += 2;
        else if(nums[i-1] < nums[i] && nums[i + 1] > nums[i])
            sum += 1;
        else sum += 0;
    }
    return sum;
}
```

This function calculates the sum of beauties of the elements in the `nums` array. Each element's beauty is determined by comparing it with its neighbors, and the final sum is returned.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumOfBeauties(vector<int>& nums) {
	```
	Defines the function `sumOfBeauties`, which takes a vector of integers `nums` and calculates the sum of beauties for each element based on specific rules.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes the variable `n` to store the size of the `nums` vector, which is used in subsequent iterations.

3. **Variable Initialization**
	```cpp
	    vector<pair<int,int>> left(n), right(n);
	```
	Creates two vectors of pairs `left` and `right` to store the largest element and its index for each element, from left and right directions respectively.

4. **Left Array Initialization**
	```cpp
	    left[0] = make_pair(nums[0], 0);
	```
	Initializes the first element of the `left` array with the first element of `nums` and its index.

5. **Loop Initialization**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	Begins a for loop to iterate through the `nums` vector, starting from the second element.

6. **Conditional Check**
	```cpp
	        if(nums[i] >= left[i - 1].first) {
	```
	Checks if the current element `nums[i]` is greater than or equal to the largest element seen so far from the left (i.e., `left[i - 1]`), which would update the `left` array.

7. **Update Left Array**
	```cpp
	            left[i] = make_pair(nums[i], i);
	```
	Updates the `left` array with the current element `nums[i]` and its index.

8. **Left Array Continuation**
	```cpp
	        } else left[i] = left[i - 1];
	```
	If the current element `nums[i]` is smaller than the previous largest element from the left, the current `left[i]` is set to the previous value.

9. **Right Array Initialization**
	```cpp
	    right[n-1] = make_pair(nums[n - 1], n - 1);
	```
	Initializes the last element of the `right` array with the last element of `nums` and its index.

10. **Loop Initialization**
	```cpp
	    for(int i = n - 2; i >= 0; i--)
	```
	Begins a reverse loop from the second-to-last element of `nums` to the first element.

11. **Conditional Check**
	```cpp
	        if(nums[i] <= right[i + 1].first) {
	```
	Checks if the current element `nums[i]` is less than or equal to the smallest element seen so far from the right (i.e., `right[i + 1]`).

12. **Update Right Array**
	```cpp
	            right[i] = make_pair(nums[i], i);
	```
	Updates the `right` array with the current element `nums[i]` and its index.

13. **Right Array Continuation**
	```cpp
	        } else right[i] = right[i + 1];
	```
	If the current element `nums[i]` is greater than the smallest element from the right, the current `right[i]` is set to the previous value.

14. **Sum Initialization**
	```cpp
	    int sum = 0;
	```
	Initializes the variable `sum` to 0, which will hold the final beauty sum.

15. **Loop Initialization**
	```cpp
	    for(int i = 1; i < n - 1; i++) {
	```
	Begins a loop to iterate over the middle elements of the `nums` array, excluding the first and last elements.

16. **Conditional Check**
	```cpp
	        if(left[i - 1].first < nums[i] && right[i + 1].first > nums[i])
	```
	Checks if the current element `nums[i]` is greater than the previous element in the `left` array and smaller than the next element in the `right` array.

17. **Update Sum**
	```cpp
	            sum += 2;
	```
	If the condition is true, adds 2 to the `sum`, indicating a higher beauty for `nums[i]`.

18. **Conditional Check**
	```cpp
	        else if(nums[i-1] < nums[i] && nums[i + 1] > nums[i])
	```
	Checks if `nums[i]` is greater than the previous element and smaller than the next element, indicating a lower beauty.

19. **Update Sum**
	```cpp
	            sum += 1;
	```
	If the condition is true, adds 1 to the `sum`, indicating a lower beauty for `nums[i]`.

20. **Sum Continuation**
	```cpp
	        else sum += 0;
	```
	If neither condition is true, adds 0 to the `sum`.

21. **Return Statement**
	```cpp
	    return sum;
	```
	Returns the final value of `sum`, which is the sum of beauties of the elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input array.
- **Average Case:** O(n), where n is the length of the input array.
- **Worst Case:** O(n), where n is the length of the input array.

The time complexity is linear since we only traverse the array a constant number of times.

### Space Complexity 💾
- **Best Case:** O(n), as the space complexity remains the same even in the best case.
- **Worst Case:** O(n), where n is the length of the input array, due to the space used by the left and right arrays.

The space complexity is linear due to the extra space used for the left and right arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-beauty-in-the-array/description/)

---
{{< youtube pOb_fN_-rzo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
