class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {

        vector<int> merged;

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j]) {
                merged.push_back(a[i]);
                i++;
            }
            else {
                merged.push_back(b[j]);
                j++;
            }
        }

        while(i < a.size()) {
            merged.push_back(a[i]);
            i++;
        }

        while(j < b.size()) {
            merged.push_back(b[j]);
            j++;
        }

        int n = merged.size();

        if(n % 2 == 1) {
            return merged[n / 2];
        }
        else {
            return (merged[n / 2 - 1] + (double)merged[n / 2]) / 2.0;
        }
    }
};
