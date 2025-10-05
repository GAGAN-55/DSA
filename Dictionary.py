# =================== DICTIONARY OPERATIONS ===================

# 1. Create a dictionary
my_dict = {'name': 'Alice', 'age': 25, 'city': 'Wonderland'}

# 2. Access elements (by key)
name = my_dict['name']
age = my_dict['age']
print(f"Dictionary - Name: {name}, Age: {age}")

# 3. Modify elements (update value by key)
my_dict['age'] = 26
print(f"Dictionary - After modifying age: {my_dict}")

# 4. Add elements (add a new key-value pair)
my_dict['job'] = 'Engineer'
print(f"Dictionary - After adding a new key: {my_dict}")

# 5. Remove elements (del, pop, popitem)
del my_dict['city']  # Remove a key-value pair
print(f"Dictionary - After deleting 'city': {my_dict}")
job = my_dict.pop('job')  # Remove and return value of 'job'
print(f"Dictionary - After popping 'job': {my_dict}, Popped value: {job}")
key_value_pair = my_dict.popitem()  # Remove and return last key-value pair
print(f"Dictionary - After popping an item: {my_dict}, Popped item: {key_value_pair}")

# 6. Searching (check if key exists)
has_name = 'name' in my_dict
print(f"Dictionary - Is 'name' key in the dictionary? {has_name}")

# 7. Iterating over the dictionary
print("Dictionary - Iterating over keys:")
for key in my_dict:
    print(key, ":", my_dict[key])

print("Dictionary - Iterating over values:")
for value in my_dict.values():
    print(value)

print("Dictionary - Iterating over key-value pairs:")
for key, value in my_dict.items():
    print(key, ":", value)

# 8. Getting all keys and values
keys = my_dict.keys()
values = my_dict.values()
print(f"Dictionary - Keys: {keys}, Values: {values}")

# 9. Clearing the dictionary
my_dict.clear()
print(f"Dictionary - After clearing the dictionary: {my_dict}")