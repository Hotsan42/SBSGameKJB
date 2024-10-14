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

    // ������ �ʱ�ȭ
    for (int i = 0; i < 25; i++) {
        myBingo[i] = i + 1;
        comBingo[i] = i + 1;
    }

    // ������ ����
    srand(time(0));
    random_shuffle(myBingo.begin(), myBingo.end());
    random_shuffle(comBingo.begin(), comBingo.end());

    cout << "�� ������:" << endl;
    printBingo(myBingo);

    cout << "��ǻ�� ������:" << endl;
    printBingo(comBingo);

    while (true) {
        int myChoice;
        cout << "���ڸ� �θ�����: ";
        cin >> myChoice;

        // �� �����ǰ� ��ǻ�� �����ǿ��� ���� ��ü
        replaceNumber(myBingo, myChoice);
        replaceNumber(comBingo, myChoice);

        cout << "�� ������:" << endl;
        printBingo(myBingo);

        cout << "��ǻ�� ������:" << endl;
        printBingo(comBingo);

        // ��ǻ�Ͱ� ���ڸ� �θ�
        int comChoice = rand() % 25 + 1;
        cout << "��ǻ�Ͱ� ���� " << comChoice << " ��(��) �ҷ����ϴ�." << endl;

        // �� �����ǰ� ��ǻ�� �����ǿ��� ���� ��ü
        replaceNumber(myBingo, comChoice);
        replaceNumber(comBingo, comChoice);

        cout << "�� ������:" << endl;
        printBingo(myBingo);

        cout << "��ǻ�� ������:" << endl;
        printBingo(comBingo);
    }

    return 0;
}
