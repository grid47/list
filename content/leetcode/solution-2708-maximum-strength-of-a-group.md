
+++
authors = ["grid47"]
title = "Leetcode 2708: Maximum Strength of a Group"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2708: Maximum Strength of a Group in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Greedy","Bit Manipulation","Sorting","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Kqv0-lRVYwM"
youtube_upload_date="2023-05-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Kqv0-lRVYwM/maxresdefault.webp"
comments = true
+++



---
You are given an integer array representing the scores of students in an exam. Your task is to form a non-empty group of students such that the group's strength, defined as the product of their scores, is maximized. The goal is to return the maximum possible strength that can be achieved by choosing an optimal group of students.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers representing the scores of the students.
- **Example:** `Input: nums = [1, -3, 2, -1, 4]`
- **Constraints:**
	- 1 <= nums.length <= 13
	- -9 <= nums[i] <= 9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible strength of a group of students formed from the input array.
- **Example:** `Output: 72`
- **Constraints:**
	- The result must be the maximum product of selected scores.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the product of scores by selecting an optimal subset of the array elements.

- Step 1: Calculate the product of positive numbers and the product of negative numbers in the array.
- Step 2: Handle special cases where the number of negative numbers is odd.
- Step 3: If there are zeros, consider excluding the negative numbers or zeros to maximize the product.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, -2, 4, -1]`  \
  **Explanation:** We can select the elements [3, -2, 4] to maximize the product. The strength would be 3 * -2 * 4 = -24.

- **Input:** `Input: nums = [5, -6, 3, -2, -1]`  \
  **Explanation:** The maximum strength can be achieved by selecting the elements [5, -6, 3], with a product of 5 * -6 * 3 = 90.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to consider the potential of both positive and negative numbers in the array to maximize the product.

### Initial Thoughts 💭
- A product of negative numbers can be positive if the number of negative numbers is even.
- If there is a zero in the array, we might use it to avoid negative products.
- The optimal solution will involve careful consideration of negative and positive numbers, and possibly excluding negative products if they would decrease the overall strength.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty, as per constraints.
- The solution should work within the constraints, considering arrays with up to 13 elements.
- If all numbers are zero, the result should be 0.
- If there is only one element, return that element.
- Ensure handling of negative numbers and zeros in the array.
{{< dots >}}
## Code 💻
```cpp
long long maxStrength(vector<int>& nums) {
    
    bool zero = false, allneg = true, allzero = true, pos = false;
    
    int ncnt = 0, pcnt = 0;
    
    long long ans = 1, neg = 1;
    int mxn = -10;
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        if(nums[i] > 0) {
            pcnt++;
            pos = true;
            allzero = false;
            allneg = false;
            ans *= nums[i];
        } else if(nums[i] == 0) {
            zero = true;
        } else {
            ncnt++;
            allzero = false;                
            mxn= max(mxn, nums[i]);
            neg *= nums[i];
        }
    }
    
    if(allzero) return 0;
    
    if(ncnt > 0 && (ncnt %2)) {
        if(pcnt == 0 && ncnt == 1) return zero? 0: neg; 
        neg = neg / mxn;
    }
    

    if(pcnt == 0) {
        return neg;
    }
    
    return ans * neg;
}
```

This function `maxStrength` takes a vector of integers `nums` and calculates the maximum strength of the array by considering the product of positive, negative, and zero values with special handling for edge cases like all elements being zero or the presence of an odd number of negative values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long maxStrength(vector<int>& nums) {
	```
	Start of the `maxStrength` function that takes a vector of integers `nums` and returns a long long value representing the maximum strength.

2. **Variable Initialization**
	```cpp
	    bool zero = false, allneg = true, allzero = true, pos = false;
	```
	Initialize variables: `zero` to track if there are any zeros, `allneg` to check if all numbers are negative, `allzero` to check if all numbers are zero, and `pos` to check if there are any positive numbers.

3. **Counter Variables**
	```cpp
	    int ncnt = 0, pcnt = 0;
	```
	Initialize counters: `ncnt` for negative numbers and `pcnt` for positive numbers.

4. **Initialization of Answer Variables**
	```cpp
	    long long ans = 1, neg = 1;
	```
	Initialize variables `ans` and `neg` to 1 to hold the product of positive numbers and negative numbers, respectively.

5. **Empty Line**
	```cpp
	    int mxn = -10;
	```
	Initialize `mxn` to -10 to keep track of the largest negative number.

6. **Initialize Array Size**
	```cpp
	    int n = nums.size();
	```
	Get the size of the input vector `nums` and store it in the variable `n`.

7. **Loop Through Array**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to iterate over each element of the vector `nums`.

8. **Check Positive Value**
	```cpp
	        if(nums[i] > 0) {
	```
	Check if the current number is positive.

9. **Increment Positive Counter**
	```cpp
	            pcnt++;
	```
	Increment the `pcnt` counter for positive numbers.

10. **Set Positive Flag**
	```cpp
	            pos = true;
	```
	Set the `pos` flag to true indicating that a positive number has been found.

11. **Update Zero Flag**
	```cpp
	            allzero = false;
	```
	Set `allzero` to false as we have found a non-zero number.

12. **Update Negative Flag**
	```cpp
	            allneg = false;
	```
	Set `allneg` to false as we have found a non-negative number.

13. **Multiply Positive Value**
	```cpp
	            ans *= nums[i];
	```
	Multiply the current positive number with `ans` to accumulate the product.

14. **Check for Zero**
	```cpp
	        } else if(nums[i] == 0) {
	```
	Check if the current number is zero.

15. **Set Zero Flag**
	```cpp
	            zero = true;
	```
	Set the `zero` flag to true indicating that a zero has been found.

16. **Handle Negative Value**
	```cpp
	        } else {
	```
	Handle the case where the current number is negative.

17. **Increment Negative Counter**
	```cpp
	            ncnt++;
	```
	Increment the `ncnt` counter for negative numbers.

18. **Update Zero Flag Again**
	```cpp
	            allzero = false;                
	```
	Set `allzero` to false again as we found a non-zero number.

19. **Update Maximum Negative**
	```cpp
	            mxn= max(mxn, nums[i]);
	```
	Update `mxn` to keep track of the largest negative number.

20. **Multiply Negative Value**
	```cpp
	            neg *= nums[i];
	```
	Multiply the current negative number with `neg` to accumulate the product of negative numbers.

21. **Check if All Zeroes**
	```cpp
	    if(allzero) return 0;
	```
	Check if all numbers in the array were zero and return 0 in that case.

22. **Handle Odd Number of Negatives**
	```cpp
	    if(ncnt > 0 && (ncnt %2)) {
	```
	If there are negative numbers and their count is odd, handle by excluding the largest negative number.

23. **Handle Special Case for One Negative**
	```cpp
	        if(pcnt == 0 && ncnt == 1) return zero? 0: neg; 
	```
	If there are no positive numbers and exactly one negative number, return the product (either zero or the negative value).

24. **Update Negative Product**
	```cpp
	        neg = neg / mxn;
	```
	Remove the largest negative number from the product of negative numbers.

25. **Check for No Positive Numbers**
	```cpp
	    if(pcnt == 0) {
	```
	Check if there are no positive numbers in the array.

26. **Return Negative Product**
	```cpp
	        return neg;
	```
	Return the product of negative numbers if there are no positive numbers.

27. **Return Maximum Strength**
	```cpp
	    return ans * neg;
	```
	Return the final product of positive and negative values as the maximum strength.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we are iterating through the array only once to compute the necessary product and handle special cases.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we are only using a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-strength-of-a-group/description/)

---
{{< youtube Kqv0-lRVYwM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
