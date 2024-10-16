#include <bits/stdc++.h>
using namespace std;

// Функция для проверки хода ферзя (движение по вертикали, горизонтали или диагонали)
bool isValidQueenMove(int X1, int Y1, int X2, int Y2) {
    // Ферзь может двигаться по вертикали, горизонтали или диагонали
    return (X1 == X2 || Y1 == Y2 || abs(X1 - X2) == abs(Y1 - Y2));
}

// Функция для проверки хода ладьи (движение по вертикали или горизонтали)
bool isValidRookMove(int X1, int Y1, int X2, int Y2) {
    return (X1 == X2 || Y1 == Y2);
}

// Функция для проверки хода слона (движение по диагонали)
bool isValidBishopMove(int X1, int Y1, int X2, int Y2) {
    return (abs(X1 - X2) == abs(Y1 - Y2));
}

// Функция для проверки хода коня (ход буквой "Г")
bool isValidKnightMove(int X1, int Y1, int X2, int Y2) {
    return ((abs(X1 - X2) == 2 && abs(Y1 - Y2) == 1) || (abs(X1 - X2) == 1 && abs(Y1 - Y2) == 2));
}

int main() {
    setlocale(LC_ALL, "Russian");
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;

    // Проверка на обычный ход пешки вперед
    if (X1 == X2) {
        if (Y1 == 2 && (Y2 == Y1 + 1 || Y2 == Y1 + 2)) {
            // Первый ход белой пешки (на 1 или 2 клетки вперед)
            cout << "YES" << endl;
        } else if (Y1 >= 3 && Y2 == Y1 + 1) {
            // Обычный ход белой пешки на одну клетку вперед
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    // Проверка на захват фигуры по диагонали
    else if ((X2 == X1 + 1 || X2 == X1 - 1) && Y2 == Y1 + 1) {
        // Пешка может съесть фигуру на одну клетку по диагонали вперед
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    // Проверка на достижение последней линии и превращение пешки
    if (Y2 == 8) {
        char choice;
        cout << "Пешка достигла последней линии! Выберите фигуру для превращения (Q - ферзь, R - ладья, N - конь, B - слон): ";
        cin >> choice;

        switch (choice) {
            case 'Q': {
                cout << "Пешка превращена в ферзя." << endl;
                // Дальнейшие ходы ферзя
                cout << "Введите новый ход ферзя (начальные и конечные координаты): ";
                int Xq1, Yq1, Xq2, Yq2;
                cin >> Xq1 >> Yq1 >> Xq2 >> Yq2;
                if (isValidQueenMove(Xq1, Yq1, Xq2, Yq2)) {
                    cout << "Ход ферзя допустим." << endl;
                } else {
                    cout << "Ход ферзя недопустим." << endl;
                }
                break;
            }
            case 'R': {
                cout << "Пешка превращена в ладью." << endl;
                // Дальнейшие ходы ладьи
                cout << "Введите новый ход ладьи (начальные и конечные координаты): ";
                int Xr1, Yr1, Xr2, Yr2;
                cin >> Xr1 >> Yr1 >> Xr2 >> Yr2;
                if (isValidRookMove(Xr1, Yr1, Xr2, Yr2)) {
                    cout << "Ход ладьи допустим." << endl;
                } else {
                    cout << "Ход ладьи недопустим." << endl;
                }
                break;
            }
            case 'N': {
                cout << "Пешка превращена в коня." << endl;
                // Дальнейшие ходы коня
                cout << "Введите новый ход коня (начальные и конечные координаты): ";
                int Xn1, Yn1, Xn2, Yn2;
                cin >> Xn1 >> Yn1 >> Xn2 >> Yn2;
                if (isValidKnightMove(Xn1, Yn1, Xn2, Yn2)) {
                    cout << "Ход коня допустим." << endl;
                } else {
                    cout << "Ход коня недопустим." << endl;
                }
                break;
            }
            case 'B': {
                cout << "Пешка превращена в слона." << endl;
                // Дальнейшие ходы слона
                cout << "Введите новый ход слона (начальные и конечные координаты): ";
                int Xb1, Yb1, Xb2, Yb2;
                cin >> Xb1 >> Yb1 >> Xb2 >> Yb2;
                if (isValidBishopMove(Xb1, Yb1, Xb2, Yb2)) {
                    cout << "Ход слона допустим." << endl;
                } else {
                    cout << "Ход слона недопустим." << endl;
                }
                break;
            }
            default:
                cout << "Неверный выбор. Пешка автоматически превращена в ферзя." << endl;
        }
    }

    return 0;
}
