#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
const int MAX = 1000000+1;
vector<int> primes;
bool eras[MAX]={0};

void eratones()
{
    for(int i=2;i*i<MAX;++i)
    {
        if (!eras[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                eras[j] = true;
            }
        }
    }
    for(int i=2;i<MAX;++i)
        if(!eras[i])
            primes.push_back(i);
}

int main()
{
    freopen("test2.in", "r", stdin);
    int tc;
    cin >> tc;
    eratones();
    for (int t = 1; t <= tc; ++t)
    {
        cin >> N >> L;
        string P;
        vector<int> encrypted(L);
        for(int i=0;i<L;++i)
            cin>>encrypted[i];
        int first,next;
        vector<int> letterPrimes;
        for(int i=0,len=primes.size();i<len;++i)
            if(encrypted[0]%primes[i]==0)
            {
                first = primes[i];
                letterPrimes.push_back(primes[i]);
                letterPrimes.push_back(encrypted[0]/primes[i]);
                next = letterPrimes.back();
                break;
            }
        int start=1;
        // confirm first
        for(int i=1;;++i)
        {
            if(encrypted[i] == encrypted[i-1])
            {
                letterPrimes.push_back(first);
                swap(first, next);
            }else
            {
                if(encrypted[i]%next)
                {
                    for(int j=0;j<letterPrimes.size();j++){
                        letterPrimes[j] = (letterPrimes[j]==first?next:first);
                    }
                    swap(first, next);
                }
                start = i;
                break;
            }
        }
    
        for(int i=start;i<L;++i)
        {
            letterPrimes.push_back(encrypted[i]/next);
            next = letterPrimes.back();
        }
        vector<int> letterOrder = letterPrimes;
        sort(letterOrder.begin(), letterOrder.end());
        unique(letterOrder.begin(), letterOrder.end());

        for(int i=0;i<L+1;++i)
        {
            for(int j=0;j<26;++j)
            {
                if (letterOrder[j] == letterPrimes[i])
                {
                    P.push_back(j+'A');
                    break;
                }
            }
        }
        cout << "Case #" << t << ": " << P << '\n';
    }
    return 0;
}