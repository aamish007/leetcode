class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> use;

        // Store all prefixes from arr1
        for (int i : arr1) {

            int divisor = 1;
            while (divisor <= i) divisor *= 10;
            divisor /= 10;

            int rem = i;
            int prefix = 0;

            while (divisor > 0) {

                int v = rem / divisor;
                rem %= divisor;

                prefix = prefix * 10 + v;
                use.insert(prefix);

                divisor /= 10;
            }
        }

        int ans = 0;

        // Check prefixes in arr2
        for (int i : arr2) {

            int divisor = 1;
            while (divisor <= i) divisor *= 10;
            divisor /= 10;

            int rem = i;
            int prefix = 0;
            int k = 0;

            while (divisor > 0) {

                int v = rem / divisor;
                rem %= divisor;

                prefix = prefix * 10 + v;
                k++;

                if (use.count(prefix))
                    ans = max(ans, k);

                divisor /= 10;
            }
        }

        return ans;
    }
};