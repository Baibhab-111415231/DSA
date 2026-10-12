
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> ans;

        int rows = mat.size();
        int cols = mat[0].size();

        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        while(top <= bottom && left <= right) {

            // 1. Left to right
            for(int j = left; j <= right; j++)
                ans.push_back(mat[top][j]);
            top++;

            // 2. Top to bottom
            for(int i = top; i <= bottom; i++)
                ans.push_back(mat[i][right]);
            right--;

            // 3. Right to left
            if(top <= bottom) {
                for(int j = right; j >= left; j--)
                    ans.push_back(mat[bottom][j]);
                bottom--;
            }

            // 4. Bottom to top
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    ans.push_back(mat[i][left]);
                left++;
            }
        }

        return ans;
    }
};
