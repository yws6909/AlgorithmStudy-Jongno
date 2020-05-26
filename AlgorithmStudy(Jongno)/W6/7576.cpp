#include <iostream>
#include <queue>

struct coord { int y, x; };

enum { top, right, bottom, left };
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(int argc, const char* argv[])
{
    int m, n;
    std::scanf("%d %d", &m, &n);
    
    int map[1'000][1'000];
    
    int rear_cnt = 0;
    
    std::queue<coord> q1, q2;
    std::queue<coord>* cur_ptr = &q1;
    std::queue<coord>* next_ptr = &q2;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            std::scanf("%d", &map[i][j]);
            
            if(map[i][j] == 0)
                ++rear_cnt;
            else if(map[i][j] == 1)
                cur_ptr->push(coord{i, j});
        }
    }
    
    int ret;
    {
        ret = 0;
        
        while(true)
        {
            while(cur_ptr->empty() == false)
            {
                auto& cur = *cur_ptr;
                auto& next = *next_ptr;
                
                coord f = cur.front();
                cur.pop();
                
                for(int i = top; i <= left; ++i)
                {
                    int ny = f.y + dy[i];
                    int nx = f.x + dx[i];
                    
                    if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;
                    
                    if(map[ny][nx] == 0)
                    {
                        map[ny][nx] = 1;
                        next.push(coord{ny, nx});
                        --rear_cnt;
                    }
                }
            }
            
            if(next_ptr->empty())
                break;
            
            std::swap(cur_ptr, next_ptr);
            ++ret;
        }
        
        if(rear_cnt > 0)
            ret = -1;
    }
    
    std::printf("%d", ret);
    
    return 0;
}
