
class PythonArray(list):
    """Python Array"""

    def size(self):
        """get the array size"""
        return len(self)

    def is_empty(self):
        """is the array empty"""
        return len(self) == 0

    def prepend(self, item):
        """insert at index 0"""
        self.insert(0, item)
