
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ham tim kiem theo chieu rong
void timKiemTheoChieuRong(int soDinh, vector<vector<int> >& danhSachKe, int batDau, int ketThuc) {
    vector<bool> daTham(soDinh, false); 
    vector<int> cha(soDinh, -1);  
    queue<int> hangDoi;  

    hangDoi.push(batDau); 
    daTham[batDau] = true;  

    while (!hangDoi.empty()) {
        int u = hangDoi.front();  // lay dinh dau tien trong hang doi
        hangDoi.pop();  // loai bo dinh da lay

        // neu dinh u là dinh ket thuc, tim kiem thanh cong
        if (u == ketThuc) {
            cout << "tim kiem thanh cong, duong di la: ";
            vector<int> duongDi;
            int hienTai = ketThuc;
            while (hienTai != -1) {
                duongDi.push_back(hienTai);
                hienTai = cha[hienTai];  // truy nguoc lai duong di
            }
            // in duong di tu dinh bat dau den dinh ket thuc
            for (int i = duongDi.size() - 1; i >= 0; i--) {
                cout << duongDi[i] << " ";
            }
            cout << endl;
            return;  // dung thuat toan
        }

        // duyet tat ca cac dinh ke cua dinh u
        for (int i = 0; i < danhSachKe[u].size(); i++) {
            int ke = danhSachKe[u][i];
            if (!daTham[ke]) {  // neu dinh ke chua duoc tham
                daTham[ke] = true;  // danh dau dinh ke da tham gia
                cha[ke] = u;  // luu dinh u la cha cua dinh ke
                hangDoi.push(ke);  // dua dinh ke vao hang doi
            }
        }
    }

    cout << "tim kiem that bai" << endl; 
}

int main() {
    // cau hinh 1
    cout << "Cau hinh 1: tim kiem tu dinh 0 den dinh 5" << endl;
    int soDinh1 = 6;
    vector<vector<int> > danhSachKe1(soDinh1);
    danhSachKe1[0].push_back(1);
    danhSachKe1[0].push_back(2);
    danhSachKe1[1].push_back(3);
    danhSachKe1[1].push_back(4);
    danhSachKe1[2].push_back(5);
    timKiemTheoChieuRong(soDinh1, danhSachKe1, 0, 5);

    // Cau hinh 2
    cout << "Cau hinh 2: tim kiem tu dinh 0 den dinh 3" << endl;
    int soDinh2 = 6;
    vector<vector<int> > danhSachKe2(soDinh2);
    danhSachKe2[0].push_back(1);
    danhSachKe2[1].push_back(2);
    timKiemTheoChieuRong(soDinh2, danhSachKe2, 0, 3);  

    // cau hình 3
    cout << "Cau hinh 3: Tim kiem tu dinh 0 den dinh 4" << endl;
    int soDinh3 = 6;
    vector<vector<int> > danhSachKe3(soDinh3);
    danhSachKe3[0].push_back(1);
    danhSachKe3[1].push_back(2);
    danhSachKe3[2].push_back(0);  // Chu trình 0 -> 1 -> 2 -> 0
    danhSachKe3[1].push_back(3);
    danhSachKe3[3].push_back(4);
    timKiemTheoChieuRong(soDinh3, danhSachKe3, 0, 4);

    // cau hinh 4
    cout << "Cau hinh 4: tim kiem tu dinh 1 den 4 " << endl;
    int soDinh4 = 6;
    vector<vector<int> > danhSachKe4(soDinh4);
    danhSachKe4[0].push_back(1);
    danhSachKe4[1].push_back(2);
    danhSachKe4[2].push_back(0);  // Chu trình 0 -> 1 -> 2 -> 0
    danhSachKe4[1].push_back(3);
    danhSachKe4[3].push_back(4);
    timKiemTheoChieuRong(soDinh4, danhSachKe4, 1, 4);

    // cau hinh 5
    cout << "Cau hinh 5: tim kiem tu dinh 3 den dinh 5" << endl;
    int soDinh5 = 6;
    vector<vector<int> > danhSachKe5(soDinh5);
    danhSachKe5[0].push_back(1);
    danhSachKe5[0].push_back(2);
    danhSachKe5[1].push_back(3);
    danhSachKe5[1].push_back(4);
    danhSachKe5[2].push_back(5);
    timKiemTheoChieuRong(soDinh5, danhSachKe5, 3, 5);
    

}
