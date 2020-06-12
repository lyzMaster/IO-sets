import sys


class BiggestMultiplication:
    def __init__(self, arr):
        self.arr = arr
        # sys.maxsize：int最大值。初始化将int最小值赋予max，将int最大值赋给min
        self.max, self.se_max, self.min, self.se_min = -sys.maxsize-1, -sys.maxsize-1, sys.maxsize, sys.maxsize

    def sort(self):
        # 遍历一遍即可
        for num in self.arr:
            if num > self.max:
                self.se_max = self.max
                self.max = num
            elif num > self.se_max:
                self.se_max = num
            if num < self.min:
                self.se_min = self.min
                self.min = num
            elif num < self.se_min:
                self.se_min = num

    def run(self):
        self.sort()
        if self.se_min < 0:   # 若次小值小于0，则最小值一定为负数
            mut_neg = self.min * self.se_min   # 最小的两个负数相乘的结果
            mut_pos = self.max * self.se_max   # 最大的两个正数相乘的结果
            if mut_neg > mut_pos:
                return self.min, self.se_min
        return self.max, self.se_max


if __name__ == '__main__':
    with open("one.in", "r") as f:
        for line in f.readlines():  # 按行读取输入文件
            line = line.strip("\n")   # 去掉换行符
            array = []
            for number in line.split(","):
                array.append(int(number))

            b = BiggestMultiplication(array)   # 运行核心方法
            print(b.run())  # 得到结果



