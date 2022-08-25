#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Job{
    public:
        int m_id, m_day, m_money;

        Job(){m_id = m_day = m_money = 0;}

        bool operator< (const Job &b)const{
            if(m_day * b.m_money == m_money * b.m_day) return m_id < b.m_id;
            return (m_day * b.m_money) < (m_money * b.m_day);
        }
};

int main(){
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        if(i) cout << endl;

        int m;
        cin >> m;

        //Declaration and Initialization
        vector<Job> jobs(m);
        for(int j = 0; j < m; j++){
            cin >> jobs[j].m_day >> jobs[j].m_money;
            jobs[j].m_id = j + 1;
        }

        //Sort
        sort(jobs.begin(), jobs.end());

        //Output
        for(int j = 0; j < m; j++){
            if(j) cout << " ";
            cout << jobs[j].m_id;
        }
        cout << endl;
    }
}