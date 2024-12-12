import unittest
from rectangle import area, perimeter

class TestRectangle(unittest.TestCase):

    def test_area(self):
        self.assertEqual(area(2, 7), 14)
        self.assertEqual(area(4, 4), 16)
        self.assertEqual(area(0, 5), 0)
    def test_perimeter(self):
        self.assertEqual(perimeter(2, 7), 18)
        self.assertEqual(perimeter(4, 4), 16)
        self.assertEqual(perimeter(0, 5), 10)

if __name__ == '__main__':
    unittest.main()
