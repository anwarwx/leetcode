import sys
import os
import pandas as pd

def main():
    if (len(sys.argv) != 2):
        print(f"<./program_name> <input_file>")
        return 1
    
    ns = pd.read_csv(sys.argv[1])
    ns = [f"{ns['#'][i]}.{ns['lang'][i]}" for i in range(len(ns))]

    CC = {
        'cc': 'g++ -std=c++17',
        'c': 'gcc',
        'py': 'python3'
    }

    os.chdir('./output')
    for n in ns:
        fn = n.split('.', 1)
        if (fn[1] == "py"): os.system(f"{CC[fn[1]]} ../solutions/{n}")
        else: os.system(f"{CC[fn[1]]} ../solutions/{n} -o {fn[0]}.o")
    
    print("\n-- C/C++ --")
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
