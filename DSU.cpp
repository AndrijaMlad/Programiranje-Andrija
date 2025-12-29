#include <iostream>
 
using namespace std;
const int maxn = 105;
int idx[maxn];
int size[maxn];
int find_root(int x) {
    while(idx[x] != x) {
        idx[x] = idx[idx[x]];
        x = idx[x];
    }
    return x;
}
bool is_in_u(int A, int B) {
    if(find_root(A) == find_root(B)) {
        return true;
    }
    return false;
}
void u2e(int A, int B) {
    int idx_A = find_root(A);
    int idx_B = find_root(B);
    if(size[idx_A] < size[idx_B]) { /// za by hight samo treba da se zeme istoto ama za hight
        idx[idx_A] = idx[idx_B];
        size[idx_B] += size[idx_A];///kje bide max(h1,h2) +1(eventualno ako se isti)
    }
    else {
        idx[idx_B] = idx[idx_A];
        size[idx_A] += size[idx_B];
    }
}
int main() {
    for(int i = 0; i < maxn; i++) {
        idx[i] = i;
        size[i] = 1;
    }
    while(true) {
        string s;
        cin >> s;
        if(s == "u") {
            int a, b;
            cin >> a >> b;
            u2e(a, b);
        }
        else {
            int a, b;
            cin >> a >> b;
            if(is_in_u(a, b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}