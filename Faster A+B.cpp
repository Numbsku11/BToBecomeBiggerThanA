#include "headers.h"

int TestNumber = 1;
struct{
    int Integer;
    int Powers;
    double Results;
    // A: 1^0 B: 0^1 
}A, B;

int FileWrite()
{

    std::ofstream outputFile("results.txt", std::ios::app); 
      // Check if the file is open
    if (outputFile.is_open())
    {    
    
        // Write the results to the file
        outputFile << "Test Number: " << TestNumber << "\n\n"
        << " A1= " << A.Integer << "\n\n" << " A2= " << A.Powers << "\n\n" << " A Results are: " << A.Results
        << "\n\n" << " B1= " << B.Integer << "\n\n" << " B2= " << B.Powers << "\n\n" << " B Results are: " << B.Results << "\n\n";
        outputFile.close();
    }

    else
    {
        std::cerr << "Unable to open the file for writing." << std::endl;
        // if you get this, something fucked up
    }

    return 0;
}

int main()
{
    //std::remove("results.txt"); // use this if you need to iterate quickly
    std::ofstream outputFile("results.txt", std::ios::app);
    A.Integer++;
    B.Powers++;
    
    if (outputFile.is_open())
    {
        outputFile << "Test for when or if B would be come bigger than A when made to a power\n\n\n\n";
        outputFile.close();
        // header infomation
    }
    else
    {
        std::cerr << "Can't open file to write to" << std::endl;
    }

    while (TRUE)
    {


        // calculates the powers into a whole number 
        A.Results = pow(A.Integer,A.Powers);
        B.Results = pow(B.Integer,B.Powers);
        FileWrite();    

        if(A.Results > B.Results) // adds 1 and runs the test again
        {
            A.Integer++;
            A.Powers++;
            B.Integer++;
            B.Powers++;
            TestNumber++;
        }
        else
        {
        break;
        }
    }
    
    std::cout <<"Press any key to close the program";
    std::cin.get();
    return 0;
}
