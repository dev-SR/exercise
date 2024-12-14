namespace src.Inheritance.ex;

public class Vehicle
{
    public int DoorCount { get; init; }

    public void OpenDoors()
    {
        Console.WriteLine($"{GetType()} opening {DoorCount} doors");
    }
}


public class AutoMobile : Vehicle { }
public class Car : AutoMobile { }
public class Truck : AutoMobile { }
public class Van : AutoMobile { }

public class Bike : Vehicle { }
public class Plane : Vehicle { }