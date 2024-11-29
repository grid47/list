
+++
authors = ["grid47"]
title = "Leetcode 1276: Number of Burgers with No Waste of Ingredients"
date = "2024-07-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1276: Number of Burgers with No Waste of Ingredients in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
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
Given two integers tomatoSlices and cheeseSlices, return the number of Jumbo and Small burgers that can be made, such that all tomatoSlices and cheeseSlices are used. If it is not possible, return an empty list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers representing the number of tomato slices and cheese slices.
- **Example:** `Input: tomatoSlices = 16, cheeseSlices = 7`
- **Constraints:**
	- 0 <= tomatoSlices, cheeseSlices <= 10^7

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list with the number of Jumbo and Small burgers or an empty list if it is not possible.
- **Example:** `Output: [1, 6]`
- **Constraints:**
	- The number of burgers must use all of the given slices.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine how many Jumbo and Small burgers can be made using all the given tomato and cheese slices.

- Calculate the number of Jumbo burgers (which require 4 tomato slices and 1 cheese slice).
- Calculate the number of Small burgers (which require 2 tomato slices and 1 cheese slice).
- Check if the total number of ingredients can be used exactly without any leftovers.
{{< dots >}}
### Problem Assumptions ✅
- There are always positive integer values for tomatoSlices and cheeseSlices.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: tomatoSlices = 16, cheeseSlices = 7`  \
  **Explanation:** To make one Jumbo burger and six Small burgers, the total number of tomato slices and cheese slices will match exactly with the given inputs.

{{< dots >}}
## Approach 🚀
The problem can be solved using a simple mathematical approach by calculating the number of burgers and checking if the total slices are used up.

### Initial Thoughts 💭
- Each Jumbo burger requires 4 tomato slices and 1 cheese slice.
- Each Small burger requires 2 tomato slices and 1 cheese slice.
- We can calculate how many Jumbo burgers can be made using the formula (tomatoSlices - 2 * cheeseSlices) / 2. Then, check if the rest of the slices can form Small burgers.
{{< dots >}}
### Edge Cases 🌐
- If either tomatoSlices or cheeseSlices is zero, no burgers can be made.
- For very large inputs, ensure that the solution can handle up to 10^7 efficiently.
- If the number of tomatoSlices and cheeseSlices cannot form a valid combination, return an empty list.
- Ensure that no negative values are passed for tomatoSlices and cheeseSlices.
{{< dots >}}
## Code 💻
```cpp
vector<int> ans;
map<int, map<int, bool>> mp;
bool dp(int tmt, int chs, int one, int two) {
    if(tmt <= 0 || chs <= 0) {
        if(tmt == 0 && chs == 0) {
            ans = {one, two};
            return true;
        }
        return false;
    }
    
    if(mp.count(tmt) && mp[tmt].count(chs)) return mp[tmt][chs];
    
    if(tmt >= 4 && chs >= 1) {
        if(dp(tmt - 4, chs -1, one + 1, two))
            return mp[tmt][chs] = true;
        if(dp(tmt - 2, chs -1, one, two + 1))
            return mp[tmt][chs] = true;
    } else if(tmt >= 2 && chs >= 1) {
        if(dp(tmt - 2, chs -1, one, two + 1))
            return mp[tmt][chs] = true;            
    }
    return mp[tmt][chs] = false;
}

vector<int> numOfBurgers(int tmt, int chs) {
    ans = {};
    // dp(tmt, chs, 0, 0);
    int net = chs;
    int jumbo = (tmt - 2 * chs ) / 2;
 
    if(((tmt - 2 * chs ) < 0) || ((tmt - 2 * chs ) % 2) || (net - jumbo < 0)) return ans;
    
    return {jumbo, net - jumbo};
}
```

Implements a recursive dynamic programming solution with memoization and an optimized direct computation to solve the burger distribution problem.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> ans;
	```
	Initialize a vector to store the results of the solution.

2. **Map Operations**
	```cpp
	map<int, map<int, bool>> mp;
	```
	Declare a nested map for memoization to store intermediate results for dynamic programming.

3. **Function Definition**
	```cpp
	bool dp(int tmt, int chs, int one, int two) {
	```
	Define a recursive function for dynamic programming to find the solution.

4. **Conditional Check**
	```cpp
	    if(tmt <= 0 || chs <= 0) {
	```
	Check if the total or cheese constraints are invalid.

5. **Conditional Check**
	```cpp
	        if(tmt == 0 && chs == 0) {
	```
	Verify if the constraints are perfectly met.

6. **Vector Insertion**
	```cpp
	            ans = {one, two};
	```
	Assign the valid result to the answer vector.

7. **Return Statement**
	```cpp
	            return true;
	```
	Indicate success when constraints are satisfied.

8. **Return Statement**
	```cpp
	        return false;
	```
	Return false if constraints are not satisfied.

9. **Map Lookup**
	```cpp
	    if(mp.count(tmt) && mp[tmt].count(chs)) return mp[tmt][chs];
	```
	Check if the result for the given state is already computed.

10. **Recursive Call**
	```cpp
	    if(tmt >= 4 && chs >= 1) {
	```
	Check if sufficient tomatoes and cheese are available for a jumbo burger.

11. **Recursive Call**
	```cpp
	        if(dp(tmt - 4, chs -1, one + 1, two))
	```
	Attempt to use a jumbo burger and recursively solve the remaining problem.

12. **Memoization Update**
	```cpp
	            return mp[tmt][chs] = true;
	```
	Store the result in the memoization map and return success.

13. **Recursive Call**
	```cpp
	        if(dp(tmt - 2, chs -1, one, two + 1))
	```
	Attempt to use a small burger and recursively solve the remaining problem.

14. **Memoization Update**
	```cpp
	            return mp[tmt][chs] = true;
	```
	Store the result in the memoization map and return success.

15. **Return Statement**
	```cpp
	    return mp[tmt][chs] = false;
	```
	Return false and update the memoization map for the given state.

16. **Function Definition**
	```cpp
	vector<int> numOfBurgers(int tmt, int chs) {
	```
	Define the main function to compute the number of burgers.

17. **Variable Initialization**
	```cpp
	    ans = {};
	```
	Initialize the result vector as empty.

18. **Variable Initialization**
	```cpp
	    int net = chs;
	```
	Calculate the net cheese count.

19. **Mathematical Operation**
	```cpp
	    int jumbo = (tmt - 2 * chs ) / 2;
	```
	Compute the number of jumbo burgers using direct calculation.

20. **Conditional Check**
	```cpp
	    if(((tmt - 2 * chs ) < 0) || ((tmt - 2 * chs ) % 2) || (net - jumbo < 0)) return ans;
	```
	Validate the constraints for feasible burger counts.

21. **Return Statement**
	```cpp
	    return {jumbo, net - jumbo};
	```
	Return the calculated result with jumbo and small burgers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The solution only requires a constant number of operations regardless of input size.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

Only a constant amount of space is required.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
