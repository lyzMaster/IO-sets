class BiggestMultiplication:
    def __init__(self, arr):
        self.arr = arr

    def quick_sort(self, left, right):
        if left >= right:
            return
        low = left
        high = right
        key = self.arr[low]
        while left < right:
            while left < right and self.arr[right] > key:
                right -= 1
            self.arr[left] = self.arr[right]
            while left < right and self.arr[left] <= key:
                left += 1
            self.arr[right] = self.arr[left]
        self.arr[right] = key
        self.quick_sort(low, left - 1)
        self.quick_sort(left + 1, high)

    def run(self):
        self.quick_sort(0, len(self.arr)-1)  # 递归法快排
        if self.arr[1] < 0:  # 考虑情况 [-10, -1, 0, 1, 2]。排序后的数组第二个数是负数，那么第一个数一定是负数
            mut_neg = self.arr[0] * self.arr[1]   # 最小的两个负数相乘的结果
            mut_pos = self.arr[-1] * self.arr[-2]   # 最大的两个正数相乘的结果
            if mut_neg > mut_pos:   # 若两个最小的负数相乘后结果 > 两最大正数相乘结果
                return self.arr[0], self.arr[1]
        return self.arr[-2], self.arr[-1]  # 返回最大的两个正数


if __name__ == '__main__':
    with open("one.in", "r") as f:
        for line in f.readlines():  # 按行读取输入文件
            line = line.strip("\n")   # 去掉换行符
            array = []
            for number in line.split(","):
                array.append(int(number))

            b = BiggestMultiplication(array)   # 运行核心方法
            print(b.run())  # 得到结果



