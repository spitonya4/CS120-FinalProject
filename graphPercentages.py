import sys
# Install numpy
import numpy as np
# Install matplotlib
import matplotlib.pyplot as plt

# Store the command line arguments in variables
normal = sys.argv[1]
ultra = sys.argv[2]
master = sys.argv[3]

# Write the values to the files
percentageFile = open("../percentages.txt", "a")
# Append the values to the file
percentageFile.write(normal + " " + ultra + " " + master + "\n")
# Close the file
percentageFile.close()

# Open the file to read its contents
percentageFile = open("../percentages.txt", "r")
# Iterate through each line in the file
nCounter = 0
uCounter = 0
mCounter = 0
nTotal = 0
uTotal = 0
mTotal = 0
for line in percentageFile:
    # For each line, split by the commas
    numbers = line.split()
    # Store the first value in the normal total
    if (numbers[0] != 'nan'):
        nCounter += 1
        nTotal += float(numbers[0])
    # Store the second value in the ultra total
    if (numbers[1] != 'nan'):
        uCounter += 1
        uTotal += float(numbers[1])
    # Store the third value in the master total
    if (numbers[2] != 'nan'):
        mCounter += 1
        mTotal += float(numbers[2])
# Once done iterating through the file, divide each total by the number of lines
nVal = nTotal / nCounter
uVal = uTotal / uCounter
mVal = mTotal / mCounter

# Then multiply that value by 100
nVal = nVal * 100
uVal = uVal * 100
mVal = mVal * 100

percentageFile.close()

# Graph the values
num = 3

# Create the plot
ax = plt.subplot(111)

barWidth = .4

ax.bar(500, nVal, width = 300, color = 'r')

ax.bar(900, uVal, width = 300, color = 'b')

ax.bar(1300, mVal, width = 300, color = 'g')

# Set the window title
plt.gcf().canvas.set_window_title("Catch Completion")

# Set the graph title
plt.title("Percentages of Successful Catches vs. Throws")

# Label the x axis
plt.xlabel("Type of Ball")

# Make sure the x-axis marks are at each ball
xDistance = [500, 900, 1300]
xLabels = ['Normal', 'Ultra', 'Master']
plt.xticks(xDistance, xLabels)

# Label the y axis
plt.ylabel("Percentage of Successful Catches")

plt.show()


