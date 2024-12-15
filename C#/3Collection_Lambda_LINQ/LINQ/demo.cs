using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Collection_Lambda_LINQ.LINQ.demo;
public class Employee
{
    public int Id { get; set; }
    public string Name { get; set; }
    public int Age { get; set; }
    public double Salary { get; set; }
    public string Department { get; set; }
}

public class LINQDemo
{
    private static List<Employee> employees = GetEmployees();
    public static List<Employee> GetEmployees()
    {
        return new List<Employee>
                {
                    new Employee { Id = 1, Name = "Alice", Age = 25, Department = "HR", Salary = 120000 },
                    new Employee { Id = 2, Name = "Bob", Age = 30, Department = "IT", Salary = 95000 },
                    new Employee { Id = 3, Name = "Charlie", Age = 28, Department = "Finance", Salary = 105000  },
                    new Employee { Id = 4, Name = "Diana", Age = 35, Department = "IT", Salary = 75000  },
                    new Employee { Id = 5, Name = "Eve", Age = 22, Department = "HR", Salary = 130000 }
                };
    }

    public static void WithOutLinq()
    {

        List<Employee> highEarners = new List<Employee>();

        foreach (var employee in employees)
        {
            if (employee.Salary > 100000)
            {
                highEarners.Add(employee);
            }
        }

        highEarners.Sort((emp1, emp2) => emp1.Name.CompareTo(emp2.Name));

        foreach (var highEarner in highEarners)
        {
            Console.WriteLine(highEarner.Name);
        }
    }

    public static void WithLINQ()
    {
        var highEarners = employees
                            .Where(e => e.Salary > 100000)
                            .OrderBy(e => e.Name)
                            .Select(e => e.Name);
        foreach (var name in highEarners)
        {
            Console.WriteLine(name);
        }
    }
    public static void QuerySyntax()
    {
        var highEarners = from e in employees
                          where e.Salary > 100000
                          orderby e.Name
                          select e.Name;

        foreach (var name in highEarners)
        {
            Console.WriteLine(name);
        }
    }
}