class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr1 [256] ={0}, arr2 [256] ={0};
        int n = s.size();
        for(int i =0; i<n; i++){
            if(arr1[s[i]] != arr2[t[i]])
            return false;
            arr1[s[i]] = i+1;
            arr2[t[i]] = i+1;
         }
         return true;
    }
};
