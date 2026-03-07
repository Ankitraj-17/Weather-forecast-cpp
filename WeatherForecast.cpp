#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// The WeatherData class acts as a blueprint for a single city.
// It keeps its variables 'private' so other parts of the code can't
// accidentally break them. We use public 'getter' functions to safely read the
// data when needed.
// ------------------------------------------------------------------------------------------------
class WeatherData {
private:
  // These variables hold the actual information for each city
  string cityName;
  double temperature;
  double humidity;

public:
  // Default Constructor: Creates a blank city if no exact details are given
  WeatherData() : cityName(""), temperature(0.0), humidity(0.0) {}

  // Parameterized Constructor: Sets the city details instantly when the object
  // is created
  WeatherData(string city, double temp, double hum) {
    cityName = city;
    temperature = temp;
    humidity = hum;
  }

  // Getters: Public functions that return the private data safely (Read-only
  // access)
  string getCityName() const { return cityName; }
  double getTemperature() const { return temperature; }
  double getHumidity() const { return humidity; }

  // This method prints out this specific city's data in the required format
  void displayFormattedOutput() const {
    cout << "\n+---------------------------------------+" << endl;
    cout << "|             WEATHER REPORT            |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "| City       : " << setw(24) << left << cityName << "|" << endl;
    cout << "| Temperature: " << fixed << setprecision(1) << temperature
         << "\xC2\xB0" << "C" << setw(18) << right << "|" << endl;
    cout << "| Humidity   : " << fixed << setprecision(1) << humidity << "%"
         << setw(19) << right << "|" << endl;
    cout << "+---------------------------------------+" << endl;
  }
};

//This class doesn't store any data itself. Instead, it takes in our array of
// cities and loops through them to perform mathematical analysis (Average, Min,
// Max). Using 'static' means we can use this tool without having to create an
// Analyzer object first.
class WeatherAnalyzer {
public:
  // Takes in the array (const because we shouldn't modify the data, just read
  // it)
  static void displayStatistics(const WeatherData database[], int size) {
    if (size <= 0)
      return;

    double totalTemp = 0.0;
    int hottestIndex = 0;
    int coldestIndex = 0;

    // Loop through the entire array to calculate the totals and find the
    // extremes
    for (int i = 0; i < size; ++i) {
      double currentTemp = database[i].getTemperature();
      totalTemp += currentTemp; // Add to running total for the average later

      // Check if this city is hotter than our current record holder
      if (currentTemp > database[hottestIndex].getTemperature()) {
        hottestIndex = i;
      }
      // Check if this city is colder than our current record holder
      if (currentTemp < database[coldestIndex].getTemperature()) {
        coldestIndex = i;
      }
    }

    // Calculate exact mathematical average
    double averageTemp = totalTemp / size;

    cout << "\n+---------------------------------------+" << endl;
    cout << "|       GLOBAL WEATHER STATISTICS       |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "| Average Temp : " << setw(20) << right << fixed << setprecision(1)
         << averageTemp << "\xC2\xB0" << "C |" << endl;
    cout << "| Hottest City : " << setw(22) << right
         << database[hottestIndex].getCityName() << " |" << endl;
    cout << "| Coldest City : " << setw(22) << right
         << database[coldestIndex].getCityName() << " |" << endl;
    cout << "+---------------------------------------+" << endl;
  }
};
class WeatherForecastSimulation {
private:
  static const int NUM_CITIES = 5;
  // Objective: Apply arrays (This is our core memory holding the 5 city
  // objects)
  WeatherData cityDatabase[NUM_CITIES];

public:
  // Constructor: This runs automatically when the Simulation engine starts.
  // It populates our array slots exactly as the predefined case study
  // requested.
  WeatherForecastSimulation() {
    cityDatabase[0] = WeatherData("Mumbai", 32.0, 70.0);
    cityDatabase[1] = WeatherData("Delhi", 28.5, 45.0);
    cityDatabase[2] = WeatherData("Bangalore", 24.0, 60.0);
    cityDatabase[3] = WeatherData("Chennai", 34.0, 75.0);
    cityDatabase[4] = WeatherData("Kolkata", 31.0, 68.0);
  }

  // Iterates through the stored array using a 'for' loop to list all available
  // cities
  void displayCityList() const {
    cout << "\n+---------------------------------------+" << endl;
    cout << "|              View Cities              |" << endl;
    cout << "+---------------------------------------+" << endl;
    for (int i = 0; i < NUM_CITIES; ++i) {
      cout << "| " << setw(2) << right << i + 1 << ". " << setw(34) << left
           << cityDatabase[i].getCityName() << "|" << endl;
    }
    cout << "+---------------------------------------+" << endl;
  }

  // Feature: Ask user to pick one city, and view its detailed report
  void checkWeather() const {
    displayCityList();

    int choice;
    cout << "\n=> Select city (1-" << NUM_CITIES << "): ";

    // Validation Check: If the user types a letter (like 'A') instead of a
    // number, cin breaks. The code below clears the stream to prevent an
    // infinite error loop.
    if (!(cin >> choice)) {
      cin.clear();
      cin.ignore(10000, '\n');
      choice = -1; // Force an invalid choice to trigger the 'else' block below
    }

    // Objective: Apply conditional statements
    // We make sure the user chose 1, 2, 3, 4, or 5.
    if (choice >= 1 && choice <= NUM_CITIES) {
      int index = choice -
                  1; // Subtract 1 because arrays start at index 0 (1 becomes 0)

      // We instruct the exact City object they picked to print itself
      cityDatabase[index].displayFormattedOutput();
    } else {
      cout << "\n[!] Invalid city selection. Please try again." << endl;
    }
  }

  // Feature: Ask user to pick two cities to see them side-by-side
  void compareWeather() const {
    displayCityList();

    int choice1, choice2;
    cout << "\n=> Select first city  (1-" << NUM_CITIES << "): ";
    if (!(cin >> choice1)) {
      cin.clear();
      cin.ignore(10000, '\n');
      choice1 = -1;
    }

    cout << "=> Select second city (1-" << NUM_CITIES << "): ";
    if (!(cin >> choice2)) {
      cin.clear();
      cin.ignore(10000, '\n');
      choice2 = -1;
    }

    // Logic Check: Ensure they didn't pick the exact same city twice to compare
    // against itself
    if (choice1 == choice2 && choice1 != -1) {
      cout << "\n[!] You cannot compare a city to itself. Please select two "
              "different cities."
           << endl;
    }
    // Logic Check: Ensure both chosen numbers are safely inside the bounds of
    // our array
    else if (choice1 >= 1 && choice1 <= NUM_CITIES && choice2 >= 1 &&
             choice2 <= NUM_CITIES) {

      int idx1 = choice1 - 1;
      int idx2 = choice2 - 1;

      // Draw the side-by-side comparison table
      cout << "\n+---------------------------------------------------+" << endl;
      cout << "|               WEATHER COMPARISON                  |" << endl;
      cout << "+--------------+--------------------+---------------+" << endl;
      cout << "| Detail       | " << setw(18) << left
           << cityDatabase[idx1].getCityName() << " | " << setw(13) << left
           << cityDatabase[idx2].getCityName() << " |" << endl;
      cout << "+--------------+--------------------+---------------+" << endl;
      cout << "| Temperature  | " << fixed << setprecision(1)
           << cityDatabase[idx1].getTemperature() << "\xC2\xB0"
           << "C             | " << cityDatabase[idx2].getTemperature()
           << "\xC2\xB0" << "C        |" << endl;
      cout << "| Humidity     | " << fixed << setprecision(1)
           << cityDatabase[idx1].getHumidity() << "%              | "
           << cityDatabase[idx2].getHumidity() << "%         |" << endl;
      cout << "+--------------+--------------------+---------------+" << endl;
    } else {
      cout << "\n[!] Invalid city selection. Please try again." << endl;
    }
  }

  // Core System Loop: The central brain that keeps the menu spinning
  void runSimulation() {
    int option = 0;

    // Use a do-while loop because we want the menu to always print at least
    // once!
    do {
      // Print main UI elements
      cout << "\n=========================================" << endl;
      cout << "       WEATHER FORECAST SIMULATION       " << endl;
      cout << "=========================================" << endl;
      cout << " 1. View Cities" << endl;
      cout << " 2. Check Weather" << endl;
      cout << " 3. Compare Two Cities" << endl;
      cout << " 4. View Global Weather Statistics" << endl;
      cout << " 5. Exit" << endl;
      cout << "=========================================" << endl;
      cout << "\n=> Enter choice: ";

      if (!(cin >> option)) {
        cin.clear();
        cin.ignore(10000, '\n');
        option = -1;
      }

      // Switch statement acts as our router, sending the user to different
      // functions
      switch (option) {
      case 1:
        displayCityList();
        break;
      case 2:
        checkWeather();
        break;
      case 3:
        compareWeather();
        break;
      case 4:
        // Demonstrating static utility class pattern: passing our array memory
        // to the analyzer
        WeatherAnalyzer::displayStatistics(cityDatabase, NUM_CITIES);
        break;
      case 5:
        // By skipping to the end, the 'while' condition triggers and the app
        // closes safely
        cout << "\nExiting Weather Forecast Simulation. Goodbye!\n" << endl;
        break;
      default:
        // Catches numbers like 9 or -4
        cout << "\n[!] Invalid choice. Please enter 1-5." << endl;
      }
    } while (option != 5);
  }
};

int main() {
  // Instantiate the simulation object
  WeatherForecastSimulation app;

  // Execute the requested system loop
  app.runSimulation();

  return 0;
}








