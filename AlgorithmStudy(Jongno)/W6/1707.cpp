#include <iostream>
#include <queue>

enum { non, red, blue, reverse };

int color[20'001];
std::vector<int> graph[20'001];

bool dfs(int v, int c)
{
    bool ret = true;
    
    color[v] = c;
    
    for(auto next : graph[v])
    {
        if((color[next] == c) ||
           (color[next] == 0 && dfs(next, c ^ reverse) == false))
        {
            ret = false;
            break;
        }
    }
    
    return ret;
}

int main(int argc, const char* argv[])
{
    int k;
    std::scanf("%d", &k);
    
    for(int i = 0; i < k; ++i)
    {
        int v, e;
        std::scanf("%d %d", &v, &e);
        
        {
            std::fill_n(color + 1, v + 1, non);
            
            for(int j = 1; j <= v; ++j)
                graph[j].clear();
            
            
            for(int j = 0; j < e; ++j)
            {
                int p1, p2;
                std::scanf("%d %d", &p1, &p2);
                
                graph[p1].push_back(p2);
                graph[p2].push_back(p1);
            }
        }
        
        bool is_bipartite = true;
        {
            for(int i = 1; i <= v; ++i)
            {
                if(color[i] == non)
                {
                    is_bipartite = dfs(i, red);
                    
                    if(is_bipartite == false)
                        break;
                }
            }
        }
        
        if(is_bipartite == true)
            std::printf("YES\n");
        else
            std::printf("NO\n");
    }
    
    return 0;
}
