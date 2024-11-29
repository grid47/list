
+++
authors = ["grid47"]
title = "Leetcode 1348: Tweet Counts Per Frequency"
date = "2024-06-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1348: Tweet Counts Per Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Binary Search","Design","Sorting","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jpK7Bpf8wgk"
youtube_upload_date="2021-04-05"
youtube_thumbnail="https://i.ytimg.com/vi/jpK7Bpf8wgk/maxresdefault.jpg"
comments = true
+++



---
A social media company wants to analyze tweet activity by counting the number of tweets in given time periods, broken down by minute, hour, or day frequency. Design an API to record tweets and calculate the number of tweets within specific time intervals.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of multiple operations. Each operation is either a tweet record or a query for the tweet count per frequency in a given time period.
- **Example:** `For example, recording tweets at specific times and querying the tweet counts per frequency (minute, hour, or day).`
- **Constraints:**
	- 0 <= time, startTime, endTime <= 10^9
	- 0 <= endTime - startTime <= 10^4
	- There will be at most 10^4 calls to recordTweet and getTweetCountsPerFrequency.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a list of integers representing the number of tweets recorded during each time interval for the given frequency, within the specified time period.
- **Example:** `For a query with frequency 'minute', the result will be a list of counts for each minute chunk within the time period.`
- **Constraints:**
	- Each query must return a list of non-negative integers, representing the number of tweets for each time chunk.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently record tweet times and return the tweet counts per frequency within specified time intervals.

- 1. Store tweet records in a map with the tweet name as the key and a list of recorded times as the value.
- 2. For each query, calculate how many tweets fall into each time chunk by using the specified frequency.
- 3. Return the list of tweet counts for each time chunk.
{{< dots >}}
### Problem Assumptions ✅
- The time inputs will always be valid and within the specified range.
- The tweet names will be unique strings.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: recordTweet('tweet3', 0), recordTweet('tweet3', 60), recordTweet('tweet3', 10), getTweetCountsPerFrequency('minute', 'tweet3', 0, 59)`  \
  **Explanation:** The query returns [2] because there are two tweets within the time interval [0,59].

- **Input:** `Example 2: getTweetCountsPerFrequency('minute', 'tweet3', 0, 60)`  \
  **Explanation:** The query returns [2,1] because there are two tweets within [0,59] and one tweet at 60.

- **Input:** `Example 3: getTweetCountsPerFrequency('hour', 'tweet3', 0, 210)`  \
  **Explanation:** The query returns [4] because all 4 tweets fall within the 0-210 range.

{{< dots >}}
## Approach 🚀
The approach involves recording tweet timestamps in a map and querying them efficiently based on time intervals and frequency.

### Initial Thoughts 💭
- Storing tweet times in a list allows for efficient addition and retrieval.
- We need to optimize the query process by using a pre-defined frequency map for each type of query (minute, hour, day).
{{< dots >}}
### Edge Cases 🌐
- No tweets recorded, return empty results for any query.
- Ensure the solution can handle large time ranges and many queries efficiently.
- If the query period is very short, ensure that the correct chunk is counted.
- The solution must handle up to 10^4 queries and large time ranges efficiently.
{{< dots >}}
## Code 💻
```cpp
unordered_map<string, int> frq = {
    {"minute", 60}, {"hour", 3600}, {"day", 86400}
};
public:
TweetCounts() {
    
}

void recordTweet(string name, int time) {
    mp[name].push_back(time);
}

vector<int> getTweetCountsPerFrequency(string fq, string name, int start, int end) {
    vector<int> res;
    for(int i = 0; i <= (end - start) / frq[fq]; i++)
        res.push_back(0);
    
    for(int i = 0; i < mp[name].size(); i++) {
        int t = mp[name][i];
        if(t >= start && t <= end) {
        int idx = (t - start) / frq[fq];
        res[idx]++;
        }
    }
    return res;
}
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
```

The complete code implements a TweetCounts class, which keeps track of tweet occurrences and provides counts over specified time intervals.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Map Initialization**
	```cpp
	unordered_map<string, int> frq = {
	```
	Defines a mapping for time units (minute, hour, day) to their equivalent in seconds.

2. **Map Initialization**
	```cpp
	    {"minute", 60}, {"hour", 3600}, {"day", 86400}
	```
	Populates the map with key-value pairs representing time units and their respective values in seconds.

3. **Access Modifier**
	```cpp
	public:
	```
	Declares the public access modifier for the class.

4. **Constructor**
	```cpp
	TweetCounts() {
	```
	Defines the default constructor for the TweetCounts class.

5. **Class Methods**
	```cpp
	void recordTweet(string name, int time) {
	```
	Begins the implementation of a method to record a tweet at a specified time.

6. **Class Methods**
	```cpp
	    mp[name].push_back(time);
	```
	Adds the given time to the list of times associated with the tweet name.

7. **Frequency Computation**
	```cpp
	vector<int> getTweetCountsPerFrequency(string fq, string name, int start, int end) {
	```
	Begins a method to calculate the number of tweets within specified frequency intervals.

8. **Frequency Computation**
	```cpp
	    vector<int> res;
	```
	Initializes a vector to store the result for each interval.

9. **Loop Setup**
	```cpp
	    for(int i = 0; i <= (end - start) / frq[fq]; i++)
	```
	Sets up a loop to initialize the result vector with zeros for each interval.

10. **Loop Setup**
	```cpp
	        res.push_back(0);
	```
	Adds a zero for each interval to the result vector.

11. **Data Processing**
	```cpp
	    for(int i = 0; i < mp[name].size(); i++) {
	```
	Iterates through all recorded tweet times for the given name.

12. **Data Processing**
	```cpp
	        int t = mp[name][i];
	```
	Fetches the current tweet time.

13. **Range Filtering**
	```cpp
	        if(t >= start && t <= end) {
	```
	Checks if the tweet time falls within the specified range.

14. **Index Computation**
	```cpp
	        int idx = (t - start) / frq[fq];
	```
	Calculates the index of the interval for the current tweet time.

15. **Result Update**
	```cpp
	        res[idx]++;
	```
	Increments the count for the corresponding interval.

16. **Return Result**
	```cpp
	    return res;
	```
	Returns the computed result vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the number of tweets recorded.
- **Average Case:** O(n + k) where n is the number of tweets and k is the number of query intervals.
- **Worst Case:** O(n + k) where n is the number of tweets and k is the number of query intervals.

The time complexity depends on the number of tweets recorded and the number of intervals queried.

### Space Complexity 💾
- **Best Case:** O(n) where n is the number of tweets recorded.
- **Worst Case:** O(n) where n is the number of tweets recorded.

The space complexity depends on the number of tweets stored in the map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/tweet-counts-per-frequency/description/)

---
{{< youtube jpK7Bpf8wgk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
