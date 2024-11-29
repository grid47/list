
+++
authors = ["grid47"]
title = "Leetcode 2746: Decremental String Concatenation"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2746: Decremental String Concatenation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "RxvXIWCooRE"
youtube_upload_date="2023-06-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RxvXIWCooRE/maxresdefault.webp"
comments = true
+++



---
You are given an array of distinct strings. Your task is to perform n-1 join operations optimally to minimize the length of the final string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `words` of size `n` where each element is a distinct string.
- **Example:** `words = ["xx", "xy", "yz"]`
- **Constraints:**
	- 1 <= words.length <= 1000
	- 1 <= words[i].length <= 50
	- Each character in words[i] is a lowercase English letter

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible length of the final string after performing the join operations.
- **Example:** `4`
- **Constraints:**
	- The output will be an integer representing the minimum possible length.

{{< dots >}}
### Core Logic 🔍
**Goal:** Minimize the final length of the string by choosing optimal join operations at each step.

- Start with the first string in the array.
- For each subsequent string, try both possible join operations (str(i-1) + words[i] or words[i] + str(i-1)) and choose the one that minimizes the length.
- Repeat this process for all strings.
{{< dots >}}
### Problem Assumptions ✅
- Each string in the array is distinct.
- The array may contain up to 1000 strings.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ["xx", "xy", "yz"]`  \
  **Explanation:** By performing the join operations in the optimal order, we minimize the final length to 4.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves dynamic programming with memoization to store the results of subproblems.

### Initial Thoughts 💭
- The problem asks us to minimize the final string length by performing optimal join operations.
- We need to consider two possible join operations for each string and choose the one that minimizes the length.
- A dynamic programming approach with memoization can help solve this problem efficiently.
{{< dots >}}
### Edge Cases 🌐
- An empty input array should return 0.
- Handle arrays with up to 1000 strings efficiently.
- Consider cases where all strings have the same characters.
- Ensure that the solution works within the time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
int n ; 
int dp[1010][26][26] ;  
int rec(int level , int first , int last , vector <string>& arr){
    if(level == n){
        return 0 ; 
    }
    if(dp[level][first][last] != -1){
        return dp[level][first][last] ; 
    }
    int ans = 1e9 ;
    int t = (int)arr[level].size() ; 
    if(arr[level][t-1] - 'a' == first){
        ans = min(ans , t-1 + rec(level+1 , arr[level][0] - 'a' , last , arr) ) ; 
    }
    ans = min(ans , t + rec(level+1 , arr[level][0] - 'a' , last , arr)) ; 
    if(arr[level][0] - 'a' == last){
        ans = min(ans , t-1 + rec(level+1 , first , arr[level][t-1] - 'a' , arr)) ; 
    }
    ans = min(ans , t + rec(level+1 , first , arr[level][t-1] - 'a' , arr)) ; 
    return dp[level][first][last] = ans ; 
}


int minimizeConcatenatedLength(vector<string>& words) {
    n = (int)words.size() ; 
    memset(dp , -1 , sizeof(dp)) ; 
    int t = (int)words[0].size() ; 
    int ans = t + rec(1 , words[0][0] -'a' , words[0][t-1]-'a' , words) ; 
    return ans ; 
}
```

This function minimizes the concatenated length of a list of strings such that the first character of the current word matches the last character of the previous word.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int n ; 
	```
	Declares the integer variable `n` to store the number of words in the input list.

2. **Array Initialization**
	```cpp
	int dp[1010][26][26] ;  
	```
	Declares a 3D array `dp` to store intermediate results for dynamic programming (with dimensions for words, first and last characters).

3. **Function Definition**
	```cpp
	int rec(int level , int first , int last , vector <string>& arr){
	```
	Defines the recursive function `rec` that calculates the minimum concatenated length from a specific `level` of the word list, considering the `first` and `last` characters of the current word.

4. **Base Case**
	```cpp
	    if(level == n){
	```
	Checks if the function has processed all words in the list.

5. **Base Case Return**
	```cpp
	        return 0 ; 
	```
	Returns 0 if all words have been processed, indicating no more concatenation is needed.

6. **Memoization Check**
	```cpp
	    if(dp[level][first][last] != -1){
	```
	Checks if the result for this specific subproblem has already been computed and stored.

7. **Memoization Return**
	```cpp
	        return dp[level][first][last] ; 
	```
	Returns the stored result from the `dp` array if it has been previously computed.

8. **Initialization of Answer**
	```cpp
	    int ans = 1e9 ;
	```
	Initializes the variable `ans` to a large number, representing the best possible answer for the current subproblem.

9. **String Length Calculation**
	```cpp
	    int t = (int)arr[level].size() ; 
	```
	Calculates the length `t` of the current word at `level`.

10. **First Character Check**
	```cpp
	    if(arr[level][t-1] - 'a' == first){
	```
	Checks if the last character of the current word matches the `first` character from the previous word.

11. **Recursive Call with Matching Last Character**
	```cpp
	        ans = min(ans , t-1 + rec(level+1 , arr[level][0] - 'a' , last , arr) ) ; 
	```
	Recursively calculates the minimum concatenated length if the last character of the current word matches the first character of the previous word.

12. **Recursive Call without Matching Last Character**
	```cpp
	    ans = min(ans , t + rec(level+1 , arr[level][0] - 'a' , last , arr)) ; 
	```
	Recursively calculates the minimum concatenated length if the last character does not match.

13. **Last Character Check**
	```cpp
	    if(arr[level][0] - 'a' == last){
	```
	Checks if the first character of the current word matches the `last` character of the previous word.

14. **Recursive Call with Matching First Character**
	```cpp
	        ans = min(ans , t-1 + rec(level+1 , first , arr[level][t-1] - 'a' , arr)) ; 
	```
	Recursively calculates the minimum concatenated length if the first character of the current word matches the last character of the previous word.

15. **Recursive Call without Matching First Character**
	```cpp
	    ans = min(ans , t + rec(level+1 , first , arr[level][t-1] - 'a' , arr)) ; 
	```
	Recursively calculates the minimum concatenated length if the first character does not match.

16. **Memoization Store**
	```cpp
	    return dp[level][first][last] = ans ; 
	```
	Stores the computed result for the current subproblem in the `dp` array.

17. **Function Definition**
	```cpp
	int minimizeConcatenatedLength(vector<string>& words) {
	```
	Defines the main function to minimize the concatenated length of the words.

18. **Words Size Calculation**
	```cpp
	    n = (int)words.size() ; 
	```
	Calculates the number of words in the input list.

19. **Memory Initialization**
	```cpp
	    memset(dp , -1 , sizeof(dp)) ; 
	```
	Initializes the `dp` array with -1 to indicate that no subproblem has been solved yet.

20. **Word Length Calculation**
	```cpp
	    int t = (int)words[0].size() ; 
	```
	Calculates the length of the first word in the list.

21. **Recursive Call to Minimize Length**
	```cpp
	    int ans = t + rec(1 , words[0][0] -'a' , words[0][t-1]-'a' , words) ; 
	```
	Starts the recursion with the first word and calculates the minimized concatenated length.

22. **Return Result**
	```cpp
	    return ans ; 
	```
	Returns the minimized concatenated length as the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m * 26 * 26)

Where n is the number of strings, and m is the average length of each string.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n * 26 * 26)

The space complexity is dominated by the DP table storing results for each string and character pair.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/decremental-string-concatenation/description/)

---
{{< youtube RxvXIWCooRE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
