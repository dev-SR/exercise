## Introduction to Dotnet with C#

- [Introduction to Dotnet with C#](#introduction-to-dotnet-with-c)
  - [Dotnet Tooling Overview](#dotnet-tooling-overview)
    - [Install the dotnet CLI](#install-the-dotnet-cli)
    - [Setup Visual Studio Code](#setup-visual-studio-code)
    - [Using the dotnet CLI](#using-the-dotnet-cli)
    - [Creating new project with solutions](#creating-new-project-with-solutions)


### Dotnet Tooling Overview

#### Install the dotnet CLI

1. Download and install the .NET SDK from the official `.NET` website: [https://dot.net](https://dot.net)
2. Verify the installation by opening a terminal and running:


```bash
dotnet --version
# You should get the version number of the .NET SDK installed on your system.
```


#### Setup Visual Studio Code


To enhance your .NET development experience in VS Code, install following extensions:

- `C#`, `C# Dev Kit`, `C# Extensions` - JosKreativ, `NuGet Gallery` - pcislo



#### Using the dotnet CLI

The .NET Command Line Interface (CLI) is a cross-platform tool for developing, building, running, and publishing .NET applications. Here are some essential commands:

- **To list all available templates**:

    ```bash
    dotnet new list
    ```

    Narrow down by related tags, i.e `web` tag for web related templates
        
    ```bash
    dotnet new list web 
    ```

- `dotnet new`: **Creates a new project, configuration file, or solution based on the specified template.**

    example: 
    ```bash 
    cd Project
    dotnet new console -n MyConsoleApp -o src
    cd src
    dotnet run
    ```
    
    ```bash
          ~Project
          │
          ├── *src
          │   └── *MyConsoleApp.csproj
          │   └── Program.cs
    ```

        
    Common templates include:

    - `console`: Console application
    - `classlib`: Class library
    - `web`: ASP.NET Core empty web app
    - `webapi`: ASP.NET Core Web API
    - `mvc`: ASP.NET Core Web App (Model-View-Controller)
    - `blazorserver`: Blazor Server App
    - `blazorwasm`: Blazor WebAssembly App
    - `wpf`: Windows Presentation Foundation (WPF) Application
    - `winforms`: Windows Forms Application


- To install additional templates:

```bash 
dotnet new install <TEMPLATE_PACKAGE_NAME>
``` 

- For example, to install the `Microsoft.AspNetCore.SpaTemplates`:

```bash 
dotnet new install Microsoft.AspNetCore.SpaTemplates
``` 

- `dotnet build`: Builds a .NET project and all its dependencies.
- `dotnet run`: Runs source code without any explicit compile or launch commands.
- `dotnet watch run`: (in watch mode) Runs source code without any explicit compile or launch commands.
- `dotnet restore`: Restores the dependencies and tools of a project.
- `dotnet test`: Runs unit tests using the test runner specified in the project.
- `dotnet publish`: Publishes the application and its dependencies for deployment.

```bash 
dotnet publish -c Release
```

#### Creating new project with solutions

Although a `.sln` (solution) file in .NET is not strictly necessary for building or running individual projects, but it is essential when working with multiple projects in a structured way and most importantly to enable IntelliSense for vscode.


To create a solution and a console application in .NET using the CLI, follow these steps:

- Step 1: Create a New Solution  
  
```bash
dotnet new sln -n MySolution
```
`-n MySolution` specifies the name of the solution. This creates a file named `MySolution.sln`.

- Step 2: Create a Console Application  

Run the following command to create a new console application:  
```bash
dotnet new console -n MyConsoleApp -o src
```

`-n MyConsoleApp` specifies the name of the console application. `-o src` creates a directory `src` containing the application files.


- Step 3: Add the Console Application to the Solution  
To add the console project to the solution, run:  
```bash
dotnet sln MySolution.sln add src/MyConsoleApp.csproj
```

After running the above commands, your directory structure will look like this:  
```
Proj/
├── MySolution.sln
├── src/
│   ├── MyConsoleApp.csproj
│   ├── Program.cs
```

-  Step 4: Restore and Build the Solution  

Restore dependencies and build the solution using the following commands:  
```bash
dotnet restore
# or
dotnet restore MySolution.sln
dotnet build
```

- Step 5: Run the Console Application  

**Navigate to the `src` directory** and execute the following command:  

```bash
cd src
dotnet run
```
