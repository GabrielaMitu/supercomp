import subprocess
import time
import sys

def roda_com_entrada(executavel, arquivo_in):
    with open(arquivo_in) as f:
        start = time.perf_counter()
        proc = subprocess.run([executavel], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()
        
        return((end - start))

print(roda_com_entrada(f"./{sys.argv[1]}", sys.argv[2]))
