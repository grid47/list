
+++
authors = ["grid47"]
title = "Leetcode 2965: Find Missing and Repeated Values"
date = "2024-01-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2965: Find Missing and Repeated Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6r-PQyoHHoQ"
youtube_upload_date="2023-12-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6r-PQyoHHoQ/maxresdefault.webp"
comments = true
+++



---
You are given a 2D integer matrix `grid` of size `n * n`. The matrix contains integers in the range [1, n²], and each number appears exactly once, except for two numbers. One number `a` is repeated twice, and another number `b` is missing. Find the repeating and missing numbers `a` and `b`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D matrix `grid` where the matrix size is `n * n` and contains values in the range [1, n²]. The matrix has one repeated number `a` and one missing number `b`.
- **Example:** `grid = [[4, 1], [2, 4]]`
- **Constraints:**
	- 2 <= n == grid.length == grid[i].length <= 50
	- 1 <= grid[i][j] <= n * n
	- Exactly one number appears twice and exactly one number is missing.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 0-indexed integer array of size 2 where `ans[0]` is the repeated number `a` and `ans[1]` is the missing number `b`.
- **Example:** `[4, 3]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Use XOR operations to efficiently find the repeated and missing numbers.

- XOR all numbers from 1 to n².
- XOR all elements from the grid.
- Find the differing bit between the repeated and missing numbers.
- Use the differing bit to segregate the numbers and identify `a` and `b`.
{{< dots >}}
### Problem Assumptions ✅
- The matrix will always have one repeated and one missing number.
- All integers are within the valid range [1, n²].
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[4, 1], [2, 4]]`  \
  **Explanation:** The repeated number is 4, and the missing number is 3. Hence, the result is [4, 3].

- **Input:** `Input: grid = [[1, 3, 4], [2, 1, 7], [8, 5, 9]]`  \
  **Explanation:** The repeated number is 1, and the missing number is 6. Hence, the result is [1, 6].

{{< dots >}}
## Approach 🚀
We solve this problem using XOR to efficiently find the repeated and missing numbers by comparing the XOR results of the expected and actual grid elements.

### Initial Thoughts 💭
- The problem involves finding two numbers: one that repeats and one that is missing from a sequence.
- Using XOR is a space-efficient method to find the difference between the expected and actual sequence.
{{< dots >}}
### Edge Cases 🌐
- The grid will not be empty, as per the constraints.
- Ensure that the solution efficiently handles the maximum grid size (50 x 50).
- Handle cases where the missing number is the largest or smallest possible number.
- Ensure the solution efficiently handles the XOR operations for large grids.
{{< dots >}}
## Code 💻
```cpp
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int first = 0;
    int sec = 0;
    
    int n = grid.size();
    
    //xor from 1 to n^2
    for(int i=1;i<=n*n;i++){
        first = first ^ i;
    }

    //xor all element from array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sec = sec ^ grid[i][j];
        }
    }


    int xorboth = first ^ sec;

    int diff_bit_pos = 0;
    //find differentiating bit postion from back
    for(int i=0;i<32;i++){
        if((xorboth & (1<<i))) {
            diff_bit_pos = i;
            break;
        }
    }

    int ans0 = 0;
    int ans1 = 0;

    //differentiate the both according to the diff_bit_pos
    for(int i=1;i<=n*n;i++){
        if(i & (1<<diff_bit_pos)){
            ans0 ^= i;
        }
        else{
            ans1 ^= i;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] & (1<<diff_bit_pos)){
                ans0 ^= grid[i][j];
            }
            else{
                ans1 ^= grid[i][j];
            }
        }
    }

    //finding the order of answer
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == ans0)
                //if ans0 is found then its repeating number
                return {ans0 , ans1};
        }
    }

    //if ans0 is found then its not a repeating number
    return {ans1 , ans0};
}
```

This function aims to find the missing and repeated values in an NxN grid by using bitwise XOR operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
	```
	Declares the function `findMissingAndRepeatedValues`, which takes a 2D vector (`grid`) and returns a vector of integers representing the missing and repeated values.

2. **Variable Initialization**
	```cpp
	    int first = 0;
	```
	Initializes the variable `first` to store the XOR result of numbers from 1 to n^2.

3. **Variable Initialization**
	```cpp
	    int sec = 0;
	```
	Initializes the variable `sec` to store the XOR result of all elements in the grid.

4. **Grid Size Calculation**
	```cpp
	    int n = grid.size();
	```
	Determines the size of the grid (NxN) and stores it in `n`.

5. **XOR Operation**
	```cpp
	    for(int i=1;i<=n*n;i++){
	```
	Iterates from 1 to n^2 to XOR all numbers between 1 and n^2, storing the result in `first`.

6. **XOR Operation**
	```cpp
	        first = first ^ i;
	```
	Applies the XOR operation between `first` and the current number `i`.

7. **XOR Operation**
	```cpp
	    for(int i=0;i<n;i++){
	```
	Begins the loop to XOR all elements in the grid.

8. **XOR Operation**
	```cpp
	        for(int j=0;j<n;j++){
	```
	Inner loop that iterates through each element in the grid.

9. **XOR Operation**
	```cpp
	            sec = sec ^ grid[i][j];
	```
	XORs each element in the grid with the variable `sec`.

10. **Bitwise XOR Result**
	```cpp
	    int xorboth = first ^ sec;
	```
	Applies XOR between `first` and `sec` to find the combined XOR result of all grid elements and numbers from 1 to n^2.

11. **Bitwise Operation**
	```cpp
	    int diff_bit_pos = 0;
	```
	Initializes the variable `diff_bit_pos` to store the position of the differentiating bit.

12. **Bitwise Operation**
	```cpp
	    for(int i=0;i<32;i++){
	```
	Loops through the bits of the XOR result `xorboth` to find the first differentiating bit.

13. **Bitwise Operation**
	```cpp
	        if((xorboth & (1<<i))) {
	```
	Checks if the `i`-th bit is set (1) in the XOR result.

14. **Bitwise Operation**
	```cpp
	            diff_bit_pos = i;
	```
	Sets `diff_bit_pos` to the position of the first differentiating bit.

15. **Bitwise Operation**
	```cpp
	            break;
	```
	Exits the loop once the differentiating bit is found.

16. **Variable Initialization**
	```cpp
	    int ans0 = 0;
	```
	Initializes `ans0` to store the first value based on the differentiating bit.

17. **Variable Initialization**
	```cpp
	    int ans1 = 0;
	```
	Initializes `ans1` to store the second value based on the differentiating bit.

18. **Bitwise Differentiation**
	```cpp
	    for(int i=1;i<=n*n;i++){
	```
	Iterates through all numbers from 1 to n^2 and divides them into two groups based on the differentiating bit.

19. **Bitwise Differentiation**
	```cpp
	        if(i & (1<<diff_bit_pos)){
	```
	Checks if the `i`-th number belongs to the group that has the differentiating bit set.

20. **Bitwise Differentiation**
	```cpp
	            ans0 ^= i;
	```
	XORs `ans0` with the current number if it belongs to the group with the differentiating bit set.

21. **Bitwise Differentiation**
	```cpp
	        else{
	```
	For the other group, XORs the number with `ans1`.

22. **Bitwise Differentiation**
	```cpp
	            ans1 ^= i;
	```
	XORs `ans1` with the current number.

23. **Bitwise Differentiation**
	```cpp
	    for(int i=0;i<n;i++){
	```
	Begins the loop to differentiate grid elements into the two groups based on the differentiating bit.

24. **Bitwise Differentiation**
	```cpp
	        for(int j=0;j<n;j++){
	```
	Inner loop to iterate through each grid element.

25. **Bitwise Differentiation**
	```cpp
	            if(grid[i][j] & (1<<diff_bit_pos)){
	```
	Checks if the current grid element belongs to the group with the differentiating bit set.

26. **Bitwise Differentiation**
	```cpp
	                ans0 ^= grid[i][j];
	```
	XORs `ans0` with the grid element if it belongs to this group.

27. **Bitwise Differentiation**
	```cpp
	            else{
	```
	For the other group, XORs the element with `ans1`.

28. **Bitwise Differentiation**
	```cpp
	                ans1 ^= grid[i][j];
	```
	XORs `ans1` with the grid element.

29. **Result Determination**
	```cpp
	    for(int i=0;i<n;i++){
	```
	Begins a loop to check which of `ans0` or `ans1` is the missing or repeated number.

30. **Result Determination**
	```cpp
	        for(int j=0;j<n;j++){
	```
	Iterates over each element in the grid to check for a match with `ans0`.

31. **Result Determination**
	```cpp
	            if(grid[i][j] == ans0)
	```
	Checks if the current grid element equals `ans0`.

32. **Result Determination**
	```cpp
	                return {ans0 , ans1};
	```
	Returns `ans0` as the repeated value and `ans1` as the missing value.

33. **Result Determination**
	```cpp
	    return {ans1 , ans0};
	```
	Returns `ans1` as the repeated value and `ans0` as the missing value if `ans0` wasn't found in the grid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n²)
- **Average Case:** O(n²)
- **Worst Case:** O(n²)

The time complexity is linear with respect to the size of the grid (n²), as we need to process each element twice.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only use a few variables to track the XOR results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-missing-and-repeated-values/description/)

---
{{< youtube 6r-PQyoHHoQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
