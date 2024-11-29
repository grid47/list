
+++
authors = ["grid47"]
title = "Leetcode 2899: Last Visited Integers"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2899: Last Visited Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "vWwJsOGGKu8"
youtube_upload_date="2023-10-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/vWwJsOGGKu8/maxresdefault.webp"
comments = true
+++



---
Given an integer array `nums`, where each element is either a positive integer or -1. For each -1, find the respective last visited positive integer. The 'last visited integer' refers to the most recent positive integer seen before each -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` where each element is either a positive integer or -1.
- **Example:** `[7,-1,8,-1,-1]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- nums[i] == -1 or 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array `ans` where for each `-1` in the input, the corresponding element in `ans` is the last positive integer seen before it. If there aren't enough positive integers, append `-1`.
- **Example:** `[7,8,7]`
- **Constraints:**
	- The length of the output array should be the same as the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** To keep track of the most recent positive integers and assign them to the respective `-1` based on the count of consecutive `-1` encountered.

- Initialize an empty array `seen` and an empty array `ans`.
- Iterate through the array `nums`.
- For each positive integer, prepend it to `seen`.
- For each `-1`, find the `k`-th element in `seen` and append it to `ans`. If `k` exceeds the length of `seen`, append `-1`.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` is non-empty.
- Each `-1` in the array has a respective 'last visited integer' if enough positive integers precede it.
{{< dots >}}
## Examples 🧩
- **Input:** `[7,-1,8,-1,-1]`  \
  **Explanation:** For each `-1`, find the respective last positive integer based on the elements seen so far. If there aren't enough integers, append `-1`.

{{< dots >}}
## Approach 🚀
Iterate through the array `nums`, keep track of the positive integers in a `seen` list, and for each `-1`, append the respective 'last visited integer' to the result array.

### Initial Thoughts 💭
- Each `-1` is followed by a check for the number of previous integers.
- If there are enough integers in `seen`, return the last one; otherwise, return `-1`.
- This problem involves maintaining a stack-like structure for the integers seen so far.
{{< dots >}}
### Edge Cases 🌐
- The input will not be empty according to the constraints.
- For large inputs, the algorithm should efficiently handle up to 100 elements in `nums`.
- If there are no positive integers before a `-1`, return `-1` for that position.
- The length of the input is limited to 100, which is manageable.
{{< dots >}}
## Code 💻
```cpp
vector<int> lastVisitedIntegers(vector<string>& words) {
    vector<int>v;
    vector<int>ans;
    int count=0;
    for(int i=0;i<words.size();i++){
        if(words[i]=="prev"){
            count++;
            if(count>v.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(v[v.size()-count]);
            }
        }
        else{
            count=0;
            v.push_back(stoi(words[i]));
        }
    }
    return ans;
}
```

This code solves the problem of keeping track of the last visited integers based on a sequence of commands. If the command is 'prev', it returns the last visited integer, otherwise, it adds a new integer to the list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> lastVisitedIntegers(vector<string>& words) {
	```
	Function to process a list of commands (words) and return a list of integers corresponding to the last visited integers based on the commands.

2. **Variable Initialization**
	```cpp
	    vector<int>v;
	```
	This initializes an empty vector to store the visited integers.

3. **Variable Initialization**
	```cpp
	    vector<int>ans;
	```
	This initializes an empty vector to store the answers (last visited integers or -1).

4. **Variable Initialization**
	```cpp
	    int count=0;
	```
	This variable keeps track of how many times 'prev' has been encountered in the list.

5. **Loop**
	```cpp
	    for(int i=0;i<words.size();i++){
	```
	Loop through each word in the input list to process the commands.

6. **Condition Check**
	```cpp
	        if(words[i]=="prev"){
	```
	Check if the current command is 'prev'.

7. **Increment Counter**
	```cpp
	            count++;
	```
	Increment the count when 'prev' is encountered.

8. **Condition Check**
	```cpp
	            if(count>v.size()){
	```
	Check if the count exceeds the number of integers stored in the vector.

9. **Action**
	```cpp
	                ans.push_back(-1);
	```
	If count exceeds the size of the vector, add -1 to the answer list.

10. **Action**
	```cpp
	            }
	```
	End the if condition.

11. **Action**
	```cpp
	            else{
	```
	If count is within bounds, proceed to retrieve the last visited integer.

12. **Action**
	```cpp
	                ans.push_back(v[v.size()-count]);
	```
	Add the last visited integer to the answer list, based on the count.

13. **Else Condition**
	```cpp
	        else{
	```
	If the current command is not 'prev', proceed to add a new integer to the visited list.

14. **Action**
	```cpp
	            count=0;
	```
	Reset the count to 0 when a new integer is encountered.

15. **Action**
	```cpp
	            v.push_back(stoi(words[i]));
	```
	Convert the current word to an integer and add it to the visited integers list.

16. **Return Statement**
	```cpp
	    return ans;
	```
	Return the list of last visited integers or -1 for invalid commands.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each element is processed once, leading to a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We store the integers encountered in `seen`, so the space complexity is O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/last-visited-integers/description/)

---
{{< youtube vWwJsOGGKu8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
