
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
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
};
{{< /highlight >}}
---

### Problem Statement:
The problem asks us to identify employees who have had high access activity. Specifically, we are given a list of access times for various employees, where each entry contains an employee ID and a time they accessed a system. We need to find employees who have had at least three overlapping access times during any 60-minute window.

For example, if an employee accessed the system at 09:15, 09:45, and 10:05, these access times overlap within the 60-minute window from 09:00 to 10:00. We are tasked with identifying such employees who have at least three overlapping access times in any 60-minute span.

### Approach:
To solve this problem efficiently, we can follow these steps:

1. **Convert Time to Minutes**: Since the access times are provided in the format `HHMM`, we need to convert these times into minutes since midnight. This simplifies the comparison process since we can work with integers representing the number of minutes passed since the start of the day.

2. **Track Overlapping Access Times**: For each employee, we need to track how many times they accessed the system at each specific minute. We can use a sweep line technique, where we increment and decrement a count at specific minutes to track the number of simultaneous accesses.

3. **Sweep Line Technique**: For each access time, we increment the count for the starting minute and decrement it 60 minutes later. This allows us to efficiently track the number of accesses at any given time, without needing to check each pair of accesses individually.

4. **Count Overlaps**: After updating the sweep line for all access times of each employee, we check if there is any 60-minute window where the total number of accesses is greater than or equal to 3. If such a window exists, the employee is considered to have high access activity.

5. **Return Employees with High Access Activity**: Finally, we return a list of employee IDs who have at least three overlapping access times in any 60-minute window.

### Code Breakdown (Step by Step):

1. **`string_to_int` Function**:
   This helper function converts a string representing time (in the format "HHMM") into an integer representing the total number of minutes since midnight. The function takes a string `s` and processes it by splitting the hours and minutes, converting them to integers, and calculating the total minutes.

   ```cpp
   int string_to_int(string s) {
       int val = 0;
       for (int i = 0; i < s.length(); i++) 
           val = val * 10 + (s[i] - '0');
       return val;
   }
   ```

   For example, for an input `"0930"`, the function calculates `9 * 60 + 30 = 570` minutes.

2. **Main Function `findHighAccessEmployees`**:
   The function `findHighAccessEmployees` takes as input a 2D vector `access_times`, where each entry contains an employee ID and an access time.

   ```cpp
   vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
       map<string, vector<int>> times;
   ```

   Here, `times` is a map that associates each employee (represented by a string) with a list of access times (in minutes) that are stored in the vector.

3. **Convert Access Times to Minutes**:
   For each entry in `access_times`, we extract the employee ID and convert the access time from "HHMM" format to total minutes using the `string_to_int` function. This is done in the loop:

   ```cpp
   for (vector<string> v : access_times) {
       string s = v[1];  // access time string
       int minutes = string_to_int(s.substr(0, 2)) * 60 + string_to_int(s.substr(2));
       times[v[0]].push_back(minutes);
   }
   ```

4. **Sweep Line Approach**:
   For each employee, we initialize a sweep array `sweep` of size 1441 (since there are 1440 minutes in a day, and the index 1440 represents the minute after 23:59). We then update the `sweep` array to track the start and end of each access event:

   ```cpp
   vector<int> sweep(1441, 0);
   for (int t : time) {
       sweep[t]++;
       if (t + 60 < 1441) 
           sweep[t + 60]--;
   }
   ```

   Here, we increment `sweep[t]` for the start of the access and decrement `sweep[t + 60]` to mark the end of the access after 60 minutes.

5. **Check for Overlapping Access Times**:
   After updating the sweep array for all access times, we iterate through the array and check for any 60-minute period with at least three accesses. If such a period exists, we add the employee ID to the result:

   ```cpp
   int c = 0;
   for (int i = 0; i < 1441; i++) {
       c += sweep[i];
       if (c >= 3) {
           ans.push_back(ch);
           break;
       }
   }
   ```

6. **Return the Result**:
   After processing all employees, we return the list of employee IDs who had high access activity:

   ```cpp
   return ans;
   }
   ```

### Complexity:

1. **Time Complexity**:
   The time complexity of this solution is primarily determined by the processing of the `access_times` array and the sweep line technique:
   - Converting the access times for each employee to minutes takes \(O(m)\), where \(m\) is the total number of access times across all employees.
   - The sweep line approach for each employee involves iterating through their list of access times, updating the `sweep` array, and checking for overlapping access times, which also takes \(O(n)\) for each employee (where \(n\) is the number of employees).
   
   Therefore, the overall time complexity is \(O(m + n \times 1441)\), where:
   - \(m\) is the number of total access times across all employees.
   - \(n\) is the number of employees.

2. **Space Complexity**:
   The space complexity of this solution is \(O(n + 1441)\), where:
   - \(n\) is the number of employees (as each employee has a list of access times).
   - 1441 represents the size of the `sweep` array (for tracking access counts across all minutes in a day).

   Thus, the space complexity is linear with respect to the number of employees and the fixed size of the sweep array.

### Conclusion:
This approach provides an efficient solution to the problem by utilizing a sweep line technique to track overlapping access times. The solution is optimized by converting access times into minutes and efficiently counting overlapping access events in constant time using the sweep array.

- **Time Complexity**: \(O(m + n \times 1441)\), where \(m\) is the total number of access times and \(n\) is the number of employees.
- **Space Complexity**: \(O(n + 1441)\), where \(n\) is the number of employees and 1441 is the size of the sweep array.

This method works well even for large datasets, where brute force solutions would be inefficient. The solution guarantees correctness by efficiently checking for overlapping access times without explicitly comparing each pair of access times. It’s a scalable solution suitable for real-world applications where access logs need to be analyzed for suspicious or high-activity behavior.

[`Link to LeetCode Lab`](https://leetcode.com/problems/high-access-employees/description/)

---
{{< youtube r4DlEjNCYE0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
