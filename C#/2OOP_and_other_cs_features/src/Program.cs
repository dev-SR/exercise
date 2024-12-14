// See https://aka.ms/new-console-template for more information
using src.Inheritance.ex;
using src.oop_basic.ex;


// Person person = new Person("Jhon",25);
// or
// Person person = new("Jhon", 25);
// Person person = new Person { Name = "Jhon", Age = 25 };
//or
// Person person = new() { Name = "Jhon", Age = 25 };
// Console.WriteLine(person);

// Person person1 = new Person { Name = "John Doe", Age = 30 };
// Person person2 = new Person { Name = "John Doe", Age = 30 };

// Console.WriteLine(person1 == person2);
// Console.WriteLine(person1.Equals(person2));

// Console.WriteLine(person.ImmutableName1);//init
// Console.WriteLine(person.ImmutableName2);//immutable
// person.MutableName = "muting...";
// Console.WriteLine(person.MutableName);//muting...

internal class Program
{
    private static void Main(string[] args)
    {
        Car sedan = new() { DoorCount = 4 };
        Car coupe = new() { DoorCount = 2 };
        Truck pickupTruck = new() { DoorCount = 2 };
        Bike bike = new();

        sedan.OpenDoors();//src.Inheritance.ex.Car opening 4 doors
        coupe.OpenDoors();//src.Inheritance.ex.Car opening 2 doors
        pickupTruck.OpenDoors();//src.Inheritance.ex.Truck opening 2 doors
        bike.OpenDoors();//src.Inheritance.ex.Bike opening 0 doors

        // polymorph
        Vehicle car = new Car();
        Vehicle Bike = new Bike();
        Vehicle plane = new Plane();

        Person person = new("Jhon", 20);
    }
}

public record Person(string Name, int Age);
