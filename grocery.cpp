#include <iostream>
#include "grocery.h"

using namespace std;

int main () {
    GroceryItemTracker tracker;
    int choice = 0;

   tracker.itemFrequency = tracker.LoadFile(tracker.inFileName);
   tracker.SaveFile();
   
   while (choice != 4) {
        choice = tracker.PrintMenu();

        if (std::cin.fail()) {
            
            cin.clear(); // Clear the fail state
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            choice = 0;
        }

        switch (choice) {
            case 1:{
                
                cout << tracker.SearchItem();
                choice = 0;
                
                break;
            }
            case 2:{
                
                tracker.PrintItems();
                
                break;
            }
            case 3:{
                
                tracker.printItemHistogram();
                
                break;
            }
            case 4:{
                
                cout << "\nGoodbye\n\n";
                
                break;
            } 
            default: {
                cout << "\nInvalid choice. Please choose a valid option.";
            }
    }
   }
    
    return 0;
}
