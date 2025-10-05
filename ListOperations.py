# =================== LIST OPERATIONS ===================

# 1. Create a list
my_list = [10, 20, 30, 40, 50]

# 2. Access elements (indexing)
first_element = my_list[0]  # Accessing the first element
last_element = my_list[-1]  # Accessing the last element
print(f"First element: {first_element}, Last element: {last_element}")

# 3. Modify elements (changing value at a specific index)
my_list[1] = 100
print(f"After modifying the second element: {my_list}")

# 4. Add elements (append, insert)
my_list.append(60)  # Add to the end
print(f"After appending 60: {my_list}")
my_list.insert(2, 25)  # Insert at index 2
print(f"After inserting 25 at index 2: {my_list}")

# 5. Remove elements (pop, remove, clear)
my_list.pop()  # Removes the last element
print(f"After popping last element: {my_list}")
my_list.remove(25)  # Removes the first occurrence of 25
print(f"After removing 25: {my_list}")
my_list.clear()  # Clears all elements
print(f"After clearing the list: {my_list}")

# Recreate the list for further operations
my_list = [10, 20, 30, 40, 50]

# 6. Slicing
slice_of_list = my_list[1:4]  # Get elements from index 1 to 3 (not including 4)
print(f"Slice of list from index 1 to 3: {slice_of_list}")

# 7. Searching (checking if element exists)
exists = 30 in my_list  # Check if 30 is in the list
print(f"Is 30 in the list? {exists}")

# 8. Iterating over the list (loop)
print("Iterating over the list:")
for item in my_list:
    print(item)

# 9. Sorting (ascending and descending)
my_list.sort()  # Sort in ascending order
print(f"Sorted list (ascending): {my_list}")
my_list.sort(reverse=True)  # Sort in descending order
print(f"Sorted list (descending): {my_list}")

# 10. Reversing the list
my_list.reverse()  # Reverse the list
print(f"Reversed list: {my_list}")

# 11. List concatenation
new_list = [60, 70, 80]
combined_list = my_list + new_list  # Concatenate two lists
print(f"Concatenated list: {combined_list}")

# 12. List comprehension (creating a new list based on a condition)
squared_list = [x ** 2 for x in my_list]  # Squaring each element in the list
print(f"List of squared values: {squared_list}")
