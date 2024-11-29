
+++
authors = ["grid47"]
title = "Leetcode 1286: Iterator for Combination"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1286: Iterator for Combination in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Design","Iterator"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "LzYlG_p1-zs"
youtube_upload_date="2020-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/LzYlG_p1-zs/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGH8gEygXMA8=&rs=AOn4CLB17AilTYp_dTSeqhi2A9mL6rGv5g"
comments = true
+++



---
Design a CombinationIterator class that generates all combinations of a specified length from a sorted string of distinct lowercase English letters, and allows iterating through them in lexicographical order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string of distinct lowercase English letters and an integer specifying the combination length.
- **Example:** `Input: characters = 'abc', combinationLength = 2`
- **Constraints:**
	- 1 <= combinationLength <= characters.length <= 15
	- All characters in characters are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** The iterator will provide the next combination when next() is called and will return true for hasNext() if there are more combinations left.
- **Example:** `Output: 'ab', true, 'ac', true, 'bc', false`
- **Constraints:**
	- Each call to next() must return a valid combination.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently generate and return combinations of the specified length in lexicographical order.

- Generate all combinations of the specified length from the string of characters.
- Store the combinations in a sequence.
- Use an index to iterate over the combinations, providing the next combination on each call to next().
- Check if there are more combinations available with the hasNext() function.
{{< dots >}}
### Problem Assumptions ✅
- The characters input is always sorted and contains distinct lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: characters = 'abc', combinationLength = 2`  \
  **Explanation:** In this case, the combinations of length 2 are 'ab', 'ac', and 'bc'. The iterator will provide these combinations in order.

{{< dots >}}
## Approach 🚀
We can generate all combinations of the specified length from the given string, store them, and then return each combination one by one using an index.

### Initial Thoughts 💭
- Combinations should be generated in lexicographical order.
- A backtracking approach can be used to generate all combinations.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, the combinationLength must be 0, and no combinations can be generated.
- For very large input sizes (up to 15 characters), ensure the solution can handle generating and storing the combinations efficiently.
- When the combinationLength is equal to the length of the input string, the only possible combination is the entire string.
- Make sure the time complexity of generating combinations and iterating through them is optimized.
{{< dots >}}
## Code 💻
```cpp
string str;
int len;
vector<string> ans;
map<int, int> mp;
void bt(int idx, string &tmp) {
    if(tmp.size() == len) {
        ans.push_back(tmp);
        return;
    }
    if(idx == str.size()) {
        return;
    }
    
    for(int i = idx; i < str.size(); i++) {
        tmp += str[i];
        bt(i + 1, tmp);
        tmp.pop_back();
    }
    
}
int idx = 0;
CombinationIterator(string chars, int len) {
    this->len = len;
    sort(chars.begin(), chars.end());
    str = chars;
    string tmp = "";
    bt(0, tmp);
}

string next() {
    return ans[idx++];
}

bool hasNext() {
    if(idx < ans.size()) return true;
    return false;
}
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
```

Implements a combination iterator to generate all combinations of given length from a sorted string using backtracking.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	string str;
	```
	Declares a string to hold the input characters.

2. **Variable Declaration**
	```cpp
	int len;
	```
	Declares an integer to store the length of combinations.

3. **Variable Declaration**
	```cpp
	vector<string> ans;
	```
	Defines a vector to store the generated combinations.

4. **Data Structure**
	```cpp
	map<int, int> mp;
	```
	Defines a map, though it is unused in this context.

5. **Backtracking Function**
	```cpp
	void bt(int idx, string &tmp) {
	```
	Defines a recursive function for backtracking to generate combinations.

6. **Base Condition**
	```cpp
	    if(tmp.size() == len) {
	```
	Checks if the current string has reached the desired length.

7. **Push to Results**
	```cpp
	        ans.push_back(tmp);
	```
	Adds the completed combination to the results vector.

8. **Return Statement**
	```cpp
	        return;
	```
	Exits the recursive call when a combination is completed.

9. **End Condition**
	```cpp
	    if(idx == str.size()) {
	```
	Checks if the index has reached the end of the string.

10. **Return Statement**
	```cpp
	        return;
	```
	Returns from the function if there are no more characters to explore.

11. **Loop Start**
	```cpp
	    for(int i = idx; i < str.size(); i++) {
	```
	Loops through each character starting from the current index.

12. **Add Character**
	```cpp
	        tmp += str[i];
	```
	Adds the current character to the temporary string.

13. **Recursive Call**
	```cpp
	        bt(i + 1, tmp);
	```
	Recursively calls the backtracking function for the next index.

14. **Backtrack Step**
	```cpp
	        tmp.pop_back();
	```
	Removes the last character to explore other combinations.

15. **Constructor Initialization**
	```cpp
	CombinationIterator(string chars, int len) {
	```
	Initializes the CombinationIterator with the sorted string and combination length.

16. **Assign Value**
	```cpp
	    this->len = len;
	```
	Assigns the input length to the class variable.

17. **Sort Input**
	```cpp
	    sort(chars.begin(), chars.end());
	```
	Sorts the input characters to ensure combinations are generated lexicographically.

18. **Set Input**
	```cpp
	    str = chars;
	```
	Assigns the sorted characters to the class variable.

19. **Temporary String**
	```cpp
	    string tmp = "";
	```
	Defines an empty temporary string for backtracking.

20. **Call Backtracking**
	```cpp
	    bt(0, tmp);
	```
	Starts the backtracking process from the first index.

21. **Retrieve Next**
	```cpp
	string next() {
	```
	Defines a method to return the next combination.

22. **Increment Index**
	```cpp
	    return ans[idx++];
	```
	Returns the current combination and increments the index.

23. **Check Availability**
	```cpp
	bool hasNext() {
	```
	Defines a method to check if more combinations are available.

24. **Return Condition**
	```cpp
	    if(idx < ans.size()) return true;
	```
	Returns true if there are more combinations left to retrieve.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) - If there is only one combination to generate.
- **Average Case:** O(n) - Generating and iterating through the combinations is linear with respect to the number of combinations.
- **Worst Case:** O(n) - The worst case is when we have to generate and iterate through all combinations.

The time complexity is determined by the need to generate and iterate through the combinations. Since there are n combinations, the complexity is O(n).

### Space Complexity 💾
- **Best Case:** O(1) - If no combinations are stored.
- **Worst Case:** O(n) - Storing all combinations requires space proportional to the number of combinations.

The space complexity is O(n), where n is the number of combinations generated, since each combination needs to be stored.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/iterator-for-combination/description/)

---
{{< youtube LzYlG_p1-zs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
