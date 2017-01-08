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


if __name__ == "__main__":
    main()
