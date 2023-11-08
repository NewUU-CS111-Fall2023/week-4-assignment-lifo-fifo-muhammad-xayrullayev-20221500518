/*
 * Author: Muhammad Xayrullayev
 * Date: 4/11/2023
 * Name: Muhammad Xayrullayev
 */

 #include <iostream>

using namespace std;

int towerOfHanoi(int N) {
    if (N == 1) {
        return 1;
    } else {
        return 2 * towerOfHanoi(N - 1) + 1;
    }
}

int task_5() {
    int N;
    cout << "Enter the number of disks: ";
    cin >> N;

    int moves = towerOfHanoi(N);
    cout << "Minimal number of moves required: " << moves << endl;

    return 0;
}
