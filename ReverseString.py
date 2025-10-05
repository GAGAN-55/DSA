# Code to reverse a string
def reverse_string(s):
    # Using slicing to reverse the string
    return s[::-1]

# Example usage
input_string = "Hello, World!"
reversed_string = reverse_string(input_string)
print(f"Original String: {input_string}")
print(f"Reversed String: {reversed_string}")
