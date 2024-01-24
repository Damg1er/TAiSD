using System;
using System.Linq;
class Program
{
    static void PrintJaggedArray(int[][] jaggedArray)
    {
        for (int i = 0; i < jaggedArray.Length; ++i)
        {
            int numCols = jaggedArray[i][0];
            for (int j = 1; j <= numCols; ++j)
            {
                Console.Write(jaggedArray[i][j] + " ");
            }
            Console.WriteLine();
        }
    }
    static void FreeMemory(int[][] jaggedArray)
    {
        foreach (var row in jaggedArray)
        {
            Array.Clear(row, 0, row.Length);
        }
    }
    static void Main()
    {
        int numRows = 0;
        int[][] jaggedArray = null;
        try
        {
            int choice;
            do
            {
                Console.WriteLine("Выберите способ заполнения массива:");
                Console.WriteLine("1. Случайные числа");
                Console.WriteLine("2. Ручной ввод");
                Console.WriteLine("3. Выход из программы");
                Console.Write("Ваш выбор: ");

                if (!int.TryParse(Console.ReadLine(), out choice) || choice < 1 || choice > 3)
                {
                    Console.WriteLine("Ошибка: некорректный выбор. Введите число от 1 до 3.");
                    continue;
                }
                else
                {
                    break;
                }
            } while (true);
            if (choice == 3)
            {
                Console.WriteLine("Программа завершена.");
                return;
            }
            do
            {
                Console.Write("Введите количество строк: ");
                if (!int.TryParse(Console.ReadLine(), out numRows) || numRows <= 0)
                {
                    Console.WriteLine("Ошибка: некорректное количество строк.");
                }
                else
                {
                    break;
                }
            } while (true);
            jaggedArray = new int[numRows][];
            if (choice == 1)
            {
                Random random = new Random();
                for (int i = 0; i < numRows; ++i)
                {
                    int numCols = random.Next(1, 11);
                    jaggedArray[i] = new int[numCols + 1];
                    for (int j = 1; j <= numCols; ++j)
                    {
                        jaggedArray[i][j] = random.Next(100);
                    }
                    jaggedArray[i][0] = numCols;
                }
            }
            else if (choice == 2)
            {
                for (int i = 0; i < numRows; ++i)
                {
                    int numCols;
                    do
                    {
                        Console.Write($"Введите количество элементов в строке {i + 1}: ");
                    } while (!int.TryParse(Console.ReadLine(), out numCols) || numCols < 0);
                    jaggedArray[i] = new int[numCols + 1];
                    Console.WriteLine($"Введите элементы строки {i + 1}:");
                    for (int j = 1; j <= numCols; ++j)
                    {
                        while (!int.TryParse(Console.ReadLine(), out jaggedArray[i][j]))
                        {
                            Console.WriteLine("Ошибка ввода. Введен некорректный символ. Введите элемент еще раз:");
                        }
                    }
                    jaggedArray[i][0] = numCols;
                }
            }
            else
            {
                Console.WriteLine("Неверный выбор. Программа завершена.");
                return;
            }
            Console.WriteLine("\nИсходный массив:");
            PrintJaggedArray(jaggedArray);
            // Сортировка строк по возрастанию
            for (int i = 0; i < numRows; ++i)
            {
                Array.Sort(jaggedArray[i], 1, jaggedArray[i][0]);
            }
            Console.WriteLine("\nМассив после сортировки строк по возрастанию:");
            PrintJaggedArray(jaggedArray);
            // Перестановка строк так, чтобы их длины возрастали
            Array.Sort(jaggedArray, (a, b) => a[0].CompareTo(b[0]));
            Console.WriteLine("\nМассив после перестановки строк по возрастанию длин:");
            PrintJaggedArray(jaggedArray);
        }
        //отлавливает исключения 
        catch (Exception e)
        {
            Console.WriteLine($"Ошибка: {e.Message}");
        }
        finally
        {
            FreeMemory(jaggedArray);
        }
    }
}
