#include <iostream>
#include <fstream>
#include <windows.h>
#include <cmath>
// Libraries for maths and sending numbers to console and text doc

int A1 = 0;
int A2 = 0;

int B1 = 0;
int B2 = 0;

int TestNumber = 1;
int ExitProgram = 0;

double AResults = 0;
double BResults = 0;
// Sets the two numbers to be used in powers swap comparison, a number to keep track of current test and track when a user wants to exit the program
// Key: 1 = Integer, 2 = Power

 int FileTitle()
 {

    if (TestNumber == 1)
        {
        std::ofstream outputFile("results.txt", std::ios::app);

            if (outputFile.is_open())
            {
            outputFile << "Test for when or if B would be come bigger than A when made to a power" << "\n\n\n\n";

            outputFile.close();
            }
            else
            {
                std::cerr << "Can't open file to write to" << std::endl;
            }

        }
    return 0;
 }
int FileWrite()
{
        // Open a text file for writing
    std::ofstream outputFile("results.txt", std::ios::app);

    // Check if the file is open
    if (outputFile.is_open())
    {
        // Write the results to the file
        outputFile << "Test Number: " << TestNumber << "\n\n"
                   << " A1= " << A1 << "\n\n" << " A2= " << A2 << "\n\n" << " A Results are: " << AResults
                   << "\n\n" << " B1= " << B1 << "\n\n" << " B2= " << B2 << "\n\n" << " B Results are: " << BResults << "\n\n";

        // Close the file
        outputFile.close();
    }
    else
    {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }

    return 0;


 }



int mainop()
{

   FileTitle();

    A1 = A1 + 1;
    B2 = B2 + 1;
    // Starts of the swap by adding 1 to A and 1 to B

    Reset:
    // Check line 39 for what triggers this
    AResults = pow(A1,A2);

    BResults = pow(B1,B2);
    // Sets the results to be placed in to a separate variable to be used in displaying results

    std::cout << "Test Number: " << TestNumber << "\n\n"
                   << " A1= " << A1 << "\n\n" << " A2= " << A2 << "\n\n" << " A Results are: " << AResults
                   << "\n\n" << " B1= " << B1 << "\n\n" << " B2= " << B2 << "\n\n" << " B Results are: " << BResults << "\n\n";
    //makes the menu for each gen of the power comparison and writes out the variables and results into console

    FileWrite();

    if(AResults > BResults)
    // Checks if A is bigger than B
    {
        TestNumber = TestNumber + 1;

        A1 = A1 + 1;
        A2 = A2 + 1;

        B1 = B1 + 1;
        B2 = B2 + 1;
        // Adds plus one to all power variable and test number to continue the chain
          FileWrite();
                goto Reset;
        // Goes back to the start of the chain to start the test
        // See line 24 for where this restarts
 }
    FileWrite();
    std::cout << "Test Complete and written to results\nType 1 to close program\n\n";
    std::cin >> ExitProgram;
    if (ExitProgram == 1)
    {
        return 0;
    }

    else

    {
        std::cout << "\n\n";
        ExitProgram -= ExitProgram;
        std::cout << "Error, Please rewrite your choice\n\n"
                << "Type 1 to close the program\n\n";
        std::cin >> ExitProgram;
    }

}

