#include <bits/stdc++.h>
using namespace std;

// ������� ��� �������� ���� ����� (�������� �� ���������, ����������� ��� ���������)
bool isValidQueenMove(int X1, int Y1, int X2, int Y2) {
    // ����� ����� ��������� �� ���������, ����������� ��� ���������
    return (X1 == X2 || Y1 == Y2 || abs(X1 - X2) == abs(Y1 - Y2));
}

// ������� ��� �������� ���� ����� (�������� �� ��������� ��� �����������)
bool isValidRookMove(int X1, int Y1, int X2, int Y2) {
    return (X1 == X2 || Y1 == Y2);
}

// ������� ��� �������� ���� ����� (�������� �� ���������)
bool isValidBishopMove(int X1, int Y1, int X2, int Y2) {
    return (abs(X1 - X2) == abs(Y1 - Y2));
}

// ������� ��� �������� ���� ���� (��� ������ "�")
bool isValidKnightMove(int X1, int Y1, int X2, int Y2) {
    return ((abs(X1 - X2) == 2 && abs(Y1 - Y2) == 1) || (abs(X1 - X2) == 1 && abs(Y1 - Y2) == 2));
}

int main() {
    setlocale(LC_ALL, "Russian");
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;

    // �������� �� ������� ��� ����� ������
    if (X1 == X2) {
        if (Y1 == 2 && (Y2 == Y1 + 1 || Y2 == Y1 + 2)) {
            // ������ ��� ����� ����� (�� 1 ��� 2 ������ ������)
            cout << "YES" << endl;
        } else if (Y1 >= 3 && Y2 == Y1 + 1) {
            // ������� ��� ����� ����� �� ���� ������ ������
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    // �������� �� ������ ������ �� ���������
    else if ((X2 == X1 + 1 || X2 == X1 - 1) && Y2 == Y1 + 1) {
        // ����� ����� ������ ������ �� ���� ������ �� ��������� ������
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    // �������� �� ���������� ��������� ����� � ����������� �����
    if (Y2 == 8) {
        char choice;
        cout << "����� �������� ��������� �����! �������� ������ ��� ����������� (Q - �����, R - �����, N - ����, B - ����): ";
        cin >> choice;

        switch (choice) {
            case 'Q': {
                cout << "����� ���������� � �����." << endl;
                // ���������� ���� �����
                cout << "������� ����� ��� ����� (��������� � �������� ����������): ";
                int Xq1, Yq1, Xq2, Yq2;
                cin >> Xq1 >> Yq1 >> Xq2 >> Yq2;
                if (isValidQueenMove(Xq1, Yq1, Xq2, Yq2)) {
                    cout << "��� ����� ��������." << endl;
                } else {
                    cout << "��� ����� ����������." << endl;
                }
                break;
            }
            case 'R': {
                cout << "����� ���������� � �����." << endl;
                // ���������� ���� �����
                cout << "������� ����� ��� ����� (��������� � �������� ����������): ";
                int Xr1, Yr1, Xr2, Yr2;
                cin >> Xr1 >> Yr1 >> Xr2 >> Yr2;
                if (isValidRookMove(Xr1, Yr1, Xr2, Yr2)) {
                    cout << "��� ����� ��������." << endl;
                } else {
                    cout << "��� ����� ����������." << endl;
                }
                break;
            }
            case 'N': {
                cout << "����� ���������� � ����." << endl;
                // ���������� ���� ����
                cout << "������� ����� ��� ���� (��������� � �������� ����������): ";
                int Xn1, Yn1, Xn2, Yn2;
                cin >> Xn1 >> Yn1 >> Xn2 >> Yn2;
                if (isValidKnightMove(Xn1, Yn1, Xn2, Yn2)) {
                    cout << "��� ���� ��������." << endl;
                } else {
                    cout << "��� ���� ����������." << endl;
                }
                break;
            }
            case 'B': {
                cout << "����� ���������� � �����." << endl;
                // ���������� ���� �����
                cout << "������� ����� ��� ����� (��������� � �������� ����������): ";
                int Xb1, Yb1, Xb2, Yb2;
                cin >> Xb1 >> Yb1 >> Xb2 >> Yb2;
                if (isValidBishopMove(Xb1, Yb1, Xb2, Yb2)) {
                    cout << "��� ����� ��������." << endl;
                } else {
                    cout << "��� ����� ����������." << endl;
                }
                break;
            }
            default:
                cout << "�������� �����. ����� ������������� ���������� � �����." << endl;
        }
    }

    return 0;
}
