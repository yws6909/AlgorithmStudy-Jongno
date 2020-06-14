#include <iostream>
#include <limits>
#include <vector>
#include <queue>

int n, m, virus_code;
int map[8][8];

struct coord
{
    coord(int r, int c): row(r), col(c) {};
    int row, col;
};

enum { virus = -2, wall = -1 };
enum { top = 0, right, bottom, left };
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

std::vector<coord> virus_coords;
std::vector<coord> safe_coords;

void debug_map()
{
    std::printf("\n");
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int value;
            {
                if(map[i][j] == virus || map[i][j] == wall)
                {
                    value = -map[i][j];
                }
                else
                {
                    if(map[i][j] == virus_code)
                        value = -virus;
                    else
                        value = 0;
                }
            }
            std::printf("%d ", value);
        }
        
        std::printf("\n");
    }
}

int spread()
{
    int ret = 0;
    {
        ++virus_code;
        
        int safe_count = (int)(safe_coords.size()) - 3;
        
        std::queue<coord> q;
        
        for(auto& virus_coord : virus_coords)
            q.push(virus_coord);
        
        while(q.empty() == false)
        {
            int row;
            int col;
            {
                coord& f = q.front();
                row = f.row;
                col = f.col;
            }
            
            q.pop();
            
            for(int i = top; i <= left; ++i)
            {
                int new_row = row + dy[i];
                int new_col = col + dx[i];
                
                if((new_row < 0 || new_row >= n) ||
                   (new_col < 0 || new_col >= m))
                    continue;
                
                if(map[new_row][new_col] != virus_code &&
                   map[new_row][new_col] != wall &&
                   map[new_row][new_col] != virus)
                {
                    map[new_row][new_col] = virus_code;
                    q.emplace(new_row, new_col);
                    
                    --safe_count;
                }
            }
        }
        
        ret = safe_count;
    }
    
    //debug_map();
    return ret;
}

int build(int idx, int cnt)
{
    int ret;
    {
        if (cnt == 3)
        {
            ret = spread();
        }
        else
        {
            ret = 0;
            
            for(; idx < safe_coords.size(); ++idx)
            {
                coord& cur = safe_coords[idx];
                int& ref = map[cur.row][cur.col];
                
                int store = ref;
                ref = wall;
                
                ret = std::max(ret, build(idx + 1, cnt + 1));
                
                ref = store;
            }
        }
    }
    return ret;
}

int main(int argc, const char* argv[])
{
    virus_code = 0;
    std::scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            std::scanf("%d", &map[i][j]);
            
            map[i][j] = -map[i][j];
            
            if(map[i][j] == virus)
            {
                virus_coords.emplace_back(i, j);
            }
            else
            {
                if(map[i][j] != wall)
                    safe_coords.emplace_back(i, j);
            }
                
        }
    }
    
    int ret = build(0, 0);
    std::printf("%d", ret);
    
    return 0;
}
