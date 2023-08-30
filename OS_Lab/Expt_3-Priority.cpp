#include <bits/stdc++.h>
using namespace std;


void testcase()
{
    int n; cin >> n;

    vector<int> process_no(n) , priority(n) , burst_time(n);

    for(auto &i : process_no) cin >> i;

    for(auto &i : burst_time) cin >> i;

    for(auto &i : priority) cin >> i;


    vector<pair<int , pair<int , int>>> v_p(n);

    for(int i = 0; i < n ; i++)
    {
        int a = priority[i] , b = process_no[i] , c = burst_time[i];

        v_p[i] = {a , {b , c}};
    }

    sort(v_p.begin(), v_p.end());
    cout<< "Priority" <<  " | " << "Process No" << " | " << "Burst Time" << endl;
    for(auto &[x , y] : v_p) cout << "   " << x << "            " << y.first << "            " << y.second << endl;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    auto begin = std::chrono::high_resolution_clock::now();
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Runtime: " << elapsed.count() * 1e-9 * 1e5 << " ms.\n"; 
    return 0;
}
