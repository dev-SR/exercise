using System.Reflection;

namespace src.Reflection.ex;

public class Product
{
    public Guid Id { get; set; }
    public string Name { get; set; }
    public double Price { get; set; }

    public string GetProductDetails()
    {
        return $"{Name}: {Price:C}";
    }
}

public class ReflectionDemo
{
    public static void example()
    {
        // Create an instance of Product
        var product = new Product
        {
            Id = Guid.NewGuid(),
            Name = "Laptop",
            Price = 1200.50
        };

        // Get the Type of the object
        Type type = product.GetType();
        Console.WriteLine($"Type: {type.Name}\n");

        // Get all properties of the Product class
        Console.WriteLine("Properties:");
        foreach (var property in type.GetProperties())
        {
            Console.WriteLine($"- {property.Name} ({property.PropertyType.Name})");
        }

        // Get and display the value of a specific property
        var nameProperty = type.GetProperty("Name");
        if (nameProperty != null)
        {
            var nameValue = nameProperty.GetValue(product);
            Console.WriteLine($"\nValue of 'Name': {nameValue}");
        }

        // Get all methods of the Product class
        Console.WriteLine("\nMethods:");
        foreach (var method in type.GetMethods(BindingFlags.Public | BindingFlags.Instance))
        {
            Console.WriteLine($"- {method.Name}");
        }

        // Invoke a specific method
        var getDetailsMethod = type.GetMethod("GetProductDetails");
        if (getDetailsMethod != null)
        {
            var details = getDetailsMethod.Invoke(product, null);
            Console.WriteLine($"\nInvoked 'GetProductDetails': {details}");
        }
    }
}