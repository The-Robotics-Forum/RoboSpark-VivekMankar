import cv2
import numpy as np

img = cv2.imread(r"C:\Users\juhir\Downloads\res.jpg")

img = cv2.circle(img,(50, 151), 50, (0,0,255),-1)
img = cv2.circle(img,(50, 250), 50, (0,0,255),-1)
img = cv2.circle(img,(149, 151), 50, (0,0,255),-1)
img = cv2.circle(img,(149, 250), 50, (0,0,255),-1)
img = cv2.circle(img,(50, 349), 50, (0,0,255),-1)
img = cv2.circle(img,(149, 349), 50, (0,0,255),-1)
img = cv2.line(img, (30,400), (170,400),(255,123,100),20)
img = cv2.ellipse(img, (100, 100),(100,15),0,0,3600,(170,45,0),-1)

font = cv2.FONT_HERSHEY_COMPLEX
cv2.putText(img,'Yellow flower',(80,60),font,2,(255,255,255),5)

cv2.imshow("pot",img)

cv2.imwrite(r"C:\Users\juhir\Downloads\flowerpot.jpg",img)

cv2.waitKey(0)
cv2.destroyAllWindows()