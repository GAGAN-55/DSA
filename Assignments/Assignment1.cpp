#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Date structure
struct Date {
    int day;
    int month;
    int year;
};

// WeatherRecord ADT
class WeatherRecord {
public:
    Date date;
    string city;
    double temperature;

    WeatherRecord(Date d, string c, double t) : date(d), city(c), temperature(t) {}
};

// Weather Data Storage System
class WeatherDataStorage {
private:
    vector<string> cities;
    vector<int> years;
    vector<vector<double> > data; // 2D array: rows = years, cols = cities
    const double SENTINEL = -9999.0; // For sparse data

    // Helper to get city index
    int getCityIndex(const string& city) {
        for (size_t i = 0; i < cities.size(); i++) {
            if (cities[i] == city) return i;
        }
        return -1;
    }

    // Helper to get year index
    int getYearIndex(int year) {
        for (size_t i = 0; i < years.size(); i++) {
            if (years[i] == year) return i;
        }
        return -1;
    }

public:
    WeatherDataStorage(const vector<string>& cityList, const vector<int>& yearList)
        : cities(cityList), years(yearList)
    {
        // Initialize 2D data with sentinel values
        data.resize(years.size(), vector<double>(cities.size(), SENTINEL));
    }

    // Insert a weather record
    void insert(const WeatherRecord& record) {
        int yearIdx = getYearIndex(record.date.year);
        int cityIdx = getCityIndex(record.city);
        if (yearIdx == -1 || cityIdx == -1) {
            cout << "Error: Year or City not found in system.\n";
            return;
        }
        data[yearIdx][cityIdx] = record.temperature;
        cout << "Inserted temperature " << record.temperature << " for " << record.city
             << " in year " << record.date.year << endl;
    }

    // Delete a weather record (set to sentinel)
    void deleteRecord(const string& city, int year) {
        int yearIdx = getYearIndex(year);
        int cityIdx = getCityIndex(city);
        if (yearIdx == -1 || cityIdx == -1) {
            cout << "Error: Year or City not found in system.\n";
            return;
        }
        data[yearIdx][cityIdx] = SENTINEL;
        cout << "Deleted record for " << city << " in year " << year << endl;
    }

    // Retrieve data for a city and year
    void retrieve(const string& city, int year) {
        int yearIdx = getYearIndex(year);
        int cityIdx = getCityIndex(city);
        if (yearIdx == -1 || cityIdx == -1) {
            cout << "Error: Year or City not found in system.\n";
            return;
        }
        double temp = data[yearIdx][cityIdx];
        if (temp == SENTINEL) {
            cout << "No data found for " << city << " in year " << year << endl;
        } else {
            cout << "Temperature in " << city << " for year " << year << " is: " << temp << endl;
        }
    }

    // Populate the 2D array (for demonstration, can be expanded)
    void populateArray() {
        cout << "Populating array with sample data...\n";
        for (size_t i = 0; i < years.size(); i++) {
            for (size_t j = 0; j < cities.size(); j++) {
                data[i][j] = SENTINEL; // Start with sentinel value (no data)
            }
        }
    }

    // Row-major access: print all data row-wise
    void rowMajorAccess() {
        cout << "Row-major access (year-wise):\n";
        for (size_t i = 0; i < years.size(); i++) {
            cout << "Year " << years[i] << ": ";
            for (size_t j = 0; j < cities.size(); j++) {
                if (data[i][j] == SENTINEL)
                    cout << "N/A ";
                else
                    cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Column-major access: print all data column-wise
    void columnMajorAccess() {
        cout << "Column-major access (city-wise):\n";
        for (size_t j = 0; j < cities.size(); j++) {
            cout << "City " << cities[j] << ": ";
            for (size_t i = 0; i < years.size(); i++) {
                if (data[i][j] == SENTINEL)
                    cout << "N/A ";
                else
                    cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Handle sparse data by reporting missing entries
    void handleSparseData() {
        cout << "Handling sparse data (entries with no data):\n";
        for (size_t i = 0; i < years.size(); i++) {
            for (size_t j = 0; j < cities.size(); j++) {
                if (data[i][j] == SENTINEL) {
                    cout << "No data for " << cities[j] << " in year " << years[i] << endl;
                }
            }
        }
    }

    // Analyze time and space complexity (just print for now)
    void analyzeComplexity() {
        cout << "\nComplexity Analysis:\n";
        cout << "Insert/Delete/Retrieve operations are O(1) for known indices (year and city).\n";
        cout << "Searching indices for city and year is O(n) where n is number of cities or years.\n";
        cout << "Space complexity is O(Y*C) where Y = number of years, C = number of cities (size of 2D array).\n";
    }
};

int main() {
    // Initialize cities and years explicitly converting literals to strings
    vector<string> cities;
    cities.push_back(string("Delhi"));
    cities.push_back(string("Mumbai"));
    cities.push_back(string("Chennai"));

    vector<int> years;
    years.push_back(2022);
    years.push_back(2023);
    years.push_back(2024);

    WeatherDataStorage system(cities, years);

    system.populateArray();

    // Insert sample weather data
    system.insert(WeatherRecord({15, 1, 2022}, "Delhi", 12.5));
    system.insert(WeatherRecord({10, 6, 2023}, "Mumbai", 33.2));
    system.insert(WeatherRecord({21, 11, 2024}, "Chennai", 28.6));

    // Retrieve data
    system.retrieve("Delhi", 2022);
    system.retrieve("Mumbai", 2023);
    system.retrieve("Chennai", 2023); // No data example

    // Delete a record
    system.deleteRecord("Mumbai", 2023);

    // Access data row-major and column-major
    system.rowMajorAccess();
    system.columnMajorAccess();

    // Handle sparse data (show missing entries)
    system.handleSparseData();

    // Analyze complexity
    system.analyzeComplexity();

    return 0;
}
