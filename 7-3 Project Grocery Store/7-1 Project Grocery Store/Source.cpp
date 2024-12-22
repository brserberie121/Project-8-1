#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

class CornerGrocer {
private:
    map<string, int> itemFrequency;

    void LoadDataFromFile(const string& fileName) {
        ifstream inputFile(fileName);
        string item;
        while (inputFile >> item) {
            itemFrequency[item]++;
        }
        inputFile.close();
    }

    void SaveDataToFile(const string& fileName) {
        ofstream outputFile(fileName);
        for (const auto& entry : itemFrequency) {
            outputFile << entry.first << " " << entry.second << endl;
        }
        outputFile.close();
    }

public:
    CornerGrocer(const string& inputFileName, const string& outputFileName) {
        LoadDataFromFile(inputFileName);
        SaveDataToFile(outputFileName);
    }

    void DisplayItemFrequency(const string& item) {
        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            cout << "The item '" << item << "' was purchased " << it->second << " times." << endl;
        }
        else {
            cout << "The item '" << item << "' was not purchased." << endl;
        }
    }

    void DisplayAllFrequencies() {
        cout << left << setw(15) << "Item" << "Frequency" << endl;
        cout << "---------------------------" << endl;
        for (const auto& entry : itemFrequency) {
            cout << left << setw(15) << entry.first << entry.second << endl;
        }
    }

    void DisplayHistogram() {
        cout << "Item Frequency Histogram:" << endl;
        for (const auto& entry : itemFrequency) {
            cout << left << setw(15) << entry.first << string(entry.second, '*') << endl;
        }
    }
};

void DisplayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Search for an item's frequency" << endl;
    cout << "2. Display all items and their frequencies" << endl;
    cout << "3. Display a histogram of item frequencies" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    const string inputFileName = "CS210_Project_Three_Input_File.txt";
    const string outputFileName = "frequency.dat";

    CornerGrocer grocer(inputFileName, outputFileName);

    int choice;
    do {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string item;
            cout << "Enter the item you wish to search for: ";
            cin >> item;
            grocer.DisplayItemFrequency(item);
            break;
        }
        case 2:
            grocer.DisplayAllFrequencies();
            break;
        case 3:
            grocer.DisplayHistogram();
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
