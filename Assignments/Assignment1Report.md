# Weather Data Storage System Report

## **a. Description of the Weather Record ADT**
The **WeatherRecord ADT** represents a record of weather data for a specific date and city. It includes the following attributes:
- **Date**: A struct holding the day, month, and year of the weather record.
- **City**: A string representing the city for which the weather data is recorded.
- **Temperature**: A `double` representing the temperature for the given date and city.

Methods in this ADT include:
- **Constructor**: Initializes the date, city, and temperature values.

---

## **b. Strategy for Memory Representation (Row-Major vs. Column-Major)**

The weather data is stored in a **2D array** (vector of vectors) where:
- **Rows** represent years (time dimension).
- **Columns** represent cities (spatial dimension).
  
Two different access patterns are implemented:
- **Row-Major Access**: This accesses data **year-wise** (by row), which is efficient for processing data over time.
- **Column-Major Access**: This accesses data **city-wise** (by column), useful for analyzing data from the perspective of each city over multiple years.

The data structure helps efficiently access data using both access patterns, based on the analysis needs.

---

## **c. Approach to Handling Sparse Data**

To handle sparse data (missing temperature records), a **sentinel value** (`-9999.0`) is used to represent missing or unavailable temperature data in the 2D array. This allows:
- **Efficient storage**: Only non-sentinel data occupies space in memory.
- **Detection of missing data**: The system can easily identify and report missing data for cities and years where no record is available.

Additionally, a method is provided to handle and report missing data explicitly.

---

## **d. Time and Space Complexity Analysis for Key Operations**

1. **Insert Operation**: 
   - **Time Complexity**: O(1) for inserting at a known city-year index, assuming indices are already known or provided.
   - **Space Complexity**: O(1) for each insertion, but overall space complexity is O(Y * C) where Y is the number of years and C is the number of cities (since we are storing all possible city-year combinations in a 2D array).

2. **Delete Operation**: 
   - **Time Complexity**: O(1) for deleting a record by setting the sentinel value at a known index.
   - **Space Complexity**: O(1) for each deletion (just modifying the data in place).

3. **Retrieve Operation**: 
   - **Time Complexity**: O(1) for retrieving data at a known city-year index.
   - **Space Complexity**: O(1) for each retrieval (only returning the value at the requested index).

4. **Handling Sparse Data**: 
   - **Time Complexity**: O(Y * C) for iterating through the entire 2D array to check for missing data.
   - **Space Complexity**: O(Y * C) for storing the 2D array of weather data.

5. **Row-Major/Column-Major Access**: 
   - **Time Complexity**: O(Y * C) for iterating through all elements in the array to print data row-wise or column-wise.
   - **Space Complexity**: O(Y * C) for storing the entire array.

---

## **Conclusion**

The Weather Data Storage System provides an efficient and flexible approach to store and retrieve weather data for multiple cities and years. The system optimizes for sparse data using sentinel values, and supports both row-major and column-major data access. The complexity analysis indicates that while retrieval and modification operations are efficient, full data access and handling of sparse data require iterating through the entire dataset.

