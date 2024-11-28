import unittest
from triangle import area, perimeter

class TestTriangle(unittest.TestCase):

    def test_area(self):
        self.assertEqual(area(3, 4), 6.0)
        self.assertEqual(area(0, 4), 0.0)
        self.assertEqual(area(5, 2), 5.0)

    def test_perimeter(self):
        self.assertEqual(perimeter(3, 4, 5), 12)
        self.assertEqual(perimeter(0, 4, 5), 9)
        self.assertEqual(perimeter(1, 1, 1), 3)

if __name__ == '__main__':
    unittest.main()
