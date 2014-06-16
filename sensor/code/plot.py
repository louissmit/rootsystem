import matplotlib.pyplot as plt
from colorsys import rgb_to_hsv
import numpy as np
import sys
import os
from optparse import OptionParser
import itertools

from wav2RGB import RGB2wav

###usage##
#python plot.py outfile
def opts_parser():
	usage =\
"""\r%prog: Processing of sensor data.

Usage: %prog [OPTIONS] OUTFILE
  OUTFILE: .png file to plot the map to or .npz file to save the resluts to
"""
	parser = OptionParser(usage=usage)
	parser.add_option('-s', '--save',
			type='choice', #int,str,float
			choices=('on', 'off'), default='on',
			help='Results are being saved or not (default: %default)')

	parser.add_option('--plotformat', metavar='format',
			type='choice', choices=('pdf', 'png'), default='png',
			help='Format of the plot (default: %default)')
	
	return parser

def main():
	# read arguments
	parser = opts_parser()
	options, args = parser.parse_args()
	
	#plot results
	# Y = [int(x) for x in list(open('results.txt', 'r'))]
	results = list(open('results.txt', 'r'))[22:]
	wls = []
	intensity = []
	num_results=len(results)/2

	for i in xrange(num_results):
		sensor = int(results[2*i])
		intensity.append(sensor)
		r,g,b = [int(channel)/255.0 for channel in results[2*i+1].split()]
		wavelegth = RGB2wav(r,g,b)
		wls.append(wavelegth)
	
	#sortwls = np.argsort(wls)
	#intensity = [intensity[i] for i in sortwls][::-1]
	# X = [380.0 + x*(750.0-380.0) for x in np.sort(wls)[::-1]]
	#X = [x for x in xrange(0, len(intensity))]
	plt.scatter(wls, intensity)
	plt.ylim(0,1100)
	plt.xlim(300,650)
	plt.show()
	plt.save(arg[1]+options.format)

	#save results to file
	np.save(results,outfile)


if __name__=="__main__":
	main()