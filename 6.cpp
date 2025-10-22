// Быстрая сортировка

#include <iostream>
#include <vector>
using namespace std;

// Функция разбиения массива
int partition(vector<int>& arr, int low, int high) {
    // Выбираем последний элемент как опорный
    int pivot = arr[high];
    // Индекс для элемента, который меньше опорного
    int i = low - 1;

    // Проходим по всем элементам от low до high-1
    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++; // Увеличиваем индекс меньшего элемента
            // Меняем местами arr[i] и arr[j]
            swap(arr[i], arr[j]);
        }
    }

    // Помещаем опорный элемент на правильную позицию
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Основная функция быстрой сортировки
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Получаем индекс опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы до и после опорного
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Вспомогательная функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    cout << "Исходный массив: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}
