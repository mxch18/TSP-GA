from matplotlib import pyplot as plt
import numpy as np
import sys

if __name__ == '__main__':

    best, avg = np.empty([1,1]), np.empty([1,1])
    
    f_avg = open(sys.argv[1], 'r')
        
    for avg_line in f_avg:
        avg = np.append(avg,int(avg_line))
        
    f_avg.close()
    
    f_best = open(sys.argv[2], 'r')
    
    for best_line in f_best:
        best = np.append(best,int(best_line))
    
    f_best.close()
    
    avg = avg[1:-1]
    best = best[1:-1]
    
    plt.figure()
    plt.plot(best)
    plt.title('Best fitness over generation')
    plt.figure()
    plt.plot(avg)
    plt.title('Average fitness over generation')
    plt.show()
    
