#include <iostream>
#include <queue>

int main(int argc, const char* argv[])
{
    int n, m;
    std::scanf("%d %d", &n, &m);
    
    int ret;
    {
        bool map[1'001][1'001];
        {
            std::fill_n((bool*)(&map[0][0]), 1'001 * 1'001, false);
            
            for(int i = 0; i < m; ++i)
            {
                int p1, p2;
                std::scanf("%d %d", &p1, &p2);
                
                map[p1][p2] = true;
                map[p2][p1] = true;
            }
        }

        bool visit[1'001];
        std::fill_n(visit, 1'001, false);
     
        ret = 0;
        
        for(int i = 1; i <= n; ++i)
        {
            if(visit[i] == false)
            {
                std::queue<int> q;
                q.push(i);
                visit[i] = true;
                ++ret;
                
                while(q.empty() == false)
                {
                    int cur = q.front();
                    q.pop();
                    
                    auto& ptr = map[cur];
                    
                    for(int j = 1; j <= n; ++j)
                    {
                        if(ptr[j] == true &&
                           visit[j] == false)
                        {
                            q.push(j);
                            visit[j] = true;
                        }
                    }
                }
                
            }
        }
    }
    std::printf("%d", ret);
    
    return 0;
}
