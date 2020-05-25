#include <iostream>
#include <queue>
#include <set>

int n, m, v;
std::set<int> graph[1'001];
bool visit[1'001];

void dfs(int cur)
{
    std::printf("%d ", cur);
    visit[cur] = true;
    
    for(auto& next : graph[cur])
    {
        if(visit[next] == false)
            dfs(next);
    }
}

void bfs(int cur)
{
    std::queue<int> q;
    
    q.push(cur);
    visit[cur] = true;
    
    while(!q.empty())
    {
        int f = q.front();
        std::printf("%d ", f);
        q.pop();
        
        for(auto& it : graph[f])
        {
            if(visit[it] == false)
            {
                visit[it] = true;
                q.push(it);
            }
        }
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d %d", &n, &m, &v);
    
    for(int i = 0; i < m; ++i)
    {
        int d1, d2;
        std::scanf("%d %d", &d1, &d2);
        
        graph[d1].insert(d2);
        graph[d2].insert(d1);
    }
    
    std::fill(visit, visit + n + 2, false);
    dfs(v);
          
    std::printf("\n");
    
    std::fill(visit, visit + n + 2, false);
    bfs(v);
    
    return 0;
}
