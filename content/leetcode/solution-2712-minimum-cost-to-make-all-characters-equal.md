
+++
authors = ["grid47"]
title = "Leetcode 2712: Minimum Cost to Make All Characters Equal"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2712: Minimum Cost to Make All Characters Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8MHnlNroHaU"
youtube_upload_date="2023-05-28"
youtube_thumbnail="https://i.ytimg.com/vi/8MHnlNroHaU/maxresdefault.jpg"
comments = true
+++



---
You are given a binary string `s` of length `n`. You can perform two types of operations: (1) Flip all characters from index `0` to `i` (inclusive), with a cost of `i + 1`. (2) Flip all characters from index `i` to `n - 1` (inclusive), with a cost of `n - i`. The goal is to return the minimum cost required to make all the characters in the string equal (either all `0`s or all `1`s).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A binary string `s` of length `n`.
- **Example:** `s = "1101"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s[i] is either '0' or '1'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum cost to make all characters equal in the string.
- **Example:** `3`
- **Constraints:**
	- The output should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the minimum cost by applying the two types of operations on the string `s`.

- Iterate over the string to determine the best points to apply the flip operations.
- Apply the operations considering the costs and track the minimum cost.
{{< dots >}}
### Problem Assumptions ✅
- The input string is non-empty and contains only '0' and '1' characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** To make the string '1101' all '0's or all '1's, apply the first operation with `i = 1` (cost 2) and the second operation with `i = 2` (cost 1), giving a minimum total cost of 3.

- **Input:** `Example 2`  \
  **Explanation:** For the string '111000', applying the first operation with `i = 3` (cost 4) results in '111111', which is the minimum cost to make all characters equal.

{{< dots >}}
## Approach 🚀
The solution involves checking where to apply flip operations and computing the minimum cost for each scenario.

### Initial Thoughts 💭
- The operations can only flip from the beginning or from the end of the string.
- We need to identify points where flipping operations can be applied with minimum cost to make all characters equal.
{{< dots >}}
### Edge Cases 🌐
- An empty string is not a valid input.
- For large strings (near the upper constraint), the solution should be efficient (O(n) or O(n log n) time complexity).
- The string can already be uniform (all '0's or all '1's), in which case no operations are needed.
- The solution should handle up to 100,000 characters efficiently.
{{< dots >}}
## Code 💻
```cpp
long long minimumCost(string s) {
    /*
    
    0100111
    
    0000000 3 + 2 + 1        
    
    1011111 4 + 2 + 1   if odd len choose middle
    
    0101000
    1011111 3 + 3 + 2 + 1         
    0100000 4 + 3 + 2 + 1 if odd len choose middle
    
    010111
    
    011011
    
    011011  0/ 2 + 3 + 1
            1/ 3 + 2 + 1
    
    010011
    
    010000  2 + 2 + 1
    
    101111  3
    011111  3 + 2
    111111  3 + 2 + 1 = 6
    
    010000  3 = 3
    100000  3 + 2 = 5
    000000  3 + 2 + 1 = 6
    
    */
    
    int n = s.size();
    
    if(n == 1) return 0;
    long long res = 0;

    char k = s[n / 2];
    
    int i, j;
    
    if(n % 2)
        i = n/2 + 1, j = n/2 - 1;
    else i = n/2, j = n / 2 - 1;
        bool ltog = true, rtog = true;
        while(i < n && j >= 0) {
            if(s[i] == k && rtog || s[i] != k && !rtog) {
            } else {
                rtog = !rtog;
                res += n - i;
            }
            i++;
            if((s[j] == k && ltog) || (s[j] != k && !ltog)) {
            } else {
                ltog = !ltog;
                res += j + 1;
            }
            j--;                
        }
        return res;
}
```

The function calculates the minimum cost of converting a binary string into a specific target format by flipping characters in the most cost-effective manner.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **String Manipulations**
	```cpp
	long long minimumCost(string s) {
	```
	Defines the function to calculate the minimum cost of a string transformation.

2. **String Operations**
	```cpp
	    int n = s.size();
	```
	Finds the size of the input string `s`.

3. **Conditional Checks**
	```cpp
	    if(n == 1) return 0;
	```
	Handles the edge case where the string has only one character.

4. **Variable Initialization**
	```cpp
	    long long res = 0;
	```
	Initializes the result variable `res` to store the cost.

5. **Character Operations**
	```cpp
	    char k = s[n / 2];
	```
	Determines the target character from the middle of the string.

6. **Variable Initialization**
	```cpp
	    int i, j;
	```
	Declares indices for traversal from the middle outwards.

7. **Conditional Checks**
	```cpp
	    if(n % 2)
	```
	Checks whether the length of the string is odd.

8. **Index Calculation**
	```cpp
	        i = n/2 + 1, j = n/2 - 1;
	```
	Initializes traversal indices for an odd-length string.

9. **Index Calculation**
	```cpp
	    else i = n/2, j = n / 2 - 1;
	```
	Initializes traversal indices for an even-length string.

10. **Boolean Variables**
	```cpp
	        bool ltog = true, rtog = true;
	```
	Initializes toggle variables for tracking left and right flips.

11. **Loop Constructs**
	```cpp
	        while(i < n && j >= 0) {
	```
	Iterates over the string from the middle to the edges.

12. **Conditional Checks**
	```cpp
	            if(s[i] == k && rtog || s[i] != k && !rtog) {
	```
	Checks whether the current right character matches the target.

13. **No Operation**
	```cpp
	            } else {
	```
	Handles cases where no action is required.

14. **Boolean Operations**
	```cpp
	                rtog = !rtog;
	```
	Toggles the right flip state.

15. **Sum Calculation**
	```cpp
	                res += n - i;
	```
	Adds the cost of flipping the right character.

16. **Index Update**
	```cpp
	            i++;
	```
	Moves to the next right character.

17. **Conditional Checks**
	```cpp
	            if((s[j] == k && ltog) || (s[j] != k && !ltog)) {
	```
	Checks whether the current left character matches the target.

18. **No Operation**
	```cpp
	            } else {
	```
	Handles cases where no action is required.

19. **Boolean Operations**
	```cpp
	                ltog = !ltog;
	```
	Toggles the left flip state.

20. **Sum Calculation**
	```cpp
	                res += j + 1;
	```
	Adds the cost of flipping the left character.

21. **Index Update**
	```cpp
	            j--;                
	```
	Moves to the next left character.

22. **Return Statement**
	```cpp
	        return res;
	```
	Returns the total calculated cost.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution runs in linear time since we need to check each character at most once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses constant space as we only store a few variables to track the current state.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/description/)

---
{{< youtube 8MHnlNroHaU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
