using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Collection_Lambda_LINQ.Collection.list;

public class ListDemo
{
    public static void Test()
    {
        List<int> numbers = new List<int> { 1, 2, 3, 4, 5, 6, 8, 10 };
        var evenNumbers = GetEvenNumbers(numbers).Take(3);//LINQ integration

        foreach (var number in evenNumbers)
        {
            Console.WriteLine(number);
        }

        evenNumbers = GetEvenNumbersList(numbers).Take(3);//

        foreach (var number in evenNumbers)
        {
            Console.WriteLine(number);
        }
    }
    static IEnumerable<int> GetEvenNumbers(IEnumerable<int> numbers)
    {
        foreach (var number in numbers)
        {
            if (number % 2 == 0)
                yield return number; // Deferred execution
        }
    }



    static List<int> GetEvenNumbersList(IEnumerable<int> numbers)
    {
        List<int> _result = new();
        foreach (var number in numbers)
        {
            if (number % 2 == 0)
            {
                _result.Add(number);
            }
        }
        return _result;
    }
}


