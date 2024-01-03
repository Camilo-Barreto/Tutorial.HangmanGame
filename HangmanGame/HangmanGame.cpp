#include <iostream>

void PrintHeader(std::string message, bool printTop = true, bool printBottom = true)
{
    // The following will print the top of the header
    // else just print the border
    if (printTop)
    {
        std::cout << "+---------------------------------+" << std::endl;
        std::cout << "|";
    }
    else
    {
        std::cout << "|";

    }
    // Use a boolean to keep alternately add spaces around the message to center it
    bool front = true;

    // iterate back and forth to add the spaces to center the message
    // Start counter i at the message length to stay within the 33 char limit
    for (int i = message.length(); i < 33; i++)
    {
        // first add a space to the front
        if (front)
        {
            message = " " + message;
        }
        // else add space to the end
        else
        {
            message = message + " ";
        }
        // to alternate back and forth, perform the not operation on the bool
        front = !front;

        //// DEBUGGING - visualise the spaces added back and forth (comment later)
        //std::cout << message << std::endl;
    }

    // Print the actual message 
    std::cout << message; 

    // Now close the header box as per the GUI visualisatuion below
    // else if not needed just print the border
    if (printBottom)
    {
        std::cout << "|" << std::endl; // use endl to move to the next line 
        std::cout << "+---------------------------------+" << std::endl;
    }
    else
    {
        std::cout << "|" << std::endl;
    }
 }

int main()
{
    PrintHeader("Hang Man");

    return 0;

}

/*
            Game GUI Visualisation

    +---------------------------------+
    |             HANG MAN            |
    +---------------------------------+
    |               |                 |
    |               |                 |
    |               O                 |
    |              /|\                |
    |               |                 |
    |              / \                |
    |         +----------+            |
    |         |          |            |
    +---------------------------------+
    |        Available letters        |
    +---------------------------------+
    |     A B C D E F G H I J K L M   |
    |     N O P Q R S T U V W X Y Z   |
    +---------------------------------+
    |         Guess the word          |
    +---------------------------------+
    | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
    +---------------------------------+
    >

*/