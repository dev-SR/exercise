using System;


namespace _1basic.string_ex
{
    public class StringIntro
    {

        public static void StringDemo()
        {
            PatternMatching1();

        }
        private static void PatternMatching1()
        {
            string? a = null;
            if (a is null)
                Console.WriteLine("The value is null."); //✔
            else
                Console.WriteLine("The value is not null.");

            string b = "";
            if (b is null)
                Console.WriteLine("The value is null.");
            else
            {
                Console.WriteLine("The value is not null.");//✔
                if (b == string.Empty)
                {
                    Console.WriteLine("is not null but Empty");//✔
                }
                if (string.IsNullOrEmpty(b))
                {
                    Console.WriteLine("Null or Empty");//✔
                }
                if (string.IsNullOrWhiteSpace(b))
                {
                    Console.WriteLine("Null, Empty or Whitespace Char");//✔
                }
            }

            string[] arr = [];
            if (arr is null)
            {
                Console.WriteLine("1.Array is empty");
            }
            else if (arr.Length == 0)
            {
                Console.WriteLine("2.Array is empty");//✔
            }
        }
    }
}