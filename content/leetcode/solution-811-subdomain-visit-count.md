
+++
authors = ["grid47"]
title = "Leetcode 811: Subdomain Visit Count"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 811: Subdomain Visit Count in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/811.webp"
youtube = "oe_eXlH5dUM"
youtube_upload_date="2019-12-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/oe_eXlH5dUM/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/811.webp" 
    alt="A set of web domains where subdomains are counted, with each subdomain glowing softly as it’s identified."
    caption="Solution to LeetCode 811: Subdomain Visit Count Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a list of count-paired domains, where each entry consists of a number followed by a domain name. The number represents the number of visits to that domain. A domain may also have subdomains, and visiting a subdomain also counts as visiting its parent domains. Your task is to return the count of visits for each domain and its subdomains.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You will be provided with a list of strings where each string contains a visit count and a domain name. The format is 'count domain'. Each domain name can have subdomains separated by dots.
- **Example:** `Input: cpdomains = ['100 xyz.com', '200 abc.xyz.com']`
- **Constraints:**
	- 1 <= cpdomain.length <= 100
	- 1 <= cpdomain[i].length <= 100
	- cpdomain[i] follows the 'count domain' format.
	- The domains are composed of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of strings, each string showing the total count of visits for a domain or subdomain, in the format 'count domain'.
- **Example:** `Output: ['100 xyz.com', '200 abc.xyz.com', '300 com']`
- **Constraints:**
	- The result should be returned in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The task is to determine how many times each domain and its subdomains have been visited, accounting for the subdomains' visits as well.

- Parse the input string to extract the number of visits and the domain name.
- For each domain, also count its parent domains by iterating through the subdomains.
- Store the total visit count for each domain and its subdomains in a map or dictionary.
- Finally, return the list of counts in the required format.
{{< dots >}}
### Problem Assumptions ✅
- The input data format is valid and follows the expected pattern.
- Each domain and subdomain consists only of lowercase letters and dot separators.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: cpdomains = ['100 xyz.com', '200 abc.xyz.com']`  \
  **Explanation:** In this example, 'xyz.com' is visited 100 times, 'abc.xyz.com' is visited 200 times, and 'com' is visited a total of 300 times (100 from 'xyz.com' and 200 from 'abc.xyz.com').

{{< dots >}}
## Approach 🚀
The approach involves counting the number of visits for each domain and all its subdomains by iterating through the input list and breaking down the domain names into their subdomains.

### Initial Thoughts 💭
- Each domain name can have multiple subdomains.
- The number of visits to the parent domain is shared by all of its subdomains.
- We need to keep track of visits to both the full domain and all possible subdomains.
{{< dots >}}
### Edge Cases 🌐
- If the input list is empty, return an empty result.
- Ensure that the solution can handle the upper limit of the input size efficiently.
- Check how the solution handles cases where subdomains are not repeated.
- The solution should run efficiently for the maximum number of domains.
{{< dots >}}
## Code 💻
```cpp
vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> count;

    for(auto cp: cpdomains) {
        int i = cp.find(" ");
        int n = stoi(cp.substr(0, i));
        string s = cp.substr(i + 1);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '.')
                count[s.substr(i + 1)] += n;
        }
        count[s] += n;
    }
    vector<string> res;
    for(auto it: count)
    res.push_back(to_string(it.second) + " " + it.first);
    return res;
}
```

This function processes a list of domain visit counts and returns a list of the subdomains with the corresponding visit counts.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> subdomainVisits(vector<string>& cpdomains) {
	```
	This is the function signature, defining a function `subdomainVisits` that takes a vector of strings (`cpdomains`). The function returns a vector of strings containing the subdomain visit counts.

2. **Variable Initialization**
	```cpp
	    unordered_map<string, int> count;
	```
	An unordered map `count` is initialized to store the number of visits to each subdomain. The keys are subdomains and the values are visit counts.

3. **Subdomain Extraction**
	```cpp
	    for(auto cp: cpdomains) {
	```
	The function begins a loop to process each domain in the `cpdomains` list.

4. **Substring Processing**
	```cpp
	        int i = cp.find(" ");
	```
	This line finds the first space in the string `cp` which separates the visit count from the domain.

5. **String to Integer Conversion**
	```cpp
	        int n = stoi(cp.substr(0, i));
	```
	This converts the numeric part of the string (before the space) into an integer `n`, representing the number of visits.

6. **Domain Extraction**
	```cpp
	        string s = cp.substr(i + 1);
	```
	The part of the string after the space is extracted and stored in `s`, which is the full domain name.

7. **Loop through Subdomains**
	```cpp
	        for(int i = 0; i < s.size(); i++) {
	```
	This inner loop iterates over each character in the domain string `s`.

8. **Subdomain Counting**
	```cpp
	            if(s[i] == '.')
	```
	Whenever a period (`.`) is encountered, it indicates the end of a subdomain. The part after the period is treated as a subdomain.

9. **Increment Subdomain Count**
	```cpp
	                count[s.substr(i + 1)] += n;
	```
	The subdomain starting from the current position is added to the `count` map, and its count is incremented by `n`.

10. **Final Count Update**
	```cpp
	        count[s] += n;
	```
	The full domain `s` is also added to the map with its count incremented by `n`.

11. **Result Vector Initialization**
	```cpp
	    vector<string> res;
	```
	A new vector `res` is initialized to store the result.

12. **Result Population**
	```cpp
	    for(auto it: count)
	```
	This loop iterates over the `count` map to prepare the result vector by formatting the counts.

13. **Formatting Result**
	```cpp
	    res.push_back(to_string(it.second) + " " + it.first);
	```
	Each entry in `count` is formatted as a string with the visit count and the domain, and added to the result vector.

14. **Return Result**
	```cpp
	    return res;
	```
	The result vector `res` is returned, containing the formatted subdomain visit counts.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the total number of domains.
- **Average Case:** O(n * m) where n is the number of input domains and m is the average number of subdomains per domain.
- **Worst Case:** O(n * m) in the worst case when every domain has many subdomains.

The time complexity mainly depends on the number of subdomains and how we iterate through them.

### Space Complexity 💾
- **Best Case:** O(n) when there are fewer subdomains.
- **Worst Case:** O(n * m) where n is the number of domains and m is the average number of subdomains, due to the space used by the map to store the visit counts.

The space complexity is determined by the number of unique subdomains that need to be stored.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/subdomain-visit-count/description/)

---
{{< youtube oe_eXlH5dUM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
