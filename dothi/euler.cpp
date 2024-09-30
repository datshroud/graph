#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> edges[], vector<bool> &vis, int cnt = 1){
    if (vis[node]) return 0;
    int ans = cnt;
    vis[node] = true;
    for (auto e : edges[node]) ans = max(dfs(e, edges, vis, cnt + 1), ans);
    return ans;
}

void run(){
    cout << "Xet do thi vector co huong co phai la do thi euler hay khong:" << endl;
    int m, n;
    cout << "Nhap so diem can xet:"; cin >> m;
    cout << "Nhap so canh can xet:"; cin >> n;
    vector<int> edges1[m], edges2[m];
    vector<int> degree(m, 0);
    for (int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        while (x1 == x2 || min(x1, x2) < 0 || max(x1, x2) >= m){
            cout << x1 << "-->" << x2 << " khong hop le, vui long nhap lai:";
            cin >> x1 >> x2; 
        }
        edges2[x1].push_back(x2);
        edges2[x2].push_back(x1);
        edges1[x1].push_back(x2);
        degree[x1]++;
        degree[x2]--;
    }
    vector<bool> vis1(m, false), vis2(m, false);
    if (dfs(0, edges1, vis1) < m){
        cout << "Day khong phai la do thi lien thong, vi vay khong the la do thi euler." << endl;
        return;
    }
    int cnt1 = 0, cnt0 = 0;
    bool check = true;
    for (int i = 0; i < m; i++) {
        if (degree[i] != 0) {
            check = false;
            if (degree[i] > 0) cnt0++;
            else cnt1++;
        }
    }
    if (check){
        cout << "Day la do thi Euler." << endl;
        return;
    }
    else if (cnt1 == 1 && cnt0 == 1){
        cout << "Day la do thi nua Euler (vi day la do thi euler, khong phai chu trinh euler)." << endl;
        return;
    }
    else {
        cout << "Day khong phai la do thi Euler." << endl;
        return;
    }
}

int main(){
    char x;
    run();
    do{
        cout << "Ban co muon tiep tuc khong?(y/n)";
        cin >> x;
        if (x == 'y' || x == 'Y') run();
        else return 0;
    } while (1);
}
