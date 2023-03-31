import subprocess
import time

arquivos_in = ["in-aula.txt", "in1.txt", "in2.txt", "in3.txt", "in4.txt", "in5.txt"]
codigos = ["busca_global.cpp", "heuristica.cpp"]

for arquivo in arquivos_in:
    for code in codigos:
        with open(arquivo) aas f:
            start = time.perf_counter()
            proc = subprocess.run([f'./{code}'], input=f.read(), text=True, capture_output=True)
            end = time.perf_counter()

            print('Saída:', proc.stdout)
            print('Stderr:', proc.stderr)
            print('Tempo total(s):', end - start)