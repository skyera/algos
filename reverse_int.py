# 9/12/2015


def reverse_int_bits(num):
    result = 0
    
    while num != 0:
        a = num & 1
        result = result * 2 + a
        num >>= 1
    
    return result 


def test(str1, str2):
    num1 = int(str1, 2);

    value = reverse_int_bits(num1)
    bvalue = bin(value)
    ok = bin(value) == str2

    if not ok:
        print 'failed', str1, value, bvalue, str2
    else:
        print 'pass'

def main():
    test("0b11101101", "0b10110111")
    test("0b10001111", "0b11110001")
    test("0b00000000", "0b0")
    test("0b01010001", "0b1000101")


if __name__ == '__main__':
    main()

