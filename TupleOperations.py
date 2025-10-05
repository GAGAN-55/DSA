# =================== TUPLE OPERATIONS ===================

# 1. Create a tuple
my_tuple = (10, 20, 30, 40, 50)

# 2. Access elements (indexing)
first_element_tuple = my_tuple[0]
last_element_tuple = my_tuple[-1]
print(f"Tuple - First element: {first_element_tuple}, Last element: {last_element_tuple}")

# 3. Slicing (since tuples are immutable)
slice_of_tuple = my_tuple[1:4]
print(f"Tuple - Slice from index 1 to 3: {slice_of_tuple}")

# 4. Searching (checking if element exists)
exists_tuple = 30 in my_tuple
print(f"Tuple - Is 30 in the tuple? {exists_tuple}")

# 5. Iterating over the tuple (loop)
print("Tuple - Iterating over the tuple:")
for item in my_tuple:
    print(item)

# 6. Concatenation
new_tuple = (60, 70, 80)
combined_tuple = my_tuple + new_tuple  # Concatenate two tuples
print(f"Tuple - Concatenated: {combined_tuple}")

# 7. Repeating a tuple
repeated_tuple = my_tuple * 2  # Repeat the tuple
print(f"Tuple - Repeated: {repeated_tuple}")