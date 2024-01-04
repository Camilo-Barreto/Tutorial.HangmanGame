#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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

void DrawHangman(int guessCounter = 0)
{
    // Draw new parts for each wrong guess
    if (guessCounter >= 1)
        PrintHeader("|", false, false);
    else
        PrintHeader("", false, false);

    if (guessCounter >= 2)
        PrintHeader("|", false, false);
    else
        PrintHeader("", false, false);

    if (guessCounter >= 3)
        PrintHeader("O", false, false);
    else
        PrintHeader("", false, false);

    if (guessCounter == 4)
        PrintHeader("/  ", false, false);

    if (guessCounter == 5)
        PrintHeader("/| ", false, false);

    if (guessCounter >= 6)
        PrintHeader("/|\\", false, false);
    else
        PrintHeader("", false, false);

    if (guessCounter >= 7)
        PrintHeader("|", false, false);
    else
        PrintHeader("", false, false);

    if (guessCounter == 8)
        PrintHeader("/  ", false, false);

    if (guessCounter >= 9)
        PrintHeader("/ \\", false, false);
    else
        PrintHeader("", false, false);
}

void PrintLetters(std::string input, char from, char to)
{
    std::string letters;
    
    // print letters using ascii values from {from} to {to}
    for (int i = from; i <= to; i++)
    {
        // if letter wasnt found print it to console as it can be used
        if (input.find(i) == std::string::npos)
        {
            letters += i;
            letters += " ";
        }
        else
        {
            // Remove the letter from available list as it was used
            letters += "  ";
        }
    }
    // Finally, print the letters available
    PrintHeader(letters, false, false);
}

void PrintAvailableLetters(std::string usedLetters)
{
    // Draw the header from design
    PrintHeader("Available letters");
    PrintLetters(usedLetters, 'A', 'M');
    PrintLetters(usedLetters, 'N', 'Z'); 
}

bool PrintWordAndCheckResult(std::string answerWord, std::string userGuess)
{
    // Assuming user won
    bool won = true;
    std::string resultPrint;

    // if word doesnt match with the guess change bool to lost
    for (int i = 0; i < answerWord.length(); i++)
    {
        if (answerWord.find(userGuess[i]) == std::string::npos)
        {
            // The letter doesnt match in both words for that position
            // The word guessed is wrong
            // So, print a blank space and change won boolean
            won = false;
            resultPrint += "_ ";
        }
        else
        {
            resultPrint += answerWord[i];
            // Add a space after the letter
            resultPrint += " ";
        }
    }
    // Print the answer with blanks and dont draw top border
    PrintHeader(resultPrint, false);

    return won;
}

std::string LoadRandomWord(std::string path)
{

    int lineCount = 0;
    
    // To store the random word
    std::string word;

    // Vector to store words from txt file
    std::vector<std::string> wordVector;

    std::ifstream reader(path);

    // If file was successfuklly opened
    if (reader.is_open())
    {
        while (std::getline(reader, word))
        {
            wordVector.push_back(word);
        }

        // Random number selector
        int randomLine = rand() % wordVector.size();

        // Using .at will check for out of bounds error and throw a expection
        // Whereas the standard way used for arrays wont check if within bounds
        word = wordVector.at(randomLine);

        // Close the reader
        reader.close();
    }
    return word;
}

int main()
{
    std::string userInput = "TEIMS";
    // Print the header
    PrintHeader("Hang Man");
    // draw the body
    DrawHangman(9);
    // Print remaining letters
    PrintAvailableLetters(userInput);
    PrintHeader("Guess the Word");
    PrintWordAndCheckResult("RHINO", userInput);

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