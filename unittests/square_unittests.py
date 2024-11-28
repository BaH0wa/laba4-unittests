import unittest
from square import area, perimeter

class TestSquare(unittest.TestCase):

    def test_area(self):
        self.assertEqual(area(3), 9)
        self.assertEqual(area(0), 0)
        self.assertEqual(area(5), 25)

    def test_perimeter(self):
        self.assertEqual(perimeter(3), 12)
        self.assertEqual(perimeter(0), 0)
        self.assertEqual(perimeter(5), 20)

if __name__ == '__main__':
    unittest.main()
