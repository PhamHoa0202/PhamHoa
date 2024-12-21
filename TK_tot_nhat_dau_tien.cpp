#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Nut {
    int x, y;     
    int g, h;    
    Nut* parent;  

    Nut(int x, int y, int g, int h) : x(x), y(y), g(g), h(h), parent(NULL) {} 

    bool operator<(const Nut& other) const {
        return (g + h) > (other.g + other.h);
    }
};

// Tinh khoang cach manhattan heuristic (h)
int hamDanhGia(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// thuat toan tim duong A*
void timKiemTotNhat(int batDauX, int batDauY, int dichX, int dichY) {
    
    priority_queue<Nut> openList;

    // luot de theo doi cac nut da tham
    vector<vector<bool> > visited(10, vector<bool>(10, false));

    // nut bat dau
    Nut* start = new Nut(batDauX, batDauY, 0, hamDanhGia(batDauX, batDauY, dichX, dichY));
    openList.push(*start);

    while (!openList.empty()) {
        Nut current = openList.top();
        openList.pop();

        // neu dat den dich, tai tao lai duong di
        if (current.x == dichX && current.y == dichY) {
            cout << "Tim kiem thanh cong!" << endl;
            cout << "Duong di: ";
            vector<pair<int, int> > duongDi;

            Nut* pathNode = new Nut(current.x, current.y, current.g, current.h);
            duongDi.push_back({pathNode->x, pathNode->y});

            while (current.parent != NULL) {
                duongDi.push_back({current.parent->x, current.parent->y});
                current = *current.parent;
            }

            for (int i = duongDi.size() - 1; i >= 0; --i) {
                cout << "(" << duongDi[i].first << ", " << duongDi[i].second << ") ";
            }
            cout << endl;
            return;
        }

        visited[current.x][current.y] = true;

        // dinh nghia huong di (len,xuong, trai, phai)
        vector<pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // kham pha cac nut ke
        for (const auto& direction : directions) {
            int newX = current.x + direction.first;
            int newY = current.y + direction.second;

            //bo qua cac nut ngoai pham vi hoac da tham
            if (newX < 0 || newX >= 10 || newY < 0 || newY >= 10 || visited[newX][newY]) {
                continue;
            }

            int gNew = current.g + 1;  // Tang g (chi phi den nut)
            int hNew = hamDanhGia(newX, newY, dichX, dichY);  // tinh lai heuristic (h)
            Nut* neighbor = new Nut(newX, newY, gNew, hNew);
            neighbor->parent = new Nut(current.x, current.y, current.g, current.h);  // Gán cha

            openList.push(*neighbor);
        }
    }

    cout << "Tim kiem that bai!" << endl;
}

int main() {
    cout << "Cau hinh 1: Bat dau(0, 0) -> dich (7, 7)" << endl;
    timKiemTotNhat(0, 0, 7, 7);

    cout << "Cau hinh 2: Bat dau (0, 0) -> dich (4, 5)" << endl;
    timKiemTotNhat(0, 0, 4, 5);

    cout << "Cau hinh 3: Bat dau (2, 3) -> dich (6, 6)" << endl;
    timKiemTotNhat(2, 3, 6, 6);

    cout << "Cau hinh 4: Bat dau (3, 1) -> dich (8, 8)" << endl;
    timKiemTotNhat(3, 1, 8, 8);

    cout << "Cau hinh 5: Bat dau (1, 4) -> dich (7, 3)" << endl;
    timKiemTotNhat(1, 4, 7, 3);

    return 0;
}
