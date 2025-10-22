// Пирамидальная сортировка

public class HeapSort {

    // Основная функция для выполнения пирамидальной сортировки
    public static void heapSort(int[] arr) {
        int n = arr.length;

        // Построение max-heap (перегруппировка массива)
        // Начинаем с последнего нелистового узла
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Один за другим извлекаем элементы из кучи
        for (int i = n - 1; i > 0; i--) {
            // Перемещаем текущий корень в конец
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Вызываем heapify на уменьшенной куче
            heapify(arr, i, 0);
        }
    }

    // Функция для преобразования поддерева в кучу
    // n - размер кучи, i - корневой индекс поддерева
    static void heapify(int[] arr, int n, int i) {
        int largest = i;     // Инициализируем наибольший элемент как корень
        int left = 2 * i + 1; // Левый дочерний элемент
        int right = 2 * i + 2; // Правый дочерний элемент

        // Если левый дочерний элемент больше корня
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // Если правый дочерний элемент больше, чем текущий наибольший
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // Если наибольший элемент не корень
        if (largest != i) {
            // Меняем местами корень с наибольшим элементом
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            // Рекурсивно преобразуем затронутое поддерево
            heapify(arr, n, largest);
        }
    }

    // Вспомогательная функция для вывода массива
    static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    // Основной метод для тестирования
    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6, 7};
        
        System.out.print("Исходный массив: ");
        printArray(arr);

        heapSort(arr);

        System.out.print("Отсортированный массив: ");
        printArray(arr);
    }
}
