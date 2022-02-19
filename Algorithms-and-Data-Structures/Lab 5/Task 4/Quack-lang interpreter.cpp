#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main() {
    //freopen("quack.in", "r", stdin);
    //freopen("quack.out", "w", stdout);
    vector<string> commands;
    string operators;
    while (cin >> operators) commands.push_back(operators);
    uint16_t registers[26] = {};
    queue<uint16_t> values;
    map<string, int> labels;
    const int modulo = 65536;
    int j = 0;
    uint16_t tempInt;
    string temp;
    for (int i = 0; i < commands.size(); i++) {
        char a = commands[i][0];
        if (a == ':') {
            temp = commands[i];
            temp.erase(0, 1);
            labels[temp] = i;
            continue;
        }
    }
    while (j < commands.size()) {
        char a = commands[j][0];
        switch (a) {
            case ':' : {
                j++;
                continue;
            }
            case '+' : {
                tempInt = values.front();
                values.pop();
                tempInt += values.front();
                values.pop();
                values.push(tempInt % modulo);
                j++;
                continue;
            }
            case '-' : {
                tempInt = values.front();
                values.pop();
                tempInt -= values.front();
                values.pop();
                values.push(tempInt % modulo);
                j++;
                continue;
            }
            case '*' : {
                tempInt = values.front();
                values.pop();
                tempInt *= values.front();
                values.pop();
                values.push(tempInt % modulo);
                j++;
                continue;
            }
            case '/' : {
                tempInt = values.front();
                values.pop();
                (values.front() == 0) ? tempInt = 0 : tempInt /= values.front();
                values.pop();
                values.push(tempInt);
                j++;
                continue;
            }
            case '%' : {
                tempInt = values.front();
                values.pop();
                (values.front() == 0) ? tempInt = 0 : tempInt %= values.front();
                values.pop();
                values.push(tempInt);
                j++;
                continue;
            }
            case '>' : {
                registers[commands[j][1] - 'a'] = values.front();
                values.pop();
                j++;
                continue;
            }
            case '<' : {
                values.push(registers[commands[j][1] - 'a']);
                j++;
                continue;
            }
            case 'P' : {
                if (commands[j].length() == 1) {
                    cout << values.front() << "\n";
                    values.pop();
                } else {
                    cout << registers[commands[j][1] - 'a'] << "\n";
                }
                j++;
                continue;
            }
            case 'C' : {
                if (commands[j].length() == 1) {
                    cout << (char) (values.front() % 256);
                    values.pop();
                } else {
                    cout << (char) (registers[commands[j][1] - 'a'] % 256);
                }
                j++;
                continue;
            }
            case 'J' : {
                temp = commands[j];
                temp.erase(0, 1);
                j = labels[temp];
                continue;
            }
            case 'Z' : {
                if (registers[commands[j][1] - 'a'] == 0) {
                    temp = commands[j];
                    temp.erase(0, 2);
                    j = labels[temp];
                    continue;
                }
                j++;
                continue;
            }
            case 'E' : {
                if (registers[commands[j][1] - 'a'] == registers[commands[j][2] - 'a']) {
                    temp = commands[j];
                    temp.erase(0, 3);
                    j = labels[temp];
                    continue;
                }
                j++;
                continue;
            }
            case 'G' : {
                if (registers[commands[j][1] - 'a'] > registers[commands[j][2] - 'a']) {
                    temp = commands[j];
                    temp.erase(0, 3);
                    j = labels[temp];
                    continue;
                }
                j++;
                continue;
            }
            case 'Q' : {
                break;
            }
            default:
                values.push(stoi(commands[j]));
                j++;
        }
    }

    return 0;
}