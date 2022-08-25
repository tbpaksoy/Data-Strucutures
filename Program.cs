using DataStructures;
using System;
namespace Program
{
    class Program
    {
        public static void Main(string[] Args)
        {
            foreach (object o in Compression.LongestCommonSubsequence("abcdef".ToCharArray(), "acbf".ToCharArray()))
            {
                Console.WriteLine(o);
            }
        }
    }
}