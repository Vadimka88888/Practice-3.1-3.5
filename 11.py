// Поиск по Фибоначчи

def fibonacci_search(arr, x):
    """
    Поиск по Фибоначчи в отсортированном массиве
    """
    n = len(arr)
    
    # Инициализируем числа Фибоначчи
    fib_m2 = 0  # F(m-2)
    fib_m1 = 1  # F(m-1) 
    fib_m = fib_m2 + fib_m1  # F(m)
    
    # Находим наименьшее число Фибоначчи, большее или равное n
    while fib_m < n:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m2 + fib_m1
    
    # Смещение для отслеживания исключенного диапазона
    offset = -1
    
    # Пока есть элементы для проверки
    while fib_m > 1:
        # Проверяем элемент на позиции i
        i = min(offset + fib_m2, n - 1)
        
        # Если x больше, ищем в правой части
        if arr[i] < x:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        
        # Если x меньше, ищем в левой части  
        elif arr[i] > x:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1
        
        # Элемент найден
        else:
            return i
    
    # Проверяем последний оставшийся элемент
    if fib_m1 and offset + 1 < n and arr[offset + 1] == x:
        return offset + 1
    
    return -1  # Элемент не найден


def main():
    # Отсортированный массив для поиска
    arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
    target = 85
    
    print("Массив:", arr)
    print(f"Ищем элемент: {target}")
    
    # Выполняем поиск по Фибоначчи
    result = fibonacci_search(arr, target)
    
    if result != -1:
        print(f"Элемент найден на позиции: {result}")
    else:
        print("Элемент не найден")


if __name__ == "__main__":
    main()
