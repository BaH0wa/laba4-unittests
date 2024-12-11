import unittest
from square import area, perimeter

class TestSquare(unittest.TestCase):

    def test_area(self):
        self.assertEqual(area(2), 4)
        self.assertEqual(area(7), 49)
        self.assertEqual(area(0), 0)

    def test_perimeter(self):
        self.assertEqual(perimeter(2), 8)
        self.assertEqual(perimeter(7), 28)
        self.assertEqual(perimeter(0), 0)

if __name__ == '__main__':
    unittest.main()