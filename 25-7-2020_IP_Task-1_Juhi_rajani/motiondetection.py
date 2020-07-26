import cv2

face_cascade = cv2.CascadeClassifier(r'C:\Users\juhir\Downloads\haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier(r'C:\Users\juhir\Downloads\haarcascade_eye.xml')

cap = cv2.VideoCapture(0)

X, Y = 0, 0

while True:

    ret, frame = cap.read(0)

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = face_cascade.detectMultiScale(gray, 1.2, 5)
    # FACE DETECTION
    for (x, y, w, h) in faces:
        cv2.line(frame, (x, y), (x + 30, y), (0, 255, 200), 2)
        cv2.line(frame, (x, y), (x, y + 30), (0, 255, 200), 2)
        cv2.line(frame, (x+w, y+h), (x+w - 30, y+h), (0, 255, 200), 2)
        cv2.line(frame, (x+w, y+h), (x+w, y+h - 30), (0, 255, 200), 2)
        cv2.line(frame, (x+w, y), (x+w - 30, y), (0, 255, 200), 2)
        cv2.line(frame, (x+w, y), (x+w, y + 30), (0, 255, 200), 2)
        cv2.line(frame, (x, y+h), (x + 30, y+h), (0, 255, 200), 2)
        cv2.line(frame, (x, y+h), (x, y+h - 30), (0, 255, 200), 2)
        # CONDITIONS FOR DIRECTION
        if ( X > x + 3 ):
            dir = 'Left Motion'
        elif ( X < x - 3 ):
            dir = 'Right Motion'
        else:
            dir = 'No Motion'
        X, Y = x, y
        cv2.putText(frame, "Motion :" + dir, (10, 30), cv2.FONT_HERSHEY_TRIPLEX, 0.8, (0, 0, 0), 1)

    resImage = cv2.resize(frame, (600, 600))
    cv2.imshow("Direction", resImage)

    k = cv2.waitKey(1)
    if (k == 32):
        break

cap.release()
cv2.destroyAllWindows()