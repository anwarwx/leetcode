import sys
import os
import pandas as pd

def main():
    if (len(sys.argv) != 2):
        print(f"<./program_name> <input_file>")
        return 1
    
    ns = pd.read_csv(sys.argv[1])
    ns = [f"{n}.c" for n in ns['#']]

    CC = "gcc"

    os.chdir('./output')
    for n in ns:
        fn = n.split('.', 1)[0]
        os.system(f'{CC} ../solutions/{n} -o {fn}.o')
    
    fs = os.listdir()
    for f in fs:
        print(f"RUNNING {f}")
        print("***")
        os.system(f"./{f}")
        print("***")
        print("FINISHED")

    return 0

if __name__=='__main__':
    main()
