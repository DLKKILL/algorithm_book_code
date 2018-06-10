#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1010;

vector<int> g[maxn];
int mark[maxn];
int n, m, k;
int sum;
bool isok(int test, int index)
{
    for (int i = 0; i < g[index].size(); i++)
    {
        int j = g[index][i];
        if (mark[j] == test)
            return false;
    }
    return true;
}
void dfs(int cnt)
{
    if (cnt > n)
    {
        sum++;
        for (int i = 1; i <= n; i++)
        {
            cout << mark[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= k; i++)
        {
            if (isok(i, cnt))
            {
                mark[cnt] = i;
                dfs(cnt + 1);
                mark[cnt] = -1;
            }
        }
    }
    return;
}
void solve()
{
    dfs(1);
    cout << "total have " << sum << " case." << endl;
    return;
}
int main()
{
    cin >> n >> m >> k;
    sum = 0;
    memset(mark, -1, sizeof(mark));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve();
    getchar();
    return 0;
}
