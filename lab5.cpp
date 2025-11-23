#include <iostream>
#include <cmath>
using namespace std;

// ============================================================
// ФУНКЦІЇ ПЕРЕВІРКИ КОРЕКТНОСТІ ВВЕДЕННЯ
// ============================================================

bool IsValidDouble(double x) {
    return !cin.fail();
}

bool IsValidPositive(double x) {
    return (!cin.fail() && x > 0);
}

bool IsValidInt(int x) {
    return (!cin.fail());
}

// ============================================================
// ЗАДАЧА 1 — FIGURE 26 
// Перевірка, чи потрапляє точка у чорну фігуру
// ============================================================

void TaskFigure26() {
    double x, y;

    cout << "\n--- Задача 1: Figure 26 ---\n";

    cout << "Введiть x: ";
    cin >> x;
    if (!IsValidDouble(x)) { cout << "Помилка! Некоректне число.\n"; cin.clear(); cin.ignore(1000, '\n'); return; }

    cout << "Введiть y: ";
    cin >> y;
    if (!IsValidDouble(y)) { cout << "Помилка! Некоректне число.\n"; cin.clear(); cin.ignore(1000, '\n'); return; }

    // Умова з Figure 26 (твої попередні умови)
    bool insideSquare = (x >= -1 && x <= 1 && y >= -1 && y <= 1);
    bool whiteCircle = (x * x + y * y <= 1);

    if (insideSquare && !whiteCircle)
        cout << "Точка (" << x << ", " << y << ") — у чорнiй областi.\n";
    else
        cout << "Точка не в чорнiй областi.\n";
}

// ============================================================
// ЗАДАЧА 2 — РЯД 25 
// Обчислення суми ряду
// ============================================================

double f(int n, double x) {
    return pow(-1, n) * pow(x, 2 * n + 1) / (2 * n + 1);
}

void TaskSeries25() {
    double x, eps;
    int nmax;

    cout << "\n--- Задача 2: Пiдрахунок ряду (варiант 25) ---\n";

    cout << "Введiть x: ";
    cin >> x;
    if (!IsValidDouble(x)) { cout << "Помилка!\n"; cin.clear(); cin.ignore(1000, '\n'); return; }

    cout << "Введiть eps (>0): ";
    cin >> eps;
    if (!IsValidPositive(eps)) { cout << "Помилка!\n"; cin.clear(); cin.ignore(1000, '\n'); return; }

    cout << "Введiть максимальну кiлькiсть членiв n: ";
    cin >> nmax;
    if (!IsValidInt(nmax) || nmax <= 0) { cout << "Помилка!\n"; cin.clear(); cin.ignore(1000, '\n'); return; }

    double sum = 0;
    int n = 0;

    while (n < nmax) {
        double term = f(n, x);
        sum += term;
        if (fabs(term) < eps) break;
        n++;
    }

    cout << "Сума ряду = " << sum << "\n";
    cout << "Використано членiв: " << n + 1 << "\n";
}

// ============================================================
// ЗАДАЧА 3 — ЗБІЖНІСТЬ/РОЗБІЖНІСТЬ 
// ============================================================

double u(int n, double x) {
    return pow(-1, n) * pow((3 * x - 1), n - 1) / pow((sqrt(n) * x), 3);
}

void TaskConvergence() {
    double x, eps, g;

    cout << "\n--- Задача 3: Перевiрка збiжностi ряду ---\n";

    cout << "Введiть x: ";
    cin >> x;
    if (!IsValidDouble(x)) { cout << "Помилка!\n"; cin.clear(); cin.ignore(1000, '\n'); return; }

    cout << "Введiть eps (>0): ";
    cin >> eps;
    if (!IsValidPositive(eps)) { cout << "Помилка!\n"; cin.clear(); cin.ignore(1000, '\n'); return; }

    cout << "Введiть g (>0): ";
    cin >> g;
    if (!IsValidPositive(g)) { cout << "Помилка!\n"; cin.clear(); cin.ignore(1000, '\n'); return; }

    double sum = 0;
    int n = 1;

    while (true) {
        double term = u(n, x);
        sum += term;

        if (fabs(term) < eps) {
            cout << "Ряд ЗБIЖНИЙ\n";
            cout << "Сума ≈ " << sum << "\n";
            cout << "Завершено на n = " << n << "\n";
            return;
        }

        if (fabs(term) > g) {
            cout << "Ряд РОЗБIЖНИЙ\n";
            cout << "Член u(n) = " << term << " перевищив g.\n";
            return;
        }

        n++;
        if (n > 1e7) { cout << "Можлива розбiжнiсть (перевищено лiмiт n)\n"; return; }
    }
}

// ============================================================
// ГОЛОВНЕ МЕНЮ 
// ============================================================

int main() {
    setlocale(0, "");

    while (true) {
        cout << "\n=========== ГОЛОВНЕ МЕНЮ ===========\n";
        cout << "1 — Задача 1: Figure 26\n";
        cout << "2 — Задача 2: Ряд 25\n";
        cout << "3 — Задача 3: Збiжнiсть ряду\n";
        cout << "0 — Вихiд\n";
        cout << "Ваш вибiр: ";

        int choice;
        cin >> choice;

        if (!IsValidInt(choice)) {
            cout << "Помилка вводу!\n";
            cin.clear(); cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: TaskFigure26(); break;
            case 2: TaskSeries25(); break;
            case 3: TaskConvergence(); break;
            case 0: cout << "Вихiд...\n"; return 0;
            default: cout << "Невiрний вибiр!\n";
        }
    }

    return 0;
}

