
+++
authors = ["grid47"]
title = "Leetcode 2747: Count Zero Request Servers"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2747: Count Zero Request Servers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "B5YiuyNSVP0"
youtube_upload_date="2023-06-30"
youtube_thumbnail="https://i.ytimg.com/vi/B5YiuyNSVP0/maxresdefault.jpg"
comments = true
+++



---
Given a list of server requests and multiple queries specifying time intervals, determine the number of servers that did not receive any requests during each query's time interval.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the number of servers n, a 2D list of logs where each log contains the server id and time of request, an integer x for the time window, and a list of queries.
- **Example:** `n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= logs.length <= 10^5
	- 1 <= queries.length <= 10^5
	- logs[i].length == 2
	- 1 <= logs[i][0] <= n
	- 1 <= logs[i][1] <= 10^6
	- 1 <= x <= 10^5
	- x < queries[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of integers where each element represents the number of servers that did not receive any requests in the specified time interval for each query.
- **Example:** `[1, 2]`
- **Constraints:**
	- The length of the result array should match the length of the queries array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the number of servers that did not receive any requests during the specified time intervals in each query.

- Sort the logs based on the request time.
- For each query, calculate the relevant time interval and count how many servers did not receive requests during that time.
- Efficiently track which servers are active during each time window using a set and a map.
{{< dots >}}
### Problem Assumptions ✅
- Each server can receive multiple requests.
- The logs are sorted by the request time.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, [1, 3], [2, 6], [1, 5]], x = 5, queries = [10,11]`  \
  **Explanation:** This example explains how we can count servers that did not receive requests in the given time interval.

{{< dots >}}
## Approach 🚀
This problem requires sorting the logs and efficiently managing which servers are active in a time window for each query.

### Initial Thoughts 💭
- The problem involves calculating active servers in a dynamic time window.
- Using a set to track active servers and a map to count requests is a good approach for managing the active servers.
{{< dots >}}
### Edge Cases 🌐
- What if the logs or queries are empty?
- Handle scenarios where the number of servers or queries is large, up to the maximum constraint.
- Consider cases where all servers receive requests or no servers receive requests.
- Ensure efficient handling of large inputs.
{{< dots >}}
## Code 💻
```cpp
vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
    vector<pair<int,int>> qs;
    for(int i=0;i<queries.size();i++){      // sorting and also storing the index to create an anwer at the end
        qs.push_back({queries[i],i});   // at their appropiate place
    }
    sort(qs.begin(),qs.end());
    vector<int> result(queries.size());

    set<pair<int,int>> s;       // for storing {time,id}
    map<int,int> count;         // for storing the number of ids in the current window
    
    sort(logs.begin(),logs.end(),[&](auto const &a,auto const &b){  // sorting the logs based on their time
        return a[1]<b[1];
    });         

    int i = 0;
    for(auto &[q,index]:qs){
        while(i<logs.size() && logs[i][1]<=q){          // adding all the servers that have time <= q
            s.insert({logs[i][1],logs[i][0]});          
            count[logs[i][0]]++;
            i++;
        }
        while(!s.empty() && s.begin()->first<q-x){      // removing all the elements that are out of the current 
            count[s.begin()->second]--;                 // window i.e. < q-x
            if(count[s.begin()->second]==0) count.erase(s.begin()->second);
            s.erase(s.begin());
        }
        result[index] = n - count.size();
    }
    return result;
}
```

This function calculates the number of servers that are not busy during a given time window for a set of queries.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
	```
	Defines the function `countServers` which takes the total number of servers `n`, a log of server events `logs`, a time window `x`, and a list of queries `queries`.

2. **Variable Initialization**
	```cpp
	    vector<pair<int,int>> qs;
	```
	Declares a vector `qs` to store the queries along with their original indices, so that the results can be placed in the correct order.

3. **Loop Initialization**
	```cpp
	    for(int i=0;i<queries.size();i++){      // sorting and also storing the index to create an anwer at the end
	```
	Iterates over each query to store the query values along with their indices in the vector `qs`.

4. **Element Insertion**
	```cpp
	        qs.push_back({queries[i],i});   // at their appropiate place
	```
	Inserts each query value along with its original index into the `qs` vector.

5. **Sorting**
	```cpp
	    sort(qs.begin(),qs.end());
	```
	Sorts the queries in ascending order to process them in the correct time order.

6. **Vector Initialization**
	```cpp
	    vector<int> result(queries.size());
	```
	Declares a vector `result` to store the result for each query, initialized with the size of the `queries` vector.

7. **Set Initialization**
	```cpp
	    set<pair<int,int>> s;       // for storing {time,id}
	```
	Declares a set `s` to store pairs of time and server id, ensuring each server appears only once.

8. **Map Initialization**
	```cpp
	    map<int,int> count;         // for storing the number of ids in the current window
	```
	Declares a map `count` to store the count of server IDs currently in the time window.

9. **Sorting Logs**
	```cpp
	    sort(logs.begin(),logs.end(),[&](auto const &a,auto const &b){  // sorting the logs based on their time
	```
	Sorts the `logs` vector based on the second element (time) in each log entry.

10. **Log Sorting Logic**
	```cpp
	        return a[1]<b[1];
	```
	Defines the sorting condition for the logs to sort them by time.

11. **Loop Initialization**
	```cpp
	    int i = 0;
	```
	Initializes an index `i` to iterate through the `logs` vector.

12. **Main Loop**
	```cpp
	    for(auto &[q,index]:qs){
	```
	Iterates over each query in `qs`, where `q` is the query time and `index` is the original index of the query.

13. **Inner While Loop 1**
	```cpp
	        while(i<logs.size() && logs[i][1]<=q){          // adding all the servers that have time <= q
	```
	Adds all logs with times less than or equal to the current query time `q` to the set `s`.

14. **Set Insertion**
	```cpp
	            s.insert({logs[i][1],logs[i][0]});          
	```
	Inserts the current log entry (time, server id) into the set `s`.

15. **Map Update**
	```cpp
	            count[logs[i][0]]++;
	```
	Increments the count for the server ID in the `count` map.

16. **Increment Index**
	```cpp
	            i++;
	```
	Increments the index `i` to process the next log entry.

17. **Inner While Loop 2**
	```cpp
	        while(!s.empty() && s.begin()->first<q-x){      // removing all the elements that are out of the current 
	```
	Removes any server logs from the set `s` that are outside of the current time window.

18. **Map Update for Removal**
	```cpp
	            count[s.begin()->second]--;                 // window i.e. < q-x
	```
	Decrements the count for the server ID being removed from the time window.

19. **Erase from Map**
	```cpp
	            if(count[s.begin()->second]==0) count.erase(s.begin()->second);
	```
	Removes the server ID from the `count` map if its count reaches zero.

20. **Set Erase**
	```cpp
	            s.erase(s.begin());
	```
	Removes the log entry from the set `s`.

21. **Result Assignment**
	```cpp
	        result[index] = n - count.size();
	```
	Assigns the result for the current query by subtracting the number of servers in the time window from the total number of servers `n`.

22. **Return Statement**
	```cpp
	    return result;
	```
	Returns the `result` vector containing the answers for each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n + m log m)
- **Average Case:** O(n log n + m log m)
- **Worst Case:** O(n log n + m log m)

The sorting of logs and queries dominates the complexity.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity arises from storing logs and queries, along with the set and map for tracking active servers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-zero-request-servers/description/)

---
{{< youtube B5YiuyNSVP0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
