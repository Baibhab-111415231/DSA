class Solution {
  public:
    int rowWithMax1s(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        int minIndex = m;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    if (j < minIndex) {
                        minIndex = j;
                        ans = i;
                    }
                    break;
                }
            }
        }

        return ans;
    }
};
