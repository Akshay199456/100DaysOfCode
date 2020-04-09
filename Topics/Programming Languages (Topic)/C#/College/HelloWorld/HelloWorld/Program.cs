using System;
using LaYumba.Functional;
using static LaYumba.Functional.F;

namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
            Option<int> age = Some(23);
            string ageFunc(Option<int?> agegreeting) => agegreeting.Match(None: () => "hey hey!", Some: (num) => $"Your age is {num}");
            Console.WriteLine("Hello World!");
            Console.WriteLine(ageFunc(23));
            Console.WriteLine(ageFunc(None));
        }
    }
}
