import cv2
import numpy as np

#resizing the image and converting into hsv
original=cv2.imread(r"D:\Image processing\Day 2\yellow_flower.jpg")
res=cv2.resize(original,(800,800))
res1=cv2.resize(original,(800,800))
hsv=cv2.cvtColor(res,cv2.COLOR_RGB2HSV)


#values obtained using code in color_masking.py
rgbl=np.array([0,60,149],np.uint8)
rgbh=np.array([253,246,255],np.uint8)

#defining the kernel and masking
mask=cv2.inRange(hsv,rgbl,rgbh)
mask1=cv2.inRange(hsv,rgbl,rgbh)
kernel=np.array(([5,2,6],[5,6,8],[6,4,8]),np.uint8)

#filters
blur=cv2.filter2D(mask,-1,kernel)
avg=cv2.blur(mask,(7,7))
gaus_blur=cv2.GaussianBlur(mask,(5,5),0)
median=cv2.medianBlur(mask,9)
bilateral=cv2.bilateralFilter(mask,5,121,121)

#defining the points for flowerpot and displaying text on masked image
pts=np.array([[253,702],[521,700],[496,784],[280,787],],np.int32)
pts=pts.reshape((-1,1,2))

line=cv2.line(mask,(382,550),(382,700),(255,0,0),4)
flower_pot=cv2.polylines(mask,[pts],True,(255,0,0),5)

font=cv2.FONT_HERSHEY_TRIPLEX

cv2.putText(mask,'Gerbera Daisy',(59,81),font,3,(255,255,255),5)


#defining the points for flowerpot and displaying text on coloured image
pts=np.array([[253,702],[521,700],[496,784],[280,787],],np.int32)
pts=pts.reshape((-1,1,2))

line_clr=cv2.line(res1,(382,550),(382,700),(0,255,0),4)
flower_pot_clr=cv2.polylines(res1,[pts],True,(255,153,255),8)

font=cv2.FONT_HERSHEY_TRIPLEX

cv2.putText(res1,'Gerbera Daisy',(59,81),font,3,(153,51,255),5)

#displaying the output
cv2.imshow("mask image",mask1)
cv2.imshow("Filter2D",blur)
cv2.imshow("Averaging",avg)
cv2.imshow("Gaussian_Blur",gaus_blur)
cv2.imshow("Median Blur",median)
cv2.imshow("Bilateral",bilateral)
cv2.imshow("flowerpot",mask)
cv2.imshow("coloured_flowerpot",res1)

#saving the files
cv2.imwrite("D:\Image processing\mask1_img.jpg",mask1)
cv2.imwrite("D:\Image processing\Filter2D_img.jpg",blur)
cv2.imwrite("D:\Image processing\Average_img.jpg",avg)
cv2.imwrite("D:\Image processing\Gaussian_img.jpg",gaus_blur)
cv2.imwrite("D:\Image processing\median_img.jpg",median)
cv2.imwrite("D:\Image processing\Bilateral_img.jpg",bilateral)
cv2.imwrite("D:\Image processing\Flowerpot_img.jpg",mask)
cv2.imwrite("D:\Image processing\Flowerpot_coloured.jpg",res1)

cv2.waitKey(0)
cv2.destroyAllWindows()