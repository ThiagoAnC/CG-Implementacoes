import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

img = cv.imread("Lenna.png")

b, g, r = cv.split(img)

# histograma para com cores.

plt.hist(b.ravel(), 256, [0, 256])
plt.hist(g.ravel(), 256, [0, 256])
plt.hist(r.ravel(), 256, [0, 256])

#hist = cv.calcHist([img], [0], None, [256], [0, 256])
#plt.plot(hist)
plt.show()

cv.waitKey(0)
cv.destroyAllWindows()