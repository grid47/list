
+++
authors = ["grid47"]
title = "Leetcode 2933: High-Access Employees"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2933: High-Access Employees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "r4DlEjNCYE0"
youtube_upload_date="2023-11-14"
youtube_thumbnail="https://i.ytimg.com/vi/r4DlEjNCYE0/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D array, access_times, where each entry contains an employee's name and their system access time in 24-hour format (HHMM). An employee is considered 'high-access' if they accessed the system at least three times within any one-hour window. The task is to identify all such high-access employees and return their names.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of lists, where each sublist contains a string representing an employee's name and another string representing their access time.
- **Example:** `[['a', '0549'], ['b', '0457'], ['a', '0532'], ['a', '0621'], ['b', '0540']]`
- **Constraints:**
	- 1 <= access_times.length <= 100
	- access_times[i].length == 2
	- 1 <= access_times[i][0].length <= 10
	- access_times[i][0] consists only of English lowercase letters
	- access_times[i][1].length == 4
	- access_times[i][1] is in 'HHMM' 24-hour format

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of employee names who are considered high-access. The order of the names does not matter.
- **Example:** `['a']`
- **Constraints:**
	- The list should contain names of high-access employees only.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify employees who accessed the system at least three times within any one-hour window.

- Convert the access times into minutes.
- Sort the times for each employee.
- Use a sweep-line approach to check if three or more accesses occur within any 60-minute period.
{{< dots >}}
### Problem Assumptions ✅
- Each access time entry is guaranteed to be a valid four-digit time string in 24-hour format.
{{< dots >}}
## Examples 🧩
- **Input:** `[['a', '0549'], ['b', '0457'], ['a', '0532'], ['a', '0621'], ['b', '0540']]`  \
  **Explanation:** 'a' has three access times (05:32, 05:49, and 06:21) within the one-hour period from 05:32 to 06:31, making them a high-access employee. 'b' does not have three access times in any one-hour period, so they are not included in the result.

{{< dots >}}
## Approach 🚀
The solution involves sorting the access times for each employee, converting the times to minutes, and applying a sweep-line algorithm to identify high-access employees.

### Initial Thoughts 💭
- We need to convert time into minutes for easier manipulation.
- A sweep-line approach is ideal for checking overlapping time periods.
- Sorting the access times is important for efficiently checking access within a one-hour window.
{{< dots >}}
### Edge Cases 🌐
- An empty input should return an empty list.
- The algorithm should perform well with the maximum allowed input size of 100 records.
- If there are exactly three accesses in a one-hour period, the employee should be considered high-access.
- The solution should work within the given time and space complexity constraints.
{{< dots >}}
## Code 💻
```cpp

int string_to_int(string s){
    int val=0;
    for(int i=0;i<s.length();i++) val = val*10 + (s[i]-'0');
    
    return val;
}

vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
		map<string, vector<int>> times;
    for(vector<string> v : access_times){
        string s=v[1];
        
        int minutes = string_to_int(s.substr(0,2))*60 + string_to_int(s.substr(2));
        times[v[0]].push_back(minutes);
    }
    
    vector<string> ans;
    for(auto it=times.begin();it!=times.end();it++){
        string ch = it->first;
        vector<int> time = it->second;
        
        vector<int> sweep(1441,0);
        for(int t : time){
				// contribution of each access for next 59 minutes
            sweep[t]++;
            if(t+60 < 1441) sweep[t+60]--;
        }
        
			// check for at least 3 overlapping access times
        int c=0;
        for(int i=0;i<1441;i++){
            c += sweep[i];
            
            if(c>=3){
                ans.push_back(ch);
                break;
            }
        }
    }
    
    return ans;
}
```

This function takes a list of employee access times and returns the names of employees who have at least 3 overlapping access times within any given hour.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Helper Function**
	```cpp
	int string_to_int(string s){
	```
	Defines a helper function to convert a string representation of a number to an integer.

2. **Variable Initialization**
	```cpp
	    int val=0;
	```
	Initializes a variable 'val' to 0, which will store the resulting integer value.

3. **String Parsing**
	```cpp
	    for(int i=0;i<s.length();i++) val = val*10 + (s[i]-'0');
	```
	Iterates through the string and converts each character to its integer equivalent, updating 'val' by multiplying the current value by 10 and adding the digit.

4. **Return Statement**
	```cpp
	    return val;
	```
	Returns the final integer value after processing all characters of the string.

5. **Main Function Definition**
	```cpp
	vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
	```
	Defines the function that will identify employees with high access times.

6. **Data Structure Setup**
	```cpp
			map<string, vector<int>> times;
	```
	Declares a map 'times' where each employee's name (string) maps to a vector of access times (integers).

7. **Iterate Through Access Times**
	```cpp
	    for(vector<string> v : access_times){
	```
	Iterates over the list of employee access times.

8. **Extract Time**
	```cpp
	        string s=v[1];
	```
	Extracts the access time as a string from the second element of the current vector.

9. **Time Conversion**
	```cpp
	        int minutes = string_to_int(s.substr(0,2))*60 + string_to_int(s.substr(2));
	```
	Converts the access time from a string (HHMM format) to an integer representing minutes since midnight.

10. **Store Access Time**
	```cpp
	        times[v[0]].push_back(minutes);
	```
	Stores the calculated minutes for the current employee in the 'times' map under their name.

11. **Result Setup**
	```cpp
	    vector<string> ans;
	```
	Declares a vector 'ans' to store the names of employees who meet the criteria.

12. **Iterate Through Employees**
	```cpp
	    for(auto it=times.begin();it!=times.end();it++){
	```
	Iterates through the 'times' map to process each employee and their corresponding access times.

13. **Extract Employee Info**
	```cpp
	        string ch = it->first;
	```
	Extracts the employee's name from the map entry.

14. **Access Time Vector**
	```cpp
	        vector<int> time = it->second;
	```
	Extracts the vector of access times for the current employee.

15. **Setup Sweep Array**
	```cpp
	        vector<int> sweep(1441,0);
	```
	Initializes an array 'sweep' of size 1441 to track the number of access times at each minute during the day (minutes 0 to 1440).

16. **Iterate Through Access Times**
	```cpp
	        for(int t : time){
	```
	Iterates over each access time for the current employee.

17. **Mark Access Time**
	```cpp
	            sweep[t]++;
	```
	Increments the corresponding minute in the 'sweep' array to indicate that the employee accessed the system at this time.

18. **Handle Access Expiry**
	```cpp
	            if(t+60 < 1441) sweep[t+60]--;
	```
	Decrements the minute that marks the expiration of the access time (one hour later).

19. **Check for Overlapping Access Times**
	```cpp
	        int c=0;
	```
	Initializes a counter 'c' to track the number of overlapping access times at each minute.

20. **Sweep Through Time**
	```cpp
	        for(int i=0;i<1441;i++){
	```
	Sweeps through the entire 24-hour period (1441 minutes) to check for overlapping access times.

21. **Count Overlapping Accesses**
	```cpp
	            c += sweep[i];
	```
	Adds the number of accesses at the current minute to the counter 'c'.

22. **Check Overlap Condition**
	```cpp
	            if(c>=3){
	```
	Checks if the number of overlapping access times at the current minute is greater than or equal to 3.

23. **Record Employee**
	```cpp
	                ans.push_back(ch);
	```
	If the overlap condition is met, adds the employee's name to the 'ans' vector.

24. **End Overlap Check**
	```cpp
	                break;
	```
	Breaks out of the loop once the employee has been recorded.

25. **Return Result**
	```cpp
	    return ans;
	```
	Returns the list of employee names who have at least 3 overlapping access times.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) where n is the number of access times (due to sorting).
- **Average Case:** O(n log n) due to the sorting step.
- **Worst Case:** O(n log n) where n is the number of access times, because the sorting dominates the complexity.

The time complexity is driven by the sorting step for each employee's access times.

### Space Complexity 💾
- **Best Case:** O(n) for storing the list of access times and results.
- **Worst Case:** O(n) where n is the number of access times (due to storing the times for each employee).

The space complexity is primarily determined by the storage of employee access times and the result list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/high-access-employees/description/)

---
{{< youtube r4DlEjNCYE0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
