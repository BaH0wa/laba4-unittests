import unittest
from circle import area, perimeter

class TestCircle(unittest.TestCase):

    def test_area(self):
        self.assertAlmostEqual(area(2), 12.566370614359173)
        self.assertAlmostEqual(area(4), 50.265482457436692)
        self.assertAlmostEqual(area(0), 0)

    def test_perimeter(self):
        self.assertAlmostEqual(perimeter(5), 31.415926535897932)
        self.assertAlmostEqual(perimeter(7), 43.982297150257105)
        self.assertAlmostEqual(perimeter(0), 0)

if __name__ == '__main__':
    unittest.main()