import subprocess
import random
import argparse

def generate_random_stack(size):
    return random.sample(range(1, size * 2), size)

def run_test(stack):
    stack_str = " ".join(map(str, stack))
    push_swap_cmd = f"./push_swap {stack_str}"
    checker_cmd = f"./checker_linux {stack_str}"
    
    try:
        # Run push_swap command and capture the output
        push_swap_output = subprocess.check_output(push_swap_cmd, shell=True, text=True)
        
        # Run checker_linux command with the output of push_swap
        checker_output = subprocess.check_output(checker_cmd, input=push_swap_output, shell=True, text=True).strip()
        return checker_output
    except subprocess.CalledProcessError as e:
        return f"Error: Command '{e.cmd}' returned non-zero exit status {e.returncode}."

def main():
    parser = argparse.ArgumentParser(description="Test the push_swap program with checker_linux.")
    parser.add_argument("min_stack_size", type=int, help="Minimum size of the stack.")
    parser.add_argument("max_stack_size", type=int, help="Maximum size of the stack.")
    parser.add_argument("num_tests", type=int, help="Number of tests to perform.")
    parser.add_argument("output_file", type=str, help="File to save the generated stacks.")

    args = parser.parse_args()
    min_stack_size = args.min_stack_size
    max_stack_size = args.max_stack_size
    num_tests = args.num_tests
    output_file = args.output_file

    with open(output_file, 'w') as f:
        for i in range(num_tests):
            stack_size = random.randint(min_stack_size, max_stack_size)
            stack = generate_random_stack(stack_size)
            result = run_test(stack)
            print(f"Test {i+1}: Stack size {stack_size} -> {result}")
            f.write(f"Test {i+1}: Stack size {stack_size} -> {result}\nStack: {' '.join(map(str, stack))}\n\n")

if __name__ == "__main__":
    main()
