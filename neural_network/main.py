import cv2
import numpy as np
import pandas as pd
import math
#list in lists = ["A", "B", 3]

def create_table(lists: np.array):# в этом месте можно придумать алгоритм который будет быстрее находить все дороги от заданной точки
    points = sorted(list(map(str, list(set(lists[:, 0]) | set(lists[:, 1])))))# пока что нам нгадо заполнить только верхний треугольник
    final_array = np.full((len(points), len(points)), -1)
    search = points
    for i in range(1, len(points)):
        for road in lists:
            if road[0] == points[i - 1] and road[1] in search:
                final_array[i - 1, points.index(road[1])] = road[2]# если сразу закнуть в pandas, то можно работать по буквам в колонках   
                final_array[points.index(road[1]), i - 1] = road[2]
            if road[1] == points[i - 1] and road[0] in search:
                final_array[i - 1, points.index(road[0])] = road[2]
                final_array[points.index(road[0]), i - 1] = road[2]
        search = search[1:]
    DataFrame = pd.DataFrame(final_array, index=points, columns=points)
    print(points)
    print(DataFrame)# можно было просто выкидывать рёбра
    DataFrame.to_csv("C:/projects/GRAPH/c_plus_plus_part/table.csv", header=False)


def main():
    lists = np.array([["A", "B", 3], ["B", "C", 6], ["C", "D", 21], ["D", "A", 5]])
    create_table(lists)


if __name__ == "__main__":
    main()
"""
def processing_picture(img: np.ndarray):
    img = cv2.resize(img, (int(img.shape[1] * 2), int(img.shape[0] * 2)))
    img_grey = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)  # сделали изображение одноканальным (серым)
    img_shape = cv2.Canny(img_grey, 100, 110) # отмечаем границы
    # изменим ширину обводки
    kernel = np.ones((2, 2), np.uint8)
    #img_shape = cv2.dilate(img_shape, kernel, iterations=0)
    img_shape = cv2.GaussianBlur(img_shape, (3, 3), 0)
    return img_shape


def show_picture(img: np.ndarray):
    cv2.imshow("RESULTS", img)
    cv2.waitKey(0)


def paint(img: np.ndarray):
    con, hir = cv2.findContours(img, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)# RETR_LIST - режим получения всех контуров,CHAIN_APPROX_NONE - метод получения контуров
    return img


def layering(img: np.ndarray):
    b, g, r = cv2.split(img)
    img = cv2.merge([b, g, r]) # соединили 3 слоя
    show_picture(img)


#img = cv2.imread("images/14.PNG")
#cv2.imshow("Results", img)
#cv2.waitKey(0)# время которое будет показываться картинка

cap = cv2.VideoCapture("videos/cat.mp4")# если поставить 0, 1, 2... то получим доступ к 1-ой, 2-ой и тд камерам

while True:
    success, img = cap.read()# success - булево значение
    img = cv2.resize(img, (500, 500))

    cv2.imshow("Result", img)
    key = cv2.waitKey(5)# получает код нажатого элемента
    #print(key & 0xFF, chr(key & 0xFF))  в этой строке будет выводиться код
    if key & 0xFF == ord("q"):# cv2.waitKey(5) & 0xFF эта фигня вернёт код нажатого элемента в asci
        break

    if cv2.getWindowProperty("Result", cv2.WND_PROP_VISIBLE) == 0:# для закрытия окна при нажатии крестика
        break



img = cv2.imread("C:/projects/GRAPH/neural_network/images/shortest_rod.png")
print(img.shape)
print(img)
#photo = np.zeros((450, 450, 3), dtype="uint8")
#photo = paint(photo)
img_gr = processing_picture(img)
show_picture(img_gr)
"""