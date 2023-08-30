#include <bits/stdc++.h>
using namespace std;


void testcase()
{
    int time_quantum; cin >> time_quantum;

    vector<pair<int , int>> v_p;

    int n; cin >> n;

    for(int i = 0; i < n ; i++)
    {
        int a , b; cin >> a >> b;

        v_p.push_back({a , b});
    }

    queue<pair<int , int>> q;
    for(int i = 0; i < n ; i++) q.push(v_p[i]);
    vector<int> prev_time(n, 0);
    vector<int> waiting_time(n, 0);
    vector<int> turn_around_time(n, -1);

    int curr_time  = 0;
    while(q.size())
    {
        pair<int , int> temp = q.front();
        int i = temp.first - 1;
        if(turn_around_time[i] == -1) 
        {
            turn_around_time[i] = curr_time;
        }
        
        waiting_time[i] += curr_time - prev_time[i];


        if(temp.second <= time_quantum)
        {
            curr_time += temp.second;
            turn_around_time[i] = curr_time - turn_around_time[i];
            temp.second = 0;
        }

        else
        {
            curr_time += time_quantum;
            temp.second -= time_quantum;
            prev_time[i] = curr_time;
            q.push({i + 1 , temp.second});
        }

        q.pop();
    }
    
    // for(auto &i : waiting_time) cout << i << " "; cout << endl;
    // for(auto &i : turn_around_time) cout << i << " "; cout << endl;



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
    