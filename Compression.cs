using System.Collections;
using System;
public static class Compression
{
    public static Array LongestCommonSubsequence(Array a, Array b)
    {
        int[,] temp = new int[a.Length + 1, b.Length + 1];
        for (int i = 0; i < a.Length; i++)
        {
            for (int j = 0; j < b.Length; j++)
            {
                if (a.GetValue(i).Equals(b.GetValue(j)))
                {
                    temp[i + 1, j + 1] = temp[i, j] + 1;
                }
                else
                {
                    temp[i + 1, j + 1] = (int)MathF.Max(temp[i + 1, j], temp[i, j + 1]);
                }
            }
        }
        for (int i = 0; i < temp.GetLength(0); i++)
        {
            for (int j = 0; j < temp.GetLength(1); j++)
            {
                Console.Write(temp[i, j] + " ");
            }
            Console.WriteLine();
        }
        ArrayList list = new ArrayList();
        int x = temp.GetLength(0) - 1, y = temp.GetLength(1) - 1;
        while (x > 0 && y > 0)
        {
            if (temp[x, y] == temp[x - 1, y - 1] + 1)
            {
                list.Add(b.GetValue(y - 1));
                x--;
                y--;
            }
            while (y > 0 && temp[x, y] == temp[x, y - 1]) y--;
        }
        list.Reverse();
        return list.ToArray();
    }
}