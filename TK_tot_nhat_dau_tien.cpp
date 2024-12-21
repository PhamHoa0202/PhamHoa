#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

//
struct Nut {
    int x, y;     
    int h;         
    Nut* cha;      

    Nut(int x, int y, int h) : x(x), y(y), h(h), cha(NULL) {}  

   
    bool operator<(const Nut& other) const {
        return h > other.h;  
    }
};


int hamDanhGia(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);  
}

void timKiemTotNhat(int batDauX, int batDauY, int dichX, int dichY) {
    priority_queue<Nut> danhSachMo;  // Danh sách OPEN
    vector<vector<bool> > danhSachDaTham(10, vector<bool>(10, false));  
    
    
    Nut* batDau = new Nut(batDauX, batDauY, hamDanhGia(batDauX, batDauY, dichX, dichY));
    danhSachMo.push(*batDau);

    while (!danhSachMo.empty()) {
    
        Nut current = danhSachMo.top();
        danhSachMo.pop();


        if (current.x == dichX && current.y == dichY) {
            cout << "Tim kiem thanh cong!" << endl;
            cout << "Duong di: ";
            
            vector<pair<int, int> > duongDi;
            Nut* pathNode = new Nut(current.x, current.y, current.h);
            duongDi.push_back({pathNode->x, pathNode->y});
            while (current.cha != NULL) {  
                duongDi.push_back({current.cha->x, current.cha->y});
                current = *current.cha;
            }
          
            for (int i = duongDi.size() - 1; i >= 0; --i) {
                cout << "(" << duongDi[i].first << ", " << duongDi[i].second << ") ";
            }
            cout << endl;
            return;
        }

        
        danhSachDaTham[current.x][current.y] = true;

        
        vector<pair<int, int> > huongDi = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < huongDi.size(); ++i) {
            int newX = current.x + huongDi[i].first;
            int newY = current.y + huongDi[i].second;

        
            if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && !danhSachDaTham[newX][newY]) {
                int newH = hamDanhGia(newX, newY, dichX, dichY); 
                Nut* nuTiepTheo = new Nut(newX, newY, newH);
                nuTiepTheo->cha = new Nut(current.x, current.y, current.h);  // Liên k?t v?i cha
                danhSachMo.push(*nuTiepTheo);  // Thêm vào danh sách OPEN
            }
        }
    }

    cout << "Tim kiem that bai!" << endl;
}

int main() {

    cout << "Cau hinh 1: Bat dau (0, 0) -> Dich (7, 7)" << endl;
    timKiemTotNhat(0, 0, 7, 7);

    cout << "Cau hinh 2: Bat dau (0, 0) -> Dich (4, 5)" << endl;
    timKiemTotNhat(0, 0, 4, 5);


    cout << "Cau hinh 3: Bat dau (2, 3) -> Dich (6, 6)" << endl;
    timKiemTotNhat(2, 3, 6, 6);


    cout << "Cau hinh 4: Bat dau (3, 1) -> Dich (8, 8)" << endl;
    timKiemTotNhat(3, 1, 8, 8);


    cout << "Cau hinh 5: Bat dau (1, 4) -> Dich (7, 3)" << endl;
    timKiemTotNhat(1, 4, 7, 3);

    return 0;
}
