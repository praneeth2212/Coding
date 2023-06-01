// link https://www.interviewbit.com/problems/find-nth-fibonacci/

typedef vector<vector<long long>> vvi;

int mod = 1e9 + 7;

vvi multiply__matrix(vvi &A, vvi &B)
{

    int n = A.size();

    vvi ans(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            for (int k = 0; k < n; k++)
            {

                ans[i][j] += (A[i][k] * B[k][j]) % mod;
            }
        }
    }

    return ans;
}

vvi matrix__exponentiation(vvi &matrix, int n)
{

    if (n == 0)
        return {{1, 0}, {0, 1}};

    if (n == 1)
        return matrix;

    vvi temp = matrix__exponentiation(matrix, n / 2);

    temp = multiply__matrix(temp, temp);

    if (n & 1)
    {

        temp = multiply__matrix(temp, matrix);
    }

    return temp;
}

int Solution::solve(int n)
{

    vvi matrix = {

        {1, 1},

        {1, 0}

    };

    matrix = matrix__exponentiation(matrix, n - 2);
    return (matrix[0][0] + matrix[0][1]) % mod;
}
