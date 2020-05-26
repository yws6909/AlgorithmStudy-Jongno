#include <iostream>
#include <limits>

int n, m;
char map[101][102];
int opt[101][101];

enum { top, right, bottom, left };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(int y, int x)
{
    for(int i = top; i <= left; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny <= 0 || ny > n || nx <= 0 || nx > m)
            continue;
        
        if((map[ny][nx] == '1') &&
           (opt[y][x] + 1 < opt[ny][nx]))
        {
            opt[ny][nx] = opt[y][x] + 1;
            dfs(ny, nx);
        }
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; ++i)
    {
        std::scanf("%s", map[i] + 1);
        std::fill_n(opt[i] + 1, m, std::numeric_limits<int>::max());
    }
    
    opt[1][1] = 1;
    
    dfs(1, 1);
    
    int ret = opt[n][m];
    std::printf("%d", ret);
    
    return 0;
}
