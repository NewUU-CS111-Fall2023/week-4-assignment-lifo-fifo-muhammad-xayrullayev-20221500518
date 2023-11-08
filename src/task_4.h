 /*
 * Author: Muhammad Xayrullayev
 * Date: 4/11/2023
 * Name: Muhammad Xayrullayev
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int task_4() {
    int N;
    cin >> N;
    
    vector<stack<int>> stacks(N);
    vector<int> targetOrder(N);
    vector<int> currentOrder(N);
    
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int containerType;
            cin >> containerType;
            stacks[i].push(containerType);
            currentOrder[i] = containerType;
        }
    }
    
    for (int i = 0; i < N; i++) {
        targetOrder[i] = i + 1;
    }
    
    vector<pair<int, int>> actions;
    
    for (int targetContainerType = 1; targetContainerType <= N; targetContainerType++) {
        int sourceStack = -1;
        
        for (int i = 0; i < N; i++) {
            if (currentOrder[i] == targetContainerType) {
                sourceStack = i;
                break;
            }
        }
        
        if (sourceStack == -1) {
            cout << "0" << endl;
            return 0;
        }
        
        int targetStack = targetContainerType - 1;
        actions.push_back({sourceStack + 1, targetStack + 1});
        currentOrder[sourceStack] = 0;
        
        stacks[targetStack].push(targetContainerType);
    }
    
    for (const auto& action : actions) {
        cout << action.first << " " << action.second << endl;
    }
    
    return 0;
}
