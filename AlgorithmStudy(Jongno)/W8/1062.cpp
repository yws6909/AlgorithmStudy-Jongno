#include <iostream>

int n;
int require;
int learned;
int bit_list[50];

int try_learn(int more, int idx)
{
    int ret;
    {
        if(more == 0)
        {
            int learn_cnt = 0;
            
            for(int i = 0; i < n; ++i)
            {
                int target = bit_list[i];
                
                if((target & learned) == target)
                    ++learn_cnt;
            }
            
            ret = learn_cnt;
        }
        else if(more > 0)
        {
            int max_learn_cnt = 0;
            
            for(; idx <= ('z' - 'a'); ++idx)
            {
                int idx_bit = 0b1 << idx;
                
                if(!(require & idx_bit))
                {
                    learned ^= idx_bit;
                    
                    int learn_cnt = try_learn(more - 1, idx + 1);
                    max_learn_cnt = std::max(max_learn_cnt, learn_cnt);
                    
                    learned ^= idx_bit;
                }
            }
            
            ret = max_learn_cnt;
        }
        else
            ret = 0;
    }
    return ret;
}

int main(int argc, const char* argv[])
{
    int k;
    std::scanf("%d %d", &n, &k);
    
    auto make_bit = [](std::string s) -> int
    {
        int ret = 0;
        {
            for(auto c : s)
                ret |= 0b1 << (c - 'a');
        }
        return ret;
    };
    
    
    require = make_bit("antatica");
    learned = 0b0 | require;
    
    for(int i = 0; i < n; ++i)
    {
        std::string input;
        std::cin >> input;
        
        bit_list[i] = make_bit(input);
    }
    
    int ret = try_learn(k - 5, 0);
    std::printf("%d", ret);
    
    return 0;
}
