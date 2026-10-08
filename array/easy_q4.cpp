class Solution {
  public:
    int maximizeSum(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

                for (int i = 0; i < arr.size() && k > 0; i++) {
                    if (arr[i] < 0) {
                        arr[i] = -arr[i];
                        k--;
                    }
                }

                int sum = 0;
                int mn = abs(arr[0]);

                for (int x : arr) {
                    sum += x;
                    mn = min(mn, abs(x));
                }

                if (k % 2 == 1) {
                    sum -= 2 * mn;
                }

                return sum;
            }
};
