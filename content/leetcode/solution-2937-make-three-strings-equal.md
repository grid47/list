
+++
authors = ["grid47"]
title = "Leetcode 2937: Make Three Strings Equal"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2937: Make Three Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "7F8GNWVlYgM"
youtube_upload_date="2023-11-19"
youtube_thumbnail="https://i.ytimg.com/vi/7F8GNWVlYgM/maxresdefault.jpg"
comments = true
+++



---
You are given three strings: s1, s2, and s3. In each operation, you can choose one of these strings and remove its rightmost character. The goal is to determine the minimum number of operations required to make all three strings identical. If it's impossible to make them equal, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three strings, s1, s2, and s3.
- **Example:** `s1 = 'hello', s2 = 'heco', s3 = 'heo'`
- **Constraints:**
	- 1 <= s1.length, s2.length, s3.length <= 100
	- s1, s2, and s3 consist only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to make all strings equal, or -1 if it is impossible.
- **Example:** `For s1 = 'hello', s2 = 'heco', s3 = 'heo', the output is 2.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of operations to make the strings identical by removing the rightmost character from one of the strings in each operation.

- Start by comparing the longest common prefix among the three strings.
- For each common prefix, calculate how many characters need to be removed from each string to make them equal to the prefix.
- Return the smallest number of operations or -1 if no common prefix exists.
{{< dots >}}
### Problem Assumptions ✅
- The strings contain only lowercase English letters.
- Strings will not be empty.
{{< dots >}}
## Examples 🧩
- **Input:** `s1 = 'hello', s2 = 'heco', s3 = 'heo'`  \
  **Explanation:** By removing the rightmost character from both s1 and s2, all three strings become 'he'. Therefore, it takes 2 operations to make them equal.

- **Input:** `s1 = 'cat', s2 = 'dog', s3 = 'bat'`  \
  **Explanation:** The strings cannot be made equal because the first characters are different, so the answer is -1.

{{< dots >}}
## Approach 🚀
The approach is to find the longest common prefix of all three strings and calculate the minimum number of deletions required to make the strings equal.

### Initial Thoughts 💭
- The problem boils down to finding the longest common prefix.
- If the longest common prefix is of length k, the number of operations required will be the length of each string minus k.
{{< dots >}}
### Edge Cases 🌐
- If any of the strings is empty, return -1 as it is impossible to make them equal.
- The solution should work for strings of length up to 100.
- If all strings are already equal, no operations are needed.
- The strings must not be empty.
{{< dots >}}
## Code 💻
```cpp
int findMinimumOperations(string s1, string s2, string s3) {
    int l1=s1.length(), l2=s2.length(), l3=s3.length();
		int len=min({l1,l2,l3});
    
    int ans=INT_MAX;
    for(int i=0;i<len;i++){
        if(s1.substr(0,i+1) == s2.substr(0,i+1) && s2.substr(0,i+1) == s3.substr(0,i+1)){
            int c=l1-(i+1)+l2-(i+1)+l3-(i+1);
            ans=min(ans,c);
        }
    }
    
    return (ans==INT_MAX ? -1:ans);
}
```

The function calculates the minimum number of operations required to make three input strings, s1, s2, and s3, identical by deleting characters from each string. It computes the minimum number of deletions needed to achieve this, or returns -1 if it's not possible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findMinimumOperations(string s1, string s2, string s3) {
	```
	Defines the function 'findMinimumOperations' that takes three strings as input and returns the minimum number of deletions required to make all three strings equal, or -1 if it's not possible.

2. **Length Calculation**
	```cpp
	    int l1=s1.length(), l2=s2.length(), l3=s3.length();
	```
	Calculates the lengths of the three input strings, s1, s2, and s3, and stores them in l1, l2, and l3 respectively.

3. **Minimum Length Calculation**
	```cpp
			int len=min({l1,l2,l3});
	```
	Finds the minimum length of the three strings to limit the loop iteration to the shortest string.

4. **Answer Initialization**
	```cpp
	    int ans=INT_MAX;
	```
	Initializes the variable 'ans' to the maximum integer value, representing the minimum number of deletions, which will be updated during the loop.

5. **Loop Setup**
	```cpp
	    for(int i=0;i<len;i++){
	```
	Sets up a loop to iterate through the characters of the strings up to the length of the shortest string.

6. **Substring Comparison**
	```cpp
	        if(s1.substr(0,i+1) == s2.substr(0,i+1) && s2.substr(0,i+1) == s3.substr(0,i+1)){
	```
	Compares the substrings of s1, s2, and s3 from the beginning up to index i. If all three substrings match, the code inside the if block is executed.

7. **Operation Count Calculation**
	```cpp
	            int c=l1-(i+1)+l2-(i+1)+l3-(i+1);
	```
	Calculates the number of deletions required to make the substrings match by subtracting (i+1) from the length of each string and summing them.

8. **Answer Update**
	```cpp
	            ans=min(ans,c);
	```
	Updates the answer with the minimum value between the current answer and the calculated deletions.

9. **Final Answer**
	```cpp
	    return (ans==INT_MAX ? -1:ans);
	```
	Returns the minimum number of deletions needed, or -1 if no such operation was found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(min(s1.length, s2.length, s3.length))
- **Average Case:** O(min(s1.length, s2.length, s3.length))
- **Worst Case:** O(min(s1.length, s2.length, s3.length))

The complexity is dominated by the comparison of the strings.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/make-three-strings-equal/description/)

---
{{< youtube 7F8GNWVlYgM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
