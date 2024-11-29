
+++
authors = ["grid47"]
title = "Leetcode 1980: Find Unique Binary String"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1980: Find Unique Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aHqn4Dynd1k"
youtube_upload_date="2021-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/aHqn4Dynd1k/maxresdefault.jpg"
comments = true
+++



---
You are given an array of unique binary strings, each of length n. Your task is to find and return a binary string of length n that is not present in the given array. There can be multiple valid solutions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer n representing the number of binary strings in the array nums, and a list of strings nums where each string is a binary number of length n.
- **Example:** `nums = ['00', '11']`
- **Constraints:**
	- 1 <= n <= 16
	- nums.length == n
	- nums[i].length == n
	- All strings in nums are unique binary strings.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a binary string of length n that is not present in the array nums. If there are multiple valid answers, any valid one can be returned.
- **Example:** `Output: '10'`
- **Constraints:**
	- The returned string must not be in the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify a binary string that does not match any of the given strings in nums. The approach relies on constructing a string that is guaranteed to differ from each input string at least in one position.

- Create an empty result string.
- Iterate through the array nums and for each index i, pick the opposite of the character at index i of the i-th string in nums.
- Return the constructed binary string as the result.
{{< dots >}}
### Problem Assumptions ✅
- The binary strings in nums are unique and of the same length.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = ['01', '10']`  \
  **Explanation:** In this case, the binary strings in nums are '01' and '10'. By flipping each corresponding bit, we can create '11', which does not appear in the input array.

- **Input:** `Input: nums = ['11', '00']`  \
  **Explanation:** The binary strings in nums are '11' and '00'. By flipping each bit in the corresponding positions, we get '00', which is already in the list. Hence, '10' or '01' can be a valid output.

{{< dots >}}
## Approach 🚀
The solution uses a simple technique of generating a binary string that differs from each input string at least in one position by flipping corresponding bits.

### Initial Thoughts 💭
- This is a problem of generating a unique binary string not present in the input.
- By flipping the bits at each index, we can guarantee a string that does not appear in the input array.
{{< dots >}}
### Edge Cases 🌐
- If the array nums is empty, return a string with all bits set to '1'.
- For large arrays with n = 16, the solution should handle these inputs efficiently.
- If nums contains a single binary string, then any binary string differing from it will work.
- The maximum length of the binary string and the array size should be handled within the time complexity.
{{< dots >}}
## Code 💻
```cpp
string findDifferentBinaryString(vector<string>& nums) {
    string ans = "";
    int n = nums.size();
    for(int i = 0; i < n; i++)
    ans += nums[i][i] == '0'? '1':'0';
    return ans;
}
```

This code defines a function that takes a vector of binary strings and returns a new binary string that differs from each of the input strings at the corresponding position.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string findDifferentBinaryString(vector<string>& nums) {
	```
	Define the function `findDifferentBinaryString` that takes a vector of binary strings and returns a new binary string.

2. **Initialize Answer String**
	```cpp
	    string ans = "";
	```
	Initialize an empty string `ans` which will hold the resulting binary string.

3. **Get Size of Input**
	```cpp
	    int n = nums.size();
	```
	Get the size of the input vector `nums` and store it in `n`.

4. **Loop Through Strings**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loop through each binary string in the input vector `nums`.

5. **Build the Answer String**
	```cpp
	    ans += nums[i][i] == '0'? '1':'0';
	```
	For each string in the input vector, if the character at index `i` is '0', append '1' to `ans`; otherwise, append '0'.

6. **Return Result**
	```cpp
	    return ans;
	```
	Return the constructed binary string `ans` which is different from each of the input binary strings at the corresponding positions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the binary strings in nums.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the result string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-unique-binary-string/description/)

---
{{< youtube aHqn4Dynd1k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
