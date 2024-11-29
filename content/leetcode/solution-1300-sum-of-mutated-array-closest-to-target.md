
+++
authors = ["grid47"]
title = "Leetcode 1300: Sum of Mutated Array Closest to Target"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1300: Sum of Mutated Array Closest to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given an integer array `arr` and a target value `target`, return the integer value such that when all integers larger than this value are replaced by the value itself, the sum of the array is as close as possible to the target. If there is a tie, return the smallest such integer.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `arr` and an integer `target`.
- **Example:** `Input: arr = [5, 10, 3], target = 12`
- **Constraints:**
	- 1 <= arr.length <= 10^4
	- 1 <= arr[i], target <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the integer value that minimizes the absolute difference between the sum of the modified array and the target value.
- **Example:** `Output: 3`
- **Constraints:**
	- Return an integer representing the optimal value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the optimal integer value for modifying the array to match the target sum as closely as possible.

- Sort the array `arr` to make the process of finding the best value more efficient.
- Calculate the sum of the array and adjust the larger values to be equal to the current candidate value.
- Track the closest sum to the target, and in case of a tie, return the smallest value.
{{< dots >}}
### Problem Assumptions ✅
- The array `arr` consists of positive integers.
- The input is valid, and constraints are adhered to.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [5, 10, 3], target = 12`  \
  **Explanation:** When using the value 3, the array becomes [3, 3, 3], which gives a sum of 9. This is the closest sum to the target of 12.

- **Input:** `Input: arr = [1, 2, 3], target = 6`  \
  **Explanation:** Using the value 2, the array becomes [2, 2, 2], which exactly matches the target sum of 6.

- **Input:** `Input: arr = [100, 200, 300], target = 350`  \
  **Explanation:** Using the value 150, the array becomes [150, 150, 150], which gives a sum of 450. This is the closest sum to the target of 350.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we can consider sorting the array and finding the best integer by modifying the array's sum iteratively. This approach ensures that we calculate the closest sum without having to examine all possible values exhaustively.

### Initial Thoughts 💭
- The array's sum will be affected by replacing values larger than a given candidate with that candidate.
- Sorting the array will allow for efficient modification of the array as we check each potential candidate.
- We can use a greedy approach, adjusting values larger than the candidate and tracking the sum's proximity to the target.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that `arr` will contain at least one element.
- The solution must handle large arrays efficiently, ensuring time complexity remains manageable.
- If all values in the array are larger than the target, adjust all values to be equal to the target.
- The solution must work within the time limits for inputs of size up to 10^4.
{{< dots >}}
## Code 💻
```cpp
int findBestValue(vector<int>& A, int target) {
    sort(A.begin(), A.end());
    
    int n = A.size(), i = 0;
    while(i < n && target > A[i] * (n - i)) {
        target -= A[i++];
    }
    
    if (i == n) return A[n - 1];
    
    int res = target / (n - i);
    
    if (target - res * (n - i) > (res + 1) * (n - i) - target)
        res++;
    return res;
}
```

This function finds the best value that can be achieved by reducing or limiting the sum of the elements in the array such that the sum is as close as possible to a given target.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findBestValue(vector<int>& A, int target) {
	```
	This is the function header where the function is defined. The input parameters are 'A' (a vector of integers) and 'target' (the target sum to be achieved).

2. **Sorting**
	```cpp
	    sort(A.begin(), A.end());
	```
	Sorts the input vector 'A' in non-decreasing order. Sorting helps in efficiently calculating the optimal value to achieve the target sum.

3. **Size and Initialization**
	```cpp
	    int n = A.size(), i = 0;
	```
	Initializes 'n' with the size of array 'A' and 'i' to 0 to start iterating from the beginning of the array.

4. **While Loop**
	```cpp
	    while(i < n && target > A[i] * (n - i)) {
	```
	This while loop continues reducing the target by subtracting elements from 'A' until the remaining target cannot be further reduced by multiplying the current element with the remaining number of elements.

5. **Target Update**
	```cpp
	        target -= A[i++];
	```
	This line reduces the target by subtracting the current element 'A[i]' and then increments 'i' to move to the next element.

6. **Condition Check**
	```cpp
	    if (i == n) return A[n - 1];
	```
	Checks if all elements have been processed. If 'i' equals 'n', it means the target is achieved or exhausted, and the last element of the array 'A[n-1]' is returned.

7. **Intermediate Result Calculation**
	```cpp
	    int res = target / (n - i);
	```
	Calculates the intermediate result 'res' by dividing the remaining target by the number of elements left after 'i'. This gives an estimate of the value to set for the remaining elements.

8. **Condition for Increment**
	```cpp
	    if (target - res * (n - i) > (res + 1) * (n - i) - target)
	```
	Checks if the difference between the current target and the product of 'res' and the number of remaining elements is greater than the difference between '(res + 1)' and the target. If so, it indicates that increasing 'res' will yield a value closer to the target.

9. **Increment Result**
	```cpp
	        res++;
	```
	If the above condition is true, increment 'res' by 1 to bring it closer to the optimal value.

10. **Return Final Result**
	```cpp
	    return res;
	```
	Returns the computed value 'res' which is the optimal value that makes the sum closest to the target.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) - Sorting the array is the most time-consuming operation.
- **Average Case:** O(n log n) - Sorting dominates the complexity.
- **Worst Case:** O(n log n) - Sorting and the subsequent evaluation for each candidate value.

The time complexity is O(n log n) due to sorting the array.

### Space Complexity 💾
- **Best Case:** O(n) - Space complexity remains O(n) for the sorted array.
- **Worst Case:** O(n) - Space complexity is O(n) for storing the sorted array.

The space complexity is O(n) due to storing the array after sorting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
