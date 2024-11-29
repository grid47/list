
+++
authors = ["grid47"]
title = "Leetcode 1604: Alert Using Same Key-Card Three or More Times in a One Hour Period"
date = "2024-05-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1604: Alert Using Same Key-Card Three or More Times in a One Hour Period in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gGNxRDPPbgA"
youtube_upload_date="2020-10-05"
youtube_thumbnail="https://i.ytimg.com/vi/gGNxRDPPbgA/maxresdefault.jpg"
comments = true
+++



---
Employees use key-cards to unlock office doors, and the system records the time of each use. An alert is triggered if a worker uses their key-card three or more times within a one-hour period.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two lists: keyName and keyTime. keyName[i] represents the name of the employee, and keyTime[i] represents the time the key-card was used by that employee.
- **Example:** `["alice", "alice", "alice", "bob", "bob", "bob", "bob"]`
- **Constraints:**
	- 1 <= keyName.length, keyTime.length <= 10^5
	- keyName[i] contains only lowercase English letters
	- keyTime[i] is in the format 'HH:MM'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of unique employee names who used their key-card three or more times within a one-hour window. The result should be sorted in ascending alphabetical order.
- **Example:** `["bob"]`
- **Constraints:**
	- The names are returned sorted in ascending order

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort the times for each employee, check for any sequence of three or more uses within a one-hour window, and return those names.

- Iterate over each employee and convert their usage times to minutes.
- Sort the times of each employee.
- For each employee, check if there are three or more uses within a 60-minute window.
- If so, add the employee's name to the result list.
{{< dots >}}
### Problem Assumptions ✅
- Key-card usage times are always within a single day.
{{< dots >}}
## Examples 🧩
- **Input:** `["alice", "alice", "alice", "bob", "bob", "bob", "bob"]`  \
  **Explanation:** "bob" triggered an alert because their key-card was used 3 times within a one-hour period.

{{< dots >}}
## Approach 🚀
The approach involves sorting the times for each employee and checking if there are three or more usages within a 60-minute window.

### Initial Thoughts 💭
- We need to ensure the times are handled efficiently.
- Sorting each employee's times is key.
- A sliding window approach can be applied to check for the time window of 60 minutes.
{{< dots >}}
### Edge Cases 🌐
- Empty lists should return an empty result.
- The solution should handle up to 10^5 employees efficiently.
- Times at the very beginning or end of the day should be handled correctly.
- Ensure correct handling of time formats and boundary conditions.
{{< dots >}}
## Code 💻
```cpp

vector<string> alertNames(vector<string>& name, vector<string>& time) {
    
    unordered_map<string, vector<int>> mp;
    
    int n = name.size();
    for(int i = 0; i < n; i++)
    mp[name[i]].push_back(stoi(time[i].substr(0, 2)) * 60 + stoi(time[i].substr(3)));
    
    vector<string> ans;
    for(auto &it: mp) {
        sort(it.second.begin(), it.second.end());
        // cout << it.first << " ";
        // for(auto x: it.second)
        //     cout << x << " ";
        // cout << "\n";            
        for(int i = 0, j = 0; i < it.second.size(); i++) {
            while(it.second[i] - it.second[j] > 60)
                j++;
            
            if(i - j >= 2) {
                ans.push_back(it.first);
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
```

This code defines the function alertNames which takes in two arrays: 'name' and 'time'. It processes the data to identify users who have triggered multiple alerts within a 60-minute window.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> alertNames(vector<string>& name, vector<string>& time) {
	```
	This is the function definition of 'alertNames' which takes two arguments: 'name' and 'time', both are vectors of strings. The function will return a vector of strings containing the names of users who triggered multiple alerts within an hour.

2. **Variable Declaration**
	```cpp
	    unordered_map<string, vector<int>> mp;
	```
	An unordered_map is declared to store each name and the corresponding times at which the alerts were triggered. The map uses the name as the key and a vector of integers as the value, where each integer represents a time (in minutes).

3. **Variable Declaration**
	```cpp
	    int n = name.size();
	```
	The size of the 'name' vector is stored in variable 'n'. This value will be used to iterate over both 'name' and 'time' vectors.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	A loop is initiated to iterate through each name and corresponding time in the 'name' and 'time' vectors.

5. **Map Insertion**
	```cpp
	    mp[name[i]].push_back(stoi(time[i].substr(0, 2)) * 60 + stoi(time[i].substr(3)));
	```
	For each entry in the 'name' and 'time' vectors, the time string is converted to minutes (HH * 60 + MM), and the corresponding name is used as a key to store the times in the map.

6. **Variable Declaration**
	```cpp
	    vector<string> ans;
	```
	A vector 'ans' is initialized to store the names of users who have triggered alerts within an hour.

7. **Loop**
	```cpp
	    for(auto &it: mp) {
	```
	Iterate through the map to process each user and their corresponding list of alert times.

8. **Sort**
	```cpp
	        sort(it.second.begin(), it.second.end());
	```
	The list of times for each user (it.second) is sorted in ascending order to facilitate checking for alerts within an hour.

9. **Loop**
	```cpp
	        for(int i = 0, j = 0; i < it.second.size(); i++) {
	```
	A nested loop is used to check pairs of alert times. 'i' is the index for the current alert, and 'j' is the index for the earliest alert time that is within an hour.

10. **While Loop**
	```cpp
	            while(it.second[i] - it.second[j] > 60)
	```
	If the difference between the current alert time (it.second[i]) and the earliest alert time (it.second[j]) exceeds 60 minutes, increment 'j' to check a new earliest time.

11. **Increment**
	```cpp
	                j++;
	```
	Increment the 'j' index to check the next alert time that is within 60 minutes of the current alert.

12. **Condition Check**
	```cpp
	            if(i - j >= 2) {
	```
	If there are at least three alerts within the 60-minute window (i - j >= 2), the user qualifies to be added to the 'ans' list.

13. **Vector Push**
	```cpp
	                ans.push_back(it.first);
	```
	Add the user (it.first) to the 'ans' list since they triggered multiple alerts within an hour.

14. **Break**
	```cpp
	                break;
	```
	Exit the inner loop once a user has been added to the result list.

15. **Sort**
	```cpp
	    sort(ans.begin(), ans.end());
	```
	Sort the final list of users alphabetically.

16. **Return**
	```cpp
	    return ans;
	```
	Return the final sorted list of users who triggered multiple alerts within 60 minutes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

We sort the times for each employee, and this takes O(n log n) time in the worst case.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We store each employee's usage times, so the space complexity is O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/)

---
{{< youtube gGNxRDPPbgA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
