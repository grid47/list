
+++
authors = ["grid47"]
title = "Leetcode 386: Lexicographical Numbers"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 386: Lexicographical Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/386.webp"
youtube = "n4YGTbFfU-w"
youtube_upload_date="2021-02-27"
youtube_thumbnail="https://i.ytimg.com/vi/n4YGTbFfU-w/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/386.webp" 
    alt="A glowing series of numbers arranged in lexicographical order, highlighting their progression."
    caption="Solution to LeetCode 386: Lexicographical Numbers Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order. The solution must run in O(n) time and use O(1) extra space.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer n.
- **Example:** `n = 15`
- **Constraints:**
	- 1 <= n <= 50,000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of integers from 1 to n, sorted in lexicographical order.
- **Example:** `Output: [1, 10, 11, 12, 13, 14, 15, 2, 3, 4, 5, 6, 7, 8, 9]`
- **Constraints:**
	- The output should contain all the numbers from 1 to n, sorted lexicographically.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate the numbers in lexicographical order without storing the entire list upfront and while maintaining an efficient time complexity.

- Start from 1 and recursively append the next lexicographically smaller number.
- For each number, attempt to add a zero to make it a 'child' of the current number.
- If the current number exceeds n, backtrack to the next number in the sequence.
{{< dots >}}
### Problem Assumptions ✅
- The input value n is valid and lies within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: 15`  \
  **Explanation:** The lexicographical order of the numbers from 1 to 15 is: 1, 10, 11, 12, 13, 14, 15, 2, 3, 4, 5, 6, 7, 8, 9.

{{< dots >}}
## Approach 🚀
The approach is to generate the numbers in lexicographical order by recursively trying to append digits to the current number. The recursion will be stopped when a number exceeds n.

### Initial Thoughts 💭
- We need to find a way to generate the numbers in lexicographical order without directly sorting the entire list.
- We can perform a depth-first search (DFS) from 1, appending digits to form lexicographically smaller numbers.
{{< dots >}}
### Edge Cases 🌐
- Input will always be a valid positive integer as per constraints.
- Ensure that the algorithm handles large values of n (up to 50,000) efficiently.
- For n = 1, the output is simply [1].
- The algorithm should generate the numbers in lexicographical order efficiently.
{{< dots >}}
## Code 💻
```cpp
int num;
vector<int> ans;
vector<int> lexicalOrder(int n) {
    num = n;
    d(1);
    return ans;
}
void d(int x) {
    if(x > num) return;
    ans.push_back(x);
    d(x * 10);
    if((x % 10) < 9) d(x + 1);
}
```

This code generates a lexicographical order of numbers from 1 to n.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int num;
	```
	Declare a global variable 'num' that will store the value of 'n'.

2. **Variable Declaration**
	```cpp
	vector<int> ans;
	```
	Declare a vector 'ans' to store the numbers in lexicographical order.

3. **Function Definition**
	```cpp
	vector<int> lexicalOrder(int n) {
	```
	Define the main function 'lexicalOrder' which takes an integer 'n' as input and returns a vector of integers in lexicographical order.

4. **Assignment**
	```cpp
	    num = n;
	```
	Assign the value of 'n' to the global variable 'num'.

5. **Function Call**
	```cpp
	    d(1);
	```
	Call the recursive function 'd' with the starting value 1.

6. **Return Statement**
	```cpp
	    return ans;
	```
	Return the vector 'ans' containing the lexicographically ordered numbers.

7. **Function Definition**
	```cpp
	void d(int x) {
	```
	Define a helper function 'd' which takes an integer 'x' and recursively generates numbers in lexicographical order.

8. **Base Case**
	```cpp
	    if(x > num) return;
	```
	If the current number 'x' exceeds 'num', return and stop the recursion.

9. **Push Operation**
	```cpp
	    ans.push_back(x);
	```
	Add the current number 'x' to the vector 'ans'.

10. **Recursive Call**
	```cpp
	    d(x * 10);
	```
	Recursively call 'd' with 'x * 10', which generates the next level of lexicographical numbers.

11. **Condition Check**
	```cpp
	    if((x % 10) < 9) d(x + 1);
	```
	If the current number 'x' is not ending in 9, call 'd' with 'x + 1' to explore the next number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we generate each number exactly once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, aside from the space required to store the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lexicographical-numbers/description/)

---
{{< youtube n4YGTbFfU-w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
