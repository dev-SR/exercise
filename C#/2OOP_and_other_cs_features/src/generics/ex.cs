namespace src.generics.ex;

public interface IAnimal
{
    double Weight { get; }
    double Height { get; }
    bool HasFur { get; }
}

public record Cat(
    double Weight,
    double Height,
    bool HasFur
) : IAnimal;

public record Dog(
    double Weight,
    double Height
) : IAnimal
{
    public bool HasFur => true;
}

public record Fish(
    double Weight,
    double Height
) : IAnimal
{
    public bool HasFur => false;
}


public class AnimalService
{
    public static double CalculateWeight<T>(IEnumerable<T> animals) where T : IAnimal
    {
        var total = animals.Sum(a => a.Weight);
        return total;
    }
    public static double CalculateHeight<T>(IEnumerable<T> animals) where T : IAnimal
    {
        var total = animals.Sum(a => a.Height);
        return total;
    }

    public static IEnumerable<T> AnimalWithFur<T>(IEnumerable<T> animals) where T : IAnimal
    {
        return animals.Where(a => a.HasFur);
    }
}
