#include "headers.h"

int A1 = 1;
int A2;
int B1; 
int B2 = 1;
// A: 1^0 B: 0^1 

int TestNumber = 1;
double AResults;
double BResults; 

int FileWrite()
{

    std::ofstream outputFile("results.txt", std::ios::app); 
      // Check if the file is open
    if (outputFile.is_open())
    {    
    
        // Write the results to the file
        outputFile << "Test Number: " << TestNumber << "\n\n"
        << " A1= " << A1 << "\n\n" << " A2= " << A2 << "\n\n" << " A Results are: " << AResults
        << "\n\n" << " B1= " << B1 << "\n\n" << " B2= " << B2 << "\n\n" << " B Results are: " << BResults << "\n\n";
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
    // std::remove("results.txt"); use this if you need to iterate quickly
    std::ofstream outputFile("results.txt", std::ios::app);

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
        AResults = pow(A1,A2);
        BResults = pow(B1,B2);
        FileWrite();    

        if(AResults > BResults) // adds 1 and runs the test again
        {
            A1++;
            A2++;
            B1++;
            B2++;
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
