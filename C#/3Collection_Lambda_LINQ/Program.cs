using Collection_Lambda_LINQ.Collection.list;
using Collection_Lambda_LINQ.LINQ.demo;

// ListDemo.Test();
LINQDemo.WithOutLinq();
LINQDemo.WithLINQ();
LINQDemo.QuerySyntax();

Employee emptyFirstOrDefault = new List<Employee>().FirstOrDefault();
Console.WriteLine(emptyFirstOrDefault is null);//true

var employees = LINQDemo.GetEmployees();
try
{
    var singleEmployeeDuplicateOrDefault = employees.SingleOrDefault(e => e.Department == "HR");
}
catch (InvalidOperationException e)
{
    Console.WriteLine($"Error: {e.Message}");//"Error: Sequence contains more than one element"
}