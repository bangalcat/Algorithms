#include <bits/stdc++.h>

using namespace std;

#define grn getRandomNum

int getRandomNum(int _min, int _max){
    if(_min > _max) return _max;
    return _min + (rand()%(_max-_min));
}

int main()
{
    srand((unsigned int)time(NULL));
    int t = 1;
    int n = grn(2,8),m = grn(2,8);
    cout << t << endl;
    cout << n << ' '  << m << endl;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            cout << grn(0,5) << ' ';
        cout << endl;
    }
    return 0;
}

int p1289()
{
    //1289
    int n = grn(10,10000-1);
    cout << n << endl;
    int a = 1;
    for(int i=0;i<n-1;++i){
        int b = i+1;
        int w = grn(1,1000);
        cout << a << ' '<< b << ' '<< w << endl;
        if(a < b && grn(1,4) ==3)
            a++;
    }
    return 0;
}

int p1210()
{
    //1210
    // 1<= n <= 200, 1<= m <= 20000
    // 1 <= src, sink <= n 
    // 1 <= cost <= 10,000,000
    int n = grn(1,200);
    int m = grn(1, 2000);
    int src = grn(1,n);
    int sink = grn(1,n);
    cout << n << ' ' << m << endl;
    cout << src << ' ' << (sink==src?grn(1,n):sink) << endl;
    for(int i=0;i<n;++i)
        cout << grn(1,10000000) << '\n';
    for(int i=0;i<m;++i){
        int a = grn(1,n), b = grn(1,n);
        while(b == a) b = grn(1,n);
        cout << a << ' ' << b << '\n';
    }
    cout << endl;
    return 0;
}

int p9577()
{
    //9577
    // 1<=n<=100, 1<=m<=100
    // 0<= t1 <= 100 , 0<= t2 <= 100, 0 <= a_ct <= n, 1<= q <= n
    srand((unsigned int)time(NULL));
    int T = 30;
    int n, m;
    int t1, t2, a_ct, q;
    cout << T << endl;
    while (T--)
    {
        n = grn(1, 100), m = grn(1, 100);
        if (T < 10)
            n = grn(5, 30), m = grn(30, 100);
        cout << n << ' ' << m << endl;
        for (int i = 0; i < m; ++i)
        {
            t1 = grn(0, 100);
            t2 = grn(t1, 100);
            a_ct = grn(0, n);
            if (T < 5)
                a_ct = n - 1;
            cout << t1 << ' ' << t2 << ' ' << a_ct << ' ';
            bool used[111] = {0};
            for (int j = 0; j < a_ct; ++j)
            {
                while (used[q = grn(1, n)])
                    ;
                used[q] = true;
                cout << q << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}

int p1017()
{
    srand((unsigned int)time(NULL));
    int n;
    while ((n = getRandomNum(1, 50)) % 2)
        ;
    vector<int> used(1001, 0);
    cout << n << endl;
    for (int i = 0; i < n; ++i)
    {
        int a;
        while (used[a = getRandomNum(1, 1000)])
            ;
        used[a] = true;
        cout << a << ' ';
    }

    return 0;
}

int p11377()
{
    srand((unsigned int)time(NULL));
    int n_min = 1, n_max = 1000;
    int m_min = 1, m_max = 1000;
    int k_min = 1, k_max;

    int n,m,k;
    n = getRandomNum(n_min,n_max);
    m = getRandomNum(m_min,m_max);
    k = getRandomNum(k_min,n);
    cout << n << ' ' << m << ' ' << k << endl;
    for(int i=0;i<n;++i){
        int ct = getRandomNum(1,m);
        cout << ct << ' ';
        vector<int> used(m+10,0);
        while(ct--){
            int a;
            while(used[a = getRandomNum(1,m)]);
            cout << a << ' ';
            used[a] = true;
        }
        cout << endl;
    }
    
    return 0;
}