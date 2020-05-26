#include <iostream>
#include <queue>
#include <limits>

struct coord { int y, x; };
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main(int argc, const char* argv[])
{
    int t;
    std::scanf("%d", &t);
    
    int map[301][301];
    
    for(int i = 0; i < t; ++i)
    {
        std::fill_n((int*)(map[0]), 301 * 301, std::numeric_limits<int>::max());
        
        int l;
        std::scanf("%d", &l);
        
        int cur_y, cur_x;
        std::scanf("%d %d", &cur_y, &cur_x);
        
        std::queue<coord> q;
        q.push(coord{cur_y, cur_x});
        map[cur_y][cur_x] = 0;
        
        while(q.empty() == false)
        {
            coord f = q.front();
            q.pop();
            
            for(int j = 0; j < 8; ++j)
            {
                int ny = f.y + dy[j];
                int nx = f.x + dx[j];
                
                if(ny < 0 || ny >= l || nx < 0 || nx >= l)
                    continue;
                
                if(map[f.y][f.x] + 1 < map[ny][nx])
                {
                    q.push(coord{ny, nx});
                    map[ny][nx] = map[f.y][f.x] + 1;
                }
            }
        }
        
        int goal_y, goal_x;
        std::scanf("%d %d", &goal_y, &goal_x);

        std::printf("%d\n", map[goal_y][goal_x]);
    }
    
    return 0;
}
