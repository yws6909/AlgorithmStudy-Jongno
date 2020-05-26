#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct coord { int y, x; };

enum { top, right, bottom, left };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

char set[26][26];

int bfs(coord begin)
{
    int ret;
    {
        std::queue<coord> q;
        
        q.push(begin);
        set[begin.y][begin.x] = '0';
        ret = 1;
        
        while(q.empty() == false)
        {
            coord pt = q.front();
            q.pop();
            
            for(int i = top; i <= left; ++i)
            {
                int ny = pt.y + dy[i];
                int nx = pt.x + dx[i];
                
                if(ny < 0 || nx < 0)
                    continue;
                
                if(set[ny][nx] == '1')
                {
                    q.push(coord{ny, nx});
                    set[ny][nx] = '0';
                    ++ret;
                }
            }
        }
    }
    
    return ret;
}

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    
    for(int i = 0; i < n; ++i)
        std::scanf("%s", set[i]);
    
    std::vector<int> list;
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(set[i][j] == '1')
                    list.push_back(bfs(coord{i, j}));
            }
        }
    }
    
    std::sort(list.begin(), list.end());
    
    std::printf("%d\n", list.size());
    
    for(auto elem : list)
        std::printf("%d\n", elem);
    
    return 0;
}
