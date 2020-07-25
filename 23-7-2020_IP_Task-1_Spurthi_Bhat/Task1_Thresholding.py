import cv2
img=cv2.imread(r"D:\Image processing\text.jpg") #change path for testing the program
cv2.imshow("Original",img)

#printing dimensions
print("Original image dimensions are:")
print("Shape of image:",img.shape)
print("Size of image:",img.size)

#converting images
gray=cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
hsv=cv2.cvtColor(img,cv2.COLOR_RGB2HSV)
cv2.imshow("Grayscale", gray)
cv2.imshow("Hue", hsv)

#saving hue and grayscale images
cv2.imwrite("D:\Image processing\grayscale.jpg", gray)
cv2.imwrite("D:\Image processing\hsv.jpg", hsv)

#resizing images
resize=cv2.resize(img,(500,500))
cv2.imshow("Resize",resize)

#printing dimensions of resized images
print("Resized Image dimensions are:")
print("Shape of image:",resize.shape)
print("Size of image:",resize.size)

# simple thresholding
ret,thresh=cv2.threshold(gray,160,255,cv2.THRESH_BINARY)
ret,thresh1=cv2.threshold(gray,160,255,cv2.THRESH_BINARY_INV)
ret,thresh2=cv2.threshold(gray,160,255,cv2.THRESH_OTSU)

cv2.imshow("Thresh_Binary", thresh)
cv2.imshow("Thresh_Binary_Inversion", thresh1)
cv2.imshow("Thresh_Otsu", thresh2)

#saving the images
cv2.imwrite("D:\Image processing\Thresh_binary.jpg", thresh)
cv2.imwrite("D:\Image processing\Thresh_binary_inv.jpg", thresh1)
cv2.imwrite("D:\Image processing\Thresh_otsu.jpg", thresh2)

#adaptive and gaussian thresholding
adaptive_thresh=cv2.adaptiveThreshold(gray,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,9,9)
gaussian_thresh=cv2.adaptiveThreshold(gray,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,9,9)

cv2.imshow("Adaptive_thresh", adaptive_thresh)
cv2.imshow("Gaussian_thresh", gaussian_thresh)

#saving the images
cv2.imwrite("D:\Image processing\Adaptive_thresh.jpg", adaptive_thresh)
cv2.imwrite("D:\Image processing\gaussian_thresh.jpg", gaussian_thresh)

cv2.waitKey(0)
cv2.destroyAllWindows()