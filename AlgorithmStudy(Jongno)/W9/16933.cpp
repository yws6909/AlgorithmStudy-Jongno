#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>

struct coord
{
    coord(int r, int c, int w, int t)
    : row(r), col(c), break_wall(w), time(t)
    {};
    int row, col, break_wall, time;
};

enum { empty = 0, wall };
enum { top = 0, right, bottom, left };
enum { day = 0b0, night = 0b1, reverse = 0b1 };

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int opt[1'000][1'000][11][2];

int main(int argc, const char* argv[])
{
    int n, m, k;
    std::scanf("%d %d %d", &n, &m, &k);
    
    int map[1'000][1'000];
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
                std::scanf("%1d", &map[i][j]);
        }
    }
    
    const int inf = std::numeric_limits<int>::max() - 1;
    {
        int opt_elem_cnt = 1'000 * 1'000 * 11 * 2;
        std::fill_n((int*)(opt), opt_elem_cnt, inf);
        opt[0][0][0][day] = 1;
        opt[0][0][0][night] = 1;
    }
    
    int ret;
    {
        std::queue<coord> q;
        q.emplace(0, 0, 0, day);
        
        while(q.empty() == false)
        {
            int row;
            int col;
            int break_wall;
            int time;
            int next_time;
            {
                coord& f = q.front();
                
                row = f.row;
                col = f.col;
                break_wall = f.break_wall;
                time = f.time;
                next_time = time ^ reverse;
                
                q.pop();
            }
            
            auto& cur_opt = opt[row][col];
                                
            for(int i = top; i <= left; ++i)
            {
                int next_row = row + dy[i];
                int next_col = col + dx[i];
                
                if((next_row < 0 || next_row >= n) ||
                   (next_col < 0 || next_col >= m))
                    continue;
                
                auto& next_opt = opt[next_row][next_col];
                int next_state = map[next_row][next_col];
                
                switch (next_state)
                {
                    case empty:
                    {
                        if(next_opt[break_wall][next_time] > cur_opt[break_wall][time] + 1)
                        {
                            next_opt[break_wall][next_time] = cur_opt[break_wall][time] + 1;
                            q.emplace(next_row, next_col, break_wall, next_time);
                        }
                        
                        break;
                    }
                    case wall:
                    {
                        if(time == day)
                        {
                            if(break_wall < k)
                            {
                                if(next_opt[break_wall + 1][next_time] > cur_opt[break_wall][time] + 1)
                                {
                                    next_opt[break_wall + 1][next_time] = cur_opt[break_wall][time] + 1;
                                    q.emplace(next_row, next_col, break_wall + 1, next_time);
                                }
                            }
                        }
                        else if(time == night)
                        {
                            if(cur_opt[break_wall][next_time] > cur_opt[break_wall][time] + 1)
                            {
                                cur_opt[break_wall][next_time] = cur_opt[break_wall][time] + 1;
                                q.emplace(row, col, break_wall, next_time);
                            }
                        }
                        break;
                    }
                }
            }
        }
        
        int shortest_path;
        {
            auto& target = opt[n - 1][m - 1];
         
            shortest_path = inf;
            
            for(int i = 0; i <= k; ++i)
                shortest_path = std::min({shortest_path, target[i][day], target[i][night]});
            
            if(shortest_path == inf)
                shortest_path = -1;
        }
        
        ret = shortest_path;
    }
    std::printf("%d", ret);
    
    return 0;
}

