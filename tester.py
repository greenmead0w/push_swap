import subprocess
import random
import itertools

def generate_inputs(num_sets, set_size, num_range):
    inputs = []
    for _ in range(num_sets):
        input_set = random.sample(range(-num_range, num_range), set_size)
        inputs.append(input_set)
    return inputs

def run_program(program_path, input_set):
    arg = " ".join(map(str, input_set))
    command = f'ARG="{arg}"; ./{program_path} $ARG | wc -l'
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    return result.stdout.strip()

def compare_outputs(prog1_path, prog2_path, inputs):
    differing_inputs = []
    for input_set in inputs:
        output1 = run_program(prog1_path, input_set)
        output2 = run_program(prog2_path, input_set)
        if output1 != output2:
            differing_inputs.append(input_set)
    return differing_inputs

def log_differing_inputs(differing_inputs, log_file):
    with open(log_file, 'w') as f:
        for input_set in differing_inputs:
            f.write(" ".join(map(str, input_set)) + "\n")

def main():
    prog1_path = 'push_swap'
    prog2_path = '/prueba1/push_swap/push_swap/push_swap'
    num_sets = 100
    set_size = 100
    num_range = 200
    log_file = 'differing_inputs.txt'

    inputs = generate_inputs(num_sets, set_size, num_range)
    differing_inputs = compare_outputs(prog1_path, prog2_path, inputs)
    log_differing_inputs(differing_inputs, log_file)

if __name__ == "__main__":
    main()
