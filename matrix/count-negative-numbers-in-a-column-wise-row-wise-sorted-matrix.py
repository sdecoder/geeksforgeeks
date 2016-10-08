# Python implementation of Efficient method to count of
# negative numbers in M[n][m]

def countNegative(M, n, m):

    count = 0 # initialize result

    # Start with top right corner
    i = 0
    j = m - 1

    # Follow the path shown using arrows above
    while j >= 0 and i < n:

        if M[i][j] < 0:

            # j is the index of the last negative number
            # in this row.  So there must be ( j+1 )
            count += (j + 1)

            # negative numbers in this row.
            i += 1

        else:
            # move to the left and see if we can
            # find a negative number there
             j -= 1
    return count

# Driver code
M = [
      [-3, -2, -1,  1],
      [-2,  2,  3,  4],
      [4,   5,  7,  8]
    ]
print(countNegative(M, 3, 4))
