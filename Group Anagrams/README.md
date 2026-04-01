Problem Statement :



Given an array of strings strs, group the anagrams together. You can return the answer in any order.



Group Same Words

Imagine you and your friends are playing a game with colorful alphabet blocks. Each of you builds different words using the blocks. One friend builds "listen", another makes "silent", and someone else creates "enlist". At first, they all look like different words, but when you look closely, you realize they’re using the exact same letters, just in a different order. So, you put them in one group and say, “These words are like twins—they're made from the same letters!”

Then someone builds the word "hello" with a different set of blocks. Since no one else made a word using the same letters, it stays alone in its own group. That’s how grouping anagrams works—putting together words that are made from the same letters, even if they look a little different at first.



Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams, as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams, as they can be rearranged to form each other.


Example 2:
Input: strs = [""]
Output: [[""]]


Example 3:
Input: strs = ["a"]
Output: [["a"]]
Method Image 61
Method

Time Complexity

Space Complexity

Better

O(N*Klog(K))

O(N*K)

Best

O(N*K)

O(N*K)

Method

Better

Best
Approach
Using Hashing with Sorted Strings as Keys :



Anagrams are words that have the same characters in a different order. If we sort each word, all anagrams will end up with the same sorted representation. So, by sorting each word and grouping them by this sorted version in a hashmap, we can easily group all anagrams together.



1. Create a Map for Grouping

Initialize a map (or dictionary) where:
Key = sorted version of the string
Value = list of original strings that are anagrams of each other.


2. Iterate Over the Input Strings:

Loop through the arr list of strings.
 For each string, do the following:
 Store the original string in a temporary variable, str.
 Sort the string in-place (arr[i]), so all anagrams will have the same sorted form.
 Use the sorted string as a key in the hashmap, and push the original string (str) into the corresponding list.


3. Collect Anagram Groups:

After processing all strings, loop through each entry in the hashmap m.
Push each value (which is a list of anagrams) into the result ans.


4. Return the Result:

Return the list of anagram groups.
Time Complexity	Space Complexity
O(N*Klog(K))	O(N*K)
Code
C++

class Solution {
public:
   vector<vector<string>> groupAnagrams(vector<string>&arr) {
       vector<vector<string>>ans;
       int n=arr.size();
       unordered_map<string,vector<string>>m;
       for(int i=0;i<n;i++)
       {
           string str=arr[i];
           sort(arr[i].begin(),arr[i].end());
           m[arr[i]].push_back(str);
       }
       for(auto x:m)
       {
           ans.push_back(x.second);
       }
       return ans;
   }
}; 



BEST APPROACH

Approach
Signature Hashing Approach for Anagram Grouping :



Instead of sorting the word (which takes extra time), this approach builds a frequency signature for each word. Since anagrams have exactly the same character counts, their frequency signature (hash) will also be the same. This allows efficient grouping using constant-time hash comparison.



1.    Define a Hash Function Based on Frequency Count

Create a function that:
A frequency array of size 26 is initialized (for lowercase English letters).
Iterates through the word's characters, increasing the matching frequency array index.
Utilizing the frequency array, creates a distinct string (hash) by adding a separator (such as $) and counts to make a difference.


2.    Initialize a Map for Grouping

        Sort words according to their frequency-based hash using a dictionary or map.

The key is a word's frequency-based hash.
The value is a list of words that are anagrams, or share this hash.


3.    Go Through Every Word in the Input

For every word:
Use the hash function to create its frequency hash.
To the list mapped to this hash, add the word.


4.    Get the end result ready.

Go through every entry on the map.
Groups of anagrams are contained in each entry; compile these groups into a final list or array.


5.    Return the Grouped Anagrams

The end result is a list of lists, with words that are anagrams of one another in each inner list.




Method Image 62
Time Complexity	Space Complexity
O(N*K)	O(N*K)
Code
C++

class Solution {
public:
string getHash(string &s)
{
    string hash="";
    vector<int> freq(26, 0);
    // Count frequency of each character
    for(char ch: s)
       freq[ch - 'a'] += 1;
    // Append the frequency to construct the hash
    for(int i = 0; i <26; i++)
    {
       if(freq[i]!=0)
       hash.append(to_string(freq[i]));    
       hash.append("$");
    }
    return hash;
}




vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
       unordered_map<string,vector<string>> mp;
       for (int i = 0; i < strs.size(); i++)
       {
           string key = getHash(strs[i]);
          mp[key].push_back(strs[i]);
       }
       for(auto x:mp)
       {
           res.push_back(x.second);
       }
       return res;
          
       
}
};


