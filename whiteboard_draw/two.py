class Color:
    def __init__(self, r, g, b):
        self.r = int(r)    # 若r/g/b误输入为浮点数，将r/g/b转为整数
        self.g = int(g)
        self.b = int(b)
        assert (0 <= r <= 255) and (0 <= g <= 255) and (0 <= b <= 255)   # r/g/b必须为[0,255]之间的数，否则报错

    def __str__(self):   # 字符串化：(r,g,b)
        return "(%s,%s,%s)" % (self.r, self.g, self.b)


class Rectangular:
    def __init__(self, left_top, right_bottom, color):
        self.left_top_x = left_top[0]   # 矩阵左上角x坐标
        self.left_top_y = left_top[1]   # 矩阵左上角y坐标
        self.right_bottom_x = right_bottom[0]   # 矩阵右下角x坐标
        self.right_bottom_y = right_bottom[1]   # 矩阵右下角y坐标
        self.color = color   # 矩阵颜色


class WhiteBoard:
    def __init__(self, width, height):
        self.width = width    # 白板宽
        self.height = height   # 白板高
        self.background_color = Color(255, 255, 255)   # 白板颜色，方便更改白板背景颜色

    def draw(self, rectangular):   # 画矩阵
        for j in range(self.height):
            for i in range(self.width):
                # 按照行来打印矩阵
                # 若长宽在矩阵左上->右下之间，则打印矩阵的颜色
                if (rectangular.left_top_y <= j <= rectangular.right_bottom_y) and (rectangular.left_top_x <= i <= rectangular.right_bottom_x):
                    yield str(rectangular.color)
                else:  # 否则就打印白板的颜色
                    yield str(self.background_color)
            yield "\n"  # 每行打印完毕进行换行

    def print_img(self, rectangular):
        for i in self.draw(rectangular):
            print(i, end="")

    def save_img(self, rectangular):
        with open("img.txt", "a") as out:   # 由于为append，每次运行前需要清空img.txt
            for i in self.draw(rectangular):
                print(i, end="", file=out)


if __name__ == '__main__':
    w = WhiteBoard(11, 12)   # 定义一个白板，由于矩阵长宽都是从0开始，所以白板实际上能画的范围是 宽：[0, 11) 高：[0, 12)

    # case1：矩阵完全在白板内部
    rec = Rectangular((2, 2), (9, 10), Color(77, 90, 11))   # 定义一个矩阵，矩阵左上角坐标为(2,2)，右下角坐标为(9,10)，坐标为从0开始

    # case2：矩阵一部分超出了白板的大小，只打印在白板内部的部分矩阵面积
    # rec = Rectangular((2, 2), (100, 200), Color(77, 90, 11))

    # case3：矩阵矩阵完全超出白板的大小，只打印白板（矩阵坐标也可为负数）
    # rec = Rectangular((11, 12), (100, 200), Color(77, 90, 11))

    w.print_img(rectangular=rec)   # 打印
    w.save_img(rectangular=rec)   # 写文件

