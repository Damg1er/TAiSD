using System;
class Program
{
    // Вывод одномерного массива
    static void PrintArray(int[] array)
    {
        if (array.Length == 0)
        {
            Console.WriteLine("Массив пустой");
            return;
        }
        foreach (var element in array)
        {
            Console.Write(element + " ");
        }

        Console.WriteLine();
    }
    // Вывод двумерного массива
    static void Print2DArray(int[][] array)
    {
        if (array.Length == 0 || array[0].Length == 0)
        {
            Console.WriteLine("Массив пустой");
            return;
        }
        foreach (var row in array)
        {
            foreach (var element in row)
            {
                Console.Write(element + " ");
            }

            Console.WriteLine();
        }
    }
    // Заполнение одномерного массива случайными значениями
    static void GenerateRandomArray(int[] array)
    {
        Random random = new Random();

        for (int i = 0; i < array.Length; ++i)
        {
            array[i] = random.Next(100);
        }
    }
    // Заполнение двумерного массива случайными значениями
    static void GenerateRandom2DArray(int[][] array)
    {
        Random random = new Random();

        for (int i = 0; i < array.Length; ++i)
        {
            for (int j = 0; j < array[i].Length; ++j)
            {
                array[i][j] = random.Next(100);
            }
        }
    }
    // Создание рваного массива с заданным числом строк, пользователь вводит количество элементов в каждой строке
    static void GenerateRandomJaggedArray(out int[][] array, int numRows)
    {
        Random random = new Random();
        array = new int[numRows][];

        for (int i = 0; i < numRows; ++i)
        {
            int numCols;
            do
            {
                Console.Write($"Введите количество элементов в строке {i + 1}: ");
            } while (!int.TryParse(Console.ReadLine(), out numCols) || numCols < 0);

            array[i] = new int[numCols + 1];
            array[i][0] = numCols;

            for (int j = 1; j <= numCols; ++j)
            {
                array[i][j] = random.Next(100);
            }
        }
    }
    // Вывод рваного массива
    static void PrintJaggedArray(int[][] array)
    {
        if (array.Length == 0)
        {
            Console.WriteLine("Массив пустой");
            return;
        }
        for (int i = 0; i < array.Length; ++i)
        {
            int numCols = array[i][0];
            Console.Write($"Строка {i + 1}: ");
            for (int j = 1; j <= numCols; ++j)
            {
                Console.Write(array[i][j] + " ");
            }
            Console.WriteLine();
        }
    }
    // Удаление строки из рваного массива
    static void RemoveRowFromJaggedArray(ref int[][] array, ref int numRows, int rowNum)
    {
        if (numRows == 0)
        {
            Console.WriteLine("Ошибка: массив пустой.");
            return;
        }
        if (rowNum >= 1 && rowNum <= numRows)
        {
            Array.Clear(array[rowNum - 1], 0, array[rowNum - 1].Length);
            Array.Copy(array, rowNum, array, rowNum - 1, numRows - rowNum);
            Array.Resize(ref array, numRows - 1);
            --numRows;
        }
        else
        {
            Console.WriteLine("Ошибка: указанный номер строки не существует.");
        }
    }
    // Удаление нечетных элементов из одномерного массива
    static void RemoveOddElements(ref int[] array)
    {
        int newSize = 0;
        for (int i = 0; i < array.Length; ++i)
        {
            if (array[i] % 2 == 0)
            {
                array[newSize] = array[i];
                ++newSize;
            }
        }
        Array.Resize(ref array, newSize);
    }
    // Добавление новых строк в двумерный массив
    static void AddRandomRowsTo2DArray(ref int[][] array, ref int numRows, int cols, int numNewRows)
    {
        Random random = new Random();
        int[][] newArray = new int[numRows + numNewRows][];
        for (int i = 0; i < numNewRows; ++i)
        {
            newArray[i] = new int[cols];
            for (int j = 0; j < cols; ++j)
            {
                newArray[i][j] = random.Next(100);
            }
        }
        Array.Copy(array, 0, newArray, numNewRows, numRows);
        array = newArray;
        numRows += numNewRows;
    }
    static void Main()
    {
        Random random = new Random();
        int choice;
        do
        {
            // Выбор типа массива (1 - одномерный, 2 - двумерный, 3 - рваный, 0 - выход)
            Console.Write("Выберите тип массива (1 - одномерный, 2 - двумерный, 3 - рваный, 0 - выход): ");
            if (!int.TryParse(Console.ReadLine(), out choice) || (choice != 1 && choice != 2 && choice != 3 && choice != 0))
            {
                Console.WriteLine("Ошибка: некорректный выбор типа массива.");
                continue;
            }
            if (choice == 0)
            {
                break;
            }
            // Обработка выбора пользователя
            if (choice == 1)
            {
                // Работа с одномерным массивом
                // Ввод размера массива
                int size;
                do
                {
                    Console.Write("Введите размер массива: ");
                } while (!int.TryParse(Console.ReadLine(), out size) || size < 0);
                // Создание и заполнение массива
                int[] array = new int[size];
                // Выбор способа создания массива (вручную или случайными числами)
                int generateChoice;
                do
                {
                    Console.Write("Выберите способ создания массива (1 - вручную, 2 - случайные числа): ");
                } while (!int.TryParse(Console.ReadLine(), out generateChoice) || (generateChoice != 1 && generateChoice != 2));
                if (generateChoice == 1)
                {
                    // Ввод элементов массива вручную
                    Console.WriteLine("Введите элементы массива:");
                    for (int i = 0; i < size; ++i)
                    {
                        while (!int.TryParse(Console.ReadLine(), out array[i]))
                        {
                            Console.WriteLine("Ошибка ввода. Введен некорректный символ. Введите элемент еще раз:");
                        }
                    }
                }
                else
                {
                    // Заполнение массива случайными числами
                    GenerateRandomArray(array);
                }
                // Вывод исходного массива
                Console.Write("Исходный массив: ");
                PrintArray(array);
                // Удаление нечетных элементов
                RemoveOddElements(ref array);
                // Вывод массива после удаления нечетных элементов
                Console.Write("Массив после удаления нечетных элементов: ");
                PrintArray(array);
            }
            else if (choice == 2)
            {
                // Работа с двумерным массивом
                // Ввод количества строк и столбцов
                int rows, cols;
                do
                {
                    Console.Write("Введите количество строк и столбцов двумерного массива: ");
                } while (!int.TryParse(Console.ReadLine(), out rows) || !int.TryParse(Console.ReadLine(), out cols) || rows < 0 || cols < 0);
                // Создание и заполнение двумерного массива
                int[][] array2D = new int[rows][];
                for (int i = 0; i < rows; ++i)
                {
                    array2D[i] = new int[cols];
                }
                // Выбор способа создания массива (вручную или случайными числами)
                int generateChoice;
                do
                {
                    Console.Write("Выберите способ создания массива (1 - вручную, 2 - случайные числа): ");
                } while (!int.TryParse(Console.ReadLine(), out generateChoice) || (generateChoice != 1 && generateChoice != 2));

                if (generateChoice == 1)
                {
                    // Ввод элементов массива вручную
                    Console.WriteLine("Введите элементы массива:");
                    for (int i = 0; i < rows; ++i)
                    {
                        for (int j = 0; j < cols; ++j)
                        {
                            while (!int.TryParse(Console.ReadLine(), out array2D[i][j]))
                            {
                                Console.WriteLine("Ошибка ввода. Введен некорректный символ. Введите элемент еще раз:");
                            }
                        }
                    }
                }
                else
                {
                    // Заполнение массива случайными числами
                    GenerateRandom2DArray(array2D);
                }
                // Вывод исходного массива
                Console.WriteLine("Исходный массив:");
                Print2DArray(array2D);
                // Ввод количества новых строк для добавления
                int numNewRows;
                do
                {
                    Console.Write("Введите количество новых строк для добавления: ");
                } while (!int.TryParse(Console.ReadLine(), out numNewRows) || numNewRows < 0);
                // Добавление новых строк в начало массива
                AddRandomRowsTo2DArray(ref array2D, ref rows, cols, numNewRows);
                Console.WriteLine("Массив после добавления строк в начало:");
                Print2DArray(array2D);
            }
            else if (choice == 3)
            {
                // Работа с рваным массивом
                // Ввод количества строк рваного массива
                int numRows;
                do
                {
                    Console.Write("Введите количество строк рваного массива: ");
                } while (!int.TryParse(Console.ReadLine(), out numRows) || numRows < 0);
                int[][] jaggedArray;
                // Выбор способа создания массива (вручную или случайными числами)
                int generateChoice;
                do
                {
                    Console.Write("Выберите способ создания массива (1 - вручную, 2 - случайные числа): ");
                } while (!int.TryParse(Console.ReadLine(), out generateChoice) || (generateChoice != 1 && generateChoice != 2));
                if (generateChoice == 1)
                {
                    // Ввод элементов массива вручную
                    jaggedArray = new int[numRows][];
                    for (int i = 0; i < numRows; ++i)
                    {
                        int numCols;
                        do
                        {
                            Console.Write($"Введите количество элементов в строке {i + 1}: ");
                        } while (!int.TryParse(Console.ReadLine(), out numCols) || numCols < 0);
                        jaggedArray[i] = new int[numCols + 1];
                        jaggedArray[i][0] = numCols;
                        for (int j = 1; j <= numCols; ++j)
                        {
                            while (!int.TryParse(Console.ReadLine(), out jaggedArray[i][j]))
                            {
                                Console.WriteLine("Ошибка ввода. Введен некорректный символ. Введите элемент еще раз:");
                            }
                        }
                    }
                }
                else
                {
                    GenerateRandomJaggedArray(out jaggedArray, numRows);
                }
                Console.WriteLine("Исходный рваный массив:");
                PrintJaggedArray(jaggedArray);
                int rowNum;
                do
                {
                    Console.Write("Введите номер строки для удаления: ");
                } while (!int.TryParse(Console.ReadLine(), out rowNum));
                RemoveRowFromJaggedArray(ref jaggedArray, ref numRows, rowNum);
                Console.WriteLine("Рваный массив после удаления строки:");
                PrintJaggedArray(jaggedArray);
            }
        } while (true);
    }
}
