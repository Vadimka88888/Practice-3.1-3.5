// Интерполирующий поиск

#include <iostream>
#include <vector>
using namespace std;

// Функция интерполяционного поиска
int interpolationSearch(const vector<int>& arr, int target) {
    int low = 0;                       // Нижняя граница поиска
    int high = arr.size() - 1;         // Верхняя граница поиска

    // Пока целевой элемент в пределах диапазона и границы валидны
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Если границы совпадают, проверяем элемент
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        // Вычисляем позицию с помощью интерполяционной формулы
        // Формула основана на равномерном распределении элементов
        int pos = low + (((double)(high - low) / 
                         (arr[high] - arr[low])) * (target - arr[low]));

        // Проверяем найденный элемент
        if (arr[pos] == target) {
            return pos;  // Элемент найден
        }

        // Если целевой элемент меньше, ищем в левой части
        if (arr[pos] > target) {
            high = pos - 1;
        } 
        // Если целевой элемент больше, ищем в правой части
        else {
            low = pos + 1;
        }
    }

    return -1;  // Элемент не найден
}

// Рекурсивная версия (как в Python коде)
int interpolationSearchRecursive(const vector<int>& arr, int low, int high, int target) {
    // Проверяем базовые условия
    if (low <= high && target >= arr[low] && target <= arr[high]) {
        // Вычисляем позицию интерполяции
        int pos = low + (((double)(high - low) / 
                         (arr[high] - arr[low])) * (target - arr[low]));

        // Проверяем элемент в вычисленной позиции
        if (arr[pos] == target) {
            return pos;
        }

        // Рекурсивно ищем в соответствующей половине
        if (arr[pos] < target) {
            return interpolationSearchRecursive(arr, pos + 1, high, target);
        } else {
            return interpolationSearchRecursive(arr, low, pos - 1, target);
        }
    }

    return -1;  // Элемент не найден
}

// Вспомогательная функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Отсортированный массив с равномерным распределением
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int target = 18;

    cout << "Массив: ";
    printArray(arr);
    cout << "Ищем элемент: " << target << endl;

    // Итеративный поиск
    int result = interpolationSearch(arr, target);
    
    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << " (итеративный)" << endl;
    } else {
        cout << "Элемент не найден (итеративный)" << endl;
    }

    // Рекурсивный поиск
    result = interpolationSearchRecursive(arr, 0, arr.size() - 1, target);
    
    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << " (рекурсивный)" << endl;
    } else {
        cout << "Элемент не найден (рекурсивный)" << endl;
    }

    return 0;
}
