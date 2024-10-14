#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void printBingo(const vector<int>& bingo) 
{
    for (int i = 0; i < 25; i++) {
        if (bingo[i] == -1) {
            cout << " X ";
        }
        else {
            cout << bingo[i] << "\t";
        }
        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

void replaceNumber(vector<int>& bingo, int num) {
    for (int i = 0; i < 25; i++) {
        if (bingo[i] == num) {
            bingo[i] = -1;
            break;
        }
    }
}

int main() {
    vector<int> myBingo(25);
    vector<int> comBingo(25);

    // 빙고판 초기화
    for (int i = 0; i < 25; i++) {
        myBingo[i] = i + 1;
        comBingo[i] = i + 1;
    }

    // 빙고판 셔플
    srand(time(0));
    random_shuffle(myBingo.begin(), myBingo.end());
    random_shuffle(comBingo.begin(), comBingo.end());

    cout << "내 빙고판:" << endl;
    printBingo(myBingo);

    cout << "컴퓨터 빙고판:" << endl;
    printBingo(comBingo);

    while (true) {
        int myChoice;
        cout << "숫자를 부르세요: ";
        cin >> myChoice;

        // 내 빙고판과 컴퓨터 빙고판에서 숫자 대체
        replaceNumber(myBingo, myChoice);
        replaceNumber(comBingo, myChoice);

        cout << "내 빙고판:" << endl;
        printBingo(myBingo);

        cout << "컴퓨터 빙고판:" << endl;
        printBingo(comBingo);

        // 컴퓨터가 숫자를 부름
        int comChoice = rand() % 25 + 1;
        cout << "컴퓨터가 숫자 " << comChoice << " 을(를) 불렀습니다." << endl;

        // 내 빙고판과 컴퓨터 빙고판에서 숫자 대체
        replaceNumber(myBingo, comChoice);
        replaceNumber(comBingo, comChoice);

        cout << "내 빙고판:" << endl;
        printBingo(myBingo);

        cout << "컴퓨터 빙고판:" << endl;
        printBingo(comBingo);
    }

    return 0;
}
