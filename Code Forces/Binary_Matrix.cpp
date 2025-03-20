    #include <iostream>
    #include <vector>
    using namespace std;
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n, m;
            cin >> n >> m;
            vector<vector<int>> mat(n, vector<int>(m));
            int rowFix = 0, colFix=0;
            for (int i = 0; i < n; i++)
            {
                string k;
                cin >> k;
                for (int j = 0; j < m; j++)
                {

                    mat[i][j] = k[j] - '0';
                }
            }
            for (int i = 0; i < n; i++)
            {
                int xorr = 0;
                for (int j = 0; j < m; j++)
                {
                    xorr ^= mat[i][j];
                }
                if (xorr != 0)
                {
                    rowFix++;
                }
            }
            for (int j = 0; j < m; j++)
            {

                int xorc = 0;
                for (int i = 0; i < n; i++)
                {
                    xorc ^= mat[i][j];
                }
                if (xorc != 0)
                {
                    colFix++;
                }
            }
            cout << max(colFix, rowFix) << endl;
        }

        return 0;
    }