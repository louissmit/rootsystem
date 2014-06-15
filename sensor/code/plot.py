import matplotlib.pyplot as plt
from colorsys import rgb_to_hsv
import numpy as np
import sys

###usage##
#python plot.py outfile


def main():
	# read arguments

	#plot results
	# Y = [int(x) for x in list(open('results.txt', 'r'))]
	results = list(open('results.txt', 'r'))[22:]
	wls = []
	Y = []
	for i in xrange(3, len(results)):
		if ((i-1) % 2) == 0:
			sensor = int(results[i])
			Y.append(sensor)
			rgb = [int(channel)/255.0 for channel in results[i-1].split()]
			h = rgb_to_hsv(rgb[0], rgb[1], rgb[2])[0]
			wls.append(h)
	sortwls = np.argsort(wls)
	Y = [Y[i] for i in sortwls][::-1]
	# X = [380.0 + x*(750.0-380.0) for x in np.sort(wls)[::-1]]
	X = [x for x in xrange(0, len(Y))]
	plt.scatter(X, Y)
	plt.ylim(0,1100)
	plt.show()
	plt.save(outfile.png)

	#save results to file
	np.save(results,outfile)

if __name__ is main:

	main()
