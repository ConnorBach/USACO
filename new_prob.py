import os
from pathlib import Path

# get problem name
pname = input("Enter problem name: ")

# create directory
os.mkdir(pname)

# create c file
cwd = os.getcwd()
cwd = os.path.join(cwd, pname)

with open(os.path.join(cwd, pname + '.c'), 'w') as f:
    f.write(
    """
    /*
    ID: cbach122
    LANG: C
    TASK: %s
    */
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        return 0;
    }
    """
    % pname
    )

# create input and output files
fin = pname + '.in'
fout = pname + '.out'

Path(os.path.join(cwd, fin)).touch()
Path(os.path.join(cwd, fout)).touch()


# create makefile
with open(os.path.join(cwd, 'Makefile'), 'w') as f:
    f.write(
    """
    %s: %s
        gcc $< -o $@
    """
    % pname, pname
    )
