# Code to count digits without built-in functions
def count_digits(number):
    # Handle negative numbers by converting to positive
    if number < 0:
        number = -number
    
    # If the number is 0, return 1 as it has 1 digit
    if number == 0:
        return 1
    
    count = 0
    while number > 0:
        # Remove the last digit from the number
        number = number // 10
        count += 1
    
    return count

# Example usage
number = 12345
print(f"The number {number} has {count_digits(number)} digits.")
