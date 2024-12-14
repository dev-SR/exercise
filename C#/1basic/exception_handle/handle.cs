namespace _1basic.exception_handle.handle;


public class CustomException : Exception
{
    public int ErrorCode { get; set; }

    public CustomException(string message, int errorCode) : base(message)
    {
        ErrorCode = errorCode;
    }
}


public class HandleException
{

    public static void CustomErrorWithFiltering()
    {
        try
        {
            // Simulate an error
            throw new CustomException("This is a critical error", 500);
        }
        catch (CustomException ex) when (ex.ErrorCode == 500)
        {
            Console.WriteLine($"Critical error: `{ex.Message}`, code {ex.ErrorCode}");//✔
        }
        catch (CustomException ex)
        {
            Console.WriteLine($"Other error: {ex.Message}");
        }


    }
}

