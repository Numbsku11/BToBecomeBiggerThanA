#include <iostream>
#include <fstream>
#include <windows.h>
#include <cmath>

int A1 = 1;
int A2 = 0;

int B1 = 0;
int B2 = 1;

int TestNumber = 1;
int ExitProgram = 0;

double AResults = 0;
double BResults = 0;

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

        // Close the file
        outputFile.close();
    }

    else
    {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }
}


int main()
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
    while (TRUE)
    {

    AResults = pow(A1,A2);
    BResults = pow(B1,B2);

    std::cout << AResults << "\n\n" << BResults;

    FileWrite();

    if(AResults > BResults)
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

}

