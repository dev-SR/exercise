using _1basic.exception_handle.handle;
using _1basic.string_ex;


internal class Program
{
    private static void Main(string[] args)
    {
        // StringIntro.StringDemo();
        HandleException.CustomErrorWithFiltering();
        int[] nums = [1, 2, 3];
        Console.WriteLine(String.Join('-', nums));

    }
}

