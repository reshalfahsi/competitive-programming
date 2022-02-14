import numpy as np

N = int(input())
data = np.array([float(d) for d in input().split()])

mean = np.mean(data)
print(round(mean, 1))
print(round(np.median(data), 1))

vals, counts = np.unique(data, return_counts=True)
index = np.argmax(counts)
print(int(vals[index]))

stddev = np.std(data)
print(round(stddev, 1))


"""
import scipy.stats as st

confidence = 0.950003

confidence_interval = st.norm.interval(confidence, loc=mean, scale=stddev/N**0.5)
print(round(confidence_interval[0], 1), round(confidence_interval[1], 1))
"""

confidence = 0.96
confidence_constant = 1 + confidence

lower_confidence = mean - confidence_constant * stddev/N**0.5
upper_confidence = mean + confidence_constant * stddev/N**0.5

print(round(lower_confidence, 1), round(upper_confidence, 1))
