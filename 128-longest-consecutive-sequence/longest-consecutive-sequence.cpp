class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int n = nums.size();
        int max_len = 0;
        for (int num : seen) {
            if (!seen.count(num + 1)) {
                int len = 0;
                while (seen.count(num - len)) {
                    //cout << nums[i] << " ";
                    len++;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};