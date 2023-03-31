import subprocess
import time



def roda_com_entrada(executavel, arquivo_in):
    with open() as f:
        start = time.perf_counter()
        proc = subprocess.run([f'./{executavel}'], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()

        print('Saída:', proc.stdout)
        print('Stderr:', proc.stderr)
        print('Tempo total(s):', end - start)

        return (proc.stdout, end - start)