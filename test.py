import os

def remove_first_n_lines(file_path, n=1):
    """Remove the first n lines from the specified file."""
    with open(file_path, 'r') as file:
        lines = file.readlines()
    
    # Write back the lines excluding the first n lines
    with open(file_path, 'w') as file:
        file.writelines(lines[n:])

def process_directory(directory):
    """Process all .c files in the given directory and its subdirectories."""
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith('.c'):
                file_path = os.path.join(root, file)
                print(f"Processing file: {file_path}")
                remove_first_n_lines(file_path)

if __name__ == "__main__":
    # Specify the directory you want to process
    target_directory = '/Users/tristan/Documents/minishell/srcs/'  # Change this to your target directory
    process_directory(target_directory)