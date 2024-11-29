
+++
authors = ["grid47"]
title = "Leetcode 1124: Longest Well-Performing Interval"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1124: Longest Well-Performing Interval in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Stack","Monotonic Stack","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1Cu21ILZBx8"
youtube_upload_date="2024-03-19"
youtube_thumbnail="https://i.ytimg.com/vi/1Cu21ILZBx8/maxresdefault.jpg"
comments = true
+++



---
You are given a list of integers representing the number of hours worked each day. A day is considered tiring if the number of hours worked is strictly greater than 8. A well-performing interval is an interval of days where the number of tiring days is strictly larger than the number of non-tiring days. Your task is to return the length of the longest well-performing interval.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of integers representing the number of hours worked per day. The length of the list is between 1 and 10,000.
- **Example:** `Input: hours = [9,9,6,0,6,6,9]`
- **Constraints:**
	- The number of elements in hours is between 1 and 10,000.
	- Each integer in hours is between 0 and 16.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest well-performing interval.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be an integer representing the length of the longest well-performing interval.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest interval where the number of tiring days is greater than the number of non-tiring days.

- Traverse the list and calculate a score where tiring days are scored as +1 and non-tiring days as -1.
- Track the cumulative score and use a map to store the earliest index for each score.
- For each score, check if a previous score exists that satisfies the condition of a well-performing interval, and update the result.
{{< dots >}}
### Problem Assumptions ✅
- The input list is non-empty.
- The length of the list will be between 1 and 10,000.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: hours = [9,9,6,0,6,6,9]`  \
  **Explanation:** In this case, the longest well-performing interval is [9,9,6], as there are 2 tiring days (9,9) and 1 non-tiring day (6).

- **Input:** `Input: hours = [6,6,6]`  \
  **Explanation:** There are no tiring days in this list, so there is no well-performing interval.

{{< dots >}}
## Approach 🚀
To solve this problem, we will traverse the list and calculate a running score, updating the result whenever we encounter a well-performing interval. We will use a map to track the first occurrence of each cumulative score.

### Initial Thoughts 💭
- We can track the number of tiring and non-tiring days using a cumulative score.
- By using a map to store the first occurrence of each cumulative score, we can efficiently calculate the length of well-performing intervals.
- We can optimize the solution by processing the list in a single pass and using the map to keep track of the earliest index for each score.
{{< dots >}}
### Edge Cases 🌐
- If the list is empty, return 0.
- Ensure the solution efficiently handles large inputs, up to 10,000 elements.
- If all days are non-tiring, return 0.
- The solution should be able to handle lists with a maximum length of 10,000.
{{< dots >}}
## Code 💻
```cpp
int longestWPI(vector<int>& hours) {
    
    int n = hours.size(), res = 0, score = 0;
    map<int, int> mp;
    
    for(int i = 0; i < n; i++) {
        
        score += (hours[i] > 8) ? 1 : -1;
        
        if(score > 0)res = i + 1;
        else {

            if  (!mp.count(score))    mp[score] = i;
            if  (mp.count(score - 1)) res = max(res, i - mp[score -1]);

        }
    
    }
    
    return res;
}
```

This code defines the `longestWPI` function, which calculates the longest well-performing interval (WPI) based on working hours. The function computes a score for each day, where days with hours greater than 8 are positive and others are negative. It tracks the first occurrence of each score in a map and calculates the maximum interval where the score is positive.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int longestWPI(vector<int>& hours) {
	```
	This function `longestWPI` takes a vector of integers representing working hours for each day and returns the length of the longest well-performing interval (WPI).

2. **Variable Initialization**
	```cpp
	    
	```
	This line is for initialization and spacing in the code.

3. **Variable Initialization**
	```cpp
	    int n = hours.size(), res = 0, score = 0;
	```
	This line initializes the size of the `hours` array (`n`), the result variable `res` to store the length of the longest WPI, and the `score` to track the cumulative score as the loop progresses.

4. **Data Structure**
	```cpp
	    map<int, int> mp;
	```
	Declares a map `mp` to store the first occurrence of each score value and its corresponding index.

5. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins the loop to iterate through each element of the `hours` vector.

6. **Score Update**
	```cpp
	        score += (hours[i] > 8) ? 1 : -1;
	```
	This line updates the cumulative `score`. If the working hours for the day are greater than 8, the score is incremented by 1, otherwise, it is decremented by 1.

7. **Result Update (Positive Score)**
	```cpp
	        if(score > 0)res = i + 1;
	```
	If the cumulative score is greater than 0, the result `res` is updated to the length of the current interval (`i + 1`).

8. **Else Condition**
	```cpp
	        else {
	```
	If the cumulative score is not greater than 0, the code enters the else block to process the map of scores.

9. **Map Update**
	```cpp
	            if  (!mp.count(score))    mp[score] = i;
	```
	If the map doesn't already contain the current score, the score and its corresponding index are added to the map.

10. **Result Update (Negative Score)**
	```cpp
	            if  (mp.count(score - 1)) res = max(res, i - mp[score -1]);
	```
	If the map contains the previous score (`score - 1`), the result `res` is updated to the maximum value between the current result and the length of the interval between the current index and the index stored in the map.

11. **Return Statement**
	```cpp
	    return res;
	```
	Returns the result, which is the length of the longest well-performing interval (WPI).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input list, as we only make a single pass through the list.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the map to track the first occurrence of each cumulative score.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-well-performing-interval/description/)

---
{{< youtube 1Cu21ILZBx8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
