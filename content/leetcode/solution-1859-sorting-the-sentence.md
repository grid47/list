
+++
authors = ["grid47"]
title = "Leetcode 1859: Sorting the Sentence"
date = "2024-05-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1859: Sorting the Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "MCPhGg_vedE"
youtube_upload_date="2021-05-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MCPhGg_vedE/maxresdefault.webp"
comments = true
+++



---
You are given a shuffled sentence where each word is tagged with a number that represents its position in the original sentence. Your task is to reconstruct the sentence in its original order and return it.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a shuffled sentence containing words followed by a number that represents the word's original position in the sentence.
- **Example:** `s = "apple2 banana1 cherry4 mango3"`
- **Constraints:**
	- 2 <= s.length <= 200
	- s contains lowercase and uppercase English letters, spaces, and digits from 1 to 9.
	- The number of words in s is between 1 and 9.
	- Words in the sentence are separated by a single space.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the original sentence with the words placed in their correct order and the numbers removed.
- **Example:** `s = "banana apple mango cherry"`
- **Constraints:**
	- The output sentence must contain no leading or trailing spaces.

{{< dots >}}
### Core Logic 🔍
**Goal:** Reconstruct the original sentence by sorting the words based on their attached numbers and removing the numbers.

- Iterate over the shuffled sentence and extract each word and its attached position number.
- Store each word along with its number in a pair.
- Sort the words based on their numerical positions.
- Remove the position number from each word and reconstruct the sentence.
{{< dots >}}
### Problem Assumptions ✅
- The input sentence is well-formed and contains no leading or trailing spaces.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "apple2 banana1 cherry4 mango3"`  \
  **Explanation:** In the shuffled sentence, the words are 'apple2', 'banana1', 'cherry4', 'mango3'. When sorted by their numbers (1, 2, 3, 4), the original sentence is 'banana apple mango cherry'.

{{< dots >}}
## Approach 🚀
The problem can be approached by first extracting the word-position pairs, sorting them based on the position number, and then reconstructing the sentence.

### Initial Thoughts 💭
- The sentence is shuffled, but each word contains its original position number.
- The core task is to extract and sort based on the number and then reconstruct the original sentence.
{{< dots >}}
### Edge Cases 🌐
- There are no edge cases involving empty inputs as the sentence will always have at least two characters.
- Ensure that the sentence length does not exceed 200 characters.
- There are no special values to handle other than ensuring that the number attached to the word is correctly removed.
- The words are between 1 and 9, so sorting will not be computationally expensive.
{{< dots >}}
## Code 💻
```cpp
string sortSentence(string s) 
{
    stringstream words(s); 
    string word;
    pair<int, string> m;
    vector<pair<int, string> > sent;
    
    //SECTION 1
    while(words>>word)
    {
        int len = word.size();
        int i = int(word[len-1]) - 48;
        sent.push_back(make_pair(i, word.substr(0, len-1)));
    }
    
    //SECTION 2
    sort(sent.begin(), sent.end());
    
    //SECTION 3
    string ans = "";
    int len = sent.size();
    for(int i=0; i<len; i++)
    {
        ans += sent[i].second;
        if(i!= len-1)
            ans += " ";
    }
    
    return ans;
}
```

The function `sortSentence` sorts the words in the sentence based on the number at the end of each word. It uses the `stringstream` class to split the sentence into words, then creates a vector of pairs to store the word and its position based on the number. The words are then sorted and reassembled into the correctly ordered sentence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string sortSentence(string s) 
	```
	Define the function `sortSentence`, which takes a string `s` as input and returns a sorted sentence.

2. **Stringstream Initialization**
	```cpp
	    stringstream words(s); 
	```
	Create a `stringstream` object to split the input sentence into individual words.

3. **Variable Declaration**
	```cpp
	    string word;
	```
	Declare a variable `word` to hold each individual word from the sentence.

4. **Pair Declaration**
	```cpp
	    pair<int, string> m;
	```
	Declare a pair `m` to store an integer (position of the word) and the word itself.

5. **Vector Initialization**
	```cpp
	    vector<pair<int, string> > sent;
	```
	Create a vector `sent` to store pairs of integers and words. This will help in sorting the words based on their position number.

6. **While Loop**
	```cpp
	    while(words>>word)
	```
	Start a `while` loop to extract each word from the sentence using the `stringstream` object.

7. **Word Length Calculation**
	```cpp
	        int len = word.size();
	```
	Calculate the length of the current word.

8. **Extract Position**
	```cpp
	        int i = int(word[len-1]) - 48;
	```
	Extract the number from the last character of the word and convert it into an integer. This number determines the word's position in the sentence.

9. **Store Word with Position**
	```cpp
	        sent.push_back(make_pair(i, word.substr(0, len-1)));
	```
	Store the word (without the number) and its extracted position in the `sent` vector as a pair.

10. **Sorting**
	```cpp
	    sort(sent.begin(), sent.end());
	```
	Sort the `sent` vector of pairs based on the position of each word.

11. **String Initialization**
	```cpp
	    string ans = "";
	```
	Initialize an empty string `ans` to store the final sorted sentence.

12. **Length Calculation**
	```cpp
	    int len = sent.size();
	```
	Calculate the length of the sorted `sent` vector to determine how many words are in the sentence.

13. **For Loop**
	```cpp
	    for(int i=0; i<len; i++)
	```
	Loop through each word in the sorted `sent` vector.

14. **Concatenate Word**
	```cpp
	        ans += sent[i].second;
	```
	Add the current word (without the position number) to the result string `ans`.

15. **Add Space**
	```cpp
	        if(i!= len-1)
	```
	Check if the current word is not the last word in the sentence.

16. **Add Space**
	```cpp
	            ans += " ";
	```
	If it's not the last word, add a space after the word.

17. **Return Statement**
	```cpp
	    return ans;
	```
	Return the final sorted sentence as the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) where n is the number of words in the sentence.
- **Average Case:** O(n log n) due to sorting the words.
- **Worst Case:** O(n log n) where n is the number of words in the sentence.

The sorting step dominates the time complexity.

### Space Complexity 💾
- **Best Case:** O(n) as we still need to store the words and their positions.
- **Worst Case:** O(n) where n is the number of words, as we are storing them in a list.

Space complexity is linear in terms of the number of words in the sentence.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sorting-the-sentence/description/)

---
{{< youtube MCPhGg_vedE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
