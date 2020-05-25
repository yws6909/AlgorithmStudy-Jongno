#include <iostream>
#include <set>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int set[9];
    {
        for(int i = 0; i < n; ++i)
        {
            set[i] = i + 1;
            printf("%d ", set[i]);
        }
        printf("\n");
    }

    std::set<int, std::less<int>> map;
    
    while(true)
    {
        bool valid = false;
        
        map.clear();
        map.insert(set[n - 1]);
        
        for(int i = n - 2; i >= 0; --i)
        {
            if(set[i] > set[i + 1])
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
        
        if(valid)
        {
            for(int i = 0; i < n; ++i)
                printf("%d ", set[i]);
            printf("\n");
        }
        else
            break;
    }
    
    return 0;
}

