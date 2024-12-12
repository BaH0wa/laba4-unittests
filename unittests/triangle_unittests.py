import unittest
from triangle import area, perimeter

class TestTriangle(unittest.TestCase):

    def test_area(self):
        self.assertEqual(area(2, 8), 8)
        self.assertEqual(area(6, 6), 18)
        self.assertEqual(area(0, 5), 0)

    def test_perimeter(self):
        self.assertEqual(perimeter(4, 5, 6), 15)
        self.assertEqual(perimeter(2, 2, 2), 6)
        self.assertEqual(perimeter(0, 0, 0), 0)

if __name__ == '__main__':
    unittest.main()