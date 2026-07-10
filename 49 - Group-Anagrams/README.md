# Group Anagrams
 
## Problem
 
[https://leetcode.com/problems/group-anagrams](https://leetcode.com/problems/group-anagrams)
 
Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.
 
## Example
 
```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```
 
## Approach
 
Use a hash table keyed by each string's character-frequency signature, since two strings are anagrams if and only if they contain the same letters the same number of times.
 
For every string:
 
1. Count the occurrences of each of the 26 lowercase letters into a fixed-size array:
```
count[26] = {0}
for each char c in the string: count[c - 'a']++
```
 
2. Hash this count array to find its bucket in the table.
3. If a matching bucket already exists (same counts), append this string's index to it.
4. Otherwise, create a new bucket for this signature and record it.
After processing all strings, walk the buckets in the order they were first created and collect each group's strings into the final result.
 
## Complexity
 
* Time Complexity: `O(N)`, where N is the total number of characters across all strings (each character is visited once; no sorting is needed)
* Space Complexity: `O(N)`, for the hash table buckets and index storage
