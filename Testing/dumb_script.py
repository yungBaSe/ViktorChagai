# Скрипт для стресс-тестирования
# Для обоих решений нужен freopen("input.txt", "r", stdin)
# В tests.txt заранее генерим тесты
# Указываем, сколько строк во вводе в переменной lines_of_input
# Указываем, сколько тестов мы хотим обработать в переменной iterations

import subprocess
import os
import shutil

shutil.copy('tests.txt', 'tmp_tests.txt')

cpp_file_a = 'a.cpp'
cpp_file_stupid = 'stupid.cpp'

lines_of_input = 2
iterations = 4

def run_program(command):
    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return result.stdout.strip(), result.stderr.strip()

compile_result_a = run_program(['g++', cpp_file_a, '-o', 'a.out'])

compile_result_stupid = run_program(['g++', cpp_file_stupid, '-o', 'stupid.out'])

for _ in range(iterations):
    with open('tmp_tests.txt', 'r') as input_file:
        lines = input_file.readlines()

    if len(lines) < lines_of_input:
        print("Недостаточно строк в tmp_tests.txt для обработки.")
        break

    current_input = "".join(lines[:lines_of_input])

    with open('tmp_tests.txt', 'w') as input_file:
        input_file.writelines(lines[lines_of_input:])

    with open('input.txt', 'w') as input_file:
        input_file.writelines(lines[:lines_of_input])

    output_a, error_a = run_program(['./a.out'])

    output_stupid, error_stupid = run_program(['./stupid.out'])
    
    if output_a!= output_stupid:
        print("Failed test:")
        print("Input:")
        print(current_input)
        print("output_stupid.txt:")
        print(output_stupid)
        print("output_a.txt:")
        print(output_a)
        break
else:
    print("All good!")
