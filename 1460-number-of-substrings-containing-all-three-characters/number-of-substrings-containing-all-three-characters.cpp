class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;vector<int>letter(3,INT_MAX);
        for(int i=0;i<s.size();i++){
            int ascii=s[i]-97;
            letter[ascii]=i;
            if(letter[0]!=INT_MAX && letter[1]!=INT_MAX && letter[2]!=INT_MAX){
                count+=*min_element(letter.begin(),letter.end())+1;
            }
        }
        return count;
    }
};