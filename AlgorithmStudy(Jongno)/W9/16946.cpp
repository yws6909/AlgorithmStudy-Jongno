#include <iostream>
#include <queue>

struct coord
{
    coord(int r, int c): row(r), col(c) {};
    int row, col;
};

enum { wall = -1, empty = 0 };
enum { top = 0, right, bottom, left };

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int n, m;

void divide_area(int map[1'000][1'000], std::vector<int>& code_info)
{
    code_info.clear();
    code_info.push_back(0);
    
    int visit_code = 1;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(map[i][j] == empty)
            {
                std::queue<coord> q;
                int movable_cnt = 0;
                
                q.emplace(i, j);
                map[i][j] = visit_code;
                ++movable_cnt;
                
                while(q.empty() == false)
                {
                    int row;
                    int col;
                    {
                        coord& f = q.front();
                        
                        row = f.row;
                        col = f.col;
                        
                        q.pop();
                    }
                    
                    for(int i = top; i <= left; ++i)
                    {
                        int next_row = row + dy[i];
                        int next_col = col + dx[i];
                        
                        if((next_row < 0 || next_row >= n) ||
                           (next_col < 0 || next_col >= m))
                            continue;
                        
                        if(map[next_row][next_col] == empty)
                        {
                            q.emplace(next_row, next_col);
                            map[next_row][next_col] = visit_code;
                            ++movable_cnt;
                        }
                    }
                }
                
                code_info.emplace_back(movable_cnt);
                ++visit_code;
            }
        }
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &m);
    
    int map[1'000][1'000];
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                std::scanf("%1d", &map[i][j]);
                
                map[i][j] = -map[i][j];
            }
        }
    }
    
    std::vector<int> code_info;
    
    divide_area(map, code_info);
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int ret;
            {
                if(map[i][j] != wall)
                {
                    ret = 0;
                }
                else
                {
                    int movable_cnt;
                    {
                        movable_cnt = 1;
                        
                        int set[4] = {0, 0, 0, 0};
                        
                        for(int k = top; k <= left; ++k)
                        {
                            int next_row = i + dy[k];
                            int next_col = j + dx[k];
                            
                            if((next_row < 0 || next_row >= n) ||
                               (next_col < 0 || next_col >= m))
                                continue;
                            
                            int code = map[next_row][next_col];
                            
                            bool is_duplicate = false;
                            
                            for(int l = 0; l < 4; ++l)
                            {
                                if(set[l] == code)
                                {
                                    is_duplicate = true;
                                    break;
                                }
                            }
                            
                            if(is_duplicate == false)
                                set[k] = code;
                        }
                        
                        for(int l = 0; l < 4; ++l)
                            movable_cnt += code_info[set[l]];
                    }
                    
                    ret = movable_cnt % 10;
                }
            }
            std::printf("%d", ret);
        }
        std::printf("\n");
    }
    
    return 0;
}
