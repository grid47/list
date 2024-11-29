
+++
authors = ["grid47"]
title = "Leetcode 2456: Most Popular Video Creator"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2456: Most Popular Video Creator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2xvkEXjtmWE"
youtube_upload_date="2022-10-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/2xvkEXjtmWE/maxresdefault.webp"
comments = true
+++



---
You are given three arrays: 'creators', 'ids', and 'views'. Each index i corresponds to a video created by the creator 'creators[i]', with an id 'ids[i]', and a number of views 'views[i]'. The task is to find the most popular creators based on the sum of views of all their videos and identify the id of their most viewed video. If multiple creators have the same popularity, return all of them. For each creator, if they have multiple videos with the highest view count, return the lexicographically smallest id of their most viewed video.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three arrays: 'creators' (a list of strings), 'ids' (a list of strings), and 'views' (a list of integers). All arrays have the same length n, representing the number of videos.
- **Example:** `creators = ['anna', 'bob', 'anna', 'chris'], ids = ['one', 'two', 'three', 'four'], views = [5, 10, 5, 4]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= creators[i].length, ids[i].length <= 5
	- creators[i] and ids[i] consist of lowercase English letters only
	- 0 <= views[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 2D array where each element is a pair of creator and their most popular video's id. If there are multiple creators with the highest popularity, include all of them. If a creator has multiple videos with the highest views, return the lexicographically smallest id.
- **Example:** `[['anna', 'one'], ['bob', 'two']]`
- **Constraints:**
	- The answer can be in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the popularity of creators based on the sum of views of their videos and identify the id of their most popular video.

- 1. Iterate through each video and accumulate views for each creator.
- 2. Store the video details for each creator in a way that allows easy identification of the most viewed video.
- 3. After processing all the videos, identify the creator(s) with the highest total views.
- 4. For each of these creators, find their video with the highest views, and if there are ties, choose the lexicographically smallest video id.
{{< dots >}}
### Problem Assumptions ✅
- The video ids are not necessarily unique across creators, but each video id is unique for each creator.
{{< dots >}}
## Examples 🧩
- **Input:** `creators = ['anna', 'bob', 'anna', 'chris'], ids = ['one', 'two', 'three', 'four'], views = [5, 10, 5, 4]`  \
  **Explanation:** In this example, 'anna' has a total of 10 views (from videos 'one' and 'three'). 'bob' has 10 views (from video 'two'). 'chris' has 4 views. 'anna' and 'bob' are the most popular creators. For 'anna', the lexicographically smaller video id with the highest views is 'one'. For 'bob', the video id with the highest views is 'two'.

- **Input:** `creators = ['anna', 'anna', 'anna'], ids = ['a', 'b', 'c'], views = [1, 2, 2]`  \
  **Explanation:** Here, 'anna' is the only creator, and the most viewed video is 'b' because it has 2 views, which is lexicographically smaller than 'c'.

{{< dots >}}
## Approach 🚀
We will first calculate the total views for each creator and track the most viewed video for each creator. After determining the creators with the highest popularity, we will select the lexicographically smallest video id for those creators.

### Initial Thoughts 💭
- We need to handle large inputs efficiently, so we should aim for a linear time complexity.
- We can use a hash map to store the sum of views for each creator and a list of videos for each creator.
{{< dots >}}
### Edge Cases 🌐
- If the input arrays are empty, return an empty result.
- For large inputs, ensure the solution can handle up to 100,000 videos efficiently.
- If all videos have zero views, the result should be an empty list.
- Ensure efficient handling of both the creators and video ids, as there can be many different creators and video ids.
{{< dots >}}
## Code 💻
```cpp
class Solution {

static bool cmp(pair<ll, string> p1, pair<ll, string> p2) {
    if(p1.first == p2.first) return p1.second < p2.second;
    else return p1.first > p2.first;
}

public:
vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
    vector<vector<string>> ans;
    long long n = creators.size(), maxi = INT_MIN;
    map<string, ll> m1;
    map<string, vector<pair<ll, string>>> m2;

    for(int i = 0; i < n; i++) {
        m1[creators[i]] += views[i];
        m2[creators[i]].push_back(make_pair(views[i], ids[i]));
        maxi = max(maxi, m1[creators[i]]);
    }

    for(auto &[l, r] : m1) {
        if(r == maxi) {
            sort(m2[l].begin(), m2[l].end(), cmp);
            ans.push_back({l, m2[l].front().second});
        }
    }
    return ans;
}
```

This solution identifies the most popular creator based on views. It uses maps to track cumulative views and stores associated IDs in sorted order, returning the top creators with their most popular content.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the `Solution` class containing the required function.

2. **Helper Function**
	```cpp
	static bool cmp(pair<ll, string> p1, pair<ll, string> p2) {
	```
	Defines a comparator function to sort pairs of view counts and IDs based on the view count and lexicographical order of IDs.

3. **Condition Check**
	```cpp
	    if(p1.first == p2.first) return p1.second < p2.second;
	```
	Checks if two elements have the same view count and compares their IDs lexicographically.

4. **Condition Check**
	```cpp
	    else return p1.first > p2.first;
	```
	If view counts differ, sorts them in descending order of view count.

5. **Function Definition**
	```cpp
	public:
	```
	Marks the start of the public section in the `Solution` class.

6. **Function Definition**
	```cpp
	vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
	```
	Defines the main function to calculate the most popular creators and their most viewed content.

7. **Variable Initialization**
	```cpp
	    vector<vector<string>> ans;
	```
	Initializes the result container for the output.

8. **Variable Initialization**
	```cpp
	    long long n = creators.size(), maxi = INT_MIN;
	```
	Stores the number of creators and initializes the maximum views variable.

9. **Map Initialization**
	```cpp
	    map<string, ll> m1;
	```
	Initializes a map to store cumulative views for each creator.

10. **Map Initialization**
	```cpp
	    map<string, vector<pair<ll, string>>> m2;
	```
	Initializes a map to store pairs of views and IDs for each creator.

11. **Loop Through List**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Loops through all creators to populate the maps.

12. **Map Update**
	```cpp
	        m1[creators[i]] += views[i];
	```
	Updates the cumulative views for the current creator in the map.

13. **Map Update**
	```cpp
	        m2[creators[i]].push_back(make_pair(views[i], ids[i]));
	```
	Adds the view count and ID pair to the vector for the current creator.

14. **Maximum Update**
	```cpp
	        maxi = max(maxi, m1[creators[i]]);
	```
	Updates the maximum views encountered so far.

15. **Map Iteration**
	```cpp
	    for(auto &[l, r] : m1) {
	```
	Iterates through the map to identify creators with the maximum views.

16. **Condition Check**
	```cpp
	        if(r == maxi) {
	```
	Checks if the current creator's total views match the maximum views.

17. **Sorting**
	```cpp
	            sort(m2[l].begin(), m2[l].end(), cmp);
	```
	Sorts the content for the current creator using the comparator function.

18. **Result Update**
	```cpp
	            ans.push_back({l, m2[l].front().second});
	```
	Adds the creator and their most popular content ID to the result.

19. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the result containing the most popular creators and their top content.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We are only performing simple operations on each video and then sorting a small list of video ids for each creator.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We store video details and the popularity of each creator, which requires linear space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/most-popular-video-creator/description/)

---
{{< youtube 2xvkEXjtmWE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
