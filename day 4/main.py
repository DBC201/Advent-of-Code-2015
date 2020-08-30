import hashlib


def return_hash(inp):
    return hashlib.md5(inp.encode()).hexdigest()


def check_hash1(inp):
    return inp[0:5] == "00000"


def check_hash2(inp):
    return inp[0:6] == "000000"


if __name__ == '__main__':
    key = "yzbqklnj"
    number = 0
    while not check_hash1(return_hash(key+str(number))):
        number += 1
    print("Answer to part 1:", number)
    number = 0
    while not check_hash2(return_hash(key+str(number))):
        number += 1
    print("Answer to part 2:", number)