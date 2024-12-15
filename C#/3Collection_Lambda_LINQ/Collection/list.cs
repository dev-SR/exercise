using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Collection_Lambda_LINQ.Collection.list;

public class ListDemo
{
    public static void Test()
    {
        List<string> list = new() { "a", "b", "c" };
        list.Insert(1, "x");

        foreach (string item in list)
        {
            Console.WriteLine(item);
        }


    }

}