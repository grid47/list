
+++
authors = ["grid47"]
title = "Leetcode 739: Daily Temperatures"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 739: Daily Temperatures in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/739.webp"
youtube = "_ZEvmycwXHs"
youtube_upload_date="2024-02-27"
youtube_thumbnail="https://i.ytimg.com/vi/_ZEvmycwXHs/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/739.webp" 
    alt="A series of temperatures with the next warmer day highlighted, glowing softly as it is identified."
    caption="Solution to LeetCode 739: Daily Temperatures Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers temperatures representing the daily temperatures, return an array where each element is the number of days you need to wait after that day to get a warmer temperature. If there is no future day for which this is possible, keep the answer as 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of integers representing the daily temperatures.
- **Example:** `temperatures = [72, 74, 78, 68, 65, 70, 80, 73]`
- **Constraints:**
	- 1 <= temperatures.length <= 10^5
	- 30 <= temperatures[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where each element represents the number of days to wait for a warmer temperature.
- **Example:** `For temperatures = [72, 74, 78, 68, 65, 70, 80, 73], the output should be [1, 1, 4, 2, 1, 1, 0, 0].`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the number of days to wait for a warmer temperature for each day in the input array.

- Create an empty stack to store pairs of temperature and its index.
- Iterate over the temperatures from left to right.
- For each temperature, check if it is higher than the temperature at the index stored at the top of the stack.
- If so, pop the stack, calculate the difference in days, and store the result in the answer array.
- Push the current temperature and its index onto the stack.
- After processing all temperatures, fill in remaining stack indices with 0 (no warmer day).
{{< dots >}}
### Problem Assumptions ✅
- The input array temperatures will always contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `For temperatures = [72, 74, 78, 68, 65, 70, 80, 73], the output is [1, 1, 4, 2, 1, 1, 0, 0].`  \
  **Explanation:** Day 1 has a higher temperature on day 2 (1 day later), day 2 has a higher temperature on day 3 (1 day later), and so on.

{{< dots >}}
## Approach 🚀
A stack-based approach to efficiently determine the number of days to wait for a warmer temperature.

### Initial Thoughts 💭
- We need to track the previous days' temperatures to know when we can find a warmer day.
- Using a stack to store temperatures and their indices will allow us to efficiently compute the answer for each day.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one temperature.
- The algorithm should efficiently handle inputs up to 100,000 elements.
- If the input contains strictly decreasing temperatures, all answers will be 0.
- The solution should handle both small and large inputs within the time limit.
{{< dots >}}
## Code 💻
```cpp
vector<int> dailyTemperatures(vector<int>& temp) {
    stack<pair<int,int>> stk;
    vector<int> ans(temp.size(), 0);
    for(int i = 0; i < temp.size(); i++) {
        // cout << temp[i] << " " ;
        while(!stk.empty() && temp[i] > stk.top().first) {
            // cout << temp[i] << " " ;
            pair<int, int> x = stk.top();

            // cout << temp[i] << " " ;                
            stk.pop();
            
            // cout << temp[i] << " " << x.first << x.second; 
            ans[x.second] = i-x.second;
            // cout << temp[i] << " " ;
        }
        stk.push(make_pair(temp[i], i));
    }
    
    while(!stk.empty()) {
        auto x = stk.top();
        stk.pop();
        ans[x.second] = 0;
    }
    
    return ans;
}
```

This function calculates the number of days you would have to wait until a warmer temperature for each day in the input list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> dailyTemperatures(vector<int>& temp) {
	```
	Defines the function that takes a vector of integers, `temp`, representing daily temperatures.

2. **Variable Declaration**
	```cpp
	    stack<pair<int,int>> stk;
	```
	Declares a stack to store pairs of temperature and day index to track the previous higher temperatures.

3. **Variable Initialization**
	```cpp
	    vector<int> ans(temp.size(), 0);
	```
	Initializes a result vector `ans` with zeros, each representing the number of days until a warmer temperature for each day.

4. **Loop Setup**
	```cpp
	    for(int i = 0; i < temp.size(); i++) {
	```
	Starts a loop to iterate through each day in the input temperature vector.

5. **Loop Condition**
	```cpp
	        while(!stk.empty() && temp[i] > stk.top().first) {
	```
	Starts a while loop to check if the current temperature is greater than the previous stored temperature in the stack.

6. **Variable Assignment**
	```cpp
	            pair<int, int> x = stk.top();
	```
	Pops the top element from the stack and assigns it to `x`.

7. **Stack Operation**
	```cpp
	            stk.pop();
	```
	Pops the top element from the stack after processing it.

8. **Result Update**
	```cpp
	            ans[x.second] = i-x.second;
	```
	Updates the result array to record the number of days until a warmer temperature.

9. **Stack Push**
	```cpp
	        stk.push(make_pair(temp[i], i));
	```
	Pushes the current temperature and its index onto the stack for future comparisons.

10. **While Loop Setup**
	```cpp
	    while(!stk.empty()) {
	```
	Starts a while loop to handle any remaining elements in the stack after processing all temperatures.

11. **Variable Assignment**
	```cpp
	        auto x = stk.top();
	```
	Pops the top element of the stack into variable `x` to process any remaining days that didn't get a warmer temperature.

12. **Stack Operation**
	```cpp
	        stk.pop();
	```
	Pops the top element from the stack.

13. **Result Update**
	```cpp
	        ans[x.second] = 0;
	```
	Sets the number of days to 0 for any temperatures that didn't have a warmer temperature.

14. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the result vector, which contains the number of days until a warmer temperature for each day.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the temperatures array. This happens when the temperatures are strictly increasing.
- **Average Case:** O(n), as we process each element in the temperatures array once.
- **Worst Case:** O(n), where n is the length of the temperatures array. In the worst case, each element is processed once and added to the stack.

The time complexity is O(n) because we only iterate through the array once, with each element being pushed and popped from the stack once.

### Space Complexity 💾
- **Best Case:** O(n), as the stack may store up to n elements in the worst case.
- **Worst Case:** O(n), where n is the length of the temperatures array, due to the space required for the stack.

The space complexity is O(n) because the stack can hold up to n elements in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/daily-temperatures/description/)

---
{{< youtube _ZEvmycwXHs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
