
+++
authors = ["grid47"]
title = "Leetcode 2942: Find Words Containing Character"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2942: Find Words Containing Character in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "gJCrdytYtDY"
youtube_upload_date="2023-11-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gJCrdytYtDY/maxresdefault.webp"
comments = true
+++



---
You have n balls placed on a table, each either black or white, represented by a binary string s. In each move, you can swap two adjacent balls. Your task is to determine the minimum number of swaps required to move all black balls to the right side and all white balls to the left side.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary string s of length n where each character is either '1' (black ball) or '0' (white ball).
- **Example:** `s = '110'`
- **Constraints:**
	- 1 <= n <= 10^5
	- s[i] is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of adjacent swaps required to group all black balls to the right and all white balls to the left.
- **Example:** `For s = '110', the output is 1.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the minimum number of adjacent swaps required to arrange the balls such that all white balls are on the left and all black balls are on the right.

- Iterate through the string while counting the number of white balls ('0') encountered.
- For each black ball ('1'), count how many white balls are to the left of it, as this indicates how many swaps are needed to move the black ball to its correct position.
{{< dots >}}
### Problem Assumptions ✅
- The string contains at least one ball, and no more than 100,000 balls.
{{< dots >}}
## Examples 🧩
- **Input:** `s = '110'`  \
  **Explanation:** One swap is needed to move the black ball at position 1 to the right.

- **Input:** `s = '01010'`  \
  **Explanation:** Four swaps are needed to move all black balls to the right.

- **Input:** `s = '000111'`  \
  **Explanation:** No swaps are needed because all black balls are already grouped to the right.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the string and counting how many white balls ('0') are encountered before each black ball ('1'). This helps determine how many swaps are needed to position the black balls correctly.

### Initial Thoughts 💭
- The problem is about counting the number of swaps required to move each black ball to the right side.
- By iterating through the string and maintaining a count of white balls seen so far, we can efficiently calculate the swaps for each black ball.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, return 0 as no swaps are needed.
- The solution must efficiently handle strings with lengths up to 100,000.
- If the string is already in the desired arrangement (all white balls on the left and black balls on the right), return 0.
- The input string will not be empty.
{{< dots >}}
## Code 💻
```cpp
vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> result;
    for (int i = 0; i < words.size(); i++) {
        if (check(words[i], x)) result.push_back(i);
    }
    return result;
}
private:
bool check(string& word, char x) {
    for (auto& c : word) {
        if (c == x) return true;
    }
    return false;
}
```

This function returns a list of indices of the words in the input list 'words' that contain the character 'x'. A helper function 'check' is used to check if a word contains the character 'x'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findWordsContaining(vector<string>& words, char x) {
	```
	Defines the main function 'findWordsContaining' that takes a list of words and a character 'x', and returns a vector of indices of the words that contain 'x'.

2. **Result Initialization**
	```cpp
	    vector<int> result;
	```
	Initializes an empty vector 'result' to store the indices of the words containing the character 'x'.

3. **Loop Setup**
	```cpp
	    for (int i = 0; i < words.size(); i++) {
	```
	Starts a loop to iterate through each word in the 'words' vector using the index 'i'.

4. **Check for 'x' in Word**
	```cpp
	        if (check(words[i], x)) result.push_back(i);
	```
	Calls the helper function 'check' to determine if the current word contains the character 'x'. If true, it adds the current index 'i' to the 'result' vector.

5. **Return Statement**
	```cpp
	    return result;
	```
	Returns the 'result' vector, which contains the indices of the words that contain the character 'x'.

6. **Private Section**
	```cpp
	private:
	```
	Indicates the start of the private section of the class, where helper functions are defined.

7. **Helper Function Definition**
	```cpp
	bool check(string& word, char x) {
	```
	Defines the helper function 'check' that takes a word and a character 'x', and returns true if the word contains the character 'x'.

8. **Loop Over Characters in Word**
	```cpp
	    for (auto& c : word) {
	```
	Starts a loop to iterate through each character 'c' in the given word.

9. **Character Comparison**
	```cpp
	        if (c == x) return true;
	```
	Compares the current character 'c' with the character 'x'. If they are equal, returns true indicating that 'x' is found in the word.

10. **Return False**
	```cpp
	    return false;
	```
	If the loop completes without finding 'x', returns false, indicating that the word does not contain 'x'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution requires a single pass over the string, which is O(n) in all cases.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since only a few variables are used to track the count of white balls and the swaps.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-words-containing-character/description/)

---
{{< youtube gJCrdytYtDY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
