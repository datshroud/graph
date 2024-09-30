#include <bits/stdc++.h>
using namespace std;

void findMST_Prim(vector<int> edges[], vector<bool> &vis, vector<vector<int>> &dist, vector<pair<int, int>> &ans1, int node){
    if (vis[node]) return;
    vis[node] = true;
    int x, y;
    int mn = INT_MAX;
    for (auto e : edges[node]){
        if (mn > )
    }
}

int dfs(int node, vector<int> edges[], vector<bool> &vis, int cnt = 1){
    if (vis[node]) return 0;
    int ans = cnt;
    vis[node] = true;
    for (auto e : edges[node]) ans = max(dfs(e, edges, vis, cnt + 1), ans);
    return ans;
}

void run(){
    int m, n;
    cout << "Nhap so diem can xet:"; cin >> m;
    cout << "Nhap so canh can xet:"; cin >> n;
    vector<int> edges[m];
    vector<vector<int>> dist(m, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        while (x1 == x2 || min(x1, x2) < 0 || max(x1, x2) >= m){
            cout << x1 << "<--->" << x2 << " khong hop le, vui long nhap lai:";
            cin >> x1 >> x2; 
        }
        int d;
        cout << "Nhap do dai cua canh:";
        cin >> d;
        dist[x1][x2] = dist[x2][x1] = d;
        edges[x1].push_back(x2);
        edges[x2].push_back(x1);
    }

    vector<bool> vis1(m, false), vis2(m, false);
    if (dfs(0, edges, vis1) >= m){
        cout << "Day khong phai la do thi lien thong, vi vay khong the dung thuat toan Prim hay Kruskal" << endl;
        return;
    }

    int x;
    cout << "1. Thuat toan Prim" << endl;
    cout << "2. Thuat toan Kruskal" << endl;
    cout << "Chon thuat toan ban muon dung:";
    cin >> x;
    while (x < 1 || x > 2){
        cout << "Nhap khong hop le, vui long nhap lai:";
        cin >> x;
    }

    vector<pair<int, int>> ans1; //vector luu cac canh be nhat
    x == 1 ? findMST_Prim(edges, vis2, dist, ans1, 0) : findMST_Kruskal();
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
