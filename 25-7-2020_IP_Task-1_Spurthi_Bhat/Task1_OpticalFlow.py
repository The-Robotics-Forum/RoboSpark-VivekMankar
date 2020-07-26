import numpy as np
import cv2
face_cascade=cv2.CascadeClassifier(r"D:\Image processing\Day 3\haarcascade_frontalface_default.xml")
eye_cascade = cv2.CascadeClassifier(r"D:\Image processing\Day 3\haarcascade_eye.xml")


cap = cv2.VideoCapture(0)

# params for corner detection
feature_params = dict(maxCorners=150,
                      qualityLevel=0.3,
                      minDistance=7,
                      blockSize=7)

# Parameters for lucas kanade optical flow
lk_params = dict(winSize=(15, 15),
                 maxLevel=2,
                 criteria=(cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT,
                           10, 0.03))


color = np.random.randint(0, 255, (100, 3))

# Take first frame and find corners in it
ret, old_frame = cap.read()

old_gray = cv2.cvtColor(old_frame,
                        cv2.COLOR_BGR2GRAY)
faces = face_cascade.detectMultiScale(old_gray, 1.2, 9)
for (x, y, w, h) in faces:
        cv2.rectangle(old_gray, (x, y), (x + w, y + h), (255, 0, 0), 2)
        roi_color = old_gray[y:y + h, x:x + w]
p0 = cv2.goodFeaturesToTrack(roi_color, mask=None,
                             **feature_params)

# Create a mask image for drawing purposes
mask = np.zeros_like(old_frame)

while (1):

    ret, frame = cap.read()
    frame = cv2.flip(frame, 1)
    frame_gray = cv2.cvtColor(frame,
                              cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(frame_gray, 1.2, 9)
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

        roi_color = frame[y:y + h, x:x + w]



    # calculation of optical flow
    p1, st, err = cv2.calcOpticalFlowPyrLK(old_gray,
                                           frame_gray,
                                           p0, None,
                                           **lk_params)

    # Selecting good points
    good_new = p1[st == 1]
    good_old = p0[st == 1]

    # drawing the tracks
    for i, (new, old) in enumerate(zip(good_new,
                                       good_old)):
        a, b = new.ravel()
        c, d = old.ravel()
        mask = cv2.line(mask, (a, b), (c, d),
                        color[i].tolist(), 2)

        frame = cv2.circle(frame, (a, b), 5,
                           color[i].tolist(), -1)

    img = cv2.add(frame, mask)


    cv2.imshow('frame', img)
    if (c - a > 0 and d - b > 0):
        print("Right")
    elif (c - a < 0 and d - b < 0):
        print("Left")
    else:
        print("Still")


    k = cv2.waitKey(150)
    if k ==32:
        break

    # Updating Previous frame and points
    old_gray = frame_gray.copy()
    p0 = good_new.reshape(-1, 1, 2)

cap.release()
cv2.destroyAllWindows()

