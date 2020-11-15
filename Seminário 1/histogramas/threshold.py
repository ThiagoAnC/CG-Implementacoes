import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

src = cv.imread("t.jpg",0)

# imagem original
#cv.imshow("antes", src)

ret, thresh1 = cv.threshold(src,200, 255, cv.THRESH_BINARY)

# threshold binary.
cv.imshow("depois", thresh1)

cv.waitKey(0)
cv.destroyAllWindows()