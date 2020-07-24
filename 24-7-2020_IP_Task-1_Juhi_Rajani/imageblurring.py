import cv2
import numpy as np

img = cv2.imread(r"C:\Users\juhir\Downloads\rose_flower.jpg")
original = cv2.imread(r"C:\Users\juhir\Downloads\yellow_flower.jpg") #original image
res = cv2.resize(original, (640, 400))

bgrl = np.array([80, 20 ,120], np.uint8)#lower bound  for masking the flower
bgrh = np.array([215, 240, 240], np.uint8)#upper bound  for masking the flower
mask = cv2.inRange(img, bgrl, bgrh)  #masked image

kernel = np.array(([0, 0 ,0], [0, 1, 0], [0, 0, 0]), np.uint8)#user defined kernel

blurred = cv2.filter2D(res, -1, kernel)

avg = cv2.blur(res, (7, 7))#averaging

gaus_blur = cv2.GaussianBlur(res, (5, 5), 0)#gaussian blur

median = cv2.medianBlur(res, 7)#median blur for normal image

bilateral = cv2.bilateralFilter(res, 5, 121, 121)#bilateral filter

cv2.imshow("original", res)
cv2.imshow("blurred", blurred)
cv2.imshow("averaging", avg)
cv2.imshow("gaussian blur", gaus_blur)
cv2.imshow("median blur normal", median)
cv2.imshow("bilateral", bilateral)
cv2.imshow("masked",mask)
cv2.imshow("img",img)

cv2.imwrite(r"C:\Users\juhir\Downloads\res.jpg",res)
cv2.imwrite(r"C:\Users\juhir\Downloads\blurred.jpg",blurred)
cv2.imwrite(r"C:\Users\juhir\Downloads\avg.jpg",avg)
cv2.imwrite(r"C:\Users\juhir\Downloads\gaus_blur.jpg",gaus_blur)
cv2.imwrite(r"C:\Users\juhir\Downloads\median.jpg",median)
cv2.imwrite(r"C:\Users\juhir\Downloads\bilateral.jpg",bilateral)
cv2.imwrite(r"C:\Users\juhir\Downloads\masked.jpg",mask)


cv2.waitKey(0)
cv2.destroyAllWindows()