"""Python Array Test"""
import unittest
from array import PythonArray


class TestPythonArray(unittest.TestCase):
    """Python Array"""

    def test_size(self):
        """Size Test"""
        array = PythonArray()
        array.prepend(99)
        array.prepend(24)
        self.assertEqual(array.size(), 2)

    def test_isempty(self):
        """Is Empty Test"""
        array = PythonArray()
        self.assertTrue(array.is_empty())

    def test_prepend(self):
        """Prepend Test"""
        array = PythonArray()
        array.prepend(99)
        array.prepend(24)
        self.assertEqual(array[0], 24)

if __name__ == '__main__':
    unittest.main()
