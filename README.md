# GroceryItemTracker

Project Summary:

I created a C++ program for a grocery item tracker in this project. The program allows users to load and save item frequencies, search for items, print item frequencies, and generate a histogram of item frequencies.

What Was Done Well:

- Implemented a functional grocery item tracker with a clear menu and options for the user.
- Proper encapsulation and separation of concerns through the use of a class.
- Error handling for user input to prevent the program from getting stuck in a loop.

Possible Code Enhancements:

- Improved user input validation, including handling non-integer inputs more gracefully.
- Adding more comments and documentation for better code readability.
- Expanding the program's functionality, such as the ability to edit item frequencies or handle multiple input files.

Challenging Code Pieces:

- Handling user input errors and preventing the program from going into an infinite loop was a challenge. This was overcome by using cin.fail(), cin.clear(), and cin.ignore() to handle input errors.
- Creating a histogram with left-aligned item names was also challenging. It was solved by calculating the maximum item name width for proper alignment.

Transferable Skills:

- Input validation and error handling are important skills that can be applied in various programming projects.
- Object-oriented programming concepts, such as encapsulation, can be utilized in other software development tasks.
- Reading and writing to files and data handling are common skills used in various applications.

Maintainability, Readability, and Adaptability:
- The code has been organized into a class, separating different functionalities and making it more modular and maintainable.
- Descriptive function and variable names have been used to improve code readability.
- Error-handling mechanisms have been added to make the program more adaptable and robust when dealing with various types of input or issues.
