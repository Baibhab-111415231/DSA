class Solution {
  public:
    int buyMaximumProducts(int k, vector<int> price) {

        int n = price.size();
        vector<pair<int, int>> stocks;

        for(int i = 0; i < n; i++) {
            stocks.push_back({price[i], i + 1});
        }

        sort(stocks.begin(), stocks.end());

        int count = 0;

        for(int i = 0; i < n; i++) {

            int cost = stocks[i].first;
            int available = stocks[i].second;

            int buy = min(available, k / cost);

            count += buy;
            k -= buy * cost;

            if(k == 0)
                break;
        }

        return count;
    }
};
