#include <bits/stdc++.h>
using namespace std;

void printMTKe(){
    int m, n;
    cout << "Nhap so diem can xet:"; cin >> m;
    cout << "Nhap so canh can xet:"; cin >> n;
    vector<vector<int>> matrix(m, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        while (x1 == x2 || min(x1, x2) < 0 || max(x1, x2) >= m){
            cout << x1 << "<-->" << x2 << " khong hop le, vui long nhap lai:";
            cin >> x1 >> x2; 
        }
        matrix[x1][x2]++;
        matrix[x2][x1]++;
    }
    cout << "Ma tran ke:" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++) cout << matrix[i][j] << "\t";
        cout << endl << endl;
    }
}

void printMTLienThuoc(){
    int x;
    cout << "1. Ma tran lien thuoc voi vector vo huong" << endl;
    cout << "2. Ma tran lien thuoc voi vector co huong" << endl;
    cout << "Nhap tuy chon cua ban (1/2):";
    do{
        cin >> x;
    } while (x != 1 && x != 2);
    if (x == 1){
        int m, n;
        cout << "Nhap so diem can xet:"; cin >> m;
        cout << "Nhap so canh can xet:"; cin >> n;
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            int x1, x2;
            cin >> x1 >> x2;
            while (x1 == x2 || min(x1, x2) < 0 || max(x1, x2) >= m){
                cout << x1 << "-->" << x2 << " khong hop le, vui long nhap lai:";
                cin >> x1 >> x2; 
            }
            matrix[x1][i]++;
            matrix[x2][i]++;
        }
        cout << "Ma tran lien thuoc voi vector vo huong:" << endl;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) cout << matrix[i][j] << "\t";
            cout << endl << endl;
        }
    }
    else if (x == 2){
        int m, n;
        cout << "Nhap so diem can xet:"; cin >> m;
        cout << "Nhap so canh can xet:"; cin >> n;
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            int x1, x2;
            cin >> x1 >> x2;
            while (x1 == x2 || min(x1, x2) < 0 || max(x1, x2) >= m){
                cout << x1 << "-->" << x2 << " khong hop le, vui long nhap lai:";
                cin >> x1 >> x2; 
            }
            matrix[x1][i]++;
            matrix[x2][i]--;
        }
        cout << "Ma tran lien thuoc voi vector co huong:" << endl;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) cout << matrix[i][j] << "\t";
            cout << endl << endl;
        }
    }
}

int main(){
    int x;
    do{
        cout << "Menu:" << endl;
        cout << "1. Bieu dien ma tran ke" << endl;
        cout << "2. Bieu dien ma tran lien thuoc." << endl;
        cout << "3. Thoat" << endl;
        cout << "Nhap 1, 2 de thuc thi; nhap khac se thoat:";
        cin >> x;
        if (x == 1) printMTKe();
        else if (x == 2) printMTLienThuoc();
        else return 0;
    } while (1);
}