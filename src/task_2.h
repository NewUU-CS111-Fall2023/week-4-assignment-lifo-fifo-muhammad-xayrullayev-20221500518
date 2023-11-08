 /*
 * Author: Muhammad Xayrullayev
 * Date: 4/11/2023
 * Name: Muhammad Xayrullayev
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<pair<int, int>> reorder_train_cars(int N, const vector<int>& order) {
    vector<int> track1(N);
    for (int i = 0; i < N; i++) {
        track1[i] = i + 1;
    }
    vector<int> dead_end;
    vector<pair<int, int>> actions;

    for (int car : order) {
        while (!track1.empty() && track1.back() != car) {
            dead_end.push_back(track1.back());
            actions.push_back({1, 1});
            track1.pop_back();
        }

        if (!track1.empty() && track1.back() == car) {
            actions.push_back({1, 1});
            track1.pop_back();
        } else if (!dead_end.empty() && dead_end.back() == car) {
            actions.push_back({2, 1});
            dead_end.pop_back();
        } else {
            return {}; // Return an empty vector to indicate impossibility
        }
    }

    while (!dead_end.empty()) {
        actions.push_back({2, 1});
        dead_end.pop_back();
    }

    return actions;
}

string is_correct_arithmetic_expression(int N, const string& brackets) {
    stack<char> stack;

    for (char bracket : brackets) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            stack.push(bracket);
        } else {
            if (stack.empty()) {
                return "No";
            }

            char top = stack.top();
            stack.pop();

            if ((bracket == ')' && top != '(') || (bracket == ']' && top != '[') || (bracket == '}' && top != '{')) {
                return "No";
            }
        }
    }

    if (stack.empty()) {
        return "Yes";
    } else {
        return "No";
    }
}

int task_2() {
    int N;
    cin >> N;

    vector<int> train_order(N);
    for (int i = 0; i < N; i++) {
        cin >> train_order[i];
    }

    string brackets;
    cin >> brackets;

    vector<pair<int, int>> train_actions = reorder_train_cars(N, train_order);
    string expression_result = is_correct_arithmetic_expression(brackets.size(), brackets);

    if (train_actions.empty() || expression_result == "No") {
        cout << "0" << endl;
    } else {
        for (auto action : train_actions) {
            cout << action.first << " " << action.second << endl;
        }
    }

    return 0;
}
