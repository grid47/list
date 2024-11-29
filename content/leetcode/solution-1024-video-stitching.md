
+++
authors = ["grid47"]
title = "Leetcode 1024: Video Stitching"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1024: Video Stitching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4Qho-im90ew"
youtube_upload_date="2020-11-05"
youtube_thumbnail="https://i.ytimg.com/vi/4Qho-im90ew/maxresdefault.jpg"
comments = true
+++



---
You are given a set of video clips from a sporting event that lasts a specified duration in seconds. The clips may overlap and have varying lengths. The goal is to determine the minimum number of clips required to cover the entire event. If it's impossible to cover the entire event, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of clips, where each clip is represented by a pair of integers [start, end] indicating the start and end times of the clip. Additionally, a single integer, time, specifies the duration of the event to be covered.
- **Example:** `clips = [[0, 3], [4, 7], [2, 5], [6, 8], [5, 9]], time = 9`
- **Constraints:**
	- 1 <= clips.length <= 100
	- 0 <= starti <= endi <= 100
	- 1 <= time <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the minimum number of clips needed to cover the entire event. If it's impossible to cover the event, return -1.
- **Example:** `Output: 3`
- **Constraints:**
	- If the clips cannot cover the entire event, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The task is to determine the smallest number of clips that can be used to cover the entire duration of the sporting event. This is a greedy problem where we need to select the clips that maximize the coverage of the event, ensuring we cover the entire time range from 0 to time.

- 1. Sort the clips based on their start times.
- 2. Use a greedy approach to select clips, always choosing the one that extends the coverage the most without skipping any part of the event.
- 3. If at any point the selected clips cannot extend the coverage, return -1.
- 4. Otherwise, return the number of clips selected.
{{< dots >}}
### Problem Assumptions ✅
- The clips array will be non-empty and the event duration will be positive.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: clips = [[0, 3], [4, 7], [2, 5], [6, 8], [5, 9]], time = 9`  \
  **Explanation:** In this case, we can take the clips [0, 3], [2, 5], and [5, 9], which cover the entire event from 0 to 9. So, the output is 3.

- **Input:** `Input: clips = [[0, 1], [1, 2]], time = 5`  \
  **Explanation:** In this case, it is impossible to cover the event duration from 0 to 5 using just the clips [0, 1] and [1, 2], so the output is -1.

{{< dots >}}
## Approach 🚀
The approach uses a greedy strategy where we attempt to cover the event by iteratively selecting the clip that extends the current coverage the furthest.

### Initial Thoughts 💭
- Sorting the clips by start time allows us to systematically check which clips to select for covering the event.
- By always picking the clip that extends the coverage the most, we can minimize the number of clips needed.
{{< dots >}}
### Edge Cases 🌐
- If there are no clips, return -1 unless the event duration is 0.
- The solution must efficiently handle inputs with up to 100 clips.
- If a clip exactly matches the time, it should be counted as one clip.
- Ensure that the solution handles cases where no set of clips can cover the entire event.
{{< dots >}}
## Code 💻
```cpp
int videoStitching(vector<vector<int>>& clips, int time) {
    sort(clips.begin(), clips.end());
    int res = 0;
    for(auto i = 0, st = 0, end = 0; st < time; st=end, ++res){
        for(; i < clips.size() && clips[i][0] <= st; ++i)
            end = max(end, clips[i][1]);
        if(st == end) return -1;
    }
    return res;
}
```

This function implements the video stitching problem, where it aims to find the minimum number of clips required to cover a time interval from 0 to `time`. It sorts the clips, and iterates through them to select the optimal clips that can cover the time interval. If it's not possible to cover the time interval, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int videoStitching(vector<vector<int>>& clips, int time) {
	```
	Define the function `videoStitching`, which takes a list of clips and a target time interval to cover.

2. **Sorting**
	```cpp
	    sort(clips.begin(), clips.end());
	```
	Sort the clips by their start times to make it easier to find overlapping intervals and select the optimal clips.

3. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize the result variable `res` to 0, which will store the number of clips used to cover the time interval.

4. **Looping**
	```cpp
	    for(auto i = 0, st = 0, end = 0; st < time; st=end, ++res){
	```
	Start a loop where `i` is the index for iterating through the clips, `st` is the start of the current covered interval, and `end` is the end of the last selected clip.

5. **Looping**
	```cpp
	        for(; i < clips.size() && clips[i][0] <= st; ++i)
	```
	Loop through the clips and find the clip whose start time is less than or equal to the current start time (`st`).

6. **Max Calculation**
	```cpp
	            end = max(end, clips[i][1]);
	```
	Update the `end` time by taking the maximum of the current `end` and the end time of the current clip, which extends the covered interval.

7. **Condition Check**
	```cpp
	        if(st == end) return -1;
	```
	If the current start time `st` is the same as the end time `end`, it means no clip can extend the coverage. Return -1 to indicate it's impossible to cover the entire time interval.

8. **Return Statement**
	```cpp
	    return res;
	```
	Return the number of clips used to cover the time interval.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n), where n is the number of clips.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for sorting the clips.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/video-stitching/description/)

---
{{< youtube 4Qho-im90ew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
