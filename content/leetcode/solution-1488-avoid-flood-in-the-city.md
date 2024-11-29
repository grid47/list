
+++
authors = ["grid47"]
title = "Leetcode 1488: Avoid Flood in The City"
date = "2024-06-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1488: Avoid Flood in The City in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EcvhHoFaDoU"
youtube_upload_date="2020-06-21"
youtube_thumbnail="https://i.ytimg.com/vi/EcvhHoFaDoU/maxresdefault.jpg"
comments = true
+++



---
Your country has an infinite number of lakes. Initially, all the lakes are dry, but on the nth day, the nth lake fills up with water. If it rains over a lake that is already full, there will be a flood. You need to avoid flooding by drying out lakes on some days when there is no rain.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array rains. The ith element in the array indicates either rain or a dry day for a lake. If the element is 0, you can choose a lake to dry. If the element is greater than 0, rain falls on the lake specified by the number.
- **Example:** `rains = [1, 2, 3, 4]`
- **Constraints:**
	- 1 <= rains.length <= 10^5
	- 0 <= rains[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array ans where each index corresponds to the ith day. If it rains, output -1, otherwise output the lake to dry.
- **Example:** `Output: [-1, -1, -1, -1]`
- **Constraints:**
	- The returned array should have the same length as the input array rains.

{{< dots >}}
### Core Logic 🔍
**Goal:** Avoid floods by drying out lakes in a manner that ensures no lake will overflow.

- Track lakes that are already filled.
- If rain falls over a lake, check if it was previously filled. If it was, attempt to dry one of the lakes that can be dried without causing a flood.
- If drying is impossible or no valid lake is available, return an empty array.
{{< dots >}}
### Problem Assumptions ✅
- The lakes are infinite, and each lake can be filled only once.
{{< dots >}}
## Examples 🧩
- **Input:** `rains = [1, 2, 0, 0, 2, 1]`  \
  **Explanation:** On the first two days, lakes 1 and 2 fill up. On the third and fourth days, we dry lake 2 and lake 1 respectively to prevent a flood. No flooding occurs.

- **Input:** `rains = [1, 2, 0, 1, 2]`  \
  **Explanation:** By the third day, lakes 1 and 2 are full. No matter which lake we dry on the third day, one of them will flood.

{{< dots >}}
## Approach 🚀
Track the lakes that are full and manage the drying of lakes on days when no rain falls. Use efficient data structures to handle the operations within the time constraints.

### Initial Thoughts 💭
- We need to keep track of when lakes get full.
- When it's a dry day, we should choose which lake to dry to avoid flooding later.
- A greedy approach can be used, but we need to ensure that drying doesn't lead to a flood on a future rainy day.
{{< dots >}}
### Edge Cases 🌐
- If rains is an empty array, return an empty array.
- If rains contains the maximum possible number of elements, the solution must be efficient.
- If all values in rains are 0, any sequence of dried lakes is valid.
- Ensure no lake is dried that causes a flood when it rains later.
{{< dots >}}
## Code 💻
```cpp
vector<int> avoidFlood(vector<int>& rains) {
    
    set<int> dry;
    unordered_map<int, int> mp;
    
    int n = rains.size();
    
    vector<int> ans;
    
    for(int i = 0; i < n; i++) {
        if(rains[i] == 0) {
            dry.insert(i);
            ans.push_back(1);
        } else {
            int lake = rains[i];
            
            if(mp.count(lake)) {
                
                auto it = dry.lower_bound(mp[lake]);
                if(it == dry.end()) return {};
                
                ans[*it] = lake;
                dry.erase(*it);
            }
            mp[lake] = i;
            ans.push_back(-1);
        }
    }

    return ans;
}
```

The `avoidFlood` function simulates the process of raining and drying up lakes. It returns a vector indicating which days to flood and which days to dry up, ensuring that no lake floods twice before it dries up.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method**
	```cpp
	vector<int> avoidFlood(vector<int>& rains) {
	```
	The function accepts a vector `rains` representing the rain schedule and returns a vector where `1` means it's a dry day (we can drain a lake), `-1` means it rains, and `0` means no flooding action is required.

2. **Variable Initialization**
	```cpp
	    set<int> dry;
	```
	A set `dry` is used to store the indices of dry days where we can drain a lake. The set helps to efficiently find the next available dry day.

3. **Variable Initialization**
	```cpp
	    unordered_map<int, int> mp;
	```
	An unordered map `mp` is used to store the last occurrence index of each lake. The key is the lake's identifier, and the value is the index of the last day it rained.

4. **Variable Initialization**
	```cpp
	    int n = rains.size();
	```
	The variable `n` stores the size of the `rains` vector, representing the number of days.

5. **Variable Initialization**
	```cpp
	    vector<int> ans;
	```
	The `ans` vector will store the result. Each entry represents whether a lake floods (`-1`) or dries up (`1`) on that particular day.

6. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	The `for` loop iterates over each day in the `rains` vector to process the rain data.

7. **Condition**
	```cpp
	        if(rains[i] == 0) {
	```
	If it doesn't rain on the current day (`rains[i] == 0`), it means it's a dry day, and we have the option to drain a lake.

8. **Set Insertion**
	```cpp
	            dry.insert(i);
	```
	Insert the current day index into the `dry` set, marking it as a potential day to drain a lake.

9. **Vector Update**
	```cpp
	            ans.push_back(1);
	```
	Add `1` to the `ans` vector to indicate that on this dry day, we drain a lake.

10. **Condition**
	```cpp
	        } else {
	```
	If it rains on the current day, we need to check if the lake has already been flooded before.

11. **Variable Initialization**
	```cpp
	            int lake = rains[i];
	```
	Assign the current lake identifier from `rains[i]` to the variable `lake`.

12. **Condition**
	```cpp
	            if(mp.count(lake)) {
	```
	Check if the lake has been flooded before by looking it up in the `mp` map.

13. **Set Operations**
	```cpp
	                auto it = dry.lower_bound(mp[lake]);
	```
	Find the next available dry day to drain the lake using `lower_bound`. If no valid day exists, we can't proceed.

14. **Condition**
	```cpp
	                if(it == dry.end()) return {};
	```
	If no available dry days exist after the last flood day, return an empty vector to indicate it's impossible to avoid a flood.

15. **Vector Update**
	```cpp
	                ans[*it] = lake;
	```
	Assign the lake to the dry day found, indicating that the lake will be drained on that day.

16. **Set Update**
	```cpp
	                dry.erase(*it);
	```
	Remove the dry day from the `dry` set, since it has been used to drain the lake.

17. **Map Update**
	```cpp
	            mp[lake] = i;
	```
	Update the map `mp` with the current day index as the last day it rained for this lake.

18. **Vector Update**
	```cpp
	            ans.push_back(-1);
	```
	Add `-1` to the `ans` vector to indicate that the lake is flooded on this day.

19. **Return**
	```cpp
	    return ans;
	```
	Return the final `ans` vector which represents the flooding and draining schedule.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Processing each element in the rains array requires constant or logarithmic time, depending on the operation performed.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We need space for tracking the lakes that are full and the days that are available for drying.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/avoid-flood-in-the-city/description/)

---
{{< youtube EcvhHoFaDoU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
