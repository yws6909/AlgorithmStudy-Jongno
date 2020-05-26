#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct coord { int y, x; };

enum {
    top, righttop, right, rightbottom,
    bottom, leftbottom, left, lefttop
};

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1};

int w, h;
int set[51][51];

int main(int argc, const char* argv[])
{
    while(true)
    {
        std::scanf("%d %d", &w, &h);
        
        if(w == 0 && h == 0)
            break;
        
        for(int i = 0; i < h; ++i)
        {
            for(int j = 0; j < w; ++j)
                std::scanf("%d", &set[i][j]);
        }
        
        int ret;
        {
            ret = 0;
            
            for(int i = 0; i < h; ++i)
            {
                for(int j = 0; j < w; ++j)
                {
                    if(set[i][j] == 1)
                    {
                        ++ret;
                        
                        {
                            std::queue<coord> q;
                            
                            q.push(coord{i, j});
                            set[i][j] = 0;
                            
                            while(q.empty() == false)
                            {
                                coord pt = q.front();
                                q.pop();
                                
                                for(int i = top; i <= lefttop; ++i)
                                {
                                    int ny = pt.y + dy[i];
                                    int nx = pt.x + dx[i];
                                    
                                    if(ny < 0 || ny >= h ||
                                       nx < 0 || nx >= w)
                                        continue;
                                    
                                    if(set[ny][nx] == 1)
                                    {
                                        q.push(coord{ny, nx});
                                        set[ny][nx] = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        std::printf("%d\n", ret);
    }
    
    return 0;
}
