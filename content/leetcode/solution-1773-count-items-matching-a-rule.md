
+++
authors = ["grid47"]
title = "Leetcode 1773: Count Items Matching a Rule"
date = "2024-05-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1773: Count Items Matching a Rule in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "FL3vJlSmq7w"
youtube_upload_date="2021-02-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FL3vJlSmq7w/maxresdefault.webp"
comments = true
+++



---
You are given an array `items`, where each `items[i]` represents the type, color, and name of the ith item. You are also given a rule consisting of two strings: `ruleKey` and `ruleValue`. The task is to count how many items match the rule. An item matches the rule if one of the following conditions is true: 
- `ruleKey == 'type'` and `ruleValue` matches the type of the item. 
- `ruleKey == 'color'` and `ruleValue` matches the color of the item. 
- `ruleKey == 'name'` and `ruleValue` matches the name of the item.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `items` containing lists of strings, each representing an item with a type, color, and name. The rule is represented by two strings: `ruleKey` and `ruleValue`.
- **Example:** `items = [['laptop', 'black', 'dell'], ['phone', 'blue', 'pixel'], ['tablet', 'gold', 'samsung']], ruleKey = 'color', ruleValue = 'blue'`
- **Constraints:**
	- 1 <= items.length <= 10^4
	- 1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
	- ruleKey is one of 'type', 'color', or 'name'.
	- All strings consist only of lowercase letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of items that match the given rule.
- **Example:** `Output: 1`
- **Constraints:**
	- The result should be an integer representing the count of matching items.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to iterate over the items and check if they match the rule based on the given `ruleKey` and `ruleValue`.

- Identify the index for the ruleKey (0 for 'type', 1 for 'color', 2 for 'name').
- Loop through the items and check if the value at the index corresponding to the ruleKey matches the ruleValue.
- Increment the counter for each match found.
{{< dots >}}
### Problem Assumptions ✅
- The input array will contain at least one item.
- The ruleKey will always be one of 'type', 'color', or 'name'.
{{< dots >}}
## Examples 🧩
- **Input:** `items = [['laptop', 'black', 'dell'], ['phone', 'blue', 'pixel'], ['tablet', 'gold', 'samsung']], ruleKey = 'color', ruleValue = 'blue'`  \
  **Explanation:** In this example, there is only one item that matches the color 'blue', which is the second item ['phone', 'blue', 'pixel'].

- **Input:** `items = [['laptop', 'black', 'dell'], ['phone', 'blue', 'pixel'], ['tablet', 'black', 'samsung']], ruleKey = 'type', ruleValue = 'phone'`  \
  **Explanation:** In this case, only one item matches the type 'phone', which is the second item ['phone', 'blue', 'pixel'].

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating through the array of items and checking if each item matches the rule based on the given ruleKey and ruleValue.

### Initial Thoughts 💭
- The ruleKey indicates which element of the item (type, color, or name) to compare with ruleValue.
- We can solve the problem by simply looping through the items and checking if the value at the ruleKey index matches the ruleValue.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one item, as per the problem constraints.
- The solution should efficiently handle up to 10^4 items in the input array.
- If no items match the rule, the result will be 0.
- The input will always be valid as per the problem constraints.
{{< dots >}}
## Code 💻
```cpp
int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int i;
    if(ruleKey=="type")i=0;
    if(ruleKey=="color")i=1;
    if(ruleKey=="name")i=2;
    
    int ans=0;
    for(int j=0;j<items.size();j++){
        if(items[j][i]==ruleValue)ans++;
    }
    
    return ans;
}
```

This function counts how many items in a 2D vector `items` match a given rule. The rule is specified by the `ruleKey` (which can be 'type', 'color', or 'name') and `ruleValue` (the value to match). The function returns the count of matching items.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
	```
	Define the function `countMatches`, which takes a reference to a 2D vector `items`, and two strings `ruleKey` and `ruleValue`, and returns the count of items that match the rule.

2. **Variable Declaration**
	```cpp
	    int i;
	```
	Declare an integer variable `i`, which will hold the index of the matching category based on the `ruleKey`.

3. **Condition Check for 'type'**
	```cpp
	    if(ruleKey=="type")i=0;
	```
	Check if the `ruleKey` is 'type'. If it is, assign `i = 0`, indicating that we are checking the first element (type) in each item.

4. **Condition Check for 'color'**
	```cpp
	    if(ruleKey=="color")i=1;
	```
	Check if the `ruleKey` is 'color'. If it is, assign `i = 1`, indicating that we are checking the second element (color) in each item.

5. **Condition Check for 'name'**
	```cpp
	    if(ruleKey=="name")i=2;
	```
	Check if the `ruleKey` is 'name'. If it is, assign `i = 2`, indicating that we are checking the third element (name) in each item.

6. **Result Initialization**
	```cpp
	    int ans=0;
	```
	Initialize the variable `ans` to 0. This will hold the count of matching items.

7. **Loop Through Items**
	```cpp
	    for(int j=0;j<items.size();j++){
	```
	Start a loop to iterate through each item in the `items` 2D vector.

8. **Match Check**
	```cpp
	        if(items[j][i]==ruleValue)ans++;
	```
	If the current item’s value at the index `i` matches the `ruleValue`, increment the `ans` variable by 1.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Return the result `ans`, which contains the count of items that matched the rule.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through each item once, where n is the number of items in the input array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we are only using a constant amount of space for the counter.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-items-matching-a-rule/description/)

---
{{< youtube FL3vJlSmq7w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
