// link https://leetcode.com/problems/set-matrix-zeroes/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row_len = matrix.size();

        if (row_len == 0)
            return;

        int col_len = matrix[0].size();

        vector<int> row_flag(row_len, 0);
        vector<int> col_flag(col_len, 0);

        for (int i = 0; i < row_len; i++)
        {
            for (int j = 0; j < col_len; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_flag[i] = 1;
                    col_flag[j] = 1;
                }
            }
        }

        for (int i = 0; i < row_len; i++)
        {
            if (row_flag[i] == 1)
            {
                for (int j = 0; j < col_len; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < col_len; i++)
        {
            if (col_flag[i] == 1)
            {
                for (int j = 0; j < row_len; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};