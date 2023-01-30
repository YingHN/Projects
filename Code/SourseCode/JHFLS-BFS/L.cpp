#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e10 + 7;
bitset<MOD> used;
struct STAUT
{
    int x, y, step;
    int g[3][3];
    int hs;
    bool check()
    {
        return x >= 0 && x < 3 && y >= 0 && y < 3 && hs >= 0 && used[hs] == false && step <= 20;
    }
    void _hs_()
    {
        long long int __hs = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                __hs *= 10, __hs += g[i][j];
        hs = __hs % MOD;
    }
    void input()
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                cin >> g[i][j];
                if (g[i][j] == 0)
                    x = i, y = j;
            }
        step = 0;
        _hs_();
    }
    void output()
    {
        cout << "--(" << x << "," << y << "):" << hs << ":" << step << "--\n";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << g[i][j] << " ";
            }
            cout << "\n";
        }
    }
} oMap, tMap;
int Move[2][4] =
    {
        {0, 0, 1, -1},
        {1, -1, 0, 0}};
queue<STAUT> q;
int main()
{
    oMap.input(), tMap.input();
    oMap.output(), tMap.output();
    q.push(oMap);
    used[oMap.hs] = true;
    while (!q.empty())
    {
        STAUT now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            STAUT next = now;
            next.x += Move[0][i],
                next.y += Move[1][i],
                ++next.step;
            swap(next.g[next.x][next.y], next.g[now.x][now.y]),
                next._hs_();
            if (!next.check())
                continue;
            next.output();
            if (next.step > 20)
            {
                cout << "No solution!";
                return 0;
            }
            if (next.hs == oMap.hs)
            {
                cout << next.step;
                return 0;
            }

            q.push(next);
            used[next.hs] = true;
        }
        cout << q.size() << "BFSing...\n";
    }
}
