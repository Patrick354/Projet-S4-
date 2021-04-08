import numpy as np
import cv2
import os
from sklearn.model_selection import train_test_split
import tensorflow as tf
import matplotlib.pyplot as plt
from tensorflow import keras
from tensorflow.keras import layers
from keras.preprocessing.image import ImageDataGenerator

myList = os.listdir("Image Test")
images = []
classNo = []

for x in myList:
    myPicList = os.listdir("Image Test/"+str(x))
    for y in myPicList:
        curImg = cv2.imread("Image Test/" + x + "/" + str(y))
        curImg = cv2.resize(curImg,(32,32))
        images.append(curImg)
        classNo.append(int(x))

images = np.array(images)
classNo = np.array(classNo)

X_train,X_test,y_train,y_test = train_test_split(images,classNo,test_size=0.2)

def preProcessing(img):
    img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    return img

X_train = np.array(list(map(preProcessing,X_train)))
X_test = np.array(list(map(preProcessing,X_test)))

X_train = X_train.reshape(X_train.shape[0],X_train.shape[1],X_train.shape[2],1)

X_train = tf.keras.utils.normalize(X_train,axis=1)
X_test = tf.keras.utils.normalize(X_train,axis=1)

model = tf.keras.models.Sequential()
model.add(tf.keras.layers.Flatten())
model.add(tf.keras.layers.Dense(128,activation=tf.nn.relu))
model.add(tf.keras.layers.Dense(128,activation=tf.nn.relu))
model.add(tf.keras.layers.Dense(10,activation=tf.nn.softmax))

model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

model.fit(X_train,y_train,epochs=30)
model.save('letter_reader.model')

new_model = tf.keras.models.load_model('letter_reader.model')
prediction = new_model.predict([X_test])


print(np.argmax(prediction[0]))

plt.imshow(X_test[0])
plt.show()
















