# Misc topics in C#

- [Misc topics in C#](#misc-topics-in-c)
  - [Working with JSON](#working-with-json)
    - [Newtonsoft.Json](#newtonsoftjson)
    - [System.Text.Json](#systemtextjson)
    - [Comparing Newtonsoft.Json and System.Text.Json](#comparing-newtonsoftjson-and-systemtextjson)
      - [JsonConvert vs. JsonSerializer](#jsonconvert-vs-jsonserializer)
      - [Weirdness with JSON Converters](#weirdness-with-json-converters)
    - [Which Should You Use?](#which-should-you-use)

## Working with JSON


There are two common libraries for working with JSON in .NET:

- **Newtonsoft.Json**: A popular and widely used library for handling JSON in .NET applications. Has been around for a long time and is found in many existing applications.
- **System.Text.Json**: A newer library introduced in .NET Core 3.0 that focuses on performance improvements, accuracy, and security.

### Newtonsoft.Json

- **Older but Very Common**: Newtonsoft.Json, also known as Json.NET, is a popular and widely used library for handling JSON in .NET applications.
- **Relaxed and Forgiving**: Known for its ability to handle various JSON formats and scenarios, including some that might be less strictly defined (like JSON with comments).

Key Features:
- **JsonConvert**: A class that provides static methods for converting JSON to and from .NET objects.

Example usage:

```csharp
var employee = new Employee
{
    Id = 1,
    FirstName = "John",
    LastName = "Doe",
    Age = 30
};

var json = JsonConvert.SerializeObject(employee);

var johnReborn = JsonConvert.DeserializeObject<Employee>(json);
```

### System.Text.Json

- **Emphasizes Speed, Accuracy, Exactness, Security**: System.Text.Json is a newer library introduced in .NET Core 3.0. It focuses on performance improvements, accuracy, and security.

Key Features:

- **JsonSerializer**: A class that provides methods for serializing and deserializing JSON data.

Example usage:

```csharp
var employee = new Employee
{
    Id = 1,
    FirstName = "John",
    LastName = "Doe",
    Age = 30
};

var json = JsonSerializer.Serialize(employee);
var johnReborn = JsonSerializer.Deserialize<Employee>(json);
```

### Comparing Newtonsoft.Json and System.Text.Json

#### JsonConvert vs. JsonSerializer

- **JsonConvert**: Comes from Newtonsoft.Json and provides a flexible API for JSON operations.
- **JsonSerializer**: Comes from System.Text.Json and offers high-performance serialization and deserialization.

#### Weirdness with JSON Converters

- **Enums**: Enums in JSON are typically serialized as their base types (e.g., integers) unless explicitly configured to be serialized differently.

**Note**: In an integrated world, it's best to configure your JSON serializers to send enums as strings.

### Which Should You Use?

- **Greenfield Projects**: Use **System.Text.Json** for new projects to leverage its performance and security benefits.
- **Existing Projects**: **Newtonsoft.Json** is still fine for ongoing projects, but consider migrating to **System.Text.Json** as you update your applications. However, most of the time, there are bigger issues to tackle.
- **Avoid Mixing Libraries**: To prevent developer confusion and integration issues, it’s best not to mix **Newtonsoft.Json** and **System.Text.Json** in the same project if you can avoid it.

**Caution**: If the project is using **Newtonsoft.Json** already, avoid introducing **System.Text.Json** unless you really need the extra performance.