import unittest
from circle import area, perimeter

class TestCircle(unittest.TestCase):

    def test_area(self):
        self.assertAlmostEqual(area(3), 28.274333882308139)
        self.assertAlmostEqual(area(0), 0)
        self.assertAlmostEqual(area(1), 3.141592653589793)

    def test_perimeter(self):
        self.assertAlmostEqual(perimeter(3), 18.84955592153876)
        self.assertAlmostEqual(perimeter(0), 0)
        self.assertAlmostEqual(perimeter(1), 6.283185307179586)

if __name__ == '__main__':
    unittest.main()
