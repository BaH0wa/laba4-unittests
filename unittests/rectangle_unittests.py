import unittest
from rectangle import area, perimeter

class TestRectangle(unittest.TestCase):

    def test_area(self):
        self.assertEqual(area(3, 4), 12)
        self.assertEqual(area(0, 4), 0)
        self.assertEqual(area(5, 5), 25)

    def test_perimeter(self):
        self.assertEqual(perimeter(3, 4), 14)
        self.assertEqual(perimeter(0, 4), 8)
        self.assertEqual(perimeter(5, 5), 20)

if __name__ == '__main__':
    unittest.main()
