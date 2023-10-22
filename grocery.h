#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class GroceryItemTracker{
public:    
    map<string, int> itemFrequency;             // Store item frequencies
    const string inFileName = "freq.txt";       // input data file name
    const string outFileName = "frequency.dat"; // output data file name

    map<string, int> LoadFile(const string &FileName){
        string item;

        // Try to open file
        cout << "Opening file freq.txt." << endl;

        ifstream inputFile(FileName);

        if (!inputFile.is_open()){ // If file is not open
            cout << "Could not open file freq.txt." << endl; // Give error message if file cannot be opened.
        }

        else {
            cout << "file opened sucessfully." << endl; // Give sucess message if file is opened sucessfully.

            while (inputFile >> item) { // Read data from the input file  word by word
                transform(item.begin(), item.end(), item.begin(), ::tolower);
                ++itemFrequency[item]; // increment the frequency of each item.
            }

            inputFile.close(); // Close file.
        }

        return itemFrequency;
    }

    void SaveFile(){

        ofstream outputFile(outFileName); // Open new file .
        
        if (!outputFile.is_open()) {  // If file is not open...
            cout << "Could not open new file frequency.dat." << endl; // Give error message if file cannot be opened.
        }
        
        else {
            cout << "New file opened sucessfully";

            // Save item frequencies to new file
            for (map<string, int>::iterator itr = itemFrequency.begin(); itr != itemFrequency.end(); ++itr)
            {
                outputFile << itr->first << " " << itr->second << endl;
            }

            outputFile.close(); // Close file.
        }
    }

    void PrintItems(){

        cout << "\n\nPrinting item frequency...\n\n";
        
        // Iterate through item frequencies and print item by item 
        for (map<string, int>::iterator itr = itemFrequency.begin(); itr != itemFrequency.end(); ++itr) {
            cout << itr->first << " " << itr->second << endl;
        }
    }

    int SearchItem(){
        string item;

        // Get user input
        cout << "\nPlease enter the item you would like to search for: ";
        cin >> item;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer to prevent issues with subsequent inputs.
        transform(item.begin(), item.end(), item.begin(), ::tolower); // Convery user input to all lowercase so search is not case sensitive
        item.erase(remove_if(item.begin(), item.end(), ::isspace), item.end()); // Remove any spaces
        
        cout << "\n" << item << " frequency: ";

        // Return the frequency of the item
        return itemFrequency[item];
    }

    void printItemHistogram(){
        int maxItemNameWidth = 0;

        cout << "Histogram of Item Frequency\n";

        // Set width of item column for formatting reasons.
        for (map<string, int>::iterator itr = itemFrequency.begin(); itr != itemFrequency.end(); ++itr)
        {
            int itemNameWidth = static_cast<int>(itr->first.length()); // Convert to int without loss of precision
            if (itemNameWidth > maxItemNameWidth)
            {
                maxItemNameWidth = itemNameWidth;
            }
        }

        // Print histogram with proper column width
        for (map<string, int>::iterator itr = itemFrequency.begin(); itr != itemFrequency.end(); ++itr)
        {
            cout << left << setw(maxItemNameWidth) << itr->first << " ";
            for (int i = 0; i < itr->second; i++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
   
    int PrintMenu(){
        int choice;

        cout << "\n\nMenu:\n";
        cout << "1. Search for an item\n";
        cout << "2. Print item frequencies\n";
        cout << "3. Print item histogram\n";
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        return choice;
    }

};
