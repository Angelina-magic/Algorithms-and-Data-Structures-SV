# 康托展开是一个全排列到一个自然数的双射，因此是可逆的。
# 即对于上述例子，在（1，2，3，4，5）给出61可以算出起排列组合为 34152。由上述的计算过程可以容易的逆推回来，具体过程如下：
# 用 61 / 4! = 2余13，说明a[5]=2,说明比首位小的数有2个，所以首位为3。
# 用 13 / 3! = 2余1，说明a[4]=2，说明在第二位之后小于第二位的数有2个，所以第二位为4。
# 用 1 / 2! = 0余1，说明a[3]=0，说明在第三位之后没有小于第三位的数，所以第三位为1。
# 用 1 / 1! = 1余0，说明a[2]=1，说明在第二位之后小于第四位的数有1个，所以第四位为5。
# 最后一位自然就是剩下的数2啦。
# 通过以上分析，所求排列组合为 34152。


def fac(length):

    s = 1
    for i in range(1, length+1):
        s *= i

    return s


def cantor(length, sequence):
    v = []
    list_1 = []

    for i in range(1, length+1):
        v.append(i)

    for i in range(length-1, -1, -1):
        rem, sequence = divmod(sequence, fac(i))
        list_1.append(v[rem])
        del v[rem]

    return list_1


def main():

    length = int(input("Input the length of the list:"))
    sequence = int(input("Input the list's position:"))

    print("the list:\n", cantor(length, sequence))


main()
