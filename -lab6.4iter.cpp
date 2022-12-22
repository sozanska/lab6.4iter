#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Генерація значень елементів масиву
void CreateArray(double* a, const int size, int Low, int High)
{
    // цикл перебору елементів масиву
    for (int i = 0; i < size; i++)
        // формула обчислення випадкового числа
        a[i] = 0.01 * (10 * Low + rand() % (10 * (High - Low + 1)));

}

// Вивід елементів масиву
void PrintArray(double* a, const int size)
{
    // цикл перебору елементів масиву 
    for (int i = 0; i < size; i++)
        cout << setw(10) << fixed << setprecision(3) << a[i];  // форматований вивід елемента масиву
    cout << endl;
}

// Обчислення суми елементів з непарними номерами i=0
double SumOddNumbers(double* a, const int size)
{
    double sum = 0.0;

    // цикл перебору елементів масиву 
    for (int i = 0; i < size; i++)
    {
        // перевірка чи елемент має непарний номер
        if (i % 2)
            sum += a[i]; // 
    }
    return sum;
}

// Обчислює суму елементів масиву, розташованих між першим і останнім від’ємними елементами
double SumBetweenNegatives(double* a, const int size)
{
    double sum = 0, acc = 0;
    bool started = false;
    // цикл перебору значень масиву
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0) // перевірили чи від'ємний
        {
            if (!started)   // якщо ще не стартували раніше
            {               // стартуємо 
                acc = 0;    // обнуляємо проміжну суму
                started = true;
            }
            else
            {
                sum += acc;   // додаємо проміжну суму до основної
                acc = a[i];   // проміжній сумі присвоюємо значення елемента
            }
        }
        else
            acc += a[i]; // збільшуємо проміжну суму
    }

    return sum;
}

// стиснення масиву
void compress_array(double* a, const int size)
{
    int i = 0, k = 0;
    // i - лічильник опрацьованих елементів
    // k - лічильник викинутих елементів
    // перебір масиву з метою упаковки
    while (i < size - k)
    {
        // порівнюємо значення елемента масиву з 1,0
        if (fabs(a[i]) <= 1.0)
        {   // якщо не більше 1
            // в циклі зміщуємо елементи 
            for (int j = i; j < size - k - 1; j++)
                a[j] = a[j + 1];
            ++k; // збільшили лічильник викинутих елементів 
        }
        else
            // якщо більше 1, переходимо до наступного  
            ++i;
    }

    // Заповнюємо нулями кінець масиву
    for (i = size - 1; k != 0; a[i] = 0, k--, i--);
}


int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    int n;            // розмір масиву

    int Low = -40;
    int High = 20;
    // ввід розмірності динамічного масиву
    cout << "n = "; cin >> n;

    // cтворення динамічного масиву
    double* a = new double[n];

    CreateArray(a, n, Low, High);  // заповненння масиву випадковими числами
    PrintArray(a, n);              // вивід масиву   
    cout << " The sum odd number elements: " << SumOddNumbers(a, n) << endl;
    cout << " The sum between the first and last negatives: " << SumBetweenNegatives(a, n) << endl;

    compress_array(a, n);
    cout << " Compressed array: " << endl;
    PrintArray(a, n);              // Вивід зміненого масиву

    delete[] a; // знищили динамічнийі масив
    return 0;
}
