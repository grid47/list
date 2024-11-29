
+++
authors = ["grid47"]
title = "Leetcode 1415: The k-th Lexicographical String of All Happy Strings of Length n"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1415: The k-th Lexicographical String of All Happy Strings of Length n in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking"]
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
A happy string consists of only the letters 'a', 'b', and 'c', and no two consecutive characters in the string are the same. Given two integers n and k, return the kth happy string of length n sorted in lexicographical order, or an empty string if there are fewer than k happy strings of length n.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers n and k.
- **Example:** `n = 2, k = 4`
- **Constraints:**
	- 1 <= n <= 10
	- 1 <= k <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the kth happy string of length n or an empty string if there are fewer than k happy strings of length n.
- **Example:** `For n = 2, k = 4, the output is 'ba'.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Generate all happy strings of length n in lexicographical order and return the kth string.

- Use backtracking to generate all possible happy strings.
- Sort the strings lexicographically.
- Return the kth string, or an empty string if there are fewer than k happy strings.
{{< dots >}}
### Problem Assumptions ✅
- The value of k will always be within the range for the given n.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 2, k = 4`  \
  **Explanation:** The list of happy strings of length 2 is ['ab', 'ac', 'ba', 'bc', 'ca', 'cb']. The 4th string is 'ba'.

- **Input:** `Input: n = 3, k = 6`  \
  **Explanation:** The list of happy strings of length 3 is ['aba', 'abc', 'aca', 'acb', 'bab', 'bac', 'bca', 'bcb', 'cab', 'cac', 'cba', 'cbc']. The 6th string is 'bca'.

{{< dots >}}
## Approach 🚀
Generate all happy strings of length n using a backtracking approach and return the kth string.

### Initial Thoughts 💭
- The backtracking approach can be used to construct the strings while ensuring the condition of no two consecutive characters being the same.
- Backtracking allows us to efficiently explore all possible combinations of characters while checking for the happy string conditions.
{{< dots >}}
### Edge Cases 🌐
- k is larger than the number of possible happy strings of length n.
- For n = 10, handle cases where the number of strings is large.
- If k exceeds the number of possible happy strings of length n, return an empty string.
- Ensure the function works efficiently within the given bounds for both n and k.
{{< dots >}}
## Code 💻
```cpp
string ans = "";
int cnt = 0;
int k, n;

string getHappyString(int n, int k) {
    this->k = k;
    this->n = n;
    string tmp = "";
    bt(-1, tmp);
    return ans;
}

void bt(int prv, string &tmp) {
    if(tmp.size() == n) {
        cnt++;
        if(cnt == k){
          ans = tmp;  
        } 
        return;
    }

    for(int i = 0; i < 3; i++) {
        if(prv == i) continue;
        if(i == 0) {
            tmp += 'a';
        } else if(i == 1) {
            tmp += 'b';
        } else if(i == 2) {
            tmp += 'c';
        }
        bt(i, tmp);
        tmp.pop_back();
    }
}
```

The function `getHappyString` finds the `k`-th lexicographically smallest happy string of length `n`. A happy string contains only the characters 'a', 'b', and 'c', and no two adjacent characters are the same. The recursive function `bt` is used to generate all happy strings and return the `k`-th one.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	string ans = "";
	```
	Initializes an empty string `ans` to store the final happy string when found.

2. **Variable Initialization**
	```cpp
	int cnt = 0;
	```
	Initializes a counter `cnt` to keep track of how many happy strings have been generated.

3. **Variable Declaration**
	```cpp
	int k, n;
	```
	Declares two integer variables `k` (the index of the desired happy string) and `n` (the length of the happy string).

4. **Function Definition**
	```cpp
	string getHappyString(int n, int k) {
	```
	Defines the function `getHappyString`, which takes two integers `n` (length of the string) and `k` (the desired string's lexicographical index).

5. **Assignment**
	```cpp
	    this->k = k;
	```
	Assigns the value of `k` to the member variable `k` to be used by the recursive function.

6. **Assignment**
	```cpp
	    this->n = n;
	```
	Assigns the value of `n` to the member variable `n` for later use in the recursive function.

7. **Variable Initialization**
	```cpp
	    string tmp = "";
	```
	Initializes an empty string `tmp` that will be used to build potential happy strings.

8. **Function Call**
	```cpp
	    bt(-1, tmp);
	```
	Calls the recursive function `bt` with the initial previous character index `-1` and the empty string `tmp`.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the happy string `ans` once the `k`-th string has been found by the recursive function.

10. **Function Definition**
	```cpp
	void bt(int prv, string &tmp) {
	```
	Defines the recursive helper function `bt`, which generates all possible happy strings and checks if the `k`-th string is reached.

11. **Base Case**
	```cpp
	    if(tmp.size() == n) {
	```
	Checks if the current string `tmp` has reached the desired length `n`. If so, it proceeds to count it.

12. **Increment Operation**
	```cpp
	        cnt++;
	```
	Increments the counter `cnt` each time a string of length `n` is generated.

13. **Conditional Statement**
	```cpp
	        if(cnt == k){
	```
	Checks if the counter `cnt` has reached the desired `k`-th happy string. If so, it stores the string in `ans`.

14. **Assignment**
	```cpp
	          ans = tmp;  
	```
	Assigns the current string `tmp` to the variable `ans` when the `k`-th happy string is found.

15. **Return Statement**
	```cpp
	        return;
	```
	Returns from the recursive function once the desired string has been found or the base case is reached.

16. **Loop Constructs**
	```cpp
	    for(int i = 0; i < 3; i++) {
	```
	Begins a for loop that iterates over the three possible characters ('a', 'b', 'c') to add to the string `tmp`.

17. **Control Flow**
	```cpp
	        if(prv == i) continue;
	```
	Skips the current iteration if the character `i` is the same as the previous character (`prv`), ensuring no two adjacent characters are the same.

18. **String Manipulation**
	```cpp
	        if(i == 0) {
	```
	Checks if the current iteration is for the character 'a'.

19. **String Manipulation**
	```cpp
	            tmp += 'a';
	```
	Adds the character 'a' to the string `tmp`.

20. **Conditional Statement**
	```cpp
	        } else if(i == 1) {
	```
	Checks if the current iteration is for the character 'b'.

21. **String Manipulation**
	```cpp
	            tmp += 'b';
	```
	Adds the character 'b' to the string `tmp`.

22. **Conditional Statement**
	```cpp
	        } else if(i == 2) {
	```
	Checks if the current iteration is for the character 'c'.

23. **String Manipulation**
	```cpp
	            tmp += 'c';
	```
	Adds the character 'c' to the string `tmp`.

24. **Function Call**
	```cpp
	        bt(i, tmp);
	```
	Recursively calls the function `bt` with the new character added to `tmp` and the current character `i` as `prv`.

25. **String Manipulation**
	```cpp
	        tmp.pop_back();
	```
	Removes the last character added to `tmp` in preparation for the next iteration of the loop.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), if k is very small.
- **Average Case:** O(3^n), as we need to consider all possible combinations of characters.
- **Worst Case:** O(3^n), since we may have to generate all possible strings.

The time complexity grows exponentially with n due to the 3 choices at each step.

### Space Complexity 💾
- **Best Case:** O(1), if we are only generating a few strings.
- **Worst Case:** O(3^n), to store the strings generated.

The space complexity is proportional to the number of strings generated.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
