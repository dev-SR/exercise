namespace src.oop_basic.ex;

public class Person
{
    private string _name = "init"; //Fields
    public string ImmutableName1 => _name;//The `=>` syntax denotes that this property is a read-only computed property. ex: public string FullName => $"{FirstName} {LastName}";
    // Creates a private backing field under the hood
    public string ImmutableName2 { get; } = "immutable";// Immutable property, typically set in constructor
    public string? MutableName { get; set; }    // Creates a private backing field under the hood
    public string Name { get; init; }
    public int Age { get; init; }
    public override bool Equals(object obj)
    {
        if (obj == null || GetType() != obj.GetType()) return false; //here, GetType() == this.GetType()
        Person other = (Person)obj;
        return Name == other.Name && Age == other.Age;
    }

    public override int GetHashCode() //
    {
        return HashCode.Combine(Name, Age);
    }
    public override string ToString()
    {
        return $"Person(Name:{Name},Age:{Age})";
    }
}
