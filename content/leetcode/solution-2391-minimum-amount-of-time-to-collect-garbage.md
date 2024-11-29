
+++
authors = ["grid47"]
title = "Leetcode 2391: Minimum Amount of Time to Collect Garbage"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2391: Minimum Amount of Time to Collect Garbage in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gpjKAXQpOMM"
youtube_upload_date="2022-08-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gpjKAXQpOMM/maxresdefault.webp"
comments = true
+++



---
You are given an array of strings `garbage` where each string represents the garbage collected at a specific house. The characters 'M', 'P', and 'G' represent metal, paper, and glass garbage, respectively. The time to collect one unit of garbage is 1 minute. You are also given an array `travel` where each element represents the time required to travel between two consecutive houses. Three trucks are responsible for picking up different types of garbage and can only travel sequentially from house 0 to the end. Each truck only collects one type of garbage and each truck can only be used one at a time. Return the minimum time required to pick up all the garbage.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: `garbage` and `travel`. `garbage[i]` represents the garbage at house `i` and consists of the characters 'M', 'P', and 'G'. `travel[i]` is the time it takes to travel between house `i` and house `i + 1`.
- **Example:** `garbage = ['G','P','GP','GG'], travel = [2,4,3]`
- **Constraints:**
	- 2 <= garbage.length <= 10^5
	- garbage[i] consists of the characters 'M', 'P', 'G'.
	- 1 <= garbage[i].length <= 10
	- travel.length == garbage.length - 1
	- 1 <= travel[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total minimum time needed to collect all the garbage. This includes both the time to pick up the garbage and the time spent traveling.
- **Example:** `Output: 21`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the total time by collecting the garbage for each truck and considering the travel time for each truck's route.

- 1. Iterate through each house and for each type of garbage, track the last house where it appears.
- 2. Calculate the time required to collect all the garbage of each type.
- 3. Add the travel time for each garbage truck based on the last house where its garbage is located.
{{< dots >}}
### Problem Assumptions ✅
- Each truck must pick up all the garbage of its type.
- There are always at least one type of garbage to collect.
{{< dots >}}
## Examples 🧩
- **Input:** `garbage = ['G','P','GP','GG'], travel = [2,4,3]`  \
  **Explanation:** The metal truck collects no garbage, so we ignore it. The paper truck collects garbage at house 1 and 2, traveling a total of 6 minutes. The glass truck collects garbage from houses 0, 2, and 3, traveling a total of 13 minutes. The total time is 6 + 13 = 21 minutes.

- **Input:** `garbage = ['MMM','PGM','GP'], travel = [3,10]`  \
  **Explanation:** The metal truck collects garbage from houses 0, 1, and 2, traveling a total of 7 minutes. The paper truck collects garbage from houses 0, 1, and 2, traveling 15 minutes. The glass truck collects garbage from houses 0, 1, and 2, also traveling 15 minutes. The total time is 7 + 15 + 15 = 37 minutes.

{{< dots >}}
## Approach 🚀
We need to simulate the garbage collection by considering both the time spent picking up garbage and the travel times. This involves finding the last occurrence of each type of garbage and calculating the total time accordingly.

### Initial Thoughts 💭
- Each truck only needs to collect its respective garbage, and the trucks travel in order.
- We can start by calculating the total garbage collected for each type and then consider the travel time from house 0 to the last house with that type of garbage.
{{< dots >}}
### Edge Cases 🌐
- If the `garbage` array is empty, the total time should be zero.
- Ensure the solution can handle arrays with lengths close to 100,000 efficiently.
- Handle cases where only one type of garbage is present in the entire city.
- Make sure the solution works within the time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int last[128] = {}, res = 0;        
    for(int i = 0; i < garbage.size(); i++) {
        res += garbage[i].size();
        for(char c : garbage[i])
            last[c] = i;
    }

    for(int j = 1; j < travel.size(); j++)
        travel[j] += travel[j - 1];
    
    for(int c : "PGM")
    if(last[c])
    res += travel[last[c] - 1];
    return res;
}
```

The function `garbageCollection` calculates the total time required for garbage collection, taking into account the travel time and the amount of garbage to be collected for each type of garbage.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int garbageCollection(vector<string>& garbage, vector<int>& travel) {
	```
	The function `garbageCollection` takes two arguments: a vector `garbage` that represents the amount of garbage for each type and a vector `travel` representing the travel times between stops.

2. **Variable Initialization**
	```cpp
	    int last[128] = {}, res = 0;        
	```
	Initialize an array `last` to store the last index for each garbage type and an integer `res` to store the total garbage collection time.

3. **Loop**
	```cpp
	    for(int i = 0; i < garbage.size(); i++) {
	```
	Loop through the `garbage` vector to calculate the total amount of garbage and update the `last` array for each garbage type.

4. **Accumulating Garbage Size**
	```cpp
	        res += garbage[i].size();
	```
	Add the size of each garbage collection string to the total `res`, representing the total amount of garbage to be collected.

5. **Tracking Garbage Type**
	```cpp
	        for(char c : garbage[i])
	```
	For each character in the string representing a garbage collection, update the `last` array to store the last occurrence of each garbage type.

6. **Update Last Occurrence**
	```cpp
	            last[c] = i;
	```
	Update the `last` array to set the current index `i` as the last occurrence of the garbage type represented by character `c`.

7. **Travel Time Accumulation**
	```cpp
	    for(int j = 1; j < travel.size(); j++)
	```
	Loop through the `travel` vector starting from the second element to accumulate the total travel time at each stop.

8. **Cumulative Travel Time**
	```cpp
	        travel[j] += travel[j - 1];
	```
	Accumulate travel times by adding the previous stop's travel time to the current stop's travel time.

9. **Garbage Collection for Each Type**
	```cpp
	    for(int c : "PGM")
	```
	Loop through the string 'PGM' to check for the last occurrence of each garbage type (P, G, M).

10. **Check Last Occurrence**
	```cpp
	    if(last[c])
	```
	Check if there is a last occurrence for the garbage type `c`.

11. **Add Travel Time**
	```cpp
	    res += travel[last[c] - 1];
	```
	If a last occurrence exists, add the corresponding travel time to the total collection time.

12. **Return Result**
	```cpp
	    return res;
	```
	Return the total time for garbage collection, which includes both the garbage sizes and travel times.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the `garbage` array.
- **Average Case:** O(n), where n is the length of the `garbage` array.
- **Worst Case:** O(n), where n is the length of the `garbage` array.

The algorithm processes each house and each travel time at most once, so the time complexity is O(n).

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of houses.
- **Worst Case:** O(n), where n is the number of houses, due to the storage needed for the garbage types and travel times.

The space complexity is O(n) due to the storage required for the garbage array and travel array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/)

---
{{< youtube gpjKAXQpOMM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
