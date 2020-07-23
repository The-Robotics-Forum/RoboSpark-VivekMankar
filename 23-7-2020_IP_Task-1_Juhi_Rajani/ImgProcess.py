import cv2
import numpy as np

text1 = cv2.imread(r"C:\Users\juhir\Downloads\text.jpg", cv2.IMREAD_UNCHANGED)

# Conversion to Gray Scale and HSV
gray1 = cv2.cvtColor(text1, cv2.COLOR_BGR2GRAY)
hsv1 = cv2.cvtColor(text1, cv2.COLOR_BGR2HSV)

# Saving Gray scale and hsv images
cv2.imwrite(r"C:\Users\juhir\Downloads\gray1.jpg", gray1)
cv2.imwrite(r"C:\Users\juhir\Downloads\hsv1.jpg", hsv1)

print("original image shape",text1.shape)
print("original image shape",text1.size)

# Resizing original Image
text1 = cv2.resize(text1, (500, 500))

print("resized image shape",text1.shape)
print("resized image shape",text1.size)


# Thresholding
ret, thresh1 = cv2.threshold(gray1, 155, 255, cv2.THRESH_BINARY)
cv2.imwrite(r"C:\Users\juhir\Downloads\thresh1.jpg", thresh1)

ret, thresh2 = cv2.threshold(gray1, 133, 255, cv2.THRESH_BINARY_INV)
cv2.imwrite(r"C:\Users\juhir\Downloads\thresh2.jpg", thresh2)

gaus = cv2.adaptiveThreshold(gray1, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 1)
cv2.imwrite(r"C:\Users\juhir\Downloads\gaus.jpg", gaus)

mean = cv2.adaptiveThreshold(gray1, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 115, 1)
cv2.imwrite(r"C:\Users\juhir\Downloads\mean.jpg", mean)

titles = ['Gray Scale', 'HSV', 'Binary Thresh', 'Invert Thresh', 'Adaptive gaussian thresh', 'Adaptive mean thresh']
images = [gray1, hsv1, thresh1, thresh2, gaus, mean]

# Displaying images
for i in range(6):
    cv2.imshow(titles[i], images[i])

cv2.waitKey(0)
cv2.destroyAllWindows()  # It destroy all windows
