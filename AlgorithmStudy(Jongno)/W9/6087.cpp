#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>

struct coord
{
    coord() = default;
    coord(int r, int c, int d): row(r), col(c), direction(d) {};
    int row, col, direction;
};

enum { wall = '*', empty = '.', laser = 'C' };
enum { top = 0, right, bottom, left };

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int main(int argc, const char* argv[])
{
    int w, h;
    std::scanf("%d %d", &w, &h);
    
    coord c[2] = { {-1, -1, 0}, {-1, -1, 0} };
    
    char map[100][101];
    {
        for(int i = 0; i < h; ++i)
        {
            for(int j = 0; j < w; ++j)
            {
                std::scanf("%1s", &map[i][j]);
                
                if(map[i][j] == laser)
                {
                    if(c[0].row == -1)
                        c[0] = { i, j, 0 };
                    else
                        c[1] = { i, j, 0 };
                }
            }
        }
    }
    
    int ret;
    {
        const int inf = std::numeric_limits<int>::max();
        
        int opt[100][100][4];
        {
            std::fill_n((int*)(opt), 100 * 100 * 4, inf);
            
            std::queue<coord> q;
            
            for(int i = top; i <= left; ++i)
            {
                const int c0_row = c[0].row;
                const int c0_col = c[0].col;
                
                q.emplace(c0_row, c0_col, i);
                opt[c0_row][c0_col][i] = 0;
            }
            
            while(q.empty() == false)
            {
                int row;
                int col;
                int direction;
                {
                    coord& f = q.front();
                    
                    row = f.row;
                    col = f.col;
                    direction = f.direction;
                    
                    q.pop();
                }
                
                for(int i = top; i <= left; ++i)
                {
                    int next_row = row + dy[i];
                    int next_col = col + dx[i];
                    
                    if((next_row < 0 || next_row >= h) ||
                       (next_col < 0 || next_col >= w))
                        continue;
                    
                    if(map[next_row][next_col] == wall)
                        continue;
                    
                    int add = (direction == i)? 0 : 1;
                        
                    if(opt[next_row][next_col][i] > opt[row][col][direction] + add)
                    {
                        q.emplace(next_row, next_col, i);
                        opt[next_row][next_col][i] = opt[row][col][direction] + add;
                    }
                }
            }
        }
        
        int minimum_mirror = inf;
        
        const int c1_row = c[1].row;
        const int c1_col = c[1].col;
        
        for(int i = 0; i < 4; ++i)
            minimum_mirror = std::min(minimum_mirror, opt[c1_row][c1_col][i]);
        
        ret = minimum_mirror;
    }
    std::printf("%d", ret);
    
    return 0;
}
