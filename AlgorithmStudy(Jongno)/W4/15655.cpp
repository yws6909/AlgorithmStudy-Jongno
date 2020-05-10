#include <iostream>
#include <algorithm>

int n, m;
int input[9];
int set[9];

void print(int begin, int depth)
{
    if(depth > m)
    {
        for(int i = 1; i <= m; ++i)
            std::printf("%d ", set[i]);
        std::printf("\n");
        return;
    }
    
    
    for(int i = begin; i <= (n - (m - depth)); ++i)
    {
        set[depth] = input[i];
        print(i + 1, depth + 1);
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; ++i)
        std::scanf("%d", input + i);
    
    std::sort(input + 1, input + n + 1);
    
    print(1, 1);
    
    return 0;
}
