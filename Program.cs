using DataStructures;
using System;
namespace Program
{
    class Program
    {
        public static void Main(string[] Args)
        {
            int[] array = new int[] { 65, 4, 6514, 32, 165, 4, 894, 132, 1698, 43, 51, 8961, 35, 163, 2 };
            foreach (int i in array) Console.Write(i + ",");
            Console.WriteLine();
            Sorting.BuildMaxHeap(ref array, Array.IndexOf(array, array.Min()));
            foreach (int i in array) Console.Write(i + ",");
            Console.WriteLine();
            for (int i = 0; i * 2 + 2 < array.Length; i++)
            {
                Console.WriteLine(array[i] + "->" + array[2 * i + 1] + "," + array[2 * i + 2]);
            }
        }
    }
}