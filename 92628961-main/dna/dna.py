import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    database_file = sys.argv[1]
    with open(database_file, "r") as file:
        reader = csv.reader(file)
        headers = next(reader)
        people = {}
        for row in reader:
            people[row[0]] = [int(val) for val in row[1:]]

    # Read DNA sequence file into a variable
    dna_file = sys.argv[2]
    with open(dna_file, "r") as file:
        dna = file.read().strip()

    # Find longest match of each STR in DNA sequence
    matches = {}
    for header in headers[1:]:
        matches[header] = longest_match(dna, header)

    # Check database for matching profiles
    for person, values in people.items():
        if all(matches[header] == value for header, value in zip(headers[1:], values)):
            print(person)
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == "__main__":
    main()
