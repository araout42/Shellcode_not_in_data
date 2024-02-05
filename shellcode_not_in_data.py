import sys
import secrets

def binary_to_hex_string(file_path):
    with open(file_path, 'rb') as file:
        binary_data = file.read()
        hex_string = binary_data.hex()
    return hex_string

def generate_c_code(hex_string, array_name):
    array_size = len(hex_string) *2
    random_string = secrets.token_hex(array_size//2)

    c_code = f"char {array_name}[{array_size + 1}] = \"{random_string}\"; \n\n\n"
    c_code += ''.join([f"{array_name}[{i // 2}] = (char)0x{hex_string[i:i+2]}; " for i in range(0, len(hex_string)//2, 2)])

    return c_code

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file.bin_path>")
        sys.exit(1)

    file_path = sys.argv[1]
    array_name = 'buf'

    # Convert binary to hex string
    hex_string = binary_to_hex_string(file_path)

    # Generate C code
    c_code = generate_c_code(hex_string, array_name)

    # Print the generated C code
    print(c_code)

if __name__ == "__main__":
    main()
