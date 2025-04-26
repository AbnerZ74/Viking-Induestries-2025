import cv2
import glob

image_paths = glob.glob('unstiched_imgs/*.jpg')
imgs = []

for image in image_paths:
    img = cv2.imread(image)
    imgs.append(img)
    cv2.imshow("Image", img)
    cv2.waitKey(0)

imageStither = cv2.Stitcher_create()

error, stitched_img = imageStither.stitch(imgs)

if not error:
    cv2.imwrite("stitchedOutput.png", stitched_img)
    cv2.imshow("Stitched Image", stitched_img)
    cv2.waitKey(0)