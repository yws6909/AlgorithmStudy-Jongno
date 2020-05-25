#include <iostream>
#include <set>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int set[10'000];
    {
        for(int i = 0; i < n; ++i)
            std::scanf("%d", set + i);
    }

    std::set<int, std::greater<int>> map;
    
    bool valid = false;
    {
        map.insert(set[n - 1]);
        
        for(int i = n - 2; i >= 0; --i)
        {
            if(set[i] < set[i + 1])
                map.insert(set[i]);
            else
            {
                int temp = set[i];
                auto find = map.upper_bound(set[i]);
                set[i] = *find;
                map.erase(find);
                map.insert(temp);
                
                auto iter = map.begin();
                
                for(++i; i < n; ++i, ++iter)
                    set[i] = *iter;
                
                valid = true;
                break;
            }
        }
    }
    
    if(valid)
    {
        for(int i = 0; i < n; ++i)
            printf("%d ", set[i]);
    }
    else
        std::printf("-1");
    
    return 0;
}

