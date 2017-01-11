"""Python Practice Driver"""
from array import PythonArray


def main():
    """Main"""
    array = PythonArray()
    array.append(1)
    array.append(22)
    print array.size()
    print array.is_empty()
    print array[0]
    array.prepend(999)
    print array[0]
    print array.pop()
    print len(array)
    del array[1]
    print len(array)


if __name__ == "__main__":
    main()
