import filecmp

def find_first_difference(file1, file2):
    differing_line = None

    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        for line_number, (line1, line2) in enumerate(zip(f1, f2), start=1):
            if line1 != line2:
                differing_line = (line_number, line1, line2)
                break  # Stop as soon as a difference is found

    return differing_line

def main():
    if len(sys.argv) != 3:
        print("Usage: python compare_files.py <file1> <file2>")
    else:
        file1, file2 = sys.argv[1], sys.argv[2]
        differing_line = find_first_difference(file1, file2)

        if differing_line is not None:
            line_number, line1, line2 = differing_line
            print("\033[31mWrong\033[0m")  # Red text for "Wrong"
            print(f"\033[31mDiffering line (Line {line_number}):\033[0m")
            print(f"\033[31m- {line1.strip()}\033[0m")
            print(f"\033[31m+ {line2.strip()}\033[0m")
        else:
            print("\033[32mPassed\033[0m")  # Green text for "Passed"

if __name__ == "__main__":
    import sys
    main()
