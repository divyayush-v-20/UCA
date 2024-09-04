// there are n cities and m clinics to be located
// there is an array which contains population of the (i + 1)th city,
// place clinics in such a way that maximum load on a city is minimized
// i.e sum of medians is minimum

/*
    n = 3, population = [100, 50, 200]
    m = 4
    1st option is to place clinics as : 2 1 1
    load = 100/2 + 50 + 200 = 300
    max load = 200
    2nd option : 1 2 1
    load = 100 + 50/2 + 200 = 325
    max load = 200
    3rd option : 1 1 2
    load = 100 + 50 + 100 = 250
    max load = 100


    break m into n parts, and check the best solution - DP/Binary Search
*/

#include <bits/stdc++.h>
using namespace std;

int minimizeLoad(int n, vector<int>& population, int m){
    priority_queue<pair<int,int>> pq;
    for(int i : population){
        pq.push({i, 1});
        m--;
    }

    vector<pair<int,int>> vec;
    
    while(!pq.empty()){
        vec.push_back(pq.top());
        pq.pop();
    }
    int index = 0;
    while(m > 0){
        if(index % n == 0){
            vec[index % n].second += 1;
            --m;
        } 
        else{
            int cur_load = vec[index % n].first/vec[index % n].second;
            if(cur_load > (vec[0].first / vec[0].second)){
                vec[index % n].second += 1;
                --m;
            }
        }
        index ++;
    }
    int maxi = INT_MIN;
    for(auto i : vec){
        maxi = max(maxi, i.first / i.second);
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> population(n);
    for(int i = 0; i < n; ++i){
        cin >> population[i];
    }
    int m;
    cin >> m;

    cout<<minimizeLoad(n, population, m);

    return 0;
} 

// 50 40 30 20 10
// 3  3  2  1  1
// ans = 20