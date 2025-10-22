// Бинарный поиск

#include <iostream>
#include <vector>
using namespace std;

// Функция бинарного поиска
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;                    // Левая граница области поиска
    int right = arr.size() - 1;      // Правая граница области поиска

    // Пока область поиска не пуста
    while (left <= right) {
        // Вычисляем средний индекс (защита от переполнения)
        int mid = left + (right - left) / 2;

        // Если нашли целевой элемент
        if (arr[mid] == target) {
            return mid;  // Возвращаем индекс найденного элемента
        }

        // Если целевой элемент меньше среднего
        if (arr[mid] > target) {
            right = mid - 1;  // Сужаем поиск до левой половины
        } else {
            left = mid + 1;   // Сужаем поиск до правой половины
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
    // Отсортированный массив для поиска
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;  // Искомый элемент

    cout << "Отсортированный массив: ";
    printArray(sortedArray);
    cout << "Ищем элемент: " << target << endl;

    // Выполняем бинарный поиск
    int result = binarySearch(sortedArray, target);

    // Выводим результат
    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }

    return 0;
}
